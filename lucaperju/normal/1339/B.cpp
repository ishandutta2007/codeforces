#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok;
    long long k=0,t,d;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int st=n/2;
        int dr=st+1;
        for(i=1;i<=n;++i)
        {
            if(i%2==0)
            {
                cout<<v[st]<<' ';
                --st;
            }
            else
            {
                cout<<v[dr]<<' ';
                ++dr;
            }
        }
        cout<<'\n';
    }
    return 0;
}