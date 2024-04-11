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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()


const int MOD = 1e9 + 7;
int d[76][1<<20];
int n;
char S[80];

int dfs(int x, int b){
	if(d[x][b] != -1)return d[x][b];
	int res = 0;
	int nb = b+1;
	if(b > 0 && nb == (nb & -nb))res = 1;
	if(x == n){
		return d[x][b] = res;
	}
	int c = 0;
	for(int i=x;i<n;i++){
		c = c * 2 + S[i] - '0';
		int nb = b;
		if(c > 20)break;
		else if(c == 0)continue;
		else nb |= 1<<(c-1);
		res = (res + dfs(i+1, nb)) % MOD;
	}
	return d[x][b] = res;
}

void solve(){
	memset(d, -1, sizeof d);
	scanf("%d%s", &n, S);
	int ans = 0;
	for(int i=0;i<n;i++)ans = (ans + dfs(i, 0)) % MOD;
	printf("%d", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}