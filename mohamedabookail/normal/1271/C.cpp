/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n, a, b;
	cin >> n >> a >> b;
	ll top = 0, bottom = 0, left = 0, right = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		if(x < a && y < b)  { left++; bottom++;  }
		if(x > a && y > b)  { top++; right++;    }
		if(x > a && y < b)  { right++; bottom++; }
		if(x < a && y > b)  { top++; left++;     }
		if(x == a && y < b) { bottom++;	         }
		if(x == a && y > b) { top++;             }
		if(x < a && y == b) { left++;            }
		if(x > a && y == b) { right++;           }
	}
	ans = max({left, right, top, bottom});
	cout << ans << endl;
	if(left == ans) { cout << (a - 1) << ' ' << b << endl; }
	else if(right == ans) { cout << (a + 1) << ' ' << b << endl; }
	else if(top == ans) { cout << a << ' ' << (b + 1) << endl; }
	else { cout << a << ' ' << (b - 1) << endl; }
}