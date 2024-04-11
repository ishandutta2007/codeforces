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
ll n,m;
bool arr[1001][1001]{0};
set<int>r,c;
bool row(int i){
    int val = 0;
    for(int j=1;j<=m;j++){
        if(arr[i][j]==1 && arr[i][j-1]==0){
            val++;
        }
    }
    if(val!=0){
        r.erase(i);
    }
    return val<2;
}
bool col(int j){
    int val = 0;
    for(int i=1;i<=n;i++){
        if(arr[i][j]==1 && arr[i-1][j]==0){
            val++;
        }
    }
    if(val!=0){
        c.erase(j);
    }
    return val<2;
}
bool vis[1001][1001]{0};
void fill(pii a,vector<pii>&v){
    v.push_back({a.first-1,a.second});
    v.push_back({a.first+1,a.second});
    v.push_back({a.first,a.second+1});
    v.push_back({a.first,a.second-1});
}
void dfs(pii i){
    vis[i.first][i.second]=1;
    vector<pii>v;
    fill(i,v);
    for(auto i:v){
        if(i.first>0 && i.second>0 && i.first<=n && i.second<=m && arr[i.first][i.second] && !vis[i.first][i.second]){
            dfs(i);
        }
    }
}
void solve(){
    cin>>n>>m;
    char c1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c1;
            if(c1=='.'){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        r.insert(i+1);
    }
    for(int j=0;j<m;j++){
        c.insert(j+1);
    }
    for(int i=1;i<=n;i++){
        if(!row(i)){
            cout<<-1<<"\n";
            return;
        }
    }
    for(int i=1;i<=m;i++){
        if(!col(i)){
            cout<<-1<<"\n";
            return;
        }
    }
    if((r.size()!=0 && c.size()==0)||(c.size()!=0 && r.size()==0)){
        cout<<-1<<"\n";
        return;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && arr[i][j]){
                dfs({i,j});
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
        //cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}