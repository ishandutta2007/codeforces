#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long ans = 0, n;



int main()
    {
    FAST;

    cin >> n;
    ans+= n%5;
    n-= n%5;

    if (n%10 == 5)
        {
        ans++;
        }
    n/=10;

    ans+= n%2;
    n-= n%2;

    ans+= (n%10)/2;
    n/= 10;

    ans+= n;




    cout << ans;

    return 0;
    }