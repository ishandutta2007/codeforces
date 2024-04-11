#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n,c[N];
int Le[N],Ri[N],stk[N],top;
ll ans,tot;
bool ck(int x)
{return (top&&(c[stk[top]]|c[x])==c[x]);}
void init()
{
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
}
ll cal()
{
	ans=(ll)n*(n-1)/2;
	for(int i=1;i<=n;i++)
	{
		tot+=(Ri[i]-Le[i]);
		tot+=(ll)(i-Le[i])*(Ri[i]-i);
	}
}
void work()
{
	for(int i=1;i<=n;i++)
	{
		while(ck(i)&&c[stk[top]]!=c[i])top--;
		Le[i]=stk[top]+1,stk[++top]=i;
	}
	top=0;
	stk[top]=n+1;
	for(int i=n;i;i--)
	{
		while(ck(i))top--;
		Ri[i]=stk[top]-1;
		stk[++top]=i;
	}
}
int main()
{
	init();
	work();
	cal();
	cout<<ans-tot<<endl;
}
/*
orzzororezozooorozorozoroozoooozoororoozorozrozororz
please do not hack me . qwq
*/