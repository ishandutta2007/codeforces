#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int main(){
	int i,j;
	for (i=2; i<=100001; i++)
		for (j=i+i; j<=100001; j+=i)  vis[j]=1;int n;scanf("%d",&n);
	if (n<=2) puts("1"); else puts("2");
	for (i=2; i<=n+1; i++) if (vis[i]) printf("2 "); else printf("1 ");
	return 0;
}