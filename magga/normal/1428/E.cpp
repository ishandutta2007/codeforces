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
long long int ans = 0;
long long int calc(long long int m,long long int n){
    return pow((m+n-1)/n,2ll) * (m%n) + pow(m/n,2ll)*(n - (m%n));
}
pair<pii,long long int> next(pair<pii,long long int> a){
    ans -= a.F.F;
    pair<pii,long long int> ret;
    ret.F.S = a.F.S;
    ret.S = a.S + 1;
    ret.F.F = calc(a.F.S,a.S+1)-calc(a.F.S,a.S+2); 
    return ret;
}
long long int gen(long long int a){
    if(a==1){
        return 0;
    }
    return calc(a,1) - calc(a,2);
}
void solve(){
    ans = 0;
    long long int n,k;cin>>n>>k;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans += arr[i]*arr[i];
    }
    priority_queue<pair<pii,long long int>>pq;
    for(int i=0;i<n;i++){
        pq.push({{gen(arr[i]),arr[i]},1});
    }
    for(int i=0;i<k-n;i++){
        auto a = pq.top();
        pq.pop();
        pq.push(next(a));
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}