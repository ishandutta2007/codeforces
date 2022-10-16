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
ll n,d;
bool arr[2000][2000]{0};
bool brr[2000][2000]{0};
void reverse(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j]=arr[j][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=brr[i][j];
        }
    }
}
bool vis[2000]{0};
void ff(){
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
}   
stack<int>s;
void dfs(int to){
    vis[to]=1;
    for(int i=0;i<2000;i++){
        if(arr[to][i] && !vis[i]){
            dfs(i);
        }
    }
    s.push(to);
}
set<int>so;
void dfs1(int to){
    vis[to]=1;
    for(int i=0;i<2000;i++){
        if(arr[to][i] && !vis[i]){
            dfs1(i);
        }
    }
    so.insert(to);
}
bool check(){
    int i;
    reverse();
    ff();
    dfs1(s.top());
    return so.size()==n;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d;
            arr[i][j]=d>0;
        }
    }
    dfs(0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cout<<"NO"<<"\n";
            return;
        }    
    }
    if(!check()){
        cout<<"NO"<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(arr[i][i]){
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}