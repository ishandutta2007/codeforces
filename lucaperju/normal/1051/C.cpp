#include <bits/stdc++.h>
using namespace std;
long long cmmdc(long long a,long long b)
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
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*struct ura
{
    int val,id;
}a[1005];
bool cmp (ura a, ura b)
{
    if(a.val>b.val)
        return true;
    return false;
}*/
int v[105],fv[105];
int main()
{
    // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    cin>>n;
    int cntun=0,cntm=0;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
    }
    for(i=1;i<=100;++i)
    {
        if(fv[i]==1)
            ++cntun;
        else
        if(fv[i]>2)
            ++cntm;
    }
    if(cntun%2==1 && cntm==0)
    {
        cout<<"NO";
        return 0;
    }
    cnt=cntun;
    cout<<"YES\n";
    for(i=1;i<=n;++i)
    {
        if(fv[v[i]]==1)
        {
            if(cnt<=cntun/2)
                cout<<'B';
            else
                cout<<'A';
            --cnt;
        }
        else
            if(fv[v[i]]>2)
            {
                if(cntun%2==1 && ok==1)
                {
                    cout<<'B';
                    ok=0;
                }
                else
                cout<<'A';
            }
        else
            cout<<'A';

    }
    return 0;
}