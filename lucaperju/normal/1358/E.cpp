#include <bits/stdc++.h>

using namespace std;
long long v[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    for(i=1;i<=(n+1)/2;++i)
        cin>>v[i];
    long long x;
    cin>>x;
    for(i=(n+3)/2;i<=n;++i)
        v[i]=x;
    s=0;
    if(x>0)
    {
        for(i=1;i<=n;++i)
        {
            s+=v[i];
        }
        if(s>0)
        {
            cout<<n;
        }
        else
            cout<<-1;
    }
    else
    {
        long long s=0;
        int k=-1;
        long long st=0;
        for(i=n;i>=1;--i)
        {
            s+=v[i];
            st+=v[i];
            if(k==-1 && s>0)
                k=n-i+1;
            else
                s-=v[i+k];
            if(s<=0 && k)
            {
                k=-1;
                s=st;
            }

        }
        cout<<k;
    }
    return 0;
}