#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

template<class T>
struct  BinaryIndexedTree{
    int n;
    vector<T>dat;

    BinaryIndexedTree(int n=0):n(n),dat(n+1){}

    void add(int k,T x){
        for(k++;k<=n;k+=k&-k)dat[k]+=x;
    }
    T sum(int k){
        T ret{};
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N;
int A[222222];
int Q;
int K[222222],pos[222222];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    scanf("%lld",&Q);
    rep(i,Q)scanf("%lld%lld",&K[i],&pos[i]),K[i]--,pos[i]--;

    vint ord(N);iota(all(ord),0);
    sort(all(ord),[&](int i,int j){
        if(A[i]==A[j])return i<j;
        return A[i]>A[j];
    });

    vector<vint>bucket(N);
    rep(i,Q)bucket[K[i]].pb(i);

    BinaryIndexedTree<int>bit(N+114);
    vint ans(Q);

    rep(i,N){
        bit.add(ord[i],1);

        for(auto j:bucket[i]){
            int lb=0,ub=N;
            while(ub-lb>1){
                int mid=(ub+lb)/2;
                if(bit.sum(mid-1)<=pos[j])lb=mid;
                else ub=mid;
            }
            ans[j]=A[lb];
        }
    }
    rep(i,Q)printf("%lld\n",ans[i]);
    return 0;
}