#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
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
typedef pair<ll, ll> PL;
typedef long double ldouble;

char P[1010][1010];
int n, m;
int S[2][1010][1010];

void go(int x, int y, int dx, int dy, int idx){
	if(x <= 0 || y <= 0 || x > n || y > m)return;
	if(P[x][y] == '*') return;
	S[idx][x][y] = 1;
	go(x + dx, y + dy, dx, dy, idx);
}

void go(int x, int y, int idx){
	int xx[4] = {1, -1, 0, 0};
	rep(i, 4){
		int dx = xx[i], dy = xx[(i+2) & 3];
		go(x, y, dx, dy, idx);
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%s", P[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(P[i][j] == 'S'){
			go(i, j, 0);
		}
		else if(P[i][j] == 'T'){
			go(i, j, 1);
		}
	}
	for(int i=1;i<=n;i++){
		int ok = 0;
		for(int j=1;j<=m;j++){
			if(P[i][j] == '*')ok = 0;
			else{
				if(S[0][i][j])ok |= 1;
				if(S[1][i][j])ok |= 2;
			}
			if(ok == 3){
				puts("YES");
				return;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		int ok = 0;
		for(int j=1;j<=n;j++){
			if(P[j][i] == '*')ok = 0;
			else{
				if(S[0][j][i])ok |= 1;
				if(S[1][j][i])ok |= 2;
			}
			if(ok == 3){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}