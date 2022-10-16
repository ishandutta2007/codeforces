#include <iostream>
#include <cstring>
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
    else
    if(cnt<0)
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
int fv[500],fvc[500];
char v[100005];
bool verif (int cur)
{
    int i,cnt=0;
    for(i='a';i<='z';++i)
    {
        if(fv[i]>cur)
            return false;
        if(fv[i]==cur)
            ++cnt;
    }
    if(cnt==1)
        return true;
    return false;
}
int main()
{
    char c;
    long long a,b,nrca,nrcb,n,i,j,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nra,nrb,ok=0,poz,cur=0,m,cn;
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>c>>v;
        if(c=='?')
        {
            fv[v[0]]=-1;
            if(ok)
                ++s;
        }
        else
        if(c=='.')
        {
            cn=strlen(v);
            for(j='a';j<='z';++j)
                fvc[j]=0;
            for(j=0;j<cn;++j)
                fvc[v[j]]=1;
            for(j='a';j<='z';++j)
            {
                if(fvc[j])
                    fv[j]=-1;
            }
        }
        else
        {
            if(ok)
            {
                ++s;
                continue;
            }
            ++cur;
            cn=strlen(v);
            for(j='a';j<='z';++j)
                fvc[j]=0;
            for(j=0;j<cn;++j)
                fvc[v[j]]=1;
            for(j='a';j<='z';++j)
            {
                if(fvc[j] && fv[j]!=-1)
                    ++fv[j];
            }
        }
        if(verif(cur))
            ok=1;
    }
    cout<<s;
    return 0;
}