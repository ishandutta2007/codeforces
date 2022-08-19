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
int _,n,k,f[N];
char s[N];
map<char,int> hs[N];

int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}


int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		for (int i=0;i<n;i++) f[i]=i;
		for (int i=0;i<n;i++) f[find(i)]=find(n-1-i);
		for (int i=0;i<n-k;i++) f[find(i)]=find(i+k);
		for (int i=0;i<n;i++) hs[i].clear();
		for (int i=0;i<n;i++) hs[find(i)][s[i]]++;
		int ans=0;
		for (int i=0;i<n;i++) {
			int s=0,mx=0;
			for (auto p:hs[i]) s+=p.se,mx=max(mx,p.se);
			ans+=s-mx;
		}
		printf("%d\n",ans);
	}
}