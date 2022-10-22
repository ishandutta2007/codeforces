#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define inf 10001000
using namespace std;
int n,f[8];char s[5];
int main()
{
    int x,k,t;cin>>n;
    for (int i=0;i<8;i++) f[i]=inf;
    for (int i=1;i<=n;i++)
    {
    	cin>>x;t=0;scanf("%s",s);k=strlen(s);
    	for (int i=0;i<k;i++) t|=1<<(s[i]-'A');
		f[t]=min(f[t],x);
		for (int i=0;i<8;i++) f[i|t]=min(f[i|t],f[i]+x);
	}
	if (f[7]==inf) puts("-1");else printf("%d",f[7]);
}