 #include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
void read(ll &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
#define maxn 100010
ll n,m,_n,_m;
int len1,len2;
bool vis[maxn];
int a[maxn];
int mjy=0;

void check()
{
	int b1=0,b2=0;
	for (int i=1;i<=len1;i++)
		b1=b1*7+a[i];
	for (int i=len1+1;i<=len1+len2;i++)
		b2=b2*7+a[i];
	if (b1<n && b2<m)	mjy++;
}
void doit(int t)
{
	if (t>len1+len2)
	{
		check();
		return;
	}
	for (int i=0;i<7;i++)
	if (!vis[i])
	{
		a[t]=i;
		vis[i]=true;
		doit(t+1);
		a[t]=0;
		vis[i]=false;
	}
}
int main()
{
	read(n),read(m);
	_n=1,_m=1;
	len1=0,len2=0;
	while (_n<n)	_n*=7,len1++;
	while (_m<m)	_m*=7,len2++;
	if (n==1)	len1=1;
	if (m==1)	len2=1;
	if (len1+len2>7)
	{
		printf("0\n");
		return 0;
	}
	doit(1);
	printf("%d\n",mjy);
	return 0;
}