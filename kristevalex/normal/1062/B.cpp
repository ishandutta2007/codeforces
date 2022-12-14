#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, Max = 0, Min = 10000000, ans = 1;





int main()
    {
    FAST;


    cin >> n;

    if (n == 1)
    {
    cout << "1 0";
    return 0;
    }

    m = n;
    int SQRT = sqrt(n);

    map<int, int> Map;

    for (int i = 2; i <= SQRT; ++i)
        {
        while (m%i == 0)
            {
            m/= i;
            ++(Map[i]);
            }
        }

    if (m > 1) ++(Map[m]);


    for (auto it = Map.begin(); it != Map.end(); ++it)
        {
        ans*= it->first;
        if (Max < it->second) Max = it->second;
        if (Min > it->second) Min = it->second;
        }


    tmp = 1;

    for (int i = 1; true; i++)
        {
        if (tmp >= Max)
            {
            if (Max == Min && tmp == Max)
                cout << ans << " " << i-1;
            else
                cout << ans << " " << i;

            return 0;
            }

        tmp*= 2;
        }


    return 0;
    }