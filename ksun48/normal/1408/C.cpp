#include <bits/stdc++.h>
using namespace std;

using ld = double;

void solve(){
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	a.insert(a.begin(), 0);
	a.insert(a.end(), l);
	ld s = 0;
	ld e = 1e9;
	for(int j = 0; j < 70; j++){
		ld m = (s + e) / 2;
		ld tdist = 0;
		for(int r = 0; r < 2; r++){
			ld dist = 0;
			ld ctime = m;
			for(int i = 0; i < (int)a.size(); i++){
				ld v = i+1;
				ld maxtime = 1e12;
				if(i + 1 < (int)a.size()) maxtime = (a[i+1] - a[i]) / v;
				maxtime = min(maxtime, ctime);
				ctime -= maxtime;
				dist += v * maxtime;
			}
			tdist += dist;
			reverse(a.begin(), a.end());
			for(int& x : a) x = l - x;
		}
		if(tdist < l){
			s = m;
		} else {
			e = m;
		}
	}
	cout << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) solve();
}