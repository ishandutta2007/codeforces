#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<vector<int>> graph;


long long a, b, k, n, m, tmp, ans = 0;
struct as
{
    public:
    int xor_;
    bool has_k;
    bool has_full;
};

as dfs(int cur, int prev)
{
    as ret;

    ret.xor_ = ::data[cur];
    ret.has_k = false;
    ret.has_full = false;

    int num_k = 0;

    for (int i = 0; i < ::graph[cur].size(); ++i)
    {
        int next = ::graph[cur][i];
        if (next != prev)
        {
            as nt = dfs(next, cur);

            if (nt.has_full)
                ret.has_full = true;

            ret.xor_ ^= nt.xor_;

            if (nt.has_k)
            {
                ret.has_k = true;
                num_k++;
            }
        }
    }


    if (ret.xor_ == k)
        ret.has_k = true;

    if (ret.xor_ == 0 && ret.has_k)
        ret.has_full = true;


    if (num_k >= 2)
        ret.has_full = true;


    //cout << "for " << cur<< ", " << ret.xor_ << ", " << ret.has_k << ", " <<ret.has_full << endl;

    return ret;
}




int solve()
{
    cin >> n >> a;

    ::data.resize(n);
    ::graph.resize(n);

    k = 0;

    for (int i = 0; i < n; ++i)
        {cin >> ::data[i];
        k^= ::data[i];
        graph.resize(0);
        }

        for (int i = 0; i < n-1; ++i)
        {
                int val1, val2;
                cin >> val1 >> val2;
                val1--; val2--;
                ::graph[val1].push_back(val2);
                ::graph[val2].push_back(val1);

        }



    if (k == 0)
    {
        cout << "YES" << endl;
        return 0;
    }

    if (a < 3)
    {
        cout << "NO" << endl;
        return 0;
    }


    as a = dfs(0, -1);

    cout << ((a.has_full)? "YES" : "NO") << endl;


    return 0;
}


int main()
{
    FAST;


    int t;
    cin >> t;
    while(t--)
        solve();




    return 0;
}