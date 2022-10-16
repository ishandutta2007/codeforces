#include <bits/stdc++.h>
using namespace std;
char a[100005],b[100005],c[100005];
long long fva[300],fvb[300],fvc[300];
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,y,k=1,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxa=0,mxb=0,mxc=0;
    cin>>n;
    cin>>a;
    long long x=strlen(a);
    for(i=0;i<x;++i)
    {
        ++fva[a[i]];
        mxa=max(mxa,fva[a[i]]);
    }
    cin>>b;
    x=strlen(b);
    for(i=0;i<x;++i)
    {
        ++fvb[b[i]];
        mxb=max(mxb,fvb[b[i]]);
    }
    cin>>c;
    x=strlen(c);
    for(i=0;i<x;++i)
    {
        ++fvc[c[i]];
        mxc=max(mxc,fvc[c[i]]);
    }
    mxa=min(x,mxa+n)-(n==1 && mxa==x);
    mxb=min(x,mxb+n)-(n==1 && mxb==x);
    mxc=min(x,mxc+n)-(n==1 && mxc==x);
    if(mxa>mxb && mxa>mxc)
    {
        cout<<"Kuro";
    }
    else
    if(mxb>mxa && mxb>mxc)
    {
        cout<<"Shiro";
    }
    else
    if(mxc>mxa && mxc>mxb)
    {
        cout<<"Katie";
    }
    else
        cout<<"Draw";
    return 0;
}