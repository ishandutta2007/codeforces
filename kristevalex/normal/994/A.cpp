#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, m, tmp;


int main()
    {
    FAST;

    cin >> n >> m;

    vector<long long> data (n);
    vector<bool> fingers (10, false);


    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        }

    for (int i = 0; i < m; i++)
        {
        cin >> tmp;
        fingers[tmp] = true;
        }

    queue<long long> Queue;

    for (int i = 0; i < n; i++)
        {
        if (fingers[data[i]])
            {
            Queue.push(data[i]);
            }
        }


    //cout << ;

    while (!Queue.empty())
        {
        cout << Queue.front() << " ";
        Queue.pop();
        }


    return 0;
    }