#include <bits/stdc++.h>

using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int v[500003];
map<int,int>mp[500003];
int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            if(c=='D')
                v[i]=1;
            else
                v[i]=0;
        }
        int a=0,b=0;
        for(i=1;i<=n;++i)
        {
            if(v[i])
                ++a;
            else
                ++b;
            if(a==0 || b==0)
            {
                cout<<i<<' ';
                continue;
            }
            int c,ca,cb;
            c=cmmdc(a,b);
            ca=a/c;
            cb=b/c;
            cout<<1+mp[ca][cb]<<' ';
            ++mp[ca][cb];
        }
        cout<<'\n';
        a=0,b=0;
        for(i=1;i<=n;++i)
        {
            if(v[i])
                ++a;
            else
                ++b;
            if(a==0 || b==0)
            {
                continue;
            }
            int c,ca,cb;
            c=cmmdc(a,b);
            ca=a/c;
            cb=b/c;
            mp[ca][cb]=0;
        }
    }
    return 0;
}