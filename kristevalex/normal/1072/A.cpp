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


    cin >> n >> m >> k;

    data.resize(n);

    long long cur = (2*m+2*n-4);

    for (int i = 0; i < k; i++)
        {
        ans+= cur;
        cur-= 16;
        }




    cout << ans;

    return 0;
    }