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
bool dp[4005][4005];
void solve(){
    ll n;cin>>n;
    n*=2;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v;
    int curr = 1;
    int ma = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>ma){
            v.push_back(curr);
            curr = 1;
            ma = arr[i];
        }else{
            curr++;
        }
    }
    v.push_back(curr);
    sort(v.begin(),v.end());
    for(int i=0;i<=v.size();i++){
        for(int j=0;j<=(n/2);j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i=1;i<=v.size();i++){
        int a = v[i-1];
        for(int j=0;j<=(n/2);j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0;j<(n/2);j++){
            if(dp[i-1][j] && j+a<=n/2){
                dp[i][j+a] = 1;
            }
        }
    }
    if(dp[v.size()][n/2]){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
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