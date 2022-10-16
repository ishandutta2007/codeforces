#include <bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int st[200005],dr[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,j,s=0,k,l,t;
    cin>>a>>b;
    n=strlen(a);
    int m=strlen(b);
    i=j=0;
    for(i=0;i<n;++i)
    {
        if(a[i]==b[j])
            ++j;
        st[i+1]=j;
    }
    j=m-1;
    for(i=n-1;i>=0;--i)
    {
        if(a[i]==b[j])
            --j;
        dr[i+1]=m-1-j;
    }
    i=0;
    j=1;
    while(j<=n)
    {
        while(st[i]+dr[j]>=m && j<=n)
            ++j;
        --j;
        if(j-i-1>s)
            s=j-i-1;
        ++i;
        if(j==n)
            break;
    }
    for(i=1;i<=n;++i)
        if(st[i]==m)
            s=max(s,n-i);
    cout<<s;
    return 0;
}