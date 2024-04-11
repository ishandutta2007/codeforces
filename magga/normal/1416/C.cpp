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
bool bit(long long int n,int i){
    return ( (n>>i) & 1 );
}
void solve(){
    ll n,d;cin>>n;
    vector<long long int>v;
    for(int i=0;i<n;i++){
        cin>>d;
        v.push_back(d);
    }
    v.push_back(-1);
    long long int ans = 0;
    int z=0,o=0;
    long long int dp1,dp2;
    long long int oi = 0;
    vector<long long int>a,b,t;
    for(int i=31;i>=0;i--){
        z=0;
        o=0;
        dp1=0;
        dp2=0;
        a.clear();
        b.clear();
        t.clear();
        for(int j=0;j<v.size();j++){
            if(v[j]==-1){
                z = 0;
                o = 0;
                for(auto i:a){
                    t.push_back(i);
                }
                if(a.size()!=0)
                    t.push_back(-1);
                for(auto i:b){
                    t.push_back(i);
                }
                if(b.size()!=0)
                    t.push_back(-1);
                a.clear();
                b.clear();
                continue;
            }
            if(bit(v[j],i)){
                dp2+=z;
                o++;
                a.push_back(v[j]);
            }else{
                dp1+=o;
                z++;
                b.push_back(v[j]);
            }
        }
        oi += min(dp1,dp2);
        if(dp2<dp1){
           ans |= (1<<i); 
        }
        v = t;
    }
    cout<<oi<<" "<<ans<<"\n";
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