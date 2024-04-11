#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    unsigned long long i,t,j,k,mx,p,mxx=0,s;
    unsigned long long q=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int cnt=0,cntc=0;
        for(i=1;i<=n;++i)
        {
            ++cntc;
            if(cntc>=v[i])
            {
                ++cnt;
                cntc=0;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}