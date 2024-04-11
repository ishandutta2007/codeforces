#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n,s=0,rz=0,a,b,ok;
    long long k,t;
    cin>>t;
    while(t--)
    {
        int ok=0;
        cin>>n>>a>>b;
        if(b==n*1LL*(n-1)+1LL)
        {
            ok=1;
            --b;
        }
        if(a>b)
        {
            cout<<1<<'\n';
            continue;
        }
        long long st=1,dr,ca=a,cr=0;
        while(ca>cr+(n-st)*2LL)
        {
            cr+=(n-st)*2LL;
            ++st;
        }
        dr=st+1LL+(a-cr-1LL)/2LL;
        for(i=a;i<=b;++i)
        {
            if(i%2LL)
                cout<<st<<' ';
            else
            {
                cout<<dr<<' ';
                ++dr;
                if(dr>n)
                {
                    ++st;
                    dr=st+1LL;
                }
            }
        }
        if(ok)
            cout<<1;
        cout<<'\n';
    }
    return 0;
}