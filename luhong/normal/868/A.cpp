#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
int n;
char g[5],in[505][5];
bool flag=0;
int main(){
	scanf("%s",g);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%s",in[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(in[i][1]==g[0]&&in[j][0]==g[1]||(in[i][0]==g[0]&&in[i][1]==g[1])) flag=1;
	if(flag) puts("YES");
	else puts("NO");
}