#include<bits/stdc++.h>
#define N 200009
using namespace std;

int n,m,fa[N],dad[N];
int getfa(int x){ return x==fa[x]?x:fa[x]=getfa(fa[x]); }
int getdad(int x){ return x==dad[x]?x:dad[x]=getdad(dad[x]); }
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=n; i++) fa[i]=dad[i]=i;
	while (m--){
		scanf("%d%d%d",&i,&x,&y);
		if (i==1){
			fa[getfa(x)]=getfa(y);
		} else if (i==2){
			for (i=getdad(x); i<y; i=getdad(i+1)){
				fa[getfa(i)]=getfa(i+1);
				dad[i]=getdad(i+1);
			}
		} else{
			puts(getfa(x)==getfa(y)?"YES":"NO");
		}
	}
	return 0;
}