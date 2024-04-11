#include <bits/stdc++.h>

using namespace std;
int v[20005];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,a,b,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        cnti+=v[i]%2;
        cntp+=1-(v[i]%2);
    }
    sort(v+1,v+n+1);
    if(cntp>=cnti)
    {
        if(cntp-cnti<=1)
        {
            cout<<0;
            return 0;
        }
        int vl=cntp-cnti-1;
        for(i=1;i<=n && vl;++i)
        {
            if(v[i]%2==0)
            {
                s+=v[i];
                --vl;
            }
        }
        cout<<s;
    }
    else
    {
        if(cnti-cntp<=1)
        {
            cout<<0;
            return 0;
        }
        int vl=cnti-cntp-1;
        for(i=1;i<=n && vl;++i)
        {
            if(v[i]%2==1)
            {
                s+=v[i];
                --vl;
            }
        }
        cout<<s;
    }
    return 0;
}