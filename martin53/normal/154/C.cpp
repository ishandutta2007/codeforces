#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,base=1e6+3,mod=1e9+7,base_=1e6+37,mod_=1e9+9;
int n,m;
vector<int> friends[nmax];
pair<int/*hash*/,int/*hash_*/> hash_without[nmax],hash_with[nmax];

pair<int/*hash*/,int/*hash_*/> find_hash(int index)
{
    long long val=0,val_=0;
    for(auto k:friends[index])
        {
        val=(val*base+k)%mod;
        val_=(val_*base_+k)%mod_;
        }
    return {val,val_};
}
map< pair<int/*hash*/,int/*hash_*/>,int> seen;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
    cin>>x>>y;
    friends[x].push_back(y);
    friends[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        sort(friends[i].begin(),friends[i].end());
        hash_without[i]=find_hash(i);
        friends[i].push_back(i);
        sort(friends[i].begin(),friends[i].end());
        hash_with[i]=find_hash(i);

        seen[hash_without[i]]++;

    }

    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+(seen[hash_without[i]]-1);
    }


    for(int i=1;i<=n;i++)
        for(auto k:friends[i])
            {
            if(hash_without[i]==hash_without[k])ans--;
            if(hash_with[i]==hash_with[k])ans++;
            }
        cout<<ans/2<<endl;
    return 0;
}