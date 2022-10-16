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
    ll n,m;cin>>n>>m;
    ll arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            arr[i][j]--;
        }
    }
    int a=0,b=1,c=2;
    ll dp[3]{0};
    string s;cin>>s;
    for(int i=0;i<m;i++){
        if(s[i]=='L'){
            dp[b] = (dp[b] + n - 1)%n;
        }else if(s[i]=='R'){
            dp[b] = (dp[b] + 1)%n;
        }else if(s[i]=='U'){
            dp[a] = (dp[a] + n - 1)%n;
        }else if(s[i]=='D'){
            dp[a] = (dp[a] + 1)%n;
        }else if(s[i]=='C'){
            swap(a,c);
        }else{
            swap(b,c);
        }
    }
    ll ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int i1 = 0;
            int j1 = 0;
            int k1 = 0;
            if(a==0){
                i1 = (i + dp[0])%n;
            }else if(a==1){
                i1 = (j + dp[1])%n;
            }else{
                i1 = (arr[i][j] + dp[2])%n;
            }
            if(b==0){
                j1 = (i + dp[0])%n;
            }else if(b==1){
                j1 = (j + dp[1])%n;
            }else{
                j1 = (arr[i][j] + dp[2])%n;
            }
            if(c==0){
                k1 = (i + dp[0])%n;
            }else if(c==1){
                k1 = (j + dp[1])%n;
            }else{
                k1 = (arr[i][j] + dp[2])%n;
            }
            ans[i1][j1]=k1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]+1<<" ";
        }
        cout<<"\n";
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