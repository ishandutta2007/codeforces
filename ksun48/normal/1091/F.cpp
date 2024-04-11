#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<LL> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	LL ans = 0;
	LL inf = 1e18;
	vector<LL> staminas(6, 0);
	for(int i = 0; i < n; i++){
		if(s[i] == 'G'){
			staminas[5] = inf;
			staminas[2] += 2*a[i];
		} else if(s[i] == 'W'){
			staminas[3] = inf;
			staminas[1] += 2*a[i];
		} else if(s[i] == 'L'){
			// nothing
		}
		ans += a[i];
		for(int j = 0; j < 6; j++){
			LL need = min(staminas[j], a[i]);
			ans += need * j;
			staminas[j] -= need;
			a[i] -= need;
		}
		// consume a[i] least staminas
	}
	cout << ans << endl;
}