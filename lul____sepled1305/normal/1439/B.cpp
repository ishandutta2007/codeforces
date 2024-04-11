#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
 
//Resubmit for no reason
 
bool find_can(vi G[], vector<vi> &can,int n,int k)
{
    queue<int> qu;
    int i,j,siz = n;
    int dp[n];
    bool del[n];
    for(i=0;i<n;i++)
    {
        dp[i] = G[i].size();
        del[i] = false;
        if(dp[i] < k)
            qu.push(i);
    }
    while(!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        if(del[node])
            continue;
 
        if(dp[node]==k-1)
        {
            vi cur;
            cur.pb(node);
            for(auto it: G[node])
            {
                if(!del[it])
                    cur.pb(it);
            }
            can.pb(cur);
        }
        for(auto it: G[node])
        {
            dp[it]--;
            if(dp[it] < k && !del[it])
                qu.push(it);
        }
        del[node] = true;
        siz--;
    }
    if(siz!=0)
    {
        cout<<1<<' '<<siz<<'\n';
        for(i=0;i<n;i++)
            if(!del[i])
                cout<<i+1<<' ';
        cout<<"\n";
        return true;
    }
    else
    {
        return false;
    }
}
 
ll fast_hash(int a, int b)
{
    return 1LL*1e6*a+b;
}
 
void solve()
{
    int n,m,k,i,j,a,b;
    cin>>n>>m>>k;
    vi G[n];
    vector<vi> ans;
    unordered_set<ll> mp;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
        if(a > b)
            swap(a,b);
        mp.insert(fast_hash(a,b));
    }
    bool pass = find_can(G,ans,n,k);
    if(k > sqrt(4*m))
        cout<<-1<<"\n";
    else if(!pass)
    {
        bool pass = false;
        for(auto v: ans)
        {
            bool cur_pass = true;
            for(i=0;i<k;i++)
            {
                if(!cur_pass)
                    break;
                for(j=0;j<i;j++)
                {
                    if(mp.count(fast_hash(min(v[j],v[i]),max(v[j],v[i])))==0)
                        cur_pass = false;
                }
            }
            if(cur_pass)
            {
                cout<<"2\n";
                for(i=0;i<k;i++)
                    cout<<v[i]+1<<' ';
                cout<<"\n";
                pass = true;
                break;
            }
        }
 
        if(!pass)
            cout<<-1<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}