#include <bits/stdc++.h>
using namespace std;
char v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        cin>>v;
        int n=strlen(v);
        int cnt0=0,cnt1=0,cnt2=0;
        for(i=0;i<n;++i)
        {
            if(v[i]=='S')
                ++cnt0;
            else if (v[i]=='R')
                ++cnt1;
            else
                ++cnt2;
        }
        if(cnt0>=cnt1 && cnt0>=cnt2)
        {
            for(i=1;i<=n;++i)
                cout<<'R';
        }
        else if(cnt1>=cnt0 && cnt1>=cnt2)
        {
            for(i=1;i<=n;++i)
                cout<<'P';
        }
        else
        {
            for(i=1;i<=n;++i)
                cout<<'S';
        }
        cout<<'\n';
    }
    return 0;
}