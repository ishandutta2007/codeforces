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
bool cross(pii a,pii b,pii c){
    a = {a.F-b.F,a.S-b.S};
    b = {c.F-b.F,c.S-b.S};
    if(a.F*b.F+a.S*b.S<=0){
        return 1;
    }else{
        return 0;
    }
}
void solve(){
    ll n;cin>>n;
    pair<pii,int> arr[n];
    ll l,r;
    for(int i=0;i<n;i++){
        cin>>arr[i].F.F>>arr[i].F.S;
        arr[i].S=i+1;
    }
    for(int i=0;i<n;i++){
        for(int i=0;i<n-2;i++){
            if(cross(arr[i].F,arr[i+1].F,arr[i+2].F)){
                swap(arr[i+1],arr[i+2]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].S<<" ";
    }
    cout<<"\n";
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