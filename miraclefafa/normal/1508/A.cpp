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
int n;
int p[N];
char s[3][N];
void solve() {
	scanf("%d",&n);
	scanf("%s%s%s",s[0],s[1],s[2]);
	rep(i,0,3) rep(j,0,3) if (i!=j) {
		rep(z,0,2) {
			int c1=0,c2=0;
			rep(p1,0,2*n) c1+=s[i][p1]=='0'+z,c2+=s[j][p1]=='0'+z;
			if (c1>=n&&c2>=n&&c1>=c2) {
				rep(i,0,c1+1) p[i]=0;
				//printf("zz %d %d %d\n",i,j,z);
				int c0=0,cc=0;
				rep(f,0,2*n) {
					if (s[i][f]=='0'+z) {
						c0++;
						cc=0;
					} else {
						cc++;
						p[c0]=max(p[c0],cc);
					}
				}

				c0=0,cc=0;
				rep(f,0,2*n) {
					if (s[j][f]=='0'+z) {
						c0++;
						cc=0;
					} else {
						cc++;
						p[c0]=max(p[c0],cc);
					}
				}
				rep(i,0,c1+1) {
					if (i) printf("%d",z);
					rep(j,0,p[i]) printf("%d",1-z);
				}
				puts("");
				return;
			}
		}
	}
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}