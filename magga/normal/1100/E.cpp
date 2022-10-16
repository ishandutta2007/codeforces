#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
vector<int>arr[100001];
int state[100001];
set<int>ans;
vector<int>Top;
ll n,u,v,w,m;
bool flag = 1;
set<pair<pii,int>>moo;
map<pair<pii,int>,vector<int>>indexes;
void reset(){
    Top.clear();
    flag = 1;
    for(int i=1;i<=n;i++){
        arr[i].clear();
        state[i]=0;
    }
}
void dfs(int to){
    if(state[to]==1){
        flag = 0;
        return;
    }
    if(state[to]==2){
        return;
    }
    state[to]=1;
    for(auto i:arr[to]){
        dfs(i);
    }
    state[to]=2;
    Top.push_back(to);
}
bool check(int mid){
    reset();
    for(auto i:moo){
        if(i.S>mid){
            arr[i.F.F].push_back(i.F.S);
        }
    }
    for(int i=1;i<=n;i++){
        if(state[i]==0){
            dfs(i);
        }
    }
    if(!flag) return false;
    vector<int> as(n+1,0);
    reverse(Top.begin(),Top.end());
    int i = 0;
    for(auto j:Top){
        as[j]=i;
        i++;
    }
    ans.clear();
    for(auto i : moo){
        if(as[i.F.F]>as[i.F.S]){
            for(auto j : indexes[i])
                ans.insert(j);
        }
    }
    return true;
}
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        moo.insert({{u,v},w});
        indexes[{{u,v},w}].push_back(i+1);
    }
    ll start = 0,end = 1e9,mid,an;
    while(start<=end){
        mid = (start+end+1)/2;
        if(check(mid)){
            end = mid-1;
            an = mid;
        }else{
            start=mid+1;
        }
    }
    cout<<an<<" "<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}