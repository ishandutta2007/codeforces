#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
int Abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int a[1010000],b[1001][1001];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int j=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]>a[j]+k)j++;
		while(a[i]>a[j]&&a[i]<=a[j]+k)j++,ans++;
	}
	printf("%d",n-ans);return 0;
}