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
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, p[1000010];
int k;
int chk[1000010];
int cyc[1000010];
bitset <1000010> D;

void solve(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	int C[2] = {};
	for(int i=1;i<=n;i++){
		if(chk[i])continue;
		int t = i; chk[t] = 1; t = p[t]; int len = 1;
		while(chk[t] == 0){
			chk[t] = 1;
			t = p[t];
			++len;
		}
		C[1] += len / 2;
		C[0] += len % 2;
		cyc[len]++;
	}
	int mx = 0;
	if(k <= C[1])mx = 2 * k;
	else if(k <= C[1] + C[0])mx = k + C[1];
	else mx = n;
	for(int i=2;i<=n;i++){
	    int t = cyc[i];
	    cyc[i] = 0;
		for(int j=0;j<20;j++){
		    if(t >= 1<<j)t -= 1<<j, cyc[i<<j]++;
		}
		for(int j=0;j<20;j++)if(1<<j & t)cyc[i<<j]++;
	}
	D[0] = 1;
	for(int i=2;i<=n;i++){
		while(cyc[i]--){
			D = D | D << i;
		}
	//	for(int j=0;j<=n;j++)printf("%d ", D.test(j)); puts("");
	}
	if(D[k])printf("%d ", k);
	else printf("%d ", k+1);
	printf("%d", mx);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}