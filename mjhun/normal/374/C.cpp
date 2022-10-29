#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF (1<<20)
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

char nx[256];
char b[1204][1024];
int f[1024][1024];
bool s[1024][1024];
int n,m,r;

void dfs(int x, int y){
	f[x][y]=1;
	s[x][y]=true;
	for(int d=-1;d<=1;d+=2){
		if(b[x+d][y]==nx[b[x][y]]){
			if(f[x+d][y]<0)dfs(x+d,y);
			else if(s[x+d][y])r=INF;
			f[x][y]=max(f[x][y],1+f[x+d][y]);
		}
		if(b[x][y+d]==nx[b[x][y]]){
			if(f[x][y+d]<0)dfs(x,y+d);
			else if(s[x][y+d])r=INF;
			f[x][y]=max(f[x][y],1+f[x][y+d]);
		}
	}
	if(b[x][y]=='D')r=max(r,f[x][y]);
	s[x][y]=false;
}

int main(){
	nx['D']='I';nx['I']='M';nx['M']='A';nx['A']='D';
	scanf("%d%d",&n,&m);
	fore(i,1,n+1)scanf("%s",b[i]+1);
	memset(f,-1,sizeof(f));
	fore(i,1,n+1){
		fore(j,1,m+1){
			if(f[i][j]<0)dfs(i,j);
		}
	}
	if(r>=INF)puts("Poor Inna!");
	else if(r<4)puts("Poor Dima!");
	else printf("%d\n",r/4);
	return 0;
}