#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[1<<20];
int f[20][1<<20],d[1<<20];
bool t[1<<20];
int n,k;

void dfs(int x){
	for(int y:g[x]){
		if(y==f[0][x])continue;
		f[0][y]=x;
		d[y]=d[x]+1;
		dfs(y);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	f[0][n-1]=-1;
	dfs(n-1);
	fore(k,1,20)fore(i,0,n){
		if(f[k-1][i]<0)f[k][i]=-1;
		else f[k][i]=f[k-1][f[k-1][i]];
	}
	t[n-1]=true;
	int q=n-k-1;
	for(int _=n-1;_>=0;--_){
		int i=_;
		if(t[i])continue;
		int j=i;
		for(int k=19;k>=0;--k)if(f[k][j]>=0&&!t[f[k][j]])j=f[k][j];
		j=f[0][j];assert(j>=0&&t[j]);
		if(d[i]-d[j]<=q){
			q-=d[i]-d[j];
			while(i!=j){
				t[i]=true;
				i=f[0][i];
			}
		}
	}
	assert(q==0);
	bool p=false;
	fore(i,0,n)if(!t[i]){
		if(p)putchar(' ');
		p=true;
		printf("%d",i+1);
	}
	puts("");
	return 0;
}