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

const int N=101000;
char s[N],t[20];
int n,g[N];
int ty,l,r,m,q;
int trans(char op) {
	if (op=='A') return 0;
	else if (op=='C') return 1;
	else if (op=='G') return 2;
	else return 3;
}
struct bit {
	int n;
	int p,q,r;
	vector<int> c;
	void init(int m) {
		n=m;
		c=VI(m+1,0);
	}
	void modify(int x,int s) {
		assert(x>0);
//		if (q==4) printf("A %d %d %d %d %d\n",p,q,r,x,s);
		for (;x<=n;x+=x&-x) {
			c[x]+=s;
		}
	}
	int query(int x) {
		assert(x<=n);
//		if (q==4) printf("Q %d %d %d %d\n",p,q,r,x);
		int s=0;
		for (;x;x-=x&-x) s+=c[x];
//		printf("gg %d\n",s);
		return s;
	}
}T[4][11][11];
void modify(int x,int w,int ty) {
	rep(j,1,11) T[w][j][x%j].modify(x/j+1,ty);
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,0,4) rep(j,1,11) rep(k,0,j) {
		// (m-1)*j+k<=n
		T[i][j][k].init(n/j+1);
		T[i][j][k].p=i; T[i][j][k].q=j; T[i][j][k].r=k;
	}
	rep(i,1,n+1) {
		g[i]=trans(s[i]);
		modify(i,g[i],1);
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&ty,&l);
		if (ty==1) {
			scanf("%s",t);
			modify(l,g[l],-1);
			g[l]=trans(t[0]);
			modify(l,g[l],1);
		} else {
			scanf("%d%s",&r,t);
			m=strlen(t);
			int ret=0;
			rep(i,0,m) {
				int c=trans(t[i]);
				int v=(r-l-i)%m; if (v<0) v+=m;
				int t=r-v;
				ret+=T[c][m][(l+i)%m].query((t+m)/m)-T[c][m][(l+i)%m].query((l+i)/m);
				// l+i
			}
			printf("%d\n",ret);
		}
	}
}