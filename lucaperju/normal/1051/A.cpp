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
char v[105];
int main()
{
    // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    cin>>t;
    int okc=0,okm=0,okM=0;
    for(j=1; j<=t; ++j)
    {
        okc=okm=okM=0;
        cin>>v;
        n=strlen(v);
        for(i=0; i<n; ++i)
        {
            if(v[i]<='9' && v[i]>='0')
                okc++;
            else if(v[i]>='a' && v[i]<='z')
                okm++;
            else if(v[i]<='Z' && v[i]>='A')
                ++okM;
        }
      /*  if(okc==0)
        {
            if(v[0]>='a' && v[1]<='z')
            {
                if(okm>1)
                    v[0]='0';
                else
                    v[1]='0';
            }
            else
            {
                if(okM>1)
                    v[0]='0';
                else
                    v[1]='0';
            }
        }
        else if(okm==0)
        {
            if(v[0]>='0' && v[0]<='0')
            {
                if(okc>1)
                    v[0]='a';
                else
                    v[1]='a';
            }
            else
            {
                if(okM>1)
                    v[0]='a';
                else
                    v[1]='a';
            }
        }
        else if(okM==0)
        {
            if(v[0]>='a' && v[0]<='z')
            {
                if(okm>1)
                    v[0]='A';
                else
                    v[1]='A';
            }
            else
            {
                if(okc>1)
                    v[0]='A';
                else
                    v[1]='A';
            }
        }*/
        for(i=0; i<n; ++i)
        {
            if(v[i]<='9' && v[i]>='0' && okc>1)
            {
                if(okm==0)
                {
                    okm=1;
                    v[i]='a';
                }
                else if(okM==0)
                {
                    okM=1;
                    v[i]='A';
                }
            }
            else if(v[i]>='a' && v[i]<='z' && okm>1)
            {
                if(okc==0)
                {
                    okc=1;
                    v[i]='0';
                }
                else if(okM==0)
                {
                    okM=1;
                    v[i]='A';
                }
            }
            else if(v[i]<='Z' && v[i]>='A' && okM>1)
            {
                if(okm==0)
                {
                    okm=1;
                    v[i]='a';
                }
                else if(okc==0)
                {
                    okc=1;
                    v[i]='0';
                }
            }
        }
        cout<<v<<'\n';
    }
    return 0;
}