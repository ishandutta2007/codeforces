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
void pre(){}
ll vis[52][52]{0};
char arr[52][52]{0};
int dfs(int i,int j){
    if(vis[i][j]){
        return 0;
    }
    vis[i][j]=1;
    if(arr[i][j]=='#'){
        return 0;
    }
    int ret = 0;
    if(arr[i][j]=='G'){
        ret++;
    }
    ret+=dfs(i+1,j);
    ret+=dfs(i-1,j);
    ret+=dfs(i,j+1);
    ret+=dfs(i,j-1);
    return ret;
}
bool check(int i,int j){
    if(arr[i-1][j]=='G'){
        return false;
    }
    if(arr[i+1][j]=='G'){
        return false;
    }
    if(arr[i][j-1]=='G'){
        return false;
    }
    if(arr[i][j+1]=='G'){
        return false;
    }
    arr[i-1][j]='#';
    arr[i+1][j]='#';
    arr[i][j+1]='#';
    arr[i][j-1]='#';
    return true;
}
void solve(){
    ll n,m;cin>>n>>m;
    int gp=0;
    set<pii>s;
    set<pii>s1;;
    s.insert({n,m});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='G'){
                gp++;
                s.insert({i,j});
            }else if(arr[i][j]=='B'){
                s1.insert({i,j});
            }
            vis[i][j]=0;
        }
    }
    if(gp==0){
        cout<<"Yes"<<"\n";
        return;
    }
    for(int i=0;i<=n+1;i++){
        arr[i][0]='#';
        arr[i][m+1]='#';
    }
    for(int i=0;i<=m+1;i++){
        arr[0][i]='#';
        arr[n+1][i]='#';
    }
    for(auto i : s1){
        if(!check(i.F,i.S)){
            cout<<"No"<<"\n";
            return;
        }
    }
    if(dfs(n,m)!=gp){
        cout<<"No"<<"\n";
        return;
    }
    cout<<"Yes"<<"\n";
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