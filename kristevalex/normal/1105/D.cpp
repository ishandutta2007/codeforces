#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<string> field;

long long a, b, k, n, m, tmp, ans = 0, p;


#define pii pair<int, int>

vector<int> datap;
vector<int> dataa;
vector<queue<pii>> dataq;


void print()
    {
    for (int i = 0; i < p; i++)
        {
        cout << dataa[i] << " ";
        }
    }


int main()
    {
    FAST;


    cin >> n >> m >> p;

    datap.resize(p);
    dataa.resize(p);
    dataq.resize(p);
    for (int i = 0; i < p; i++)
        {
        cin >> datap[i];
        datap[i] = min((long long)datap[i], m*n);
        dataa[i] = 0;
        }

    field.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> field[i];

        for (int j = 0; j < m; j++)
            {
            if (field[i][j] - '1' >= 0 && field[i][j] - '1' < 9)
                {
                dataq[field[i][j] - '1'].push({i, j});
                dataa[field[i][j] - '1']++;
                }
            }

        }

    int n_2[9] = {};

    for (int i = 0, n__2 = 1; i < p; i++)
        {
        ans+= n__2;
        n_2[i] = n__2;

        n__2*=2;
        }

    while (ans > 0)
        {
        for (int i = 0; i < p; i++)
            {
            for (int j = 0; j < datap[i]; j++)
                {
                if (dataq[i].empty())
                    {
                    if (ans & n_2[i]) ans-= n_2[i];
                    break;
                    }

                dataq[i].push({-1, -1});

                while(true)
                    {
                    auto cur = dataq[i].front();
                    dataq[i].pop();
                    if (cur == pii(-1, -1)) break;

                    if (cur.first > 0)
                        if (field[cur.first-1][cur.second] == '.')
                            {
                            dataq[i].push({cur.first-1, cur.second});
                            field[cur.first-1][cur.second] = '#';
                            dataa[i]++;
                            }

                    if (cur.second > 0)
                        if (field[cur.first][cur.second-1] == '.')
                            {
                            dataq[i].push({cur.first, cur.second-1});
                            field[cur.first][cur.second-1] = '#';
                            dataa[i]++;
                            }

                    if (cur.first < n-1)
                        if (field[cur.first+1][cur.second] == '.')
                            {
                            dataq[i].push({cur.first+1, cur.second});
                            field[cur.first+1][cur.second] = '#';
                            dataa[i]++;
                            }

                    if (cur.second < m-1)
                        if (field[cur.first][cur.second+1] == '.')
                            {
                            dataq[i].push({cur.first, cur.second+1});
                            field[cur.first][cur.second+1] = '#';
                            dataa[i]++;
                            }


                    }

                }
            }
        }







    print();

    return 0;
    }