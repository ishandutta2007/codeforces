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

bool a[1024][1024];
int n,m,s,t;
int ds[1024],dt[1024];
queue<int> q;

void bfs(int s, int *d){
	fore(i,0,n)d[i]=-1;
	d[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		fore(y,0,n)if(a[x][y]&&d[y]<0){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);s--;t--;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		a[x][y]=a[y][x]=true;
	}
	bfs(s,ds);bfs(t,dt);
	int r=0;
	fore(x,0,n)fore(y,x+1,n)if(!a[x][y]){
		if(ds[x]+dt[y]+1<ds[t])continue;
		if(ds[y]+dt[x]+1<ds[t])continue;
		r++;
	}
	printf("%d\n",r);
	return 0;
}