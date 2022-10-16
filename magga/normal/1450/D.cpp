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
const ll MAXN = 400000;
const ll K = 20;
ll st[MAXN][K + 1];
ll lo[MAXN+1];
void pre(){
    lo[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lo[i] = lo[i/2] + 1;
}
void construct(vector<int>arr){
    int N = arr.size();
    for (int i = 0; i < N; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
ll query(int L,int R){
    int j = lo[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
bool f[500001];
bool check(vector<int> &arr,int n,int k){
    if(k>n){
        return 1;
    }
    for(int i=0;i<=n-k+1;i++){
        f[i]=0;
    }
    for(int i=0;i<n-k+1;i++){
        f[   query(i,i+k-1)     ] = 1;
    }
    for(int i=1;i<=n-k+1;i++){
        if( !f[i] ){
            return false;
        }
    }
    return true;
}
void solve(){
    ll n;cin>>n;
    set<int>s1;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s1.insert(arr[i]);
    }
    construct(arr);
    int start = 2,end = n+1,ans = n,mid;
    while(start<=end){
        mid = (start+end)/2;
        if(check(arr,n,mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid+1;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==1 && s1.size()==n){
            cout<<1;
        }else if(i==1){
            cout<<0;
        }else if(i>=ans){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<"\n";
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