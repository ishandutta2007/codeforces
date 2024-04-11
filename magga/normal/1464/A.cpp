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
    ll n,a,b,m;cin>>n>>m;
    map<int,int>f;
    set<int>s;
    int ans = 0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a!=b){
            ans++;
        }else{
            s.insert(a);
        }
        f[a]=b;
        //f[a]=0;
    }
    for(auto i=0;i<n;i++){
        int lst = i,curr;
        if(s.find(i)!=s.end() || f.find(i)==f.end()){
            continue;
        }
        //cout<<i<<" =";
        s.insert(i);
        curr = f[i];
        while( f.find(curr)!=f.end() && curr!=lst ){
            s.insert(curr);
            curr = f[curr];
        }
        if(curr==lst){
            //cout<<curr<<" ";
            ans++;
        }
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