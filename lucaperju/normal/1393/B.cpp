#include <bits/stdc++.h>
using namespace std;
int fv[100005];
int main()
{
    long long t,n,s,m,i,j,x,y,l,r;
    cin>>n;
    int nr2=0,nr4=0,nr6=0,nr8=0;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        ++fv[a];
        if(fv[a]==2)
            ++nr2;
        if(fv[a]==4)
            ++nr4;
        if(fv[a]==6)
            ++nr6;
        if(fv[a]==8)
            ++nr8;
    }
    int q;
    cin>>q;
    for(i=1;i<=q;++i)
    {
        char c;
        int a;
        cin>>c>>a;
        if(c=='+')
        {
            ++fv[a];
            if(fv[a]==2)
                ++nr2;
            if(fv[a]==4)
                ++nr4;
            if(fv[a]==6)
                ++nr6;
            if(fv[a]==8)
                ++nr8;
        }
        else
        {
            if(fv[a]==2)
                --nr2;
            if(fv[a]==4)
                --nr4;
            if(fv[a]==6)
                --nr6;
            if(fv[a]==8)
                --nr8;
            --fv[a];
        }
        if(nr8)
        {
            cout<<"YES\n";
            continue;
        }
        if(nr6)
        {
            if(nr2>=2)
            {
                cout<<"YES\n";
                continue;
            }
        }
        if(nr4)
        {
            if(nr2>=3 || nr4>=2)
            {
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
    return 0;
}