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
string a = "RL";
string b = "RRL";
string c = "RLL";
string d = "RRLL";
int match_string(string &s,string a){
    int ret = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=a[i]){
            ret++;
        }
    }
    return ret;
}
void pre(){}
long long int answer(string s){
    ll dp[s.size()+1];
    for(int i=0;i<=s.size();i++){
        dp[i]=1e18;
    }
    dp[0]=0;
    for(int i=2;i<=s.size();i++){
        dp[i] = min(dp[i],dp[i-2] + match_string(a,s.substr(i-2,2)));
        if(i>2){
            dp[i] = min(dp[i],dp[i-3] + match_string(b,s.substr(i-3,3)));
            dp[i] = min(dp[i],dp[i-3] + match_string(c,s.substr(i-3,3)));
        }   
        if(i>3){
            dp[i] = min(dp[i],dp[i-4] + match_string(d,s.substr(i-4,4)));
        }
    }
    return dp[s.size()];
}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    ll ans = 1e18;
    for(int i=0;i<4;i++){
        ans = min(ans,answer(s));
        s = s[s.size()-1] + s.substr(0,s.size()-1);
    }
    cout<<ans<<"\n";
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