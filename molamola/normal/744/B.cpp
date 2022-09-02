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

int n;
int ans[22][1010];

void solve(){
	scanf("%d", &n);
	for(int i=0;i<10 && (1<<i) < n;i++){
		vector <int> v;
		for(int j=0;j<n;j++)if(j & 1<<i)v.pb(j);
		printf("%d\n", sz(v));
		for(int e : v)printf("%d ", e+1); puts("");
		fflush(stdout);
		for(int j=0;j<n;j++)scanf("%d", ans[i] + j);
	}
	for(int i=0;(1<<i)<n;i++){
		vector <int> v;
		for(int j=0;j<n;j++)if(!(j & 1<<i))v.pb(j);
		printf("%d\n", sz(v));
		for(int e : v)printf("%d ", e+1); puts("");
		fflush(stdout);
		for(int j=0;j<n;j++)scanf("%d", ans[10+i] + j);
	}
	printf("-1\n");
	for(int i=0;i<n;i++){
		int res= 1e9 + 9;
		for(int j=0;(1<<j)<n;j++){
			if(1<<j & i)res = min(res, ans[10+j][i]);
			else res = min(res, ans[j][i]);
		}
		printf("%d ", res);
	}
	fflush(stdout);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}