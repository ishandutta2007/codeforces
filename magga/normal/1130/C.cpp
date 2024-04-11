#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
void pre(){}
ll n;
vector<pair<ll,ll>>a[2];
bool arr[50][50];
bool vis[50][50]{0};
void fill(pair<int,int>to,vector<pair<int,int>>&ar){
    ar[0]={to.first+1,to.second};
    ar[1]={to.first-1,to.second};
    ar[2]={to.first,to.second+1};
    ar[3]={to.first,to.second-1};
}
int oo = 0;
void dfs(pair<int,int>to,pair<int,int>from,int id){
    vector<pair<int,int>>v(4);
    fill(to,v);
    vis[to.first][to.second]=1;
    a[id].push_back(to);
    for(auto i:v){
        if(i.first>-1 && i.second > -1 && i.first<n && i.second<n && arr[i.first][i.second] && !vis[i.first][i.second]){
            dfs(i,to,id);
        }
    }
}
ll cost(pair<int,int>i,pair<int,int>j){
    return pow(i.first-j.first,2)+pow(i.second-j.second,2);
}
void solve(){
    cin>>n;
    char c;
    ll x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2; 
    x1--;y1--;x2--;y2--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='1'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }   
    dfs({x1,y1},{-1,-1},0);
    dfs({x2,y2},{-1,-1},1);
    ll ans = 1e10;

    for(auto i:a[1]){
        for(auto j:a[0]){
            //cout<<i.first<<" "<<i.second<<"\n";
            //cout<<j.second<<" "<<j.second<<"\n";
            ans=min(ans,cost(i,j));
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}