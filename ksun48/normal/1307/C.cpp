#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	vector<vector<ll> > freq(26, vector<ll>(26, 0));
	vector<ll> cfreq(26, 0);
	int n = (int)s.size();
	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			freq[j][s[i]-'a'] += cfreq[j];
		}
		cfreq[s[i]-'a']++;
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			ans = max(ans, freq[i][j]);
		}
		ans = max(ans, cfreq[i]);
	}
	cout << ans << '\n';
}