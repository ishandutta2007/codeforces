#include <bits/stdc++.h>
using namespace std;
long long v[5];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,mod;
    cin>>t;
    while(t--)
    {
        long long c1,c2,c3,a1,a2,a3,a4,a5;
        cin>>c1>>c2>>c3>>a1>>a2>>a3>>a4>>a5;
        c1-=a1;
        c2-=a2;
        c3-=a3;
        if(c1<0 || c2<0 || c3<0)
        {
            cout<<"NO\n";
            continue;
        }
        c1-=a4;
        if(c1<0)
        {
            c3+=c1;
            c1=0;
        }
        if(c3<0)
        {
            cout<<"NO\n";
            continue;
        }
        if(c2+c3>=a5)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}