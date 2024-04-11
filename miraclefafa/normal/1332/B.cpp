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

const int N=1010;

int pr[]={2,3,5,7,11,13,17,19,23,29,31};
int _,n,col[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		map<int,int> hs;
		for (int i=0;i<n;i++) {
			int x;
			scanf("%d",&x);
			for (int j=0;j<11;j++) if (x%pr[j]==0) {
				hs[j]=0;
				col[i]=j;
				break;
			}
		}
		int m=0;
		for (auto &x:hs) x.se=++m;
		printf("%d\n",SZ(hs));
		for (int i=0;i<n;i++) printf("%d%c",hs[col[i]]," \n"[i==n-1]);
	}
}