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
ll dp[100001][2];
void pre(){
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=100000;i++){
        dp[i][0] = ((i+1)/2)%2 ;
        dp[i][1] = !dp[i][0] | !dp[i-1][1];
    }
}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=31;i>=0;i--){
        int a = 0;
        for(int j=0;j<n;j++){
            if( (arr[j]^(1ll<<i)) < arr[j]){
                a++;
            }
        }
        if(a%2==1){
            if( (((a+1)/2)%2)|(n-a)%2 ) {
                cout<<"WIN"<<"\n";
            }else{
                cout<<"LOSE"<<"\n";
            }
            return;
        }
    }
    cout<<"DRAW"<<"\n";
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