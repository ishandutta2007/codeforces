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
typedef long double db;
mt19937_64 mrand(random_device{}()); 
const ll mod=1000000007;
ll rnd(ll x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

db rnd() {
	return rnd(1ll<<50)/(db)(1ll<<50);
}
const int N=10100;
int n,m,pc,ac[N];
db wt[N],tc[N];
char s[N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) wt[i]=1;
	//rep(i,0,n) tc[i]=0.7;
	int pc=0;
	rep(i,0,m) {
		scanf("%s",s);
		/*int ans=rnd(2);
		rep(j,0,n) {
			if (rnd()>tc[j]) s[j]=ans+'0'; else s[j]=rnd(2)+'0';
		}*/
		db w0=0,sw=0;
		rep(j,0,n) {
			if (s[j]=='0') w0+=wt[j];
			sw+=wt[j];
		}
		char oc=(rnd()<w0/sw)?'0':'1';
		printf("%c\n",oc);
		//pc+=oc!=(ans+'0');
		fflush(stdout);
		int d=0;
		scanf("%d",&d);
		//d=ans;
		rep(j,0,n) if (s[j]!=d+'0') wt[j]*=0.8,ac[j]+=1;
		//rep(j,0,n) printf("%.5e ",wt[j]); puts("");
	}
	//printf("%d %d\n",*min_element(ac,ac+n),pc);
}