#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0, t;


char inv(char a)
{
    if (a == '0')
        return '1';
    return '0';
}

void solve()
{
    cin >> n >> m;
    vector<std::string> data(n);
    vector<pair<int, int>> as;

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    if (n%2 == 1 && m%2 == 1)
    {
        if (data[n-1][m-1] == '1')
        {
            as.push_back({n-1  , m-1  });
            as.push_back({n-1-1, m-1  });
            as.push_back({n-1  , m-1-1});

            data[n-2][m-1] = inv(data[n-2][m-1]);
            data[n-1][m-2] = inv(data[n-1][m-2]);
        }
    }

    if (m%2 == 1)
    {
        for (int i = 0; i < n/2; ++i)
        {
            if (data[2*i][m-1] == '1')
            {
                as.push_back({2*i  , m-1  });
                as.push_back({2*i  , m-1-1});
                as.push_back({2*i+1, m-1-1});

                data[2*i  ][m-2] = inv(data[2*i  ][m-2]);
                data[2*i+1][m-2] = inv(data[2*i+1][m-2]);
            }
            if (data[2*i+1][m-1] == '1' )
            {
                as.push_back({2*i+1, m-1  });
                as.push_back({2*i  , m-1-1});
                as.push_back({2*i+1, m-1-1});

                data[2*i  ][m-2] = inv(data[2*i  ][m-2]);
                data[2*i+1][m-2] = inv(data[2*i+1][m-2]);
            }
        }
    }

    if (n%2 == 1)
    {
        for (int j = 0; j < m/2; ++j)
        {
            if (data[n-1][2*j] == '1')
            {
                as.push_back({n-1  , 2*j  });
                as.push_back({n-1-1, 2*j  });
                as.push_back({n-1-1, 2*j+1});

                data[n-2][2*j  ] = inv(data[n-2][2*j  ]);
                data[n-2][2*j+1] = inv(data[n-2][2*j+1]);
            }
            if (data[n-1][2*j+1] == '1')
            {
                as.push_back({n-1  , 2*j+1});
                as.push_back({n-1-1, 2*j  });
                as.push_back({n-1-1, 2*j+1});

                data[n-2][2*j  ] = inv(data[n-2][2*j  ]);
                data[n-2][2*j+1] = inv(data[n-2][2*j+1]);
            }
        }
    }

    for (int i = 0; i < n/2; ++i)
    {
        for (int j = 0; j < m/2; ++j)
        {
            int sum = 0;
            if (data[2*i][2*j] == '1')
                sum++;
            if (data[2*i][2*j+1] == '1')
                sum++;
            if (data[2*i+1][2*j] == '1')
                sum++;
            if (data[2*i+1][2*j+1] == '1')
                sum++;

            if (sum == 1)
            {

                int dn = 1;

                int dm = 1;

                int ii = 2*i;
                int jj = 2*j;


                if (data[2*i][2*j] == '1')
                {


                }
                if (data[2*i][2*j+1] == '1')
                {
                    dm = -1;
                    jj++;


                }
                if (data[2*i+1][2*j] == '1')
                {
                    dn = -1;
                    ii++;


                }
                if (data[2*i+1][2*j+1] == '1')
                {
                    dn = -1;
                    dm = -1;
                    ii++;
                    jj++;


                }

                as.push_back({ii   , jj   });
                as.push_back({ii+dn, jj   });
                as.push_back({ii+dn, jj+dm});

                as.push_back({ii   , jj   });
                as.push_back({ii   , jj+dm});
                as.push_back({ii+dn, jj+dm});

                as.push_back({ii   , jj+dm});
                as.push_back({ii+dn, jj   });
                as.push_back({ii   , jj   });
            }
            else if (sum == 2)
            {
                if (data[2*i][2*j] == '1' && data[2*i + 1][2*j + 1] == '1')
                {
                    as.push_back({2*i   , 2*j   });
                    as.push_back({2*i+1, 2*j   });
                    as.push_back({2*i   , 2*j+1});

                    as.push_back({2*i+1, 2*j   });
                    as.push_back({2*i   , 2*j+1});
                    as.push_back({2*i+1, 2*j+1});
                }
                else if (data[2*i][2*j + 1] == '1' && data[2*i + 1][2*j] == '1')
                {
                    as.push_back({2*i   , 2*j   });
                    as.push_back({2*i+1, 2*j   });
                    as.push_back({2*i+1, 2*j+1});

                    as.push_back({2*i   , 2*j   });
                    as.push_back({2*i   , 2*j+1});
                    as.push_back({2*i+1, 2*j+1});
                }
                else
                {
                    for (int ii = 0; ii < 2; ++ii)
                    {
                        for (int jj = 0; jj < 2; ++jj)
                        {
                            if (data[2*i + ii][2*j + jj] == '0')
                            {
                                as.push_back({2*i+ii, 2*j+jj});
                                as.push_back({2*i+ii, 2*j+(1-jj)});
                                as.push_back({2*i+(1-ii), 2*j+jj});
                            }
                        }
                    }
                }
            }
            else if (sum == 3)
            {
                for (int ii = 0; ii < 2; ++ii)
                {
                    for (int jj = 0; jj < 2; ++jj)
                    {
                        if (data[2*i + ii][2*j + jj] == '0')
                        {
                            as.push_back({2*i+(1-ii), 2*j+(1-jj)});
                            as.push_back({2*i+ii, 2*j+(1-jj)});
                            as.push_back({2*i+(1-ii), 2*j+jj});
                        }
                    }
                }
            }
            else if (sum == 4)
            {

                    as.push_back({2*i  , 2*j  });
                    as.push_back({2*i+1, 2*j  });
                    as.push_back({2*i+1, 2*j+1});

                    as.push_back({2*i  , 2*j  });
                    as.push_back({2*i  , 2*j+1});
                    as.push_back({2*i+1, 2*j+1});

                    as.push_back({2*i  , 2*j  });
                    as.push_back({2*i+1, 2*j  });
                    as.push_back({2*i  , 2*j+1});

                    as.push_back({2*i+1, 2*j  });
                    as.push_back({2*i  , 2*j+1});
                    as.push_back({2*i+1, 2*j+1});

            }

        }
    }


    cout << as.size()/3 << endl;

    vector<string>ass(n);

    for (int i = 0; i < n; ++i)
    {
        ass[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            ass[i][j] = '0';
        }
    }

    for (int i = 0; i < as.size(); ++i)
    {
        ass[as[i].first][as[i].second] = inv(ass[as[i].first][as[i].second]);
        cout << as[i].first + 1 << " " << as[i].second + 1 << " ";
        if(i%3 == 2)
            cout << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        //cout << ass[i] << endl;
    }
}


int main()
{
    FAST;

    cin >> t;

    while(t--)
        solve();

    return 0;
}