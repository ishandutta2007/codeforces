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

int n, k;
int a[200020];

ll ab(ll x){return x > 0 ? x : -x;}

void Do(int m, ll val){
	int res = 0;
	for(int i=m;i<=n && i<=m+40;i++){
		if(val % (1LL<<(i-m)) == 0){
			ll t = val >> (i-m);
			t = a[i] - t;
			if(ab(t) <= k){
				if(i == n && t == 0);
				else res++;
			}
		}
	}
	printf("%d", res);
}

void solve(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<=n;i++)scanf("%d", a+i);
	ll now = 0;
	for(int i=n;i>=0;i--){
		now = now * 2 + a[i];
		if(ab(now) > k){
			ll now2 = 0;
			for(int j=0;j<=i-1;j++){
				now2 += a[j];
				if(now2 & 1){
					printf("0");
					return;
				}
				now2 >>= 1;
			}
			Do(i, now + now2);
			return;
		}
	}
	Do(0, now);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}