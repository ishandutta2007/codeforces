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

int chk[200020];
int c, n;
int p[200020];
ll SS[200020];
vector <Pi> v;

int ok(int x, int i){
	if(SS[i] < x)return 0;
	if(p[i] > x){
		int t = (int)(upper_bound(p+1, p+1+i, x) - p - 1);
		if(t == 0)return 0;
		return ok(x, t);
	}
	int low = 1, high = i, f = -1;
	while(low <= high){
		int mid = (low + high) >> 1;
		if(SS[i] - SS[mid-1] <= x)f = mid, high = mid - 1;
		else low = mid + 1;
	}
	if(SS[i] - SS[f-1] == x)return 1;
	return ok(x - (int)(SS[i] - SS[f-1]), f-1);
}

void solve(){
	scanf("%d%d", &c, &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	sort(p+1, p+1+n);
	for(int i=1;i<=n;i++)SS[i] = SS[i-1] + p[i];
	int t = c;
	for(int i=n;i;i--){
		if(p[i] > t)continue;
		v.pb(Pi(t, i));
		t -= p[i];
	}
	int ans = 1e9;
	p[n+1] = 1e9;
	for(auto e : v){
		int low = p[e.Se] + 1, high = min(e.Fi - 1, p[e.Se + 1]);
		//printf("%d %d : %d %d\n", e.Fi, e.Se, low, high);
		for(int i=low;i<=high;i++){
			if(!ok(e.Fi - i, e.Se))ans = min(ans, i);
		}
	}
	if(ans == 1e9)puts("Greed is good");
	else printf("%d", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}