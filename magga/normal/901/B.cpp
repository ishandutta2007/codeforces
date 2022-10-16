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
vector<long long int>b{1};
vector<long long int>a{0,1};
void pre(){
    vector<long long int>ret=b;
    ret.push_back(0);
    ret.push_back(0);
    for(int i=0;i<a.size();i++){
        ret[i+1] += a[i];
        ret[i+1]%=2;
    }
    b = a ;
    a = ret;
}
void ans(int a){
    for(int i=0;i<a-1;i++){
        pre();
    }
}
void solve(){
    ll n;cin>>n;
    ans(n);
    cout<<a.size()-1<<"\n";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<b.size()-1<<"\n";
    for(auto i:b){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}