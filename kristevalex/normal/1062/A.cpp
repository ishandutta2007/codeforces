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


    cin >> n;

    data.resize(n+2);
    data[0] = 0;

    for (int i = 1; i <= n; i++)
        cin >> data[i];

    data[n+1] = 1001;


    int cur = 0;
    for (int i = 1; i < n+2; i++)
        {
        if (data[i] == data[i-1] + 1) ++cur;
        else cur = 0;
        if (ans < cur) ans = cur;
        }

    ans-= 1;
    if (ans < 0) ans = 0;

    cout << ans;

    return 0;
    }