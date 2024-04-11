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
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<1<<" "<<1<<"\n";
        cout<<-1*arr[0]<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
        return;
    }
    vector<long long int>crr(n);
    vector<long long int>brr(n);
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
        crr[i]=-1*arr[i];
    }
    cout<<1<<" "<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<crr[i]*n<<" ";
        arr[i]+=crr[i]*n;
    }
    cout<<"\n";
    cout<<2<<" "<<n<<"\n";
    for(int i=1;i<n;i++){
        cout<<brr[i]*(n-1)<<" ";
        arr[i]+=brr[i]*(n-1);
    }
    cout<<"\n";
    cout<<1<<" "<<1<<"\n";
    cout<<-1*arr[0]<<"\n";
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