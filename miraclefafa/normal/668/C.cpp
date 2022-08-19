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

const int N=1010000;
double p[N],q[N],a[N],b[N];
int n;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lf",p+i),p[i]+=p[i-1];
	rep(i,1,n+1) scanf("%lf",q+i);
	per(i,1,n+1) q[i]+=q[i+1];
	rep(i,1,n+1) {
		// a[i]*b[i]=p[i]
		// (1-a[i])*(1-b[i])=q[i+1]
		// a[i]+b[i]=1+p[i]-q[i+1]
		double B=1+p[i]-q[i+1],c=p[i];
		double delta=sqrt(max(B*B-4*c,0.));
		a[i]=(B+delta)/2,b[i]=(B-delta)/2;
	}
	rep(i,1,n+1) printf("%.10f ",a[i]-a[i-1]); puts("");
	rep(i,1,n+1) printf("%.10f ",b[i]-b[i-1]); puts("");
}