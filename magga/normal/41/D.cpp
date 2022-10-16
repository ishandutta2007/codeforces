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
int val(char c){
    return c-'0';
}
void solve(){
    ll n,m,k;cin>>n>>m>>k;
    k++;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool dp[n][m+2][1001];
    pii rev[n][m+2][1001];
    for(int i=0;i<n;i++)
        for(int j=0;j<=m+1;j++)
            for(int k=0;k<=1000;k++){
                dp[i][j][k]=0;
                rev[i][j][k]={0,0};
            }
    for(int i=1;i<=m;i++){
        dp[0][i][val(arr[0][i-1])]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=1000;k++){
                if(dp[i-1][j-1][k]){
                    dp[i][j][k+val(arr[i][j-1])]=1;
                    rev[i][j][k+val(arr[i][j-1])]={j-1,val(arr[i][j-1])};
                }else if(dp[i-1][j+1][k]){
                    dp[i][j][k+val(arr[i][j-1])]=1;
                    rev[i][j][k+val(arr[i][j-1])]={j+1,val(arr[i][j-1])};
                }
            }
        }
    }
    ll ans = -1;
    ll oo=-1,op=-1;
    for(int i=1;i<=m;i++){
        for(ll j = 0;j<=1000;j++){
            if(j%k!=0){
                continue;
            }
            if(dp[n-1][i][j]){
                if(j>ans){
                    ans = j;
                    op = i;
                }
            }
        }
    }
    cout<<ans<<"\n";
    if(ans==-1)
        return;
    cout<<op<<"\n";
    for(int i=n-1;i>=1;i--){
        //cout<<rev[i][op][ans].first<<" "<<rev[i][op][ans].second<<"\n";
        oo = op;
        op = rev[i][op][ans].first;
        ans-=rev[i][oo][ans].second;
        if(oo>op){
            cout<<"L";
        }else{
            cout<<"R";
        }
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}