#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mx,rzmx=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(i==1)
                mx=a;
            else
                mx=max(mx,a);
            rzmx=max(rzmx,mx-a);
        }
        int cnt=0;
        while(rzmx>0)
        {
            rzmx/=2;
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}