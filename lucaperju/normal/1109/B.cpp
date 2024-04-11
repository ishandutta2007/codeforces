#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
char v[5005],aux[5005];
bool verif (int n, int pz)
{
    int i,j=-1,ok=0;
    for(i=pz;i<n;++i)
        aux[++j]=v[i];
    for(i=0;i<pz;++i)
        aux[++j]=v[i];
    for(i=0;i<n;++i)
    {
        if(aux[i]!=aux[n-i-1])
            return false;
        if(aux[i]!=v[i])
            ok=1;
    }
    if(ok==1)
        return true;
    return false;
}
int main()
{
    long long i,j=0,n,k=0,pz=-1,s=0,x,y,z,a,b,c,m,pr,ok=0,okk=1;
    cin>>v;
    n=strlen(v);
    if(n==1)
    {
        cout<<"Impossible";
        return 0;
    }
    for(i=1;i<n;++i)
    {
        if(verif(n,i))
        {
            cout<<1;
            return 0;
        }
    }
    if(n&1)
    {
        s=2;
        for(i=0;i<n/2;++i)
        {
            if(i!=0 && v[i]!=v[i-1])
                ok=1;
          /*  if(v[i]!=v[n/2-i-1])
                okk=0;*/
        }
        if(ok==0)
        {
            cout<<"Impossible";
            return 0;
        }
        cout<<s;
    }
    else
    {
        s=1;
        for(i=0;i<n/2;++i)
        {
            if(i!=0 && v[i]!=v[i-1])
                ok=1;
            if(v[i]!=v[n/2-i-1])
                okk=0;
        }
        if(ok==0)
        {
            cout<<"Impossible";
            return 0;
        }
        if(okk==1)
            ++s;
        cout<<s;
    }
}