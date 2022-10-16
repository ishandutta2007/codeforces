#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n,L;
    cin>>n>>L;
    int R=L;
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        int l,r;
        cin>>l>>r;
        if(max(L,l)<=min(R,r))L=max(L,l),R=min(R,r);
        else if(L>r)ans+=L-r,R=L,L=r;
		else if(l>R)ans+=l-R,L=R,R=l;
    }
    cout<<ans<<endl;
}