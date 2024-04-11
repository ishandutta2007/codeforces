#include<bits/stdc++.h>
using namespace std;
int x,res,a[1000100];
int main()
{
	scanf("%d",&x);
	for(int i=2;i<=x;i++)if(!a[i])for(int j=i;j<=x;j+=i)a[j]=i;
	for(int i=res=x-a[x]+1;i<x;i++)if(a[i]!=i)res=min(res,i-a[i]+1);
	printf("%d\n",res);
	return 0;
}