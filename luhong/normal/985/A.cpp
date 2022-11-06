#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
int Abs(int x){return x>0?x:-x;}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n/2;i++)scanf("%d",&a[i]);
	sort(a+1,a+n/2+1);int sum1=0,sum2=0;
	for(int i=1;i<=n/2;i++)sum1+=Abs(2*i-1-a[i]),sum2+=Abs(2*i-a[i]);
	printf("%d",min(sum1,sum2));return 0;
 }