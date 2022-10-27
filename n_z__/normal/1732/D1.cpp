#include<bits/stdc++.h>
using namespace std;
#define int long long
struct custom_hash{static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
main()
{
    unordered_map<int,int,custom_hash>mp,ans;
    unordered_map<int,set<int>,custom_hash>vis,del;
    mp[0]=1;
    int t;
    cin>>t;
    while(t--)
    {
        char op;
        int x;
        cin>>op>>x;
        if(op=='+')
        {
            for(auto q:vis[x])
            del[q].erase(x);
            mp[x]=1;
        }
        else if(op=='-')
        {
            for(auto q:vis[x])
            del[q].insert(x);
            mp[x]=0;
        }
        else
        {
            while(mp[ans[x]])vis[ans[x]].insert(x),ans[x]+=x;
            int res=ans[x];
            if(!del[x].empty())res=min(res,*del[x].begin());
            cout<<res<<endl;
        }
    }
}