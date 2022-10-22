#include <bits/stdc++.h>

using namespace std;
const int N = 5000 + 10;
char s[N];
int n, a[N][N], in[N], out[N], vis[N], cir[N], to[N];
int id[N], tot;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> (s + 1);
		for(int j = 1; j <= n; j++) {
			a[i][j] = s[j] - '0';
			if(a[i][j]) in[j]++, out[i]++;
		}
	}
	for(; ; ) {
		int x = -1;
		for(int i = 1; i <= n; i++) {
			if(in[i] == 0 && !vis[i]) {
				x = i;
				break;
			}
			if(out[i] == 0 && !vis[i]) {
				x = i;
				break;		
			}
		}
		if(x == -1) break;
		vis[x] = 1;
		if(in[x] == 0) {
			for(int i = 1; i <= n; i++) if(a[x][i]) in[x]--, out[x]--;
		} else {
			for(int i = 1; i <= n; i++) if(a[i][x]) out[i]--, in[x]--;
		}
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) id[++tot] = i;
	if(tot == 0) {
		cout << -1 << endl;
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	int s = id[1];
	for(; ; ) {
		for(int i = 1; i <= tot; i++) {
			int x = id[i];
			if(a[s][x]) {
				to[s] = x;
				break;
			}
		}
		vis[s] = 1;
		s = to[s];
		if(vis[s]) break;
	}
	memset(vis, 0, sizeof(vis));
	tot = 0;
	for(; !vis[s]; id[++tot] = s, vis[s] = 1, s = to[s]);	
	for(int i = 3; i <= tot; i++) {
		if(a[id[i]][id[1]]) {
			cout << id[1] <<" " << id[i - 1] <<" " << id[i] << endl;
			return 0;
		}
	}
	assert(0);
	return 0;
}