#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=1005;
int n,m,l=1,r;
char c[maxn][maxn];
int deg[maxn*2],ans[maxn*2],q[maxn*2];
vector<int>edge[maxn*2];

namespace Dsu{
	int f[maxn*2];
	void init(){rep(i,n+m)f[i]=i;}
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);} 
	void merge(int x,int y){f[find(x)]=find(y);}
}

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	Dsu::init();
	rep(i,n){
		scanf("%s",c[i]);
		rep(j,m)if(c[i][j]=='=')Dsu::merge(i,j+n);
	}
	rep(i,n)rep(j,m)if(Dsu::find(i)==Dsu::find(j+n)&&c[i][j]!='='){
		puts("No");
		return 0;
	}
	rep(i,n)rep(j,m){
		if(c[i][j]!='='){
			int ii=Dsu::find(i),jj=Dsu::find(j+n);
			if(c[i][j]=='<')edge[ii].pb(jj),deg[jj]++;
			else edge[jj].pb(ii),deg[ii]++;
		}
	}
	int cnt=0;
	rep(i,n+m)if(Dsu::find(i)==i)cnt++; 
	rep(i,n+m)if(Dsu::find(i)==i&&!deg[i])q[++r]=i,ans[i]=1;
	while(l<=r){
		int x=q[l++];
		rep(i,edge[x].size()){
			int y=edge[x][i];
			deg[y]--;
			if(!deg[y])ans[y]=ans[x]+1,q[++r]=y;
		}
	}
	if(r!=cnt){
		puts("No");
		return 0;
	} 
	puts("Yes");
	rep(i,n)printf("%d ",ans[Dsu::find(i)]);puts("");
	rep(i,m)printf("%d ",ans[Dsu::find(i+n)]);puts("");
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}