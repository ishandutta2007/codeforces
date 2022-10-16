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
    ll n;cin>>n;
    ll arr[n];
    ll brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    multiset<pii>m;
    if(n%2==1 && arr[n/2]!=brr[n/2]){
        cout<<"No"<<"\n";
        return;
    }
    for(int i=0;i<n/2;i++){
        m.insert({arr[i],arr[n-1-i]});
    }
    for(int i=0;i<n/2;i++){
        if(m.find({brr[i],brr[n-1-i]})==m.end() && m.find({brr[n-1-i],brr[i]})==m.end()){
            cout<<"No"<<"\n";
            return;
        }
        if(m.find({brr[i],brr[n-1-i]})==m.end()){
            m.erase(m.find({brr[n-1-i],brr[i]}));
        }else 
            m.erase(m.find({brr[i],brr[n-1-i]}));
    }
    cout<<"Yes"<<"\n";
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