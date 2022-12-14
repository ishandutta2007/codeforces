#include <bits/stdc++.h>
using namespace std;




int n, m, k, s;






int main()
    {
    cin >> n >> m >> k >> s;


    vector<int> tovar (n);
    vector<vector<int>> graph (n);

    for (int i = 0; i < n; i++)
        {
        cin >> tovar[i];
        tovar[i]--;
        }

    int tmp1, tmp2;

    for (int i = 0; i < m; i++)
        {
        cin >> tmp1 >> tmp2;
        graph[--tmp1].push_back(--tmp2);
        graph[tmp2].push_back(tmp1);
        }

    for (int i = 0; i < n; i++)
        {
        queue<pair<int, int>> Queue;
        vector<bool> used_ver (n, false);
        vector<bool> used_tovar (k, false);
        int sum_dist = 0, num_of = 1;
        used_ver[i] = true;
        used_tovar[tovar[i]] = true;

        Queue.push({i, 0});

        while (!Queue.empty())
            {
            if (num_of >= s) break;
            pair<int, int> cur_ver = Queue.front();
            Queue.pop();
            int SIZE = graph[cur_ver.first].size();
            for (int j = 0; j < SIZE; j++)
                {
                int next_ver = graph[cur_ver.first][j];
                if (!used_ver[next_ver])
                    {
                    used_ver[next_ver] = true;
                    Queue.push({next_ver, cur_ver.second+1});
                    if (!used_tovar[tovar[next_ver]])
                        {
                        //cout << "moving to: " << next_ver << endl;
                        used_tovar[tovar[next_ver]] = true;
                        num_of++;
                        sum_dist+= cur_ver.second+1;
                        if (num_of >= s) break;
                        }
                    }
                }
            if (num_of >= s) break;
            }
        cout << sum_dist << " ";
        }

    return 0;
    }