#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> a >> b;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 0; i < n/2; i++)
        {
        if (data[i] == 2 && data[n-i-1] == 2)
            {
            ans+= 2*min(a, b);
            continue;
            }

        if (data[i] == 2 || data[n-i-1] == 2)
            {
            if (min(data[i], data[n-i-1]) == 0) ans+= a;
            else ans+= b;

            continue;
            }

        if (data[i] != data[n-i-1])
            {
            cout << -1;
            return 0;
            }
        }

    if (n&1)
        if (data[n/2] == 2)
            ans+= min(a, b);


    cout << ans;

    return 0;
    }