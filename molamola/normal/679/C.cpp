#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

char inp[510][510];

int T1[510][510];
int cc[510][510];
int N, K;

int get(int x1, int y1, int x2, int y2){
	return T1[x2][y2] - T1[x1-1][y2] - T1[x2][y1-1] + T1[x1-1][y1-1];
}

int cnt_get(int x1, int y1){
	return get(x1, y1, x1+K-1, y1+K-1);
}

int com[510][510];
int vis[510][510];
int sz_com[510*510];

void dfs(int x, int y, int cnt){
	static int xx[4] = {1, -1, 0, 0};
	sz_com[cnt]++;
	com[x][y] = cnt;
	vis[x][y] = 1;
	rep(i, 4){
		int nx = x + xx[i], ny = y + xx[(i+2) & 3];
		if(1 <= nx && nx <= N && 1 <= ny && ny <= N && !vis[nx][ny] && cc[nx][ny] == 0){
			dfs(nx, ny, cnt);
		}
	}
}
int _chk[510*510], now;

inline void Ins(int x){
	if(_chk[x] == 0)now += sz_com[x];
	_chk[x]++;
}

inline void Del(int x){
	if(_chk[x] == 1)now -= sz_com[x];
	_chk[x]--;
}

void solve(){
	scanf("%d%d", &N, &K);
	for(int i=1;i<=N;i++)scanf("%s", inp[i]+1);
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
		T1[i][j] = cc[i][j] = (inp[i][j] == 'X');
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
		T1[i][j] += T1[i-1][j] + T1[i][j-1] - T1[i-1][j-1];
	}
	int cnt = 0;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)if(cc[i][j] == 0 && !vis[i][j])dfs(i, j, ++cnt);
	int ans = 0;
	for(int i=1;i<=N-K+1;i++){
		for(int j=1;j<=cnt;j++)_chk[j] = 0;
		now = 0;
		for(int j=-1;j<=K;j++){
			if(i+j < 1 || i+j > N)continue;
			for(int k=0;k<=K;k++){
				if(1+k > N || ((j == -1 || j == K) && k == K))continue;
				int t = com[i+j][1+k];
				Ins(t);
			}
		}
		ans = max(ans, now + cnt_get(i, 1));
		for(int j=2;j<=N-K+1;j++){
			if(i != 1)Del(com[i-1][j-1]), Ins(com[i-1][j+K-1]);
			if(j != 2){
				for(int k=0;k<K;k++){
					Del(com[i+k][j-2]);
				}
			}
			if(i != N-K+1)Del(com[i+K][j-1]), Ins(com[i+K][j+K-1]);
			if(j != N-K+1){
				for(int k=0;k<K;k++){
					Ins(com[i+k][j+K]);
				}
			}
			ans = max(ans, now + cnt_get(i, j));
		}
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}