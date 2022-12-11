#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int N = 110;
int _w;

int n, k;
vector<int> g[N];
bool output_first;

int f[N][N][N][2];
pii from[N][N][N][2];

void print( int u ) {
	if( output_first ) output_first = false;
	else putchar(' ');
	printf( "%d", u );
}

void dfs( int u ) {
	for( int v : g[u] )
		dfs(v);
	int sz = (int)g[u].size();
	for( int i = 0; i <= sz; ++i )
		memset( f[u][i], 0x3f, sizeof f[u][i] );
	f[u][0][1][0] = f[u][0][1][1] = 0;
	for( int i = 0; i < sz; ++i ) {
		int v = g[u][i];
		int szv = (int)g[v].size();
		for( int j = 0; j < N; ++j ) {
			for( int c = 0; c < N; ++c ) {
				if( f[u][i][j][0] < f[u][i+1][j][0] ) {
					f[u][i+1][j][0] = f[u][i][j][0];
					from[u][i+1][j][0] = pii(j, 0);
				}
				if( j+c < N && f[u][i][j][0] + f[v][szv][c][0] + 2 < f[u][i+1][j+c][0] ) {
					f[u][i+1][j+c][0] = f[u][i][j][0] + f[v][szv][c][0] + 2;
					from[u][i+1][j+c][0] = pii(j, 0);
				}
				if( j+c < N && f[u][i][j][0] + f[v][szv][c][1] + 1 < f[u][i+1][j+c][1] ) {
					f[u][i+1][j+c][1] = f[u][i][j][0] + f[v][szv][c][1] + 1;
					from[u][i+1][j+c][1] = pii(j, 0);
				}
				if( f[u][i][j][1] < f[u][i+1][j][1] ) {
					f[u][i+1][j][1] = f[u][i][j][1];
					from[u][i+1][j][1] = pii(j, 1);
				}
				if( j+c < N && f[u][i][j][1] + f[v][szv][c][0] + 2 < f[u][i+1][j+c][1] ) {
					f[u][i+1][j+c][1] = f[u][i][j][1] + f[v][szv][c][0] + 2;
					from[u][i+1][j+c][1] = pii(j, 1);
				}
			}
		}
	}
}

void output( int u, int idx, int cnt, int oneway ) {
	print(u);
	int oneway_subtree = -1, oneway_cnt = -1;
	while( idx ) {
		pii tmp = from[u][idx][cnt][oneway];
		if( tmp.second != oneway ) {
			assert( oneway - tmp.second == 1 );
			oneway_subtree = g[u][idx-1];
			oneway_cnt = cnt - tmp.first;
			assert( oneway_cnt != 0 );
			idx--;
			cnt = tmp.first;
			oneway = tmp.second;
		} else {
			if( tmp.first != cnt ) {
				int v = (int)g[u][idx-1];
				output(v, (int)g[v].size(), cnt - tmp.first, 0);
				print(u);
			}
			idx--;
			cnt = tmp.first;
			oneway = tmp.second;
		}
	}
	if( oneway_subtree != -1 )
		output(oneway_subtree, (int)g[oneway_subtree].size(), oneway_cnt, 1);
}

void solve() {
	dfs(1);
	int sz = (int)g[1].size();
	printf( "%d\n", f[1][sz][k][1] );
	output_first = true;
	output(1, sz, k, 1);
	puts("");
}

int main() {
	int T;
	_w = scanf( "%d", &T );
	while( T-- ) {
		_w = scanf( "%d%d", &n, &k );
		for( int i = 1; i <= n; ++i )
			g[i].clear();
		for( int i = 2; i <= n; ++i ) {
			int fa;
			_w = scanf( "%d", &fa );
			g[fa].push_back(i);
		}
		solve();
	}
	return 0;
}