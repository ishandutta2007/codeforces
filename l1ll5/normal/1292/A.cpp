#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q;
bool a[N][2];
bool b[N][2];
int d[N];
int now;
void blk(int x)
{
	if(!d[x])now++;
	d[x]=1;
}
void clr(int x)
{
	if(d[x])now--;
	d[x]=0;
}
int main()
{
	memset(b,1,sizeof(b));
	n=read(),q=read();
	for(int i=1;i<=q;i++)
	{
		int r=read()-1,c=read();
		a[c][r]^=1;

		if(!a[c][r])
		{
			if(a[c][r^1]) now--;
			if(c!=1)
			if(a[c-1][r^1]) now--;
			if(c!=n)
			if(a[c+1][r^1]) now--;
		}
		else
		{			//b[c][r]=0;

			if(a[c][r^1]) now++;
			if(c!=1)
			if(a[c-1][r^1]) now++;
			if(c!=n)
			if(a[c+1][r^1]) now++;
		}

		if(now)
		{
			puts("No");
		}
		else puts("Yes");
	}
}