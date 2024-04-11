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

int n, k, b, c;
int t[200020], t2[200020];
int add[200020];

void solve(){
	scanf("%d%d%d%d", &n, &k, &b, &c);
	if(b > 5*c)b = 5 * c;
	for(int i=1;i<=n;i++)scanf("%d", t+i);
	sort(t+1, t+1+n);
	ll A = 1e18;
	for(int i=0;i<5;i++){
		for(int j=1;j<=n;j++){
			int x = (i - t[j]) % 5;
			if(x < 0)x += 5;
			t2[j] = t[j] + x;
			add[j] = x * c;
		}
		priority_queue <ll> pq;
		ll now = 0, ans = 1e18;
		for(int j=1;j<=n;j++){
			ll a = (ll)(i - t2[j]) / 5 * b + add[j];
			now += a;
			pq.push(a);
			if(sz(pq) > k){
				ll t = pq.top(); pq.pop();
				now -= t;
			}
			if(sz(pq) == k){
				ans = min(ans, now + (ll)(t2[j] - i) / 5 * b * k);
			}
		}
		A = min(A, ans);
	}
	printf("%lld", A);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}