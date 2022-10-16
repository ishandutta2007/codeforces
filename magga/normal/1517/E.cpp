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
// Please write the recurances once :(
void pre(){}
struct prefix{
    vector<long long int>m;
    ll n;
    prefix(vector<long long> v){
        n = v.size();
        m.resize(n+10);
        for(int i=0;i<n;i++){
            m[i+5] = m[i+3] + v[i];
        }
    }
    long long query(int i){
        return m[i+5];
    }
    long long upto(int i,int j){
        return query(i-1) + query(j);
    }
};
long long solution(vector<long long>v,long long thresh){
    ll ret = 0;
    prefix p(v);
    for(int i=v.size();i>=0;i--){
        int start = 0 ,end = i/2,mid,ans = 0;
        while(start<=end){
            mid = (start + end + 1)/2;
            if(p.upto(i-2*mid-1,i-1)>thresh){
                start = mid+1;
            }else{
                end = mid-1;
                ans = i/2+1-mid;
            }
        }
        ret+=ans;
    }
    return ret;
}
void solve(){
    ll n;cin>>n;
    vector<ll>v(n);
    ll ans = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll thresh = (sum-1)/2;
    ans = solution(v,thresh);
    
    if(v.size()>=3){
        vector<ll>p(n-3);
        for(int i=0;i<n-3;i++){
            p[i]=v[i];
        }
         ans += solution(p,thresh-v.back());
        for(int i=3;i<n;i++){
            p[i-3]=v[i];
        }
       
        ans += solution(p,thresh-v[1]-v[2]);
    }
    if(v.size()>=6){
        vector<ll>p(n-6);
        for(int i=3;i<n-3;i++){
            p[i-3]=v[i];
        }
        ans += solution(p,thresh-v[1]-v[2]-v.back());
    }
    long long  dp[n+1];
    dp[0]=0;
    for(int i=0;i<n-2;i++){
        dp[i+1] = dp[i] + v[i];
        if(i>0 && 2*dp[i+1]>sum){
            ans++;
        }
    }
    cout<<ans%998244353<<"\n";
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