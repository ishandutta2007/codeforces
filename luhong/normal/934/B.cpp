#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int k;scanf("%d",&k);if(k==1)return 0*puts("4");
	if(k>36)return 0*puts("-1");
	else
	{
		for(int i=1;i<=(k>>1);i++)cout<<8;
		if(k&1)cout<<0;
	 } 
	 return 0;
}