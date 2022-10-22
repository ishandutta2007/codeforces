#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q,p[32][N];bool ok[32][N],o[N];
int fnd(int t,int x){return p[t][x]==x?x:p[t][x]=fnd(t,p[t][x]);}
void unite(int t,int x,int y){x=fnd(t,x),y=fnd(t,y),p[t][x]=y;}
bool check0(int x,int y){for(int i=0;i<30;i++)if(fnd(i,x)==fnd(i,y))return 1;return 0;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=30;i++)
		for(int j=1;j<=n;j++)p[i][j]=j;
	for(int i=1,a,b,w;i<=m;i++){
		scanf("%d%d%d",&a,&b,&w);
		for(int j=0;j<30;j++)if(w&(1<<j))unite(j,a,b);
		if(w&1^1){ok[0][a]=ok[0][b]=1;}
	}
	for(int i=1;i<=n;i++)if(ok[0][i])
		for(int j=1;j<30;j++)ok[j][fnd(j,i)]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<30;j++)ok[j][i]=ok[j][fnd(j,i)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<30;j++)o[i]|=ok[j][i];
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(check0(x,y)){printf("0\n");continue;}
		else if(o[x]){printf("1\n");continue;}
		printf("2\n");
	}
	return 0;
}