
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
ll calc(vector<ll>arr,int val){
    ll ret = 0;
    ll n = arr.size();
    ll curr = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            ret+=abs(i-curr);
            curr+=2;
        }
    }
    return ret;
}
void solve(){
    ll n;cin>>n;
    vector<ll> arr(n);
    ll val = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]%=2;
        val+=arr[i];
    }
    ll ans = 1e15;
    if(n%2==0){
        if(val!=n/2){
            cout<<-1<<"\n";
            return;
        }
        for(int i=0;i<2;i++){
            arr.push_back(i);
            ans=min(ans,calc(arr,i));
            arr.pop_back();
        }
    }else{
        if(val==n/2){
            ans=calc(arr,0);
        }else if(val==(n+1)/2){
            ans=calc(arr,1);
        }else{
            ans = -1;
        }
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