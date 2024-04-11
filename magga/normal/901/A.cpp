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
void solve(){
    ll n;cin>>n;
    ll arr[n+1];
    for(int i=0;i<=n;i++)   cin>>arr[i];
    vector<long long int> ans[2];
    ans[0].pb(0);
    ans[1].pb(0);
    vector<long long int>tree[n+1];
    tree[0].push_back(1);
    int oo = 2;
    for(int i = 1;i<=n;i++){
        auto j = tree[i-1].back();
        auto beck = tree[i-1][0];
        for(int k=0;k<arr[i]-1;k++){ 
            tree[i].push_back(oo);
            oo++;
            ans[0].push_back(j);
            ans[1].push_back(j);
        }  
        if(arr[i]!=1 && arr[i-1]!=1){
            tree[i].push_back(oo);
            oo++;
            ans[0].push_back(j);
            ans[1].push_back(beck);
        }else{
            tree[i].push_back(oo);
            oo++;
            ans[0].push_back(j);
            ans[1].push_back(j);
        }
    }
    if(ans[0]==ans[1]){
        cout<<"perfect"<<"\n";
        return;
    }else{
        cout<<"ambiguous"<<"\n";
    }
    for(auto i:ans[0]){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(auto i:ans[1]){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}