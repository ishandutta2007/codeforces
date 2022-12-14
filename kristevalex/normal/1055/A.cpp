#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> dataa;
vector<long long> datab;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m;
    --m;

    dataa.resize(n);
datab.resize(n);

    for (int i = 0; i < n; i++)
        cin >> dataa[i];
for (int i = 0; i < n; i++)
        cin >> datab[i];

    if (dataa[0] == 0)
    {
        cout << "NO";
        return 0;
    }

    if (dataa[m] == 1)

    {
        cout << "YES";
        return 0;
    }

    if (datab[m] == 0)

    {
        cout << "NO";
        return 0;
    }

    for (int i = m; i < n; i++)
        {
        if (datab[i] == 1 && dataa[i] == 1)

            {
            cout << "YES";
            return 0;
            }
        }

    cout << "NO";

    return 0;
    }