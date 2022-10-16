#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
char v[2003][2003];
int rzf[2003][2003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long k=0,t,i,j=0,cnt=0,n,is,js,ib,jb,s=0,cur=0,q,m,la,lb;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            cin>>v[i][j];
    for(i=1;i<=n;++i)
    {
        int st=0,dr=0;
        for(j=1;j<=n;++j)
            if(v[i][j]=='B')
                break;
        st=j;
        if(st==n+1)
        {
            ++s;
            continue;
        }
        for(j=n;j>=1;--j)
            if(v[i][j]=='B')
                break;
        dr=j;
        if(dr-st+1>k)
            continue;
        ++rzf[max(1LL,i-k+1)][max(1LL,dr-k+1)];
        --rzf[max(1LL,i-k+1)][st+1];
        --rzf[i+1][max(1LL,dr-k+1)];
        ++rzf[i+1][st+1];
    }
    for(j=1;j<=n;++j)
    {
        int st=0,dr=0;
        for(i=1;i<=n;++i)
            if(v[i][j]=='B')
                break;
        st=i;
        if(st==n+1)
        {
            ++s;
            continue;
        }
        for(i=n;i>=1;--i)
            if(v[i][j]=='B')
                break;
        dr=i;
        if(dr-st+1>k)
            continue;
        ++rzf[max(1LL,dr-k+1)][max(1LL,j-k+1)];
        --rzf[max(1LL,dr-k+1)][j+1];
        --rzf[st+1][max(1LL,j-k+1)];
        ++rzf[st+1][j+1];
    }
    int mx=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            rzf[i][j]+=rzf[i-1][j]+rzf[i][j-1]-rzf[i-1][j-1];
            mx=max(mx,rzf[i][j]);
        }
    cout<<mx+s;
}