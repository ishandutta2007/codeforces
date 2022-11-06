#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=200004;
ll tt[MAXN],d[MAXN];
queue<ll> q;
ll ans[MAXN];
int main() {
	ll n,b; scanf("%I64d %I64d",&n,&b);
	for (ll i=0;i<n;i++) {
		scanf("%I64d %I64d",&tt[i],&d[i]);
	}
	ll t=0;
	for (ll j=0;j<n;j++) {
		while (1) {
			if (q.empty()) break;
			ll idx=q.front();
			ll nt=max(t+d[idx],tt[idx]+d[idx]);
			if (nt>tt[j]) break;
			t=nt;
			ans[idx]=t;
			q.pop();
		}
		if (q.size()>b) {
			ans[j]=-1;
		}
		else {
			q.push(j);
		}
	}
	while (1) {
		if (q.empty()) break;
		ll idx=q.front();
		ll nt=max(t+d[idx],tt[idx]+d[idx]);
		t=nt;
		ans[idx]=t;
		q.pop();
	}
	for (ll j=0;j<n;j++) {
		printf("%I64d ",ans[j]);
	}
	printf("\n");
}