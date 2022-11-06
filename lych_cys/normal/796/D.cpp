#include<bits/stdc++.h>
#define N 300005
using namespace std;

int n,m,tot,len,p[N],h[N],e[N][2],fst[N],pnt[N<<1],nxt[N<<1]; bool bo[N];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
int main(){
	scanf("%d%d%d",&n,&m,&len);
	int i,x,y,head=0,tail=0;
	for (i=1; i<=m; i++){
		scanf("%d",&x);
		if (bo[x]){ i--; m--; continue; } bo[x]=1;
		p[x]=x; h[++tail]=x;
	}
	for (i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		e[i][0]=x; e[i][1]=y;
		add(x,y); add(y,x);
	}
	while (head<tail){
		x=h[++head];
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (!p[y]){
				p[y]=p[x]; h[++tail]=y;
			}
		}
	}
	printf("%d\n",m-1);
	for (i=1; i<n; i++)
		if (p[e[i][0]]!=p[e[i][1]]) printf("%d ",i);
	return 0;
}