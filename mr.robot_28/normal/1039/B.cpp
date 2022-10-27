#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(time(0));
 
signed main() {
    ll n;
	int  k;
    cin >> n >> k;
    ll l = 1, r = n;
    while(true)
    {
    	while(r - l > 50)
	    {
    		ll midd = (r + l) / 2;
    		cout << l << " " << midd << endl;
    		string s;
    		cin >> s;
    		if(s == "Yes")
    		{
    			r = midd;
    		}
    		else
    		{
    			l = midd + 1;
    		}
    		l = max(1LL, l - k);
    		r = min(n, r + k);
		}
		int len = (r - l + 1);
		int a = rnd() % len;
		cout << a + l << " " << a + l << endl;
		string s;
		cin >> s;
		if(s == "Yes")
		{
			return 0;
		}
		l = max(1ll, l - k);
		r = min(n, r + k);
	}
    return 0;
}