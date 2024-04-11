#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define x (i-1)%pos+1
const int maxn=5e5+10;
int m,n;
char t[maxn];
int main(){
	scanf("%d%d%s",&n,&m,t+1);
	ri k=min(m,n),pos=1;
	for(ri i=2;i<=k;++i)
		if(t[i]<t[x])pos=i;
		else if(t[i]>t[x])break;
	for(ri i=1;i<=m;++i)putchar(t[x]);
	return 0;
}