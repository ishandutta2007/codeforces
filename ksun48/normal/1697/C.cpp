#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	bool works = true;
	auto okay = [&](string z, string tz) -> bool {
		if(z.size() == 1) return true;
		vector<int> cnt(3, 0);
		for(char c : z){
			cnt[c-'a']++;
		}
		if(cnt[0] && cnt[2]) return false;
		if(!cnt[0] && !cnt[2]) return true;
		if(!cnt[2]){
			int diff = 0;
			for(int i = 0; i < (int)z.size(); i++){
				if(z[i] == 'a') diff++;
				if(tz[i] == 'a') diff--;
				if(diff < 0) return false;
			}
			return true;
		}
		if(!cnt[0]){
			int diff = 0;
			for(int i = 0; i < (int)z.size(); i++){
				if(z[i] == 'b') diff++;
				if(tz[i] == 'b') diff--;
				if(diff < 0) return false;
			}
			return true;
		}
		return true;
	};
	string z;
	string tz;
	vector<int> pdiff(3);
	for(int i = 0; i < n; i++){
		pdiff[s[i]-'a']++;
		pdiff[t[i]-'a']--;
		z += s[i];
		tz += t[i];
		if(pdiff == vector<int>{0, 0, 0}){
			works &= okay(z, tz);
			z = "";
			tz = "";
		}
	}
	if(!z.empty()) works = false;
	cout << (works ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int Q;
	cin >> Q;
	while(Q--) solve();
}