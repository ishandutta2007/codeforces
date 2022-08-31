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

const int N=101000;
int n,p[N],top0,top1,r[N],ret;
int s0[N],s1[N];
bool check(int R) {
	int top0=0,top1=0;
	per(i,0,n) {
		while (top0>0&&p[s0[top0-1]]<=p[i]) top0--;
		s0[top0++]=i;
		while (top1>0&&p[s1[top1-1]]>=p[i]) top1--;
		s1[top1++]=i;
		int pl=-1,pr=top0;
		while (pl+1<pr) {
			int md=(pl+pr)>>1;
			if (p[s0[md]]>p[i]+R) pl=md; else pr=md;
		}
		r[i]=(pl==-1)?n:s0[pl];
		pl=-1; pr=top1;
		while (pl+1<pr) {
			int md=(pl+pr)>>1;
			if (p[s1[md]]<p[i]-R) pl=md; else pr=md;
		}
		r[i]=min(r[i],(pl==-1)?n:s1[pl]);
	}
	int v=0;
	rep(i,0,n) {
		if (i>v) return 0;
		v=max(v,r[i]-1);
	}
	return 1;
}
int solve() {
	int l=0,r=1000000001;
	while (l+1<r) {
		int md=(r+l)>>1;
		if (check(md)) r=md;
		else l=md;
	}
	return r;
}
int main() {
	scanf("%d%d%d",&n,&p[0],&p[1]);
	n+=2;
	rep(i,2,n) scanf("%d",p+i);
	ret=solve();
	swap(p[1],p[0]);
	ret=min(ret,solve());
	printf("%d\n",ret);
}