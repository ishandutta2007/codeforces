#include <bits/stdc++.h>

using namespace std;


const int mod=1000000007;
int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        int cnt=0;
        long long rz=1;
        for(i=1;i<=n*m;++i)
        {
            char c;
            cin>>c;
            if(c=='0')
                ++cnt;
            else
            {
                rz=rz*2LL%mod;
            }
        }
        if(cnt==0)
            --rz;
        cout<<rz<<'\n';
    }
    return 0;
}