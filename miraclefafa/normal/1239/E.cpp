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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef bitset<1250002> status;

status pd[51][26];
int pos[1250002];
int a[55],s,n;
pair<VI,VI> ansv;
int ans;

int main() {
	scanf("%d",&n);
	rep(i,0,2*n) scanf("%d",a+i),s+=a[i];
	sort(a,a+2*n); 
	pd[2*n][0][0]=1;
	ans=1<<30;
	per(i,0,2*n) {
		int lp=-1;
		rep(j,0,s/2+1) {
			if (pd[i+1][n-1][j]) lp=j;
			pos[j]=lp;
		}
		rep(p1,0,i) {
			// a[p1]+a[i]+2*val <= s
			int v=(s-a[p1]-a[i])/2;
			int fs=pos[v];
			//printf("gg %d %d %d %d\n",a[p1],a[i],v,fs);
			if (fs==-1) continue;
			if (s-fs<ans) {
				int val=fs,cand=n-1;
				VI v1,v2;
				rep(j,i+1,2*n) {
					assert(pd[j][cand][val]);
					if (cand>0&&val>=a[j]&&pd[j+1][cand-1][val-a[j]]){
						cand--; val-=a[j]; v1.pb(a[j]);
					} else {
						v2.pb(a[j]);
					}
				}
				ans=s-fs;
				//printf("gg %d\n",ans);
				// v2
				rep(j,0,i) if (j!=p1) v2.pb(a[j]);
				sort(all(v1)); sort(all(v2)); reverse(all(v2));
				v1.insert(v1.begin(),a[p1]);
				v2.pb(a[i]);
				ansv=mp(v1,v2);
			}
		}
		rep(j,0,n) {
			if (j>0) pd[i][j]=pd[i+1][j]|(pd[i+1][j-1]<<a[i]);
			else pd[i][j]=pd[i+1][j];
		}
	}
	rep(i,0,n) printf("%d%c",ansv.fi[i]," \n"[i==n-1]);
	rep(i,0,n) printf("%d%c",ansv.se[i]," \n"[i==n-1]);
}