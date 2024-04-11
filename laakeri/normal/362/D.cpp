#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll l[100001];

vector<int> g[100001];

int used[100001];
int used2[100001];

ll dfs2(int x){
    if (used2[x]) return 0;
    used2[x]=1;
    ll r=l[x];
    for (int nx:g[x]){
        r+=dfs2(nx);
    }
    return r;
}

int dfs(int x){
    if (used[x]) return 0;
    used[x]=1;
    int r=1;
    for (int nx:g[x]){
        r+=dfs(nx);
    }
    return r;
}

int main(){
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    int s1=0;
    int s2=0;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        l[a]+=c;
        g[a].push_back(b);
        g[b].push_back(a);
        s1=a;
        s2=b;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > rs;
    vector<pair<ll,ll> > v;
    int rgs=0;
    for (int i=1;i<=n;i++){
        if (dfs(i)>0){
            rs.push(make_pair(dfs2(i), i));
            rgs++;
        }
    }
    while (rs.size()>1&&rgs>q&&p>0){
        auto r1=rs.top();
        rs.pop();
        auto r2=rs.top();
        rs.pop();
        pair<ll, ll> nr=make_pair(r1.first+r2.first+min((ll)1e9, r1.first+r2.first+1ll), r1.second);
        s1=r1.second;
        s2=r2.second;
        rs.push(nr);
        rgs--;
        p--;
        v.push_back(make_pair(r1.second, r2.second));
    }
    if (rgs!=q){
        cout<<"NO"<<endl;
        return 0;
    }
    while (p>0&&s1>0){
        v.push_back(make_pair(s1, s2));
        p--;
    }
    if (p>0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for (auto vv:v){
        cout<<vv.first<<" "<<vv.second<<'\n';
    }
}