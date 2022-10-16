#include <bits/stdc++.h>
using namespace std;
char v[100003];
int main()
{
    long long t,n,i,j,m,k=0;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        cin>>v;
        int cntu=0,cntd=0,cntr=0,cntl=0;
        n=strlen(v);
        for(i=0;i<n;++i)
        {
            if(v[i]=='U')
                ++cntu;
            if(v[i]=='D')
                ++cntd;
            if(v[i]=='R')
                ++cntr;
            if(v[i]=='L')
                ++cntl;
        }
        if(a<0)
        {
            a=-a;
            swap(cntr,cntl);
        }
        if(b<0)
        {
            b=-b;
            swap(cntu,cntd);
        }
        if(cntr>=a && cntu>=b)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}