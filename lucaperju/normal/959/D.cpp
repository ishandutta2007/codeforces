#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int a[100005];
bool ciur[1750203];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        int ca=a[i];
        if(ciur[ca]==1)
            break;
        for(j=2;j*j<=ca;++j)
        {
            if(ca%j==0)
            {
                for(k=j;k<=1750200;k+=j)
                    ciur[k]=1;
                while(ca%j==0)
                    ca/=j;
            }
        }
        if(ca!=1)
        {
            for(k=ca;k<=1750200;k+=ca)
                ciur[k]=1;
        }
        cout<<a[i]<<' ';
    }
    if(i==n+1)
        return 0;
    for(j=a[i];ciur[j];++j){}
    cout<<j<<' ';
    int ca=j;
    for(j=2;j*j<=ca;++j)
    {
        if(ca%j==0)
        {
            for(k=j;k<=1750200;k+=j)
                ciur[k]=1;
            while(ca%j==0)
                ca/=j;
        }
    }
    if(ca!=1)
    {
        for(k=ca;k<=1750200;k+=ca)
            ciur[k]=1;
    }
    ++i;
    j=2;
    for(;i<=n;++i)
    {
        while(ciur[j])
            ++j;
        cout<<j<<' ';
        for(k=j;k<=1750200;k+=j)
            ciur[k]=1;
    }
    return 0;
}