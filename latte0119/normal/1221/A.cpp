#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int Q;

int N;

void solve(){
    scanf("%lld",&N);
    vint cnt(33);
    rep(i,N){
        int a;scanf("%lld",&a);
        cnt[__lg(a)]++;
    }
    
    for(int i=0;i<11;i++){
        cnt[i+1]+=cnt[i]/2;
    }
    if(cnt[11])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    scanf("%lld",&Q);
    while(Q--)solve();
    
}