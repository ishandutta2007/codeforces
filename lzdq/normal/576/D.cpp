#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=155,INF=0x3f3f3f3f;
int n,m,dis[MAXN][MAXN];
struct Edge{
	int x,y,d;
	inline void Init(){
		scanf("%d%d%d",&x,&y,&d);
		x--,y--;
	}
}ed[MAXN];
bool operator <(Edge a,Edge b){
	return a.d<b.d;
}
struct Matrix{
	bitset<MAXN> a[MAXN];
	bitset<MAXN>& operator [](int x){
		return a[x];
	}
}mul,go,one;
Matrix operator *(Matrix a,Matrix b){
	static Matrix res;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			res[i][j]=0;
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			if(a[i][k]) res[i]|=b[k];
	return res;
}
Matrix operator +(Matrix a,Matrix b){
	static Matrix res;
	int i=0;
		for(int j=0; j<n; j++)
			res[i][j]=0;
		for(int k=0; k<n; k++)
			if(a[i][k]) res[i]|=b[k];
	return res;
}
Matrix Fstpw(Matrix a,int b){
	Matrix res=one;
	while(b){
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int ans=-1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++)
		ed[i].Init();
	sort(ed,ed+m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=0; i<n; i++)
		dis[i][i]=0,one[i][i]=1;
	go[0][0]=1;
	for(int i=0,t=0; i<m; i++){
		go=go+Fstpw(mul,ed[i].d-t);
		t=ed[i].d;
		int x=ed[i].x,y=ed[i].y;
		mul[x][y]=1;
		dis[x][y]=1;
		for(int j=0; j<n; j++)
			dis[j][y]=min(dis[j][y],dis[j][x]+dis[x][y]);
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				dis[j][k]=min(dis[j][k],dis[j][y]+dis[y][k]);
		for(int j=0; j<n; j++)
			if(go[0][j]&&dis[j][n-1]<INF){
				if(~ans) ans=min(ans,t+dis[j][n-1]);
				else ans=t+dis[j][n-1];
			}
		if(~ans) break;
	}
	if(~ans) printf("%d\n",ans);
	else puts("Impossible");
	return 0;
}