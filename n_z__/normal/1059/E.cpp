#include<bits/stdc++.h>
using namespace std;
#define int long long
tuple<int,int,int>q[100001];
main()
{
    int n,l,s;
    cin>>n>>l>>s;
    for(int x=1,y;x<=n;x++)
    {
        cin>>y,q[x]=make_tuple(y,0,0);
        if(get<0>(q[x])>s)return puts("-1")*0;
    }
    for(int x=2,y;x<=n;x++)
    cin>>y,q[x]=make_tuple(get<0>(q[x]),y,0);
    int ans=0;
    for(int x=n,now=x,ll=l,ss=s;x>=1;x--,now=x,ll=l,ss=s,ans+=!get<2>(q[x]))
    if(!get<2>(q[x]))while(now>=1&&ll>=1&&ss>=get<0>(q[now]))q[now]=make_tuple(get<0>(q[now]),get<1>(q[now]),1),ll--,ss-=get<0>(q[now]),now=get<1>(q[now]);
    cout<<ans<<endl;
}