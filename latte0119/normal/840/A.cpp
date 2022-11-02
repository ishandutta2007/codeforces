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

int N;
int A[222222];

int latte[222222];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    vpint ord;
    rep(i,N){
        int b;cin>>b;
        ord.pb({b,i});
    }
    sort(all(ord));
    rep(i,N)latte[ord[i].se]=i;

    sort(A,A+N);
    reverse(A,A+N);
    rep(i,N){
        if(i)printf(" ");
        printf("%lld",A[latte[i]]);
    }
    puts("");
}