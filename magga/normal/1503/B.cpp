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
int inp(){
    int c;cin>>c;
    return c;
}
void output(int a,pii c){
    cout<<a<<" "<<c.F<<" "<<c.S<<"\n";
    cout.flush();
}
void solve(){
    ll n;cin>>n;
    vector<pii>odd,even;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==0){
                even.push_back({i,j});
            }else{
                odd.push_back({i,j});
            }
        }
    }
    int c = n*n;
    for(int i=0;i<c;i++){
        auto j = inp();
        if(odd.size()==0){
            if(j==1){
                output(2,even.back());
                even.pop_back();
            }else{
                output(1,even.back());
                even.pop_back();
            }
            continue;
        }
        if(even.size()==0){
            if(j==1){
                output(3,odd.back());
                odd.pop_back();
            }else{
                output(1,odd.back());
                odd.pop_back();
            }
            continue;
        }
        if(j!=3 && odd.size()>0){
            output(3,odd.back());
            odd.pop_back();
        }else if(j!=2 && even.size()>0){
            output(2,even.back());
            even.pop_back();
        }
    }

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