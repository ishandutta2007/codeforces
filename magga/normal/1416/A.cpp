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
    int n;cin>>n;
    long long int arr[n];
    vector<int> m[n+1];
    for(int i=1;i<=n;i++) m[i].pb(0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]].pb(i+1);
    }
    for(int i=1;i<=n;i++) m[i].pb(n+1);
    int ans[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    int k = n;
    vector<int>v;
    for(int i=1;i<=n;i++){
        int oo = 0;
        for(int j=0;j<m[i].size()-1;j++){
            oo = max(oo,m[i][j+1]-m[i][j]);
        }
        while(k>0 && k>=oo){
            ans[k]=i;
            k--;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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