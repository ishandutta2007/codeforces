#include <bits/stdc++.h>

using namespace std;
int v[5003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ok=0,i,j,cnt=4,h,l,r,t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ok=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            ok+=(a&1);
        }
        if(ok==0 || ok==n)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}