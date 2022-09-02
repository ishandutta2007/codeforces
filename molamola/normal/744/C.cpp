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

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

char c[20];
int r[20], b[20];
int n;
int d[1<<16][400];
int rr[1<<16], bb[1<<16];
int cr[1<<16], cb[1<<16];

int Do(int bits, int x){
	if(d[bits][200 + x] != -1)return d[bits][200 + x];
	if(bits == (1<<n) - 1){
		return 0;
	}
	int del = -bb[bits] + rr[bits] + x;
	if(del >= 0){
		int res = ~0u>>1;
		for(int i=0;i<n;i++)if(!(1<<i & bits)){
			int nr = max(0, r[i] - cr[bits]), nb = max(0, b[i] - cb[bits]);
			int add = max(nr, nb - del);
			res = min(res, 1 + add + Do(bits | 1<<i, x + b[i] - r[i] + nr - nb));
		}
		return d[bits][200 + x] = res;
	}
	else{
		int res = ~0u>>1;
		for(int i=0;i<n;i++)if(!(1<<i & bits)){
			int nr = max(0, r[i] - cr[bits]), nb = max(0, b[i] - cb[bits]);
			int add = max(nr + del, nb);
			res = min(res, 1 + add + Do(bits | 1<<i, x + b[i] - r[i] + nr - nb));
		}
		return d[bits][200 + x] = res;
	}
}

void solve(){
	scanf("%d", &n);
	rep(i, n){
		scanf(" %c%d%d", &c[i], r+i, b+i);
	}
	rep(i, 1<<n)rep(j, n)if(1<<j & i){
		rr[i] += r[j], bb[i] += b[j];
		if(c[j] == 'R')cr[i]++;
		else cb[i]++;
	}
	memset(d, -1, sizeof d);
	printf("%d\n", Do(0, 0));
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}