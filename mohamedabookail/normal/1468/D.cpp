/**
*    author:  Mohamed AboOkail
*    created: 25/12/2O2O
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		long long n, m, a, b;
		cin >> n >> m >> a >> b;
		vector < long long > v(m);
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long x = 0, z = 0;
		if(a < b) {
			x = b - 1;
			z = b - a;
		}
		else {
			x = n - b;
			z = a - b;
		}
		z--;
		long long cnt = 0;
		//if(v[0] == 1) cnt++;
		vector < long long > vx;
		//if(v[0] != 1) vx.push_back(v[0]);
		for (int i = 0; i < min(z, m); i++) {
			vx.push_back(v[i]);
		}
		long long idx = vx.size() - 1;
		for (int i = 1; i <= z; i++) {
			bool ok = 0;
			for (int j = idx; j >= 0; j--) {
				if(i + vx[j] <= x) {
					cnt++;
					idx = j - 1;
					ok = 1;
					break;
				}
			}
			if(!ok) break;
		}
		cout << cnt << endl;
	}
}