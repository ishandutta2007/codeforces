#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int a[N],sa[N],b[N],sb[N],c[N],n;
void modify(int x,int s) { for (;x<=n;x+=x&-x) c[x]+=s;}
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
void gao(int *a,int *sa) {
	rep(i,0,n) a[i]+=1;
	memset(c,0,sizeof(c));
	rep(i,0,n) {
		modify(a[i],1);
		sa[i]=a[i]-query(a[i]);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	gao(a,sa);
	rep(i,0,n) scanf("%d",b+i);
	gao(b,sb);
	rep(i,0,n) sa[i]+=sb[i];
	per(i,0,n) {
		int p=n-i;
		if (sa[i]>=p) {
			sa[i]-=p;
			if (i) sa[i-1]+=1;
		}
	}
	memset(c,0,sizeof(c));
	rep(i,1,n+1) modify(i,1);
	rep(i,0,n) {
		int l=0,r=n;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (query(md)>=sa[i]+1) r=md; else  l=md;
		}
		modify(r,-1);
		sa[i]=r;
	}
	rep(i,0,n) printf("%d ",sa[i]-1);
	puts("");
}