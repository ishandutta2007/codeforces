#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<pair<long long, long long>> data;
vector<bool> ansers;

long long a, b, k, d, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> m >> d >> n;

    data.resize(n);
    ansers.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i].first >> data[i].second;
        ansers[i] = false;
        }


    for (int i = 0; i < n; i++)
        {
        long long x = data[i].first + data[i].second;
        long long y = data[i].first - data[i].second;

        if (y <= d && y >= -d && x >= d && x <= 2*m - d)
            {ansers[i] = true;}
        }

    for (int i = 0; i < n; i++)
        {
        cout << ((ansers[i])? "YES":"NO") << endl;
        }

    return 0;
    }