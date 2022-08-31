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
ll powmod(ll a,ll b) {int res=1;for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
// head

int n,p,q,ret;

VI gao(int n) {
	VI ret(p+1,0);
	if (n==0) {
		ret[0]=1;
	} else if (n%2==0) {
		VI c=gao(n/2);
		rep(i,0,p+1) rep(j,0,p+1) if (i+j<=p) ret[i+j]+=c[i]*c[j];
	} else {
		VI c=gao(n-1);
		rep(i,0,p+1) rep(j,0,2) if (i+j<=p) ret[i+j]+=c[i];
	}
	return ret;
}
int main() {
	scanf("%d%d%d",&n,&p,&q);
	VI r=gao(n);
//	rep(i,0,p+1) printf("%d ",r[i]);puts("");
	rep(i,1,q+1) {
		int v=0,c=1;
		rep(k,0,p+1) {
			if (k<n) v+=r[k]*c;
			c=c*i;
		}
		ret^=v*i;
	}
	printf("%u\n",(unsigned)ret);
}