#include <bits/stdc++.h>

using namespace std;
long long v[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long mn=99999999999LL;
        cnt=0;
        for(i=n;i>=1;--i)
        {
            if(v[i]>mn)
                ++cnt;
            else
                mn=v[i];
        }
        cout<<cnt<<'\n';
    }
    return 0;
}