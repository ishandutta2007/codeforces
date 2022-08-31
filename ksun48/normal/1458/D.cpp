#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int csum = 0;
	map<int,int> freq;
	map<int,int> up, down;
	for(char c : s){
		if(c == '0'){
			down[csum]++;
			csum--;
		} else {
			up[csum]++;
			csum++;
		}
		freq[csum]++;
	}
	string ans;
	int end = csum;
	csum = 0;
	while(ans.size() < s.size()){
		// try 0
		char nxt = '1';
		if(down.count(csum)){
			if(end >= csum || freq.upper_bound(csum) == freq.end() || up.count(csum-1)){
				nxt = '0';
			}
		}
		if(nxt == '1'){
			up[csum]--;
			if(up[csum] == 0) up.erase(csum);
			csum++;
			freq[csum]--;
			if(freq[csum] == 0) freq.erase(csum);
		} else {
			down[csum]--;
			if(down[csum] == 0) down.erase(csum);
			csum--;
			freq[csum]--;
			if(freq[csum] == 0) freq.erase(csum);			
		}
		ans += nxt;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}