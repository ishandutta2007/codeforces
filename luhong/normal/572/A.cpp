#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000],b[1000000];
int main()
{
	int A,B;scanf("%d%d",&A,&B);
	int k,m;scanf("%d%d",&k,&m);
	for(int i=1;i<=A;i++)scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)scanf("%d",&b[i]);
	if(a[k]<b[B-m+1])puts("YES");
	else puts("NO");
	return 0;
}