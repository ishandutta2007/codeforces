#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mod 1000003
#define N 100005
using namespace std;
int n,m,tot,h[N],fst[N],pnt[N<<1],nxt[N<<1],d[N];

void add(int x,int y){pnt[++tot]=y;nxt[tot]=fst[x];fst[x]=tot;}
int find(int t){
	memset(d,-1,sizeof(d));int head=0,tail=1;h[1]=t;d[t]=0;
	while (head<tail){
		int x=h[++head];
		int p;for(p=fst[x];p;p=nxt[p]){int y=pnt[p];if (d[y]==-1){d[y]=d[x]+1;h[++tail]=y;}}
	}
	return h[tail];
}
int main(){
	scanf("%d%d",&n,&m); int i,x,y;
	if (n==1){puts("1");return 0;}
	for (i=1; i<=m; i++){
		
		scanf("%d%d",&x,&y);add(x,y);add(y,x);
	}
	x=find(1); y=find(x); cout<<d[y]<<endl;
	return 0;
}