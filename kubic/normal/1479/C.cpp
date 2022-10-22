#include <bits/stdc++.h>
using namespace std;
#define N 10005
int L,R,w,n,m,S,T;struct Edge {int u,v,w;}e[N];
void addE(int u,int v,int w) {e[++m]=(Edge) {u,v,w};}
void print()
{
	puts("YES");printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i)
		printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
}
int main()
{
	scanf("%d %d",&L,&R);w=R-L+1;n=32;S=1;T=32;
	if(L>1) T=31,addE(T,32,L-1);addE(S,T,1);
	for(int i=2;i<=21;++i)
	{
		addE(S,i,1);
		for(int j=2;j<i;++j) addE(j,i,1<<j-2);
	}
	for(int i=19;i;--i) if(w>>i&1)
	{
		w^=1<<i;if(w) {addE(i+2,T,w);continue;}
		for(int j=2;j<i+2;++j) addE(j,T,1<<j-2);
	}print();return 0;
}