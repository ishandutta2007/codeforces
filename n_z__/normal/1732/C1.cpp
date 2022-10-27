#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+1),ss(n+1),xs(n+1),pre(n+1),nxt(n+1);
        for(int x=1;x<=n;x++)
        cin>>a[x],ss[x]=ss[x-1]+a[x],xs[x]=xs[x-1]^a[x];
        pre[0]=0;
        for(int x=1;x<=n;x++)
        if(a[x-1])pre[x]=x-1;else pre[x]=pre[x-1];
        nxt[n]=n+1;
        for(int x=n-1;x>=1;x--)
        if(a[x+1])nxt[x]=x+1;else nxt[x]=nxt[x+1];
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ans=(ss[r]-ss[l-1])-(xs[r]^xs[l-1]);
            if(ans==0)cout<<l<<' '<<l<<endl;
            else{
                int L=l,R=r;
                for(int x=l,t1=35;t1&&x<=r;x=nxt[x],t1--)
                for(int y=r,t2=35;t2&&y>=x;y=pre[y],t2--)
                if(((ss[y]-ss[x-1])-(xs[y]^xs[x-1]))==ans)
                if(y-x<R-L)L=x,R=y;
                cout<<L<<' '<<R<<endl;
            }
        }
    }
}