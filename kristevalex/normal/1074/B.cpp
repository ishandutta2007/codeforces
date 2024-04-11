#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, t, m, tmp1, tmp2, ans = 0;


void solve()
    {
    cin >> n;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n-1; i++)
        {
        cin >> tmp1 >> tmp2;
        --tmp2;
        --tmp1;

        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
        }

    int sz_my;
    cin >> sz_my;
    map<int, int> My;
    for (int i = 0; i < sz_my; i++)
        {
        cin >> tmp1;
        --tmp1;
        My[tmp1] = 1;
        //cout << tmp1 << " ";
        }

    int sz_over;
    cin >> sz_over;
    map<int, int> Over;
    for (int i = 0; i < sz_over; i++)
        {
        cin >> tmp1;
        --tmp1;
        Over[tmp1] = 1;
        }

    cout << "B " << 1+tmp1 << endl;
    cout.flush();
    cin >> tmp1;
    --tmp1;


     if (My[tmp1] == 1)
        {

        cout << "C " << 1+tmp1 << endl;

        cout.flush();

        return;
        }



    queue<int> Queue;
    vector<bool> used(n);
    Queue.push(tmp1);
    used[tmp1] = true;

    //cout << "start" << endl;

    while(true)
        {
        int cur = Queue.front();
        Queue.pop();
        //cout << cur << " ";

        for (int i = 0; i < graph[cur].size(); i++)
            {
            int next = graph[cur][i];
            if (!used[next])
                {
                if (My[next] == 1)
                    {
                    cout << "A " << 1+next << endl;
                    cout.flush();
                    cin >> tmp1;
                    --tmp1;

                    if (Over[tmp1] == 1)
                        cout << "C " << 1+next << endl;
                    else
                        cout << "C -1" << endl;
                    cout.flush();

                    return;
                    }

                used[next] = true;
                Queue.push(next);
                }
            }
        }
    }


int main()
    {
    //FAST;


    cin >> t;



    for (int i = 0; i < t; i++)
        solve();


    return 0;
    }