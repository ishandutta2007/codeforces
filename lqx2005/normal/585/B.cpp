#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 100 + 20;
int n, k, vis[3][N];
string s[3];
void solve() {
	cin >> n >> k;
	for(int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	for(int i = 1; i <= 3; i++) {
		s[0].push_back('.');
		s[1].push_back('.');
		s[2].push_back('.');
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i + 3 < int(s[0].length()); i += 3) {
		for(int x = 0; x < 3; x++) {
			if(s[x][i] == 's') vis[x][i] = 1;
			for(int d = -1; d <= 1; d++) {
				if(x + d < 0 || x + d >= 3) continue;
				if(s[x][i + 1] == '.' && s[x + d][i + 1] == '.' && s[x + d][i + 2] == '.' && s[x + d][i + 3] == '.') {
					vis[x + d][i + 3] |= vis[x][i];
				}
			}
		}
	}
	int ans = 0;
	for(int x = int(s[0].length()) - 3; x < int(s[0].length()); x++) {
		for(int d = 0; d < 3; d++) {
			ans |= vis[d][x];
		}
	}
	cout << (ans ? "YES\n" : "NO\n") << endl;
	return;
}

int main() {
	int t;
	for(cin >> t; t--; solve());
	return 0;
}