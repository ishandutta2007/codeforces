#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 1, sum = 0;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        sum+= data[i];
        if (data[i] > ans) ans = data[i];
        }


    while (ans*n <= 2*sum)
        ans++;



    cout << ans;

    return 0;
    }