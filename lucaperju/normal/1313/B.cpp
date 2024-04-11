#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,t,n,m,l,k,s,p,cnt=0;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>n>>x>>y;
        long long cx=x,cy=y;
        --cx;
        cx=max(0LL,cx-max(0LL,(n-y-1)));
        --cy;
        cy=max(0LL,cy-max(0LL,(n-x-1)));
        cout<<max(cx,cy)+1<<' ';
        x=n+1-x;
        y=n+1-y;
        cx=x,cy=y;
        --cx;
        cx=max(0LL,cx-(n-y));
        --cy;
        cy=max(0LL,cy-(n-x));
        cout<<n-max(cx,cy)<<'\n';
    }
    return 0;
}