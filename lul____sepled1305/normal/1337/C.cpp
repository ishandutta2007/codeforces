#include<bits/stdc++.h>
using namespace std;
#define pb push_back
long long i,j,k,a,b,c,sum,weight,n,ans;
const int N=2e5+10;
vector<int> tree[N];
long long sub_tree[N];
long long deep[N];
long long cal[N];

long long dfs(long long ver, long long par, long long weight)
{
    long long subtree=0;
    weight++;
    deep[ver] = weight;
    for(auto it: tree[ver])
    {
        if( it == par) continue;
        subtree+=dfs(it, ver, weight)+1;
    }
    sub_tree[ver] = subtree;
    cal[ver] = deep[ver] - sub_tree[ver];
    return subtree;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        tree[a-1].pb(b-1);
        tree[b-1].pb(a-1);
    }
    dfs(0,0,-1);
    sort(cal,cal+n, greater<>());
    for(i=0;i<k;i++)
        ans+=cal[i];
    cout<<ans;
    return 0;
}