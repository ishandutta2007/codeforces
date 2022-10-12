/**
*    author:  Mohamed Abo_Okail
*    created: 21/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > a(n);
		int aa = -1, bb = -1;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i]) {
				if(aa == -1) aa = i;
				bb = i;
			}
		}
		int cnt = 0;
		for (int i = aa; i <= bb; i++) {
			if(!a[i]) cnt++;
		}
		cout << cnt << endl;
	}
}