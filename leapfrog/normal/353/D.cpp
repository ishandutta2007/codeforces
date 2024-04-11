#include<bits/stdc++.h>
using namespace std;
int n,zk,mx=0;char c[1000005];
int main()
{
	scanf("%s",c+1),n=strlen(c+1),zk=0;
	for(int i=1;i<=n;i++) if(c[i]=='M') ++zk;else if(zk) mx=max(mx+1,zk);
	return printf("%d\n",mx),0;
}