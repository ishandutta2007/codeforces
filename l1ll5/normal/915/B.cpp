#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,pos,l,r;
int ans;
int main()
{
    n=read(),pos=read(),l=read(),r=read();
    if(l==1&&r==n)
    {
        puts("0");
        return 0;
    }/*
    if(l==r)
    {
        if(l==1||l==n)
        {
            ans=abs(pos-l)+1;
            cout<<ans<<endl;
            return 0;
        }
        ans=abs(pos-l)+2;
        cout<<ans<<endl;
        return 0;
    }
    if(pos<=l)
    {
        ans+=l-pos;
        if(r!=n)ans+=r-l+1;
        ans++;
        cout<<ans<<endl;
        return 0;
    }
    if(pos>=r)
    {
        ans+=pos-r;
        if(l!=1)ans+=r-l+1;
        ans++;
        cout<<ans<<endl;
        return 0;
    }
    ans=pos-l;
    ans++;
    if(r!=n)ans+=r-l+1;
    int tmp=0;

    tmp=r-pos;
    tmp++;
    if(l!=1)tmp+=r-l+1;
    ans=min(ans,tmp);
    cout<<ans<<endl;
    return 0;*/

    if(l==1)
	{
		ans=abs(r-pos)+1;
		cout<<ans<<endl;
		return 0;
	}
	if(r==n)
	{
		ans=abs(l-pos)+1;
		cout<<ans<<endl;
		return 0;
	}
	if(l<=pos&&pos<=r)
	{
		ans=r-l+2+min(abs(l-pos),abs(r-pos));
		cout<<ans<<endl;
	}
	if(pos<l)
	{
		ans=abs(pos-r)+1;ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(pos>r)
	{
		ans=abs(pos-l)+1;ans++;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}