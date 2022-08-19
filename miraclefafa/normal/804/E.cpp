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

//int n,p[100],vis[10][10],L,R,tot;
//PII way[100],e[110];
int perm0[20][2]={0,8,3,5,0,6,4,8,2,8,1,6,3,6,1,5,0,7,3,8,4,5,4,7,1,7,2,6,3,7,0,5,1,8,2,5,2,7,4,6};
int perm1[16][2]={0,4,0,5,0,6,1,4,1,7,0,7,1,6,2,4,3,5,2,5,1,5,2,6,3,4,3,7,2,7,3,6};
int perm2[6][2]={1,3,0,3,1,2,0,1,2,3,0,2};
int perm3[10][2]={2,4,0,2,3,4,1,3,1,4,0,4,0,1,2,3,1,2,0,3};
//int perm2[]
/*void dfs(int u) {
	if (u==(n+1)*n) {
		bool val=1;
		rep(i,0,2*n+1) val&=(p[i]==i);
		if (val) {
			rep(i,0,u) printf("%d,%d,",way[i].fi,way[i].se);
			exit(0);
		}
	} else {
		rep(i,0,n+1) rep(j,n+1,2*n+1) if (!vis[i][j]) {
			vis[i][j]=1;
			way[u]=mp(i,j);
			swap(p[i],p[j]);
			dfs(u+1);
			swap(p[i],p[j]);
			vis[i][j]=0;			
		}
	}
}*/
int n,v[30];
int main() {
/*	scanf("%d",&L);
	rep(i,0,L) rep(j,i+1,L) e[tot++]=mp(i,j);
	while (1) {
		rep(i,0,L) p[i]=i;
		rep(i,0,tot) {
			swap(p[e[i].fi],p[e[i].se]);
		}
		bool val=1;
		rep(i,0,L) val&=(p[i]==i);
		if (val) {
			rep(i,0,tot) printf("%d,%d,",e[i].fi,e[i].se);
			puts("");
		}
		random_shuffle(e,e+tot);
	}*/
	scanf("%d",&n);
	if (n%4==2||n%4==3) {
		puts("NO");
		return 0;
	}
	if (n==1) {
		puts("YES");
		return 0;
	}
	puts("YES");
	rep(i,0,n/4) rep(j,i+1,n/4) {
		if (n%4==0) {
			rep(k,0,4) v[k]=i*4+1+k;
			rep(k,0,4) v[k+4]=j*4+1+k;
			rep(j,0,16) printf("%d %d\n",v[perm1[j][0]],v[perm1[j][1]]);
		} else if (i==0) {
			rep(k,0,5) v[k]=i*4+1+k;
			rep(k,0,4) v[k+5]=j*4+2+k;
			rep(j,0,20) printf("%d %d\n",v[perm0[j][0]],v[perm0[j][1]]);
		} else {
			rep(k,0,4) v[k]=i*4+2+k;
			rep(k,0,4) v[k+4]=j*4+2+k;
			rep(j,0,16) printf("%d %d\n",v[perm1[j][0]],v[perm1[j][1]]);
		}
	}
	rep(i,0,n/4) {
		if (n%4==0) {
			rep(k,0,4) v[k]=i*4+1+k;
			rep(j,0,6) printf("%d %d\n",v[perm2[j][0]],v[perm2[j][1]]);
		} else if (i==0) {
			rep(k,0,5) v[k]=i*4+1+k;
			rep(j,0,10) printf("%d %d\n",v[perm3[j][0]],v[perm3[j][1]]);
		} else {
			rep(k,0,4) v[k]=i*4+2+k;
			rep(j,0,6) printf("%d %d\n",v[perm2[j][0]],v[perm2[j][1]]);
		}
	}
}