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
void pre(){}
bool pro (ll h,ll c,ll n, ll t){
    if( (2*n+3)*(t*(n*2+1)-n*h-n*c-h) >= (2*n+1)*((n+1)*h+(n+1)*c+h-(2*n+3)*t) ){
        return true;
    }
    return false;
}
void solve(){
    ll h,c,t;cin>>h>>c>>t;
    long double mid = (h+c)/2.0;
    if(t>=h){
        cout<<1<<"\n";
        return;
    }
    if(t<=mid){
        cout<<2<<"\n";
        return;
    }
    ll oo = (h - t)*1.0/(2*t - h - c );
    if(pro(h,c,oo,t)){
        cout<<2*oo+1<<"\n";
    }else{
        cout<<2*oo+3<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<" :";
       	solve();
    }   
}