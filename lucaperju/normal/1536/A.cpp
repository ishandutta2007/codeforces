#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt0=0,cnt1=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a<0)
                ++cnt0;
            if(a>0)
                ++cnt1;
        }
        if(cnt0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n101\n";
            if(cnt0>0)
            {
                for(i=0;i<=100;++i)
                    cout<<-i<<' ';
            }
            else
                for(i=0;i<=100;++i)
                    cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}