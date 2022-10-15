#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=2e5+5;
vector<int> prd[maxn];int c[maxn];vector<int> a[maxn];bool used[maxn];
map<int,int> cnt[maxn];int sub[maxn];int res1[maxn];int res2[maxn];int ans=0;int ans1;
int cnt1[maxn];
void dfs1(int x)
{
    used[x]=true;sub[x]=1;
    for(int v:a[x]) if(!used[v]) {dfs1(v);sub[x]+=sub[v];}
    used[x]=false;
}
void add(int x,int key)
{
    int val1=cnt[x][key];
    res1[x]+=(val1*(val1-1)/2);res1[x]%=p;
    cnt[x][key]++;
    int val2=cnt1[key]-val1;--val2;
    res2[x]-=((val2)*(val2-1)/2);res2[x]%=p;
}
void dfs(int x)
{
    used[x]=true;vector<pair<int,int> > h;
    for(int v:a[x]) {if(used[v]) continue; h.push_back({sub[v],v});dfs(v);}
    if(h.empty())
    {
        res2[x]=ans1;
        for(int p:prd[c[x]]) add(x,p);
         {ans-=res1[x];} ans-=res2[x];
        used[x]=false;
        return;
    }
    sort(h.begin(),h.end());reverse(h.begin(),h.end());int x1=h[0].second;
    cnt[x].swap(cnt[x1]);swap(res1[x],res1[x1]);swap(res2[x],res2[x1]);for(int p:prd[c[x]]) add(x,p);
    for(int i=1;i<h.size();++i)
    {
        int v=h[i].second;
        for(auto [key,val]:cnt[v]) {for(int i=0;i<val;++i) add(x,key);}
    }
     {ans-=res1[x];} ans-=res2[x];ans%=p;
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;for(int i=0;i<n;++i) cin>>c[i];
    used[0]=true;used[1]=true;for(int i=2;i<maxn;++i) {if(used[i]) continue; for(int j=i;j<maxn;j+=i) {used[j]=true;prd[j].push_back(i);}}
    for(int i=0;i<n;++i)
    {
        for(int p:prd[c[i]]) {cnt1[p]++;}
    }
    for(int i=2;i<maxn;++i)
    {
        int c1=cnt1[i];
        ans+=(c1*(c1-1)*(c1-2))/6;ans%=p;
    }
    ans1=ans;
    ans*=n;ans%=p;
    for(int i=0;i<n-1;++i)
    {
        int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);
    }
    fill(used,used+n,0);
    dfs1(0);
    dfs(0);
    cout<<(ans%p+p)%p;
    return 0;
}