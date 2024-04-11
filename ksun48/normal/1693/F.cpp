#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	{
		string ss = s;
		sort(ss.begin(), ss.end());
		if(s == ss){
			cout << 0 << '\n';
			return;
		}
	}
	{
		int z = 0;
		for(char c : s){
			if(c == '0'){
				z++;
			} else {
				z--;
			}
		}
		if(z > 0){
			reverse(s.begin(), s.end());
			for(char& c : s){
				c ^= ('0' ^ '1');
			}
		}
		if(z == 0){
			cout << 1 << '\n';
			return;
		}
	}
	vector<int> psum(n+1);
	for(int i = 0; i < n; i++){
		psum[i+1] = psum[i] + (s[i] == '1' ? -1 : 1);
	}
	vector<int> first_psum(n+1, n);
	for(int i = n; i >= 0; i--){
		if(psum[i] <= 0){
			first_psum[-psum[i]] = i;
		}
	}
	int ans = 2 * n;
	int cur = n;
	int ops = 0;
	while(cur > 0 && s[cur-1] == '1') cur--;
	while(true){
		int downs = ((n - cur) - (psum[n] - psum[cur])) / 2;
		int h = psum[n] + downs;
		ans = min(ans, ops + 1 + max(-h, 0));
		if(h >= 0) break;
		cur = first_psum[-h];
		assert(cur < n);
		ops++;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}