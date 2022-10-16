#include <bits/stdc++.h>

using namespace std;
int ciur[10004];
unsigned long long v[30],unde[30];
unsigned long long prime[100004];
unsigned long long getval(unsigned long long p)
{
    unsigned long long rz=1;
    while(rz*p<=1000000000)
        rz*=p;
    return rz;
}
unsigned long long query (unsigned long long val)
{
    cout<<"? "<<val<<'\n';
    cout.flush();
    unsigned long long rz;
    cin>>rz;
    return rz;
}
unsigned long long getpow (unsigned long long rz, unsigned long long p)
{
    int cnt=0;
    while(rz>=p)
    {
        rz/=p;
        ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    unsigned long long i,t,j,k,mx,p,mxx=0,s;
    unsigned long long q=1;
    ciur[0]=ciur[1]=1;
    for(i=2;i*i<=10000;++i)
        if(!ciur[i])
            for(j=i*i;j<=10000;j+=i)
                ciur[j]=1;
    j=1;
    k=0;
    unde[1]=1;
    for(t=1;t<=22;++t)
    {
        q=1;
        for(i=1;i<=20;++i)
        {
            while(ciur[j])
                ++j;
            prime[++k]=j;
            q=q*j;
            ++j;
            if(q>1000000000000000000 || q<0)
                break;
            v[t]=q;
        }
        --k;
        unde[t+1]=k;
        --j;
    }
    cin>>t;
    while(t--)
    {
        unsigned long long rz=1,qr=22;
        for(int pz=1;pz<=22 && qr>0;++pz)
        {
            unsigned long long val=query(v[pz]);
            --qr;
            while(qr)
            {
                for(i=unde[pz];i<=min(k,unde[pz]+20);++i)
                {
                    if(val%prime[i]==0)
                        break;
                }
                if(i==min(k,unde[pz]+20)+1)
                    break;
                val/=prime[i];
                unsigned long long val1=query(getval(prime[i]));
                rz=rz*(getpow(val1,prime[i])+1);
                --qr;
            }
            if(qr==0)
            {
                for(i=unde[pz];i<=min(k,unde[pz]+20);++i)
                {
                    if(val%prime[i]==0)
                        rz*=2;
                }
            }
        }
        cout<<"! "<<max(rz+7,rz*2)<<'\n';
        cout.flush();
    }
    return 0;
}