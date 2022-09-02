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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, m;
Pi t[500050];
bitset <2020> P[2020], B[2020];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int x, y; scanf("%d%d", &x, &y);
		t[i] = Pi(x, y);
		P[x][y] = 1;
	}
	for(int i=1;i<=n;i++)B[i][i] = 1;
	for(int i=1;i<=n;i++){
		int f = -1;
		for(int j=i;j<=n;j++)if(P[j].test(i)){
			f = j; break;
		}
		swap(P[f], P[i]); swap(B[f], B[i]);
		for(int j=1;j<=n;j++)if(i != j && P[j][i]){
			P[j] ^= P[i];
			B[j] ^= B[i];
		}
	}
	rep(i, m){
		if(B[t[i].Se][t[i].Fi])puts("NO");
		else puts("YES");
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}