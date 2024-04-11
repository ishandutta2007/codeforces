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
int check(int a){
    cout<<"? "<<a<<"\n";
    cout.flush();
    cin>>a;
    return a;
}
int query(int x,int n){
    int prev;
    int ahead;
    int curr;
    if(x==1){
        prev = 1e7;
    }else{
        prev = check(x-1);
    }
    if(x==n){
        ahead = 1e7;
    }else{
        ahead = check(x+1);
    }
    curr = check(x);
    if(curr<min(ahead,prev)){
        return 0;
    }
    if(ahead<curr){
        return 1;
    }else{
        return -1;
    }
}
void solve(){
    ll n;cin>>n;
    ll start = 1,end = n,mid,ans;
    while(start<=end){
        mid = (start+end+1)/2;
        auto i = query(mid,n);
        if(i==0){
            ans=mid;
            break;
        }else if(i==1){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<"! "<<ans<<"\n";
    cout.flush();
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