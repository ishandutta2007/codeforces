#include <bits/stdc++.h>

using namespace std;
int ciur[10000007];
int a[500005];
int b[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    long long n;
    for(i=2;i<=10000000;++i)
        if(!ciur[i])
            for(j=i;j<=10000000;j+=i)
                if(!ciur[j])
                    ciur[j]=i;
    for(i=1;i<=t;++i)
    {
        int x;
        cin>>x;
        int p=ciur[x];
        while(x%p==0)
            x/=p;
        if(x==1)
            a[i]=b[i]=-1;
        else
            a[i]=p,b[i]=x;
    }
    for(i=1;i<=t;++i)
        cout<<a[i]<<' ';
    cout<<'\n';
    for(i=1;i<=t;++i)
        cout<<b[i]<<' ';
    return 0;
}