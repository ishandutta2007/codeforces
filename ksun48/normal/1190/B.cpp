#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll nmoves = 0;
	for(ll x : a) nmoves += x;
	for(ll i = 0; i < n; i++) nmoves -= i;
	int nsame = 0;
	for(int i = 1; i < n; i++){
		if(a[i] == a[i-1]) nsame += 1;
	}
	if(nsame){
		bool canmove = false;
		if(nsame == 1){
			for(int i = 1; i < n; i++){
				if(a[i] == a[i-1] && a[i-1] > 0){
					if(i == 1 || a[i-1] != a[i-2] + 1){
						canmove = true;
					}
				}
			}
		}
		if(!canmove){
			nmoves = 0;
		}
	}
	if(nmoves & 1){
		cout << "sjfnb" << '\n';
	} else {
		cout << "cslnb" << '\n';
	}
}