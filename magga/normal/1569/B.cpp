
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
    int n;cin>>n;
    string s;cin>>s;
    vector<int>loss;
    for(int i=0;i<n;i++){
        if(s[i]=='2'){
            loss.push_back(i);
        }
    }
    vector<vector<char>>ans(n,vector<char>(n,'='));
    if(loss.size()==1 || loss.size()==2){
        cout<<"NO"<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        ans[i][i]='X';
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<loss.size();i++){
        ans[loss[i]][loss[(i+1)%loss.size()]]='+';
        ans[loss[(i+1)%loss.size()]][loss[i]]='-';
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j;
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