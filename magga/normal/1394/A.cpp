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
void solve(){
    ll n,d,m;cin>>n>>d>>m;
    ll arr[n];
    vector<long long int>a,b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>m){
            a.push_back(arr[i]);
        }else{
            b.push_back(arr[i]);
        }
    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    vector<long long int>prefa{0};
    vector<long long int>prefb{0};
    for(int i=0;i<a.size();i++){
        prefa.push_back(prefa.back()+a[i]);
    }
    for(int i=0;i<b.size();i++){
        prefb.push_back(prefb.back()+b[i]);
    }
    ll ans = 0 ;
    for(int i=0;i<=a.size();i++){
        if( i*(d+1) > n + d ){
            break;
        }
        ll temp = prefa[i];
        ll buffer = a.size()-i;
        ll del = max(0ll,(i-1)*d-buffer);
        temp+=prefb[b.size()-del];
        ans=max(ans,temp); 
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