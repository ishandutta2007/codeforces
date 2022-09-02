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

typedef pair<ll, ll> PL;

PL p[300030];

void solve(){
	int n; scanf("%d", &n);
	rep(i, n)scanf("%lld%lld", &p[i].Fi, &p[i].Se);
	sort(p+1, p+n); reverse(p+1, p+n);
	
	priority_queue <ll, vector<ll>, greater<ll> > pq;
	
	int ans = 1;
	ll use = 0;
	int res = 1;
	for(int i=1;i<n;i++)if(p[i].Fi > p[0].Fi)++res;
	
	for(int i=1;i<n;i++){
		++ans; pq.push(p[i].Se - p[i].Fi + 1);
		ll dx = p[0].Fi - (i == n-1 ? 0 : p[i+1].Fi);
		if(dx < 0)continue;
		while(!pq.empty()){
			ll t = pq.top();
			if(dx >= use + t){
				use += t;
				pq.pop();
				--ans;
			}
			else break;
		}
		res = min(res, ans);
	}
	printf("%d", res);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}