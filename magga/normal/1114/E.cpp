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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
ll counter = 0;
ll moix;
ll com = 0 ;
bool query(ll x){
    counter++;
    cout<<"> "<<x<<"\n";
    cout.flush();
    bool ret;
    cin>>ret;
    return ret;
}
void diff(ll x){
    cout<<"? "<<x<<"\n";
    cout.flush();
    ll rr;
    cin>>rr;
    com = __gcd(com,moix-rr);
}
void solve(){
    ll n;cin>>n;
    ll start = 0,end =1e9,mid,ans=0;
    while(start<=end){
        mid = (start+end+1)/2;
        if(query(mid)){
            start=mid+1;
        }else{
            end=mid-1;
            ans=mid;
        }
    }
    moix=ans;
    set<int>ca;
    while(ca.size()<min(60-counter,n)){
        ca.insert(rng()%n+1);
    }
    for(auto i:ca){
        diff(i);
    }
    cout<<"! "<<moix - (n-1)*com<<" "<<com<<"\n";
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