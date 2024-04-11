#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1024][1024];
int main()
{
	scanf("%d",&n);
	a[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int p=0;p<(1<<i);p++)
			for(int q=0;q<(1<<i);q++)
			{
				a[p+(1<<i)][q]=a[p][q];
				a[p][q+(1<<i)]=a[p][q];
				a[p+(1<<i)][q+(1<<i)]=-a[p][q];
			}
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<(1<<n);j++)
			printf("%c",a[i][j]==1?'+':'*');
		puts("");
	}
	return 0;
}