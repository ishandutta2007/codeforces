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

typedef long double LD;
const int N=101000;
int n;
ll x[N],y[N];
LD ans,pw[110];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%I64d%I64d",x+i,y+i);
	pw[0]=1; rep(i,1,101) pw[i]=pw[i-1]/2;
	LD tot=1-pow(0.5,n)*(n*(n+1)/2+1);
	LD prob=1./4/tot;
	rep(j,1,n) {
		LD r=prob; r*=1-pow(0.5,n-1-j);
		int k=j;
		rep(i,0,n) {
			ans+=r*(x[i]*y[k]-x[k]*y[i]-abs(__gcd(x[i]-x[k],y[i]-y[k])));
			if (k==n-1) k=0; else k++;
		}
		prob/=2;
		if (clock()>=2.2*CLOCKS_PER_SEC) break;
	}
	printf("%.10f\n",(double)ans/2+1);
}