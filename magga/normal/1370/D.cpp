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
ll n,k;
ll arr[200001];
bool check_odd(ll a){
    int oo = 0;
    bool flag = 0;
    if(arr[0]<=a){
        flag=1;
        oo++;
    }else{
        oo++;
        flag=0;
    }
    for(int i=1;i<n;i++){
        if(flag){
            flag = 0;
            oo++;
        }else if(arr[i]<=a){
            oo++;
            flag=1;
        }
    }
    return oo>=k;
}
bool check_even(ll a){
    int oo = 1;
    bool flag = 0;
    for(int i=1;i<n;i++){
        if(flag){
            flag = 0;
            oo++;
        }else if(arr[i]<=a){
            oo++;
            flag=1;
        }
    }
    return oo>=k;
}
bool check(ll a){
    return check_even(a)||check_odd(a);
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll start = 0,end = 1e9,mid,ans=1e10;
    while(start<=end){
        mid = (start+end+1)/2;
        if(check(mid)){
            ans=mid;
            end = mid-1;
        }else{
            start=mid+1;
        }
    }
    //cout<<check(2)<<"\n";
    cout<<ans<<"\n";
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