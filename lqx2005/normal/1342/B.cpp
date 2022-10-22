#include<bits/stdc++.h>
using namespace std;
const int N=11000;
int t,n;
char a[N];
int check()
{
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) return 0;
	return 1;
}
void put()
{
	printf("%c",a[1]);
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) printf("%c",a[i]=='1'?'0':'1');
		printf("%c",a[i]);  
	 } 
	 printf("\n");
	 return;
}
int main()
{
	scanf("%lld",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%s",a+1);
		n=strlen(a+1);
		if(check()) printf("%s\n",a+1);
		else put();
	}
	return 0;
}