#include <bits/stdc++.h>

using namespace std;
long long v[103];
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
long long m1=179426491;
long long m2=179426407;
long long bz=150;
char a[1000006],b[1000006];
int add (int la, int lb)
{
    long long h1a=0,h2a=0,h1b=0,h2b=0,mx=0;
    int i,j;
    long long pc1=1,pc2=1;
    for(i=la-1,j=0;i>=0 && j<lb;--i,++j)
    {
        h1a=(h1a+(pc1*1LL*a[i])%m1)%m1;
        h2a=(h2a+(pc2*1LL*a[i])%m2)%m2;
        pc1=(pc1*bz)%m1;
        pc2=(pc2*bz)%m2;
        h1b=((h1b*1LL*bz)%m1+b[j])%m1;
        h2b=((h2b*1LL*bz)%m2+b[j])%m2;
        if(h1a==h1b && h2a==h2b)
            mx=la-i;
    }
    for(i=la;i<la+lb-mx;++i)
        a[i]=b[i-la+mx];
    return i;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long k=0,t,i,j=0,cnt=0,n,is,js,ib,jb,s=0,cur=0,q,m,la,lb;
    cin>>n;
    cin>>a;
    la=strlen(a);
    for(i=2;i<=n;++i)
    {
        cin>>b;
        lb=strlen(b);
        la=add(la,lb);
    }
    for(i=0;i<la;++i)
        cout<<a[i];
}