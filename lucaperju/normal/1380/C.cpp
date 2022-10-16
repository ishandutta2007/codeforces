#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        long long cnt=0;
        int rz=0;
        for(i=n;i>=1;--i)
        {
            ++cnt;
            if(cnt*v[i]>=k)
            {
                cnt=0;
                ++rz;
            }
        }
        cout<<rz<<'\n';
    }
    return 0;
}