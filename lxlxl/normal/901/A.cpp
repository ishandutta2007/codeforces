#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

int n;
int a[maxn];
int sum[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(i==0) sum[i]=a[i];
		else sum[i]=sum[i-1]+a[i];
	}
	
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1&&a[i-1]>1) { pos=i; break; }
	}
	if(!pos) puts("perfect");
	else
	{
		puts("ambiguous");
		
		printf("0");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++) printf(" %d",sum[i-1]);
		}
		printf("\n");
		
		printf("0");
		for(int i=1;i<pos;i++)
		{
			for(int j=1;j<=a[i];j++) printf(" %d",sum[i-1]);
		}
		printf(" %d %d",sum[pos-1]-1,sum[pos-1]);
		for(int j=3;j<=a[pos];j++) printf(" %d",sum[pos-1]);
		for(int i=pos+1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++) printf(" %d",sum[i-1]);
		}
		printf("\n");
	}
	
    return 0;
}