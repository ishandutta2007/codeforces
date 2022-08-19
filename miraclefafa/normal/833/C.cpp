#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int cnt,L[20],R[20],p[20],pp[20];
ll pw[20],pw2[20];
ll l,r,cr;
bool build(int d,int c,ll w) {
	if (d==19) {
		if (w>=l) { cr=w; return 1; }
		return 0;
	}
	if (cr!=-1) return 1;
	if (c==1) {
		ll v=w;
		for (int d=0;d<=9;d++) for (int j=0;j<p[d];j++) v=v*10+d;
		cr=v;
		return 1;
	}
	rep(k,L[d],10) if (p[k]>0) {
		--p[k];
		if (build(d+1,(c==0&k==L[d])?0:1,w*10+k)) {
			++p[k];
			return 1;
		}
		++p[k];
	}
	return 0;
}
ll check() {
	ll w=0; unsigned long long v=0;
	per(d,0,10) for (int j=0;j<p[d];j++) v=v*10+d;
	if (v<l) return 1ll<<60;
	cr=-1;
	build(0,0,0);
	return cr;
}
void dfs(int u,int d) {
	if (u==18) {
		if (check()<=r) {
			cnt++;
		}
	} else {
		for (int i=d;i<=9;i++) {
			p[i]++;
			dfs(u+1,i);
			p[i]--;
		}
	}
}
int main() {
	scanf("%lld%lld",&l,&r);
	pw[0]=1;
	for (int i=1;i<=18;i++) pw[i]=pw[i-1]*10,pw2[i]=pw2[i-1]*10+1;
	ll vl=l;
	rep(i,0,19) L[i]=l%10,l/=10;
	l=vl;
	reverse(L,L+19);
	p[0]=1;
	dfs(0,0);
	printf("%d\n",cnt);
}