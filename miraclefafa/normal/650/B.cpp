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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=501000;
int n,a,b,T,ans;
char s[N];
ll t[N],tt[N];
void solve() {
	rep(i,1,n+1) {
		ll t1=t[i]+(ll)a*(i-1);
		if (t1<=T) ans=max(ans,i); else continue;
		t1+=a*(i-1);
		if (t1>T) continue;
		int l=i,r=n;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (t[n]-t[md]+(ll)a*(n-md)+t1<=T) r=md; else l=md;
		}
//		printf("%d %d\n",i,r);
		ans=max(ans,n-r+i);
	}
}
int main() {
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",s+1);
	rep(i,1,n+1) if (s[i]=='w') tt[i]=b+1; else tt[i]=1;
//	rep(i,1,n+1) t[i+n]=t[i];
//	rep(i,1,n+n+1) t[i]+=t[i-1];
	rep(i,1,n+1) t[i]=t[i-1]+tt[i];
	solve();
	reverse(tt+2,tt+n+1);
	rep(i,1,n+1) t[i]=t[i-1]+tt[i];
	solve();
/*
	rep(i,1,n+1) {
		int l=i-1,r=i+n;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (t[md]-t[i-1]+(ll)a*(md-i)<=T) l=md; else r=md;
		}
		ans=max(ans,l-i+1);
	}*/
	printf("%d\n",ans);
}