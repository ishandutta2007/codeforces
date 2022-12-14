#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long n, m, a, b, num, ans;



int main()
    {
    FAST;

    cin >> n >> m >> a >> b;

    num = n/m;


    ans = (-num*m + n)*b;
    //cout << ans << endl;
    ans = min(ans, ((-n + m*(num+1)))*a);


    cout << ans;

    return 0;
    }