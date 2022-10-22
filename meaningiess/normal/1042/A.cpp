#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,i,a[101],mx,res;
int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++) a[i]=read(),mx=max(a[i],mx);
    for (i=1;i<=n;i++) a[0]+=mx-a[i];
    if (m>=a[0]) res=mx+ceil(1.0*(m-a[0])/n);else res=mx;
    printf("%d %d",res,mx+m);
}