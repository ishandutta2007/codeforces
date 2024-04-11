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
bool query(int a,int b){
    cout<<"? "<<a+1<<" "<<b+1<<"\n";
    cout.flush();
    string ret;cin>>ret;
    if(ret=="Yes"){
        return true;
    }else{
        return false;
    }
}
void answer(int a,int b){
    cout<<"! "<<a+1<<" "<<b+1<<"\n";
    cout.flush();
}
void solve(){
    ll n;cin>>n;
    pii arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].F;
        arr[i].S = i;
    }
    sort(arr,arr+n);
    priority_queue<pair<ll,pii>>pq;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({arr[j].F-arr[i].F,{arr[j].S,arr[i].S}});
        }
    }
    while(pq.size()>0){
        auto i = pq.top();
        pq.pop();
        if(query(i.S.F,i.S.S)){
            answer(i.S.F,i.S.S);
            return;
        }
    }
    answer(-1,-1);
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