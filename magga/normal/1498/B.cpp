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
void solve(){
    ll n,w,d;cin>>n>>w;
    ll arr[32]{0};
    ll left[32]{0};
    for(int i=0;i<n;i++){
        int count = 0;
        cin>>d;
        while(d!=1){
            count++;
            d/=2;
        }
        arr[count]++;
    }
    ll h = 0;
    for(int j=0;j<32;j++){
        int i = 31-j;
        while(left[i]<arr[i]){
            h++;
            ll b = w/(1ll<<i);
            ll c = w%(1ll<<i);
            left[i]+=b;
            for(int k=0;k<=32;k++){
                if( (c&(1ll<<k))>0 ){
                    left[k]++;
                }
            }
        }
        if(i!=0)
        left[i-1] += 2*(left[i]-arr[i]);
    }
    cout<<h<<"\n";
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