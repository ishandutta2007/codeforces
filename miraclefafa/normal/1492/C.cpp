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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,m,pos[N],posr[N];
char s[N],t[N];
void solve() {
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	int p=0;
	for (int i=0;i<m;i++) {
		while (s[p]!=t[i]) p++;
		pos[i]=p;
		p++;
	}
	p=n-1;
	posr[m]=n;
	for (int i=m-1;i>=0;i--) {
		while (s[p]!=t[i]) --p;
		posr[i]=p;
		--p;
	}
	int ans=-1;
	for (int i=0;i<m-1;i++) ans=max(ans,posr[i+1]-pos[i]);
	printf("%d\n",ans);
}

int main() {
	solve();
}