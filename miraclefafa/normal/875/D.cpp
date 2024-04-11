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
int n,a[N],pos[N],ord[N],nord[N],s[N],top;
ll ret;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
	}
	rep(i,0,31) pos[i]=0,ord[i]=i;
	top=1; a[0]=(1<<30);
	rep(i,1,n+1) {
		int t=0;
		rep(j,0,31) if ((a[i]&(1<<j))) pos[j]=i;
		sort(ord,ord+31,[&](int p,int q) { return pos[p]>pos[q]; });
		while (top>0&&a[s[top-1]]<=a[i]) --top;
		s[top++]=i; s[top]=0;
		int p=0;
//		ord[31]=0;
//		rep(j,0,31) printf("%d ",ord[j]); puts("");
		rep(j,0,31) {
			p|=(1<<ord[j]);
			int l=pos[ord[j+1]]+1,r=pos[ord[j]];
			if (j==30) l=1;
			if (l>r) continue;
			int pl=0,pr=top;
			while (pl+1<pr) {
				int md=(pl+pr)>>1;
				if (a[s[md]]<p) pr=md; else pl=md;
			}
//			printf("%d %d %d %d\n",l,r,p,s[pr-1]+1);
			l=max(l,s[pr-1]+1);
			if (l<=r) ret+=r-l+1;
		}
	}
	printf("%lld\n",ret);
}