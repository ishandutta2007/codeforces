#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;
vector<long long> _data;

long long a, b, k, n, m, tmp, ans = 0;

vector<vector<int>> graph;



int dfs(int ver, int prev)
    {
    if (_data[ver] != -1) return _data[ver];
//cout << "hello!" << ver << " " << prev <<  endl;
    int ans_ = 0;
    for (int i = 0; i < graph[ver].size(); i++)
        {
        int next = graph[ver][i];
        if (next == prev) continue;
        ans_+= dfs(next, ver);
        }
    if (ans_ == 0) ans_ = 1;

    _data[ver] = ans_;
    return ans_;
    }


int main()
    {
    //FAST;


    cin >> n;

    data.resize(n);
    _data.resize(n);

    graph.resize(n);

    for (int i = 0; i < n; i++)
        {
        _data[i] = -1;
        }

    for (int i = 1; i < n; i++)
        {cin >> data[i]; data[i]--;
        graph[data[i]].push_back(i);
        graph[i].push_back(data[i]);

        }


    dfs(0, 0);


sort(_data.begin(), _data.end());
for (int i = 0; i < n; i++)
        {
        cout << _data[i] << " ";
        }




    return 0;
    }