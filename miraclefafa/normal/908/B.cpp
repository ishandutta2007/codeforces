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

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,p[20],sx,sy,ret;
char g[60][60];
char s[110];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%s",g[i]);
	rep(i,0,n) rep(j,0,m) {
		if (g[i][j]=='S') sx=i,sy=j;
	}
	rep(i,0,4) p[i]=i;
	scanf("%s",s);
	int l=strlen(s);
	while (1) {
		int px=sx,py=sy;
		int val=-1;
		rep(j,0,l) {
			int w=s[j]-'0';
			px+=dx[p[w]],py+=dy[p[w]];
			if (px<0||px>=n||py<0||py>=m||g[px][py]=='#') { val=0; break; }
			if (g[px][py]=='E') { val=1; break; }
		}
		if (val==1) ret+=val;
		if (!next_permutation(p,p+4)) break;
	}
	printf("%d\n",ret);
}