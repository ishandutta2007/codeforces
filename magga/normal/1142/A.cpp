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
ll mi ,ma = 0;
ll a,n,k,oo,op;
ll r;
ll l;
void calculate(ll i,ll b){
    l = (i*k+b+1-op+r)%r;
    mi=min(mi,r/__gcd(r,l));
    ma=max(ma,r/__gcd(r,l));
    l = (i*k+b+1-oo+r)%r;
    mi=min(mi,r/__gcd(r,l));
    ma=max(ma,r/__gcd(r,l));
    l = (oo-i*k+b-1+r)%r;
    mi=min(mi,r/__gcd(r,l));
    ma=max(ma,r/__gcd(r,l));
    l = (op-i*k+b-1+r)%r;
    mi=min(mi,r/__gcd(r,l));
    ma=max(ma,r/__gcd(r,l));
}
void solve(){
    ll b;cin>>n>>k>>a>>b;
    op = a+1;oo=k-a+1;
    mi=n*k;r=n*k;
    for(int i=0;i<n;i++){
        calculate(i,b);
        calculate(i,k-b);    
    }
    cout<<mi<<" "<<ma<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}