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

const int M=70,N=501000;
double dp[N][M+5];
int n,x,ty,v,p[N];
int main() {
	scanf("%d",&n);
	int x=1;
	rep(i,1,M) dp[x][i]=1;
	rep(i,0,n) {
		scanf("%d%d",&ty,&v);
		if (ty==2) {
			double ret=0;
			rep(i,1,M) ret+=1-dp[v][i];
			printf("%.10f\n",ret);
		} else {
			x++; p[x]=v;
			rep(i,1,M) dp[x][i]=1;
			v=x;
			double prv=1;
			rep(j,1,M) {
				if (p[x]==0) break;
				double crv=0.5*(1+dp[p[x]][j]);
				dp[p[x]][j]/=prv;
				dp[p[x]][j]*=0.5*(1+dp[x][j-1]);
				prv=crv; x=p[x];
			}
			x=v;
		}
	}

}