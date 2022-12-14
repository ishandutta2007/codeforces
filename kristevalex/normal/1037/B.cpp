#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, tmp, ans = 0, s;





int main()
    {
    FAST;


    cin >> n >> s;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());


    long long middle = data[n/2];
    if (middle == s)
        {
        cout << 0;
        return 0;
        }

    if (middle < s)
        {
        for (int i = n/2; i < n; i++)
            {
            if (data[i] < s) ans-= (data[i] - s);
            }

        cout << ans;
        return 0;
        }

    if (s < middle)
        {
        for (int i = 0; i <= n/2; i++)
            {
            if (s < data[i]) ans-= (s - data[i]);
            }

        cout << ans;
        return 0;
        }


    return 0;

    }