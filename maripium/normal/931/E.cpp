#include<bits/stdc++.h>
using namespace std;

const int N = 5005;

string s;
vector<int> pos[N];
double ans = 0;
double w[N] = {0};

void cazing() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();++i) pos[s[i] - 'a'].push_back(i);
	for(int let = 0;let < 26;++let) {
		for(int len = 1;len < s.size();++len) {
			int u[26] = {0};
			for(int cur = 0;cur < pos[let].size();++cur) {
				++u[s[(pos[let][cur] + len) % s.size()] - 'a'];
			}
			double tem = 0;
			for(int nlet = 0;nlet < 26;++nlet) tem += (u[nlet] == 1);
			w[let] = max(w[let],tem);
		}
		ans += (w[let] / s.size());
	}
	cout << fixed << setprecision(10) << ans <<endl;
}

int main() {
	cazing();
}