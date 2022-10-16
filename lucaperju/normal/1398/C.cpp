#include <bits/stdc++.h>
using namespace std;
int v[100005];
int fv[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
            --v[i];
        }
        long long rz=0;
        ++fv[100000];
        for(i=1;i<=n;++i)
        {
            v[i]+=v[i-1];
            rz+=fv[v[i]+100000];
            ++fv[v[i]+100000];
        }
        fv[100000]=0;
        for(i=1;i<=n;++i)
            fv[v[i]+100000]=0;
        cout<<rz<<'\n';
    }
    return 0;
}