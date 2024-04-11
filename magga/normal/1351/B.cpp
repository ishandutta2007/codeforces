#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll a1,b1,c1,d1;
    a1=max(a,b);
    b1=min(a,b);
    c1=max(c,d);
    d1=min(c,d);
    if(a1==c1 && b1+d1==a1){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
    //ll oo = 0,co = 0;
    //oo = max(a,b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
//        cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}