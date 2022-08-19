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

const int N=301000;
int a[N],n,odd[N],even[N];
/*int solve(int l,int r,int ty) {
	if (l==r) return a[l];
	else if (ty==0) {
		int v=max(solve(l+1,r,1),solve(l,r-1,1));
		return v;
	}
	else {
		int v=min(solve(l+1,r,0),solve(l,r-1,0));
		return v;
	}
}
int brute() {
	n=rand()%10+1;
//	memset(dp,-1,sizeof(dp));
	rep(i,1,n+1) a[i]=rand()%100;
	return solve(1,n,0);
}
void gao() {
	int v=brute(); int s=0;
	rep(i,1,n+1) b[i]=a[i];
	if (n%2==0) s=max(a[n/2],a[n/2+1]); else if (n==1) s=a[1]; else s=min(a[n/2+1],max(a[n/2],a[n/2+2]));
	printf("%d\n",n);
	rep(i,1,n+1) printf("%d ",b[i]); puts("");
	printf("guess %d bf %d\n",s,v);
	puts("----");
	assert(s==v);
}*/
int calc(int l,int r) {
	if (r%2!=l%2) {
		return even[(l+r)/2];
	} else {
		return odd[(l+r)/2];
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,2,n) odd[i]=min(a[i],max(a[i-1],a[i+1]));
	rep(i,1,n) even[i]=max(a[i],a[i+1]);
	int od=0,ev=0;
	rep(k,0,n-1) {
		if ((n-k)%2==0) {
			ev=max(ev,calc(1,n-k));
			ev=max(ev,calc(k+1,n));
			printf("%d ",ev);
		} else {
			od=max(od,calc(1,n-k));
			od=max(od,calc(k+1,n));
			printf("%d ",od);
		}
	}
	printf("%d\n",*max_element(a+1,a+n+1));
}