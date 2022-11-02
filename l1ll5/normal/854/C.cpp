#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 600010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
struct plan
{
	ll t,c;
}a[N];
bool cmp(const plan &a,const plan &b)
{return a.c==b.c?a.t>b.t:a.c>b.c;}
int n,k;
int b[N];
bool t[N];
ll ans;
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	a[i].t=i,a[i].c=read();
	sort(a+1,a+n+1,cmp);
	int j=k+1;
	for(int i=1;i<=n;i++)
	{
		while(t[j]!=0)j++;
		if(a[i].t>k)
		{
			if(!t[a[i].t])
			b[a[i].t]=a[i].t,t[a[i].t]=1;
			else 
			{
				b[a[i].t]=j;t[j]=1;
				ans+=(ll)(j-a[i].t)*a[i].c;
			}
		}
		else 
		{
			b[a[i].t]=j;t[j]=1;
			ans+=(ll)(j-a[i].t)*a[i].c;
		}
		
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	printf("%d ",b[i]);
}
/*
 
FCCCCCCCCCC 
*/