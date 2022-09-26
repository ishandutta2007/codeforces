#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string s;
vector<int> vans[N];
vector<int> vcur[2];
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> s;
	int ans = 0;
	int cnt = 0;
	for(int i = 0;i < s.size();++i) {
		if(s[i] == '0') {
			if(vcur[1].size()) {
				vans[vcur[1].back()].push_back(i);
				vcur[0].push_back(vcur[1].back());
				vcur[1].pop_back();
			}
			else {
				++ans;
				vans[ans].push_back(i);
				vcur[0].push_back(ans);
			}
		}
		
		else {
				if(!vcur[0].size()) return cout << -1 << endl,0;
				vans[vcur[0].back()].push_back(i);
				vcur[1].push_back(vcur[0].back());
				vcur[0].pop_back();
			}
		}
	if(vcur[1].size()) return cout << -1 << endl,0;
	cout << ans << endl;
	for(int i = 1;i <= ans;++i) {
		cout << vans[i].size() << ' ';
		for(int j = 0;j < vans[i].size();++j) cout << vans[i][j] + 1<< ' '; cout << endl;
		}
}