#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    vector<pair<int,int>>ans;
    int n;
    cin>>n;
    if(n==1)cout<<1<<' '<<0<<endl;
    else if(n==2)cout<<-1<<endl;
    else{
        map<int,int>mp[31];
        for(int x=1;x<=n;x++)
        mp[__builtin_ffs(x)][x]++;
        int mx=1,mc=0;
        while(mx<n)mx*=2,mc++;
        for(int x=1;x<=mc;x++)
        {
            vector<int>v;
            int now=mx;
            while(now>=1)
            {
	            for(auto q:mp[x])
	            {
	                if(q.first<now/2){
	                    int dec=min(mp[x][q.first],mp[x][now-q.first]);
	                    mp[x][q.first]-=dec;
	                    mp[x][now-q.first]-=dec;
	                    for(int y=1;y<=dec;y++)
	                    ans.push_back({q.first,now-q.first});
	                    mp[__builtin_ffs(now-2*q.first)][now-2*q.first]+=dec;
	                    if(now!=mx)mp[__builtin_ffs(now)][now]+=dec;
	                }
	                if(q.first==now/2)
	                {
	                    for(int y=1;y<=mp[x][q.first];y++)
	                    if(mp[x][q.first]>=2)
	                    {
	                    	mp[x][q.first]-=2,ans.push_back({q.first,q.first}),mp[0][0]++;
	                    	if(now!=mx)mp[__builtin_ffs(now)][now]++;
						}
	                }
	            }
	            now/=2;
	        }
	        for(auto q:mp[x])
	        for(int y=1;y<=mp[x][q.first];y++)
	        v.push_back(q.first);
            int l=0,r=v.size()-1;
            if(v.size()%2==1){
                if(mp[0][0]==0){
                    ans.push_back({v[0],v[0]*2});
                    ans.push_back({v[0],v[0]*3});
                    mp[x][v[0]]--;
                    mp[x+2][v[0]*4]++;
                }
                else {
                    while(v[0]<mx)
                    {
                        ans.push_back({0,v[0]});
                        ans.push_back({v[0],v[0]});
                        v[0]*=2;
                    }
                }
                l++;
            }
            while(l<r)
            {
                ans.push_back({v[l],v[r]});
                mp[x][v[l]]--;
                mp[x][v[r]]--;
                mp[__builtin_ffs(v[l]+v[r])][v[l]+v[r]]++;
                mp[__builtin_ffs(v[r]-v[l])][v[r]-v[l]]++;
                l++;
                r--;
            }
        }
        for(int x=1;x<=mp[0][0];x++)
        ans.push_back({0,mx});
        cout<<ans.size()<<endl;
        for(auto q:ans)
        cout<<q.first<<' '<<q.second<<endl;
    }
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}