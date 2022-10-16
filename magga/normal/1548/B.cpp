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
const long long int N = 3e5;
long long int k;
long long int t[2*N];
long long int combine(long long int a,long long int b){
    return __gcd(a,b);
}
void build(){
    for(long long int i=k-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    for(t[p+=k]=value;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(long long int l,long long int r){
    long long int ret = 0;
    for(l+=k,r+=k;l<r;l>>=1,r>>=1){
        if(l&1) ret=combine(ret,t[l++]);
        if(r&1) ret=combine(t[--r],ret);
    }
    return ret;
}

void pre(){}
void solve(){
    int n;cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int brr[n-1];
    k = n-1;
    for(int i=0;i<n;i++){ brr[i] = abs(arr[i+1]-arr[i]); t[k+i] = brr[i]; } 
    build();
    int ans = 1;
    int j = 0;
    for(int i=0;i<n-1;i++){
        j = max(j,i);
        auto curr = query(i,j+1);
        while(j<n-1 && __gcd(curr,brr[j])!=1){
            curr=__gcd(curr,brr[j]);
            j++;
        }
        //cout<<i<<" "<<j<<" "<<curr<<"\n";
        ans = max(ans,j-i+1);
    }
    cout<<ans<<"\n";
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