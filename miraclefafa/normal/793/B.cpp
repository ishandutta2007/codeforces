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

const int N=1100;

int n,m,g[N][N],sx,sy,tx,ty,mark[N][N];
char s[N];
void walk(int x,int y,int s) {
	rep(j,y,m) {
		if (g[x][j]==1) break;
		mark[x][j]|=s;
	}
	per(j,0,y) {
		if (g[x][j]==1) break;
		mark[x][j]|=s;
	}
	rep(i,x,n) {
		if (g[i][y]==1) break;
		mark[i][y]|=s;
	}
	per(i,0,x) {
		if (g[i][y]==1) break;
		mark[i][y]|=s;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,m) {
			if (s[j]=='*') g[i][j]=1;
			else if (s[j]=='S') sx=i,sy=j;
			else if (s[j]=='T') tx=i,ty=j;
		}
	}
	walk(sx,sy,1);
	walk(tx,ty,2);
	rep(i,0,n) rep(j,0,m) if (mark[i][j]&1) walk(i,j,4);
	rep(i,0,n) rep(j,0,m) if (mark[i][j]==3||mark[i][j]==6||mark[i][j]==7) {
		puts("YES");
		return 0;
	}
	puts("NO");
}