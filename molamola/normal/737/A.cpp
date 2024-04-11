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

int n, k, s, t;
Pi P[200020];
int g[200020];

void solve(){
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for(int i=1;i<=n;i++){
		scanf("%d%d", &P[i].Fi, &P[i].Se);
	}
	for(int i=1;i<=k;i++)scanf("%d", g+i);
	g[++k] = 0, g[++k] = s;
	sort(g+1, g+1+k);
	int low = 1, high = 1000000000, res = -1;
	while(low <= high){
		int mid = (low + high) >> 1;
		ll sum = 0;
		int ok = 1;
		for(int i=2;i<=k;i++){
			int dx = g[i] - g[i-1];
			if(dx*2 <= mid)sum += dx;
			else if(dx <= mid)sum += dx + (dx * 2LL - mid);
			else ok = 0;
		}
		if(ok && sum <= t)res = mid, high = mid - 1;
		else low = mid + 1;
	}
	int ans = -1;
	if(res != -1){
		for(int i=1;i<=n;i++){
			if(P[i].Se >= res){
				if(ans == -1 || ans > P[i].Fi)ans = P[i].Fi;
			}
		}
	}
	printf("%d", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}