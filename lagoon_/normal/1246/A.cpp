#include<bits/stdc++.h>
using namespace std;
unordered_map<unsigned long long,long long>mp;
int a[100100];
#define re register
int main()
{
	re int n,p;
	scanf("%d%d",&n,&p);n-=p;
	for(re int i=1;n>=i;i++)
	{
		if(__builtin_popcount(n)<=i){printf("%d\n",i);return 0;}
		n-=p;
	}puts("-1");
}