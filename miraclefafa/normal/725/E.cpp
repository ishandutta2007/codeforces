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

const int N=201000;
int c,n,v[N],p,a;
ll s[N];
inline int get(int pos) {
	if (pos<p) return v[pos]; else if (pos==p) return a; else return v[pos-1];
}
inline ll sum(int pos) {
	if (pos<p) return s[pos]; else return s[pos-1]+a;
}
int check(int x) {
	p=lower_bound(v+1,v+n+1,x)-v;
	a=x;
	int b=c;
	while (1) {
		if (b<get(1)) return b;
		int l=1,r=n+2;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (get(md)>b) r=md; else l=md;
		}
		int pr=l;
		l=0,r=pr;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (sum(pr)-sum(md-1)<=b) r=md; else l=md;
		}
		b-=sum(pr)-sum(r-1);
		if (r==1) return b;
	}
}
int vv[N];
int ff(int x) {
	rep(i,1,n+1) vv[i]=v[i]; vv[n+1]=x;
	sort(vv+1,vv+n+2);
	int b=c;
	per(i,1,n+2) if (b>=vv[i]) b-=vv[i];
	return b;
}
int main() {
	scanf("%d%d",&c,&n);
	rep(i,1,n+1) {
		scanf("%d",v+i);
	}
	sort(v+1,v+n+1);
	rep(i,1,n+1) s[i]=s[i-1]+v[i];
	rep(i,1,c+1) {
		if (check(i)) {
//			printf("%d %d\n",i,check(i));
			printf("%d\n",i);
			return 0;
		}
	}
	puts("Greed is good");
	return 0;
}