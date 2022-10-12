/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector <ll> a(n), b(n);
	set <ll> st;
	stack <ll> stk;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		ll x = st.size();
		st.insert(i);
		if(x != st.size()) {
			stk.push(i);
		}
	}
	int g = 0;
	for (ll i = 0; i < n; i++) {
		if(a[i] != 0) {
			b[i] = a[i];
		}
		else {
			if(stk.top() != (i + 1)) {
				b[i] = stk.top();
				stk.pop();
			}
			else {
				if(stk.size() > 1) {
					ll e = stk.top();
					stk.pop();
					b[i] = stk.top();
					stk.pop();
					stk.push(e);
				}
			}
		}
	}
	ll x = 0, y = 0;
	if(!stk.empty()) {
		x = stk.top();
		for (int i = 0; i < n; i++) {
			if(a[i] == 0 && (i + 1) != x) {
				y = b[i];
				b[i] = x;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if(!b[i]) { cout << y << ' '; }
		else {
			cout << b[i] << ' ';
		}
	} cout << endl;
}