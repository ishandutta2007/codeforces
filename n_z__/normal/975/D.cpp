#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>aa;
map<pair<int,int>,int>bb;
main()
{
	int n,a,b;
    cin>>n>>a>>b;
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        int y,vx,vy;
        cin>>y>>vx>>vy;
        ans+=2*(aa[vy-a*vx]-bb[{vx,vy}]);
        aa[vy-a*vx]++;
        bb[{vx,vy}]++;
    }
    cout<<ans<<endl;
}