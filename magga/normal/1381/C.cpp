#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n,x,y;cin>>n>>x>>y;
    priority_queue<pair<int,int>>pq;
    ll arr[n];
    set<int>s;
    for(int i=0;i<=n;i++){
        s.insert(i+1);
    }
    map<int,set<int>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(s.find(arr[i])!=s.end())
            s.erase(arr[i]);
        m[arr[i]].insert(i);
    }
    ll ans[n];
    int a = *s.begin();
    for(int i=0;i<n;i++){
        ans[i] = a;
    }
    for(auto &i:m){
        pq.push({i.S.size(),i.F});
    }
    for(int i=0;i<x;i++){
        auto j = pq.top();
        pq.pop();
        auto k = *m[j.S].begin();
        m[j.S].erase(k);
        if(j.F-1>0)
            pq.push({j.F-1,j.S});
        ans[k] = j.S; 
    }
    vector<pair<int,int>>v;
    for(auto i:m){
        for(auto j:i.S){
            v.push_back({i.F,j});
        }
    }
    int cnt = n - y;
    vector<int>hmm;
    for(int i=0;i<v.size();i++){
        ans[v[i].S] = v[ ( i +  v.size()/2 )%v.size() ].F; 
        if(arr[v[i].S]==ans[v[i].S]){
            ans[v[i].S] = a;
            cnt--;
        }else{
            hmm.push_back(v[i].S);
        }
    }
    if(cnt<0){
        cout<<"NO"<<"\n";
        return;
    }
    while(cnt>0){
        ans[hmm.back()] = a;
        hmm.pop_back();
        cnt--;
    }
    map<int,int>m1,m2;
    for(auto i=0;i<n;i++){
        if(arr[i]==ans[i]){
            x--;
        }
        m1[arr[i]]++;
        m2[ans[i]]++;
    }
    for(auto i:m1){
        y -= min(i.S,m2[i.F]);
    }
    if(x!=0 || y!=0){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}