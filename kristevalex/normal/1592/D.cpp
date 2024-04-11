#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<bool> used;
vector<set<int>> graph;


long long a, b, k, n, m, tmp, ans = 0;

int dfs(int cur, int prev, int maxn)
{
    if (maxn <= 0)
        return 0;

    if (::graph[cur].size() == 0)
        return 0;

    if (::used[cur])
        return 0;

    ::used[cur] = true;
        ::data.push_back(cur);
    if (maxn == 1)
    {
        return 1;
    }
    int ret = 1;

    for (auto it = ::graph[cur].begin(); it != ::graph[cur].end(); ++it)
    {
        int next = *it;
        if (next != prev)
        {
            int nt = dfs(next, cur, maxn - ret);
            ret += nt;
        }
    }



    //cout << "for " << cur<< ", " << ret.xor_ << ", " << ret.has_k << ", " <<ret.has_full << endl;

    return ret;
}




int solve()
{
    cin >> n;

    ::data.resize(n);
    ::graph.resize(n);
    ::used.resize(n);

    vector<pair<int, int>> eds(n-1);


        for (int i = 0; i < n-1; ++i)
        {
                int val1, val2;
                cin >> val1 >> val2;
                val1--; val2--;
                ::graph[val1].insert(val2);
                ::graph[val2].insert(val1);
                eds[i] = {val1, val2};

        }




    cout << "? " << n << " ";
        for (int i = 0; i < n; ++i)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
        fflush(stdout);

        cin >> ans;


    int edgt = n-1;

    int edgn = edgt / 2;

    while (edgt > 1)
    {
        edgn = edgt / 2;

        ::data.resize(0);
        for (int i = 0; i < n; ++i)
        {
            ::used[i] = false;
        }

        int tl = edgn;

        //cout <<"req " <<  tl << ", tot: " << edgt <<  endl;
        for (int i = 0; i < n; ++i)
        {
            int vl = dfs(i, -1, tl + 1);
            //cout << "fn: " << vl<< " " <<tl+1 << endl;
            tl -= max(vl-1, 0);

            if (tl == 0)
                break;
        }

        cout << "? " << ::data.size() << " ";
        for (int i = 0; i < ::data.size(); ++i)
        {
            cout << ::data[i] + 1 << " ";
        }
        cout << endl;
        fflush(stdout);

        cin >> k;

        if (k == ans)
        {
            edgt = edgn;
            for (int i = 0; i < n-1; ++i)
            {
                if (!::used[eds[i].first] || !::used[eds[i].second])
                {
                    //cout << "er1 " << eds[i].first << " " << eds[i].second << endl;
                    ::graph[eds[i].first].erase(eds[i].second);
                    ::graph[eds[i].second].erase(eds[i].first);
                }
            }
        }
        else
        {
            edgt = edgt - edgn;
            for (int i = 0; i < n-1; ++i)
            {
                if (::used[eds[i].first] && ::used[eds[i].second])
                {
                    //cout << "er2 " << eds[i].first << " " << eds[i].second << endl;
                    ::graph[eds[i].first].erase(eds[i].second);
                    ::graph[eds[i].second].erase(eds[i].first);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (::graph[i].size() > 0)
        {
            cout << "! " << i+ 1 << " " << *(::graph[i].begin()) + 1 << endl;
            fflush(stdout);

            return 0;
        }
    }




    return 0;
}


int main()
{
    FAST;


        solve();




    return 0;
}