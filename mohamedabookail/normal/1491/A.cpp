/**
*    author:  Mohamed Abo Okail
*    created: 16/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
  
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q; cin >> n >> q;
	vector < int > a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += (a[i] == 1);
	}
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int x; cin >> x;
			if(a[x - 1] == 1) {
				a[x - 1] = 0;
				cnt--;
			}
			else {
				a[x - 1] = 1;
				cnt++;
			}
		}
		else {
			int k; cin >> k;
			cout << (cnt >= k) << endl;
		}
	}
}