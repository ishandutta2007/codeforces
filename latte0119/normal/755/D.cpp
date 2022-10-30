#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct BIT{
    int N;
    vector<int>dat;
    void init(int n){
        N=n;
        dat.resize(N+1);
    }
    BIT(){}
    BIT(int n){init(n);}

    void add(int k,int x){
        for(k++;k<=N;k+=k&-k)dat[k]+=x;
    }
    int sum(int k){
        int ret=0;
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

signed main(){
    int N,K;
    cin>>N>>K;
    K=min(K,N-K);
    BIT bit;
    bit.init(2*N);

    int cnt=1;
    int v=0;

    rep(i,N){
        cnt+=bit.sum(v+K-1)-bit.sum(v)+1;

        bit.add(v,1);
        bit.add(v+N,1);
        v=(v+K)%N;
        bit.add(v,1);
        bit.add(v+N,1);
        printf("%lld ",cnt);
    }
    puts("");
    return 0;
}