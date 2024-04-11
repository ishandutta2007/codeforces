#include <bits/stdc++.h>
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010;
char x[N];
ll comb[N][N],pw[92][N],ps[N],ret;
int d[N];
int f[N],l;
ll solve(int m,int *d) {
	ll ret=0;
	rep(i,0,10) {
		int dl=0;
		rep(j,i+1,10) dl+=d[j];
		rep(k,0,m+1) {
			ret=(ret+comb[m][k]*ps[k+d[i]]%mod*i%mod*pw[10][dl]%mod*pw[90-i*9][m-k])%mod;
		}
	}
	return ret;
}
int main() {
	scanf("%s",x);
	rep(j,0,91) {
		pw[j][0]=1;
		rep(i,1,1000) pw[j][i]=pw[j][i-1]*j%mod;
	}
	rep(i,1,1000) ps[i]=(ps[i-1]+pw[10][i-1])%mod;
	rep(i,0,1001) {
		comb[i][0]=1;
		rep(j,1,i+1) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	l=strlen(x);
	rep(i,0,l) f[i]=x[i]-'0';
	rep(i,0,l) {
		rep(j,0,f[i]) {
			d[j]++;
			ret+=solve(l-i-1,d);
			d[j]--;
		}
		d[f[i]]++;
	}
	sort(f,f+l);
	ll w=0;
	rep(i,0,l) w=(w*10+f[i])%mod;
	printf("%lld\n",(ret+w)%mod);
}