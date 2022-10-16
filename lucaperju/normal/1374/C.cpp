#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        int mn=0;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            if(c==')')
                --cnt;
            else
                ++cnt;
            mn=min(mn,cnt);
        }
        cout<<-mn<<'\n';
    }
    return 0;
}