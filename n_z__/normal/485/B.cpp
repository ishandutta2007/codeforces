#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n;
    cin>>n;
    int q,w,e,r;
    cin>>q>>e;
    w=q,r=e;
    for(int x=2;x<=n;x++)
    {
        int y,z;
        cin>>y>>z;
        q=min(q,y);
        w=max(w,y);
        e=min(e,z);
        r=max(r,z);
    }
    cout<<max(w-q,r-e)*max(w-q,r-e);
}