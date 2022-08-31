#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=55;
int n,m,sw;
char s[N][N],t[N];
vector<PII> ret1,ret2;
void gao(vector<PII> &ret) {
	// n%2==0
	rep(j,0,m) {
		int i=0;
		while (i<n) {
//			printf("%d %d %c\n",i,j,s[i][j]);
			if (s[i][j]=='L') {
				for (int k=0;i+k<n&&j+k<m;k++) {
//					puts("fuck");
//					printf("%d %d %c\n",i+1+k,j+k,s[i+1+k][j+k]);
					if (s[i+1+k][j+k]=='L') {
						for (int l=k;l>=0;l--) {
							ret.pb(mp(i+l,j+l));
							s[i+l][j+l]=s[i+l][j+l+1]='U';
							s[i+l+1][j+l]=s[i+l+1][j+l+1]='D';
							if (l>0) {
								ret.pb(mp(i+l,j+l-1));
								s[i+l][j+l-1]=s[i+l+1][j+l-1]='L';
								s[i+l][j+l]=s[i+l+1][j+l]='R';
							}
						}
						break;
					}
					if (s[i+1+k][j+1+k]=='U') {
						for (int l=k;l>=0;l--) {
							ret.pb(mp(i+l+1,j+l));
							s[i+l+1][j+l]=s[i+l+2][j+l]='L';
							s[i+l+1][j+l+1]=s[i+l+2][j+l+1]='R';
							ret.pb(mp(i+l,j+l));
							s[i+l][j+l]=s[i+l][j+l+1]='U';
							s[i+l+1][j+l]=s[i+l+1][j+l+1]='D';
						}
						break;							
					}
				}
			}
			i+=2;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	if (n%2==1) {
		sw=1;
		rep(i,0,n) {
			scanf("%s",t);
			rep(j,0,m) {
				if (t[j]=='L') s[j][i]='U';
				else if (t[j]=='R') s[j][i]='D';
				else if (t[j]=='U') s[j][i]='L';
				else s[j][i]='R';
			}
		}
		swap(n,m);
	} else {
		rep(i,0,n) scanf("%s",s[i]);
	}
	gao(ret1);
	if (sw==1) {
		rep(i,0,m) {
			scanf("%s",t);
			rep(j,0,n) {
				if (t[j]=='L') s[j][i]='U';
				else if (t[j]=='R') s[j][i]='D';
				else if (t[j]=='U') s[j][i]='L';
				else s[j][i]='R';
			}
		}		
	} else {
		rep(i,0,n) scanf("%s",s[i]);		
	}
	gao(ret2);
	reverse(all(ret2));
	for (auto p:ret2) ret1.pb(p);
	if (sw) {
		for (auto &p:ret1) swap(p.fi,p.se);
	}
	printf("%d\n",SZ(ret1));
	for (auto p:ret1) printf("%d %d\n",p.fi+1,p.se+1);
}