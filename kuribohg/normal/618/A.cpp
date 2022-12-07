#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=30;i>=0;i--)
		if(n&(1<<i)) printf("%d ",i+1);
	return 0;
}