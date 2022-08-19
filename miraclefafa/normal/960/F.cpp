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

const int N=101000;
int n,m,u,v,w;
map<int,int> c[N];
int query(int u,int w) {
	int s=0;
	for (;w;w-=w&-w) {
		auto it=c[u].find(w);
		if (it!=c[u].end()) s=max(s,it->se);
	}
	return s;
}
void modify(int u,int w,int s) {
	for (;w<=100001;w+=w&-w) c[u][w]=max(c[u][w],s);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		w++;
		modify(v,w,query(u,w-1)+1);
	}
	int ret=0;
	rep(i,1,n+1) ret=max(ret,query(i,100001));
	printf("%d\n",ret);
}