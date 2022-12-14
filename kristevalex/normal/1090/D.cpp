#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<pair<int, int>> _data;

vector<vector<int>> graph;

long long a, b, k, n, m, tmp, ans = 0;

long long cur_ind = 0;



int dfs(int ver, int prev)
    {
    _data[ver].first = -1;

    int ans_ = -1;
    for (int i = 0; i < graph[ver].size(); i++)
        {
        int next = graph[ver][i];
        if (next == prev) continue;
        if (_data[next].first == -1)
            {
            //cout << "! no" << ver << " " << next << endl;

            ans = -1;
            return -11;
            }
        if (_data[next].first == -2) ans_ = max(ans_, dfs(next, ver));
        if (_data[next].first >= 0) ans_ = max(ans_, _data[next].first);
        }

    _data[ver].first = ans_+1;

    return ans_;
    }





int main()
    {
    FAST;


    cin >> n >> m;


    _data.resize(n);
    graph.resize(n);

    for (int i = 0; i < m; i++)
        {
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        }

    int good = -1;
    int next = -1;
    for (int i = 0; i < n; i++)
        {
        if (graph[i].size() < n-1)
            {
            good = i;

            //cout << "good :" << i << endl;

            vector<int> full(n, 1);
            for (int j = 0; j < graph[i].size(); j++)
                {
                full[graph[i][j]]--;
                }

            for (int j = 0; j < n; j++)
                {
                if (i == j) continue;
                if (full[j] == 1)
                    {
                    next = j;
                    break;
                    }
                }

            break;
            }
        }

    if (good == -1)
    {
      cout << "NO";
      return 0;
    }
cout <<"YES"<< endl;
    int cnt = 3;
    for (int i = 0; i < n; i++)
        {
        if (i == good) cout << 1 << " ";
        else if (i == next) cout<< 2 << " ";
        else
            {
            cout << cnt << " ";
            ++cnt;
            }
        }

    cout << endl;

cnt = 3;
    for (int i = 0; i < n; i++)
        {
        if (i == good) cout << 1 << " ";
        else if (i == next) cout<< 1 << " ";
        else
            {
            cout << cnt << " ";
            ++cnt;
            }
        }



    }