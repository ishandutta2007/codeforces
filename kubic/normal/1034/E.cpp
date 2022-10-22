#include <bits/stdc++.h>
using namespace std;
#define N 25
#define M (1<<21)+5
#define ll long long
int n,d[M];ll b1[M],b2[M];char a1[M],a2[M];
void FWT_or(ll a[],bool fl)
{
	for(int i=1;i<1<<n;i*=2) for(int j=0;j<1<<n;j+=i*2)
		for(int k=0;k<i;++k) a[i+j+k]+=(fl?-1:1)*a[j+k];
}
int main()
{
	scanf("%d %s %s",&n,a1,a2);
	for(int i=1;i<1<<n;++i) d[i]=d[i&i-1]+1;
	for(int i=0;i<1<<n;++i)
		b1[i]=(a1[i]-48ll)<<d[i]*2,b2[i]=(a2[i]-48ll)<<d[i]*2;
	FWT_or(b1,0);FWT_or(b2,0);
	for(int i=0;i<1<<n;++i) b1[i]*=b2[i];FWT_or(b1,1);
	for(int i=0;i<1<<n;++i) putchar((b1[i]>>d[i]*2&3)+48);
	return 0;
}