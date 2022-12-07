#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=10000010;
LL P,Q;
int n,p[MAXN],pa[MAXN];
bool palindrome(int x)
{
	static int d[20],tot;
	tot=0;
	while(x)
	{
		d[++tot]=x%10;
		x/=10;
	}
	for(int i=1;i<=tot;i++)
		if(d[i]!=d[tot+1-i]) return false;
	return true;
}
int main()
{
	n=10000000;
	cin>>P>>Q;
	for(int i=1;i<=n;i++) if(palindrome(i)) pa[i]=1;
	for(int i=2;i<=n;i++) p[i]=1;
	for(int i=2;i<=n;i++)
		if(p[i])
		{
			for(int j=i+i;j<=n;j+=i)
				p[j]=0;
		}
	for(int i=1;i<=n;i++) p[i]+=p[i-1],pa[i]+=pa[i-1];
	for(int i=n;i>=1;i--)
		if(Q*p[i]<=P*pa[i]) {printf("%d\n",i);return 0;}
	return 0;
}