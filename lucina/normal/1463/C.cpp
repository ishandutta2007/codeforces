#include <bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue
#define int ll

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
const int N = 1e5 + 10;
const int MOD = 0;
pii p[N];
void solve(){
	int n, ans = 0;
	scanf("%lld", &n);
	int cur = 0, tb = 0, te = 0, des = 0, di = 0;
	for(int i = 1;  i <= n; i++) {
		scanf("%lld %lld", &p[i].st, &p[i].nd);
	}
	for(int i = 1; i < n; i++){
		if(p[i].st >= te) {
			cur = des;
			des = p[i].nd;
			tb = p[i].st;
			te = p[i].st + abs(p[i].nd - cur);
			di = (cur < des ? 1 : -1);
			if(cur == des) di = 0;
		}
		pii rn = {cur + di * (p[i].st - tb), cur + di * (min(te, p[i + 1].st) - tb)};
		if(rn.st > rn.nd) swap(rn.st, rn.nd);
		if(p[i].nd >= rn.st && p[i].nd <= rn.nd) ans++;
	}
	if(p[n].st >= te) {ans ++;}
	else {
		pii rn = {cur + di * (p[n].st - tb), des};
		if(rn.st > rn.nd) swap(rn.st, rn.nd);
		if(p[n].nd >= rn.st && p[n].nd <= rn.nd) ans++;
	}
	printf("%lld\n", ans);
}
 main(){
	int t;
	scanf("%lld", &t);
	while(t--){
		solve();
	}


}