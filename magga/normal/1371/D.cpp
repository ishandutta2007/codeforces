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
    ll n,r;cin>>n>>r;
    ll arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    int c = 0;
    for(int i=0;i<n;i++){
        if(c==r){
            break;
        }
        for(int j=0;j<n;j++){
            arr[j][(j+i)%n]=1;
            c++;
            if(c==r){
                break;
            }
        }
    }
    ll ans =0;
    ll ma = 0;
    ll mi = n;
    for(int i=0;i<n;i++){
        ll c = 0;
        for(int j=0;j<n;j++){
            c+=arr[i][j];
        }
        mi = min(mi,c);
        ma = max(ma,c);
    }
    ans += pow(ma-mi,2ll);
    mi=n,ma=0;
    for(int i=0;i<n;i++){
        ll c = 0;
        for(int j=0;j<n;j++){
            c+=arr[j][i];
        }
        mi = min(mi,c);
        ma = max(ma,c);
    }
    ans += pow(ma-mi,2ll);
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
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