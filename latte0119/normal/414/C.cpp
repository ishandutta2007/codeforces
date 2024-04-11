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
int A[1<<20];

int uku[25],beet[25];

vint init(int l,int r,int p){
    if(l+1==r){
        vint x={A[l]};
        return x;
    }
    vint a,b;
    a=init(l,(l+r)/2,p-1);
    b=init((l+r)/2,r,p-1);

    int cur=0;
    rep(i,a.size()){
        while(cur<b.size()&&b[cur]<a[i])cur++;
        uku[p]+=cur;
    }

    cur=0;
    rep(i,b.size()){
        while(cur<a.size()&&a[cur]<b[i])cur++;
        beet[p]+=cur;
    }

    vint c(a.size()+b.size());
    merge(all(a),all(b),c.begin());
    return c;
}

signed main(){
    scanf("%lld",&N);
    rep(i,1<<N)scanf("%lld",&A[i]);

    init(0,1<<N,N);

    int M;scanf("%lld",&M);
    rep(i,M){
        int q;scanf("%lld",&q);
        for(int j=0;j<=q;j++)swap(uku[j],beet[j]);
        printf("%lld\n",accumulate(uku,uku+N+1,0ll));
    }
    return 0;
}