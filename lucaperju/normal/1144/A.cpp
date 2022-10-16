#include <bits/stdc++.h>

using namespace std;
char v[105];
int fv[10000];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,a,b,mx=0,tot,m,obj,st;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        for(i=1;i<=200;++i)
            fv[i]=0;
        mn=999999;
        mx=0;
        int ok=1;
        for(i=0;i<n;++i)
        {
            mx=max(mx,v[i]-'a'+1LL);
            mn=min(mn,v[i]-'a'+1LL);
            ++fv[v[i]];
            if(fv[v[i]]==2)
                ok=0;
        }
        if(mx-mn+1==n && ok==1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}