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
void solve(){
    ll n,d;cin>>n;
    set<ll,greater<ll>>basis;
    ll arr[n];
    ll a = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        a^=arr[i];
    }
    for(int i=0;i<n;i++){
        for(auto j:basis){
            arr[i] = min( arr[i] , arr[i]^j );
        }
        if(arr[i]!=0){
            basis.insert(arr[i]);
            //cout<<arr[i]<<" "<<i<<"\n";
        }
    }   
    //cout<<"\n";
    if(a!=0){
        cout<<basis.size()<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}