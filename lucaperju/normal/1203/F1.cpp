#include <bits/stdc++.h>
using namespace std;
struct ura1
{
    int a,b;
}v1[103];
struct ura2
{
    int a,b;
}v2[103];
bool cmp1 (ura1 a, ura1 b)
{
    return a.a<b.a;
}
bool cmp2 (ura2 a, ura2 b)
{
    return a.a+a.b>b.a+b.b;
}
int d[103][70003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long i,j,s=0,k,l,t,n,cnt=0;
    cin>>n>>s;
    int n1=0,n2=0;
    for(i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(b>=0)
        {
            v1[++n1].a=a;
            v1[n1].b=b;
        }
        else
        {
            v2[++n2].a=a;
            v2[n2].b=b;
        }
    }
    sort(v1+1,v1+n1+1,cmp1);
    sort(v2+1,v2+n2+1,cmp2);
    for(i=1;i<=n1;++i)
    {
        if(v1[i].a<=s)
        {
            ++cnt;
            s+=v1[i].b;
        }
    }
    for(i=0;i<=60000;++i)
        d[0][i]=-999;
    d[0][s]=0;
    for(i=1;i<=n2;++i)
    {
        for(j=0;j<=60000;++j)
        {
            if(j-v2[i].b<=60000 && j-v2[i].b>=v2[i].a)
                d[i][j]=max(d[i-1][j],1+d[i-1][j-v2[i].b]);
            else
                d[i][j]=d[i-1][j];
        }
    }
    int mx=0;
    for(i=0;i<=60000;++i)
        mx=max(mx,d[n2][i]);
    cnt+=mx;
    if(cnt==n)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}