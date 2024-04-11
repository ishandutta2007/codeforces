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
int _,n,matl[N],matr[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		int cnt=0;
		rep(i,1,n+1) matr[i]=0,matl[i]=0;
		rep(i,1,n+1) {
			int k,x;
			scanf("%d",&k);
			rep(j,0,k) {
				scanf("%d",&x);
				if (matl[i]||matr[x]) continue;
				matr[x]=1; matl[i]=1; cnt++;
			}
		}
		if (cnt==n) {
			puts("OPTIMAL");
		} else {
			int pl=0,pr=0;
			rep(i,1,n+1) if (matl[i]==0) pl=i;
			rep(i,1,n+1) if (matr[i]==0) pr=i;
			puts("IMPROVE");
			printf("%d %d\n",pl,pr);
		}
	}
}