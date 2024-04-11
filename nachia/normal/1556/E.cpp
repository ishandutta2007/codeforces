
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


template<
  class S,
  S(*op)(S a,S b),
  S(*e)()
>
struct segtree {
  int N;
  vector<S> V;
  segtree(int n=0){
    N=1; while(N<n) N*=2;
    V.assign(N*2,e());
  }
  segtree(const vector<S>& v)
    : segtree(v.size()){
    rep(i,v.size()) V[N+i]=v[i];
    for(int i=N-1; i>=1; i--) V[i]=op(V[i*2],V[i*2+1]);
  }
  void set(int p,S v){
    p+=N; V[p]=v;
    while(p!=1){ p/=2; V[p]=op(V[p*2],V[p*2+1]); }
  }
  S get(int p){ return V[N+p]; }
  S prod(int l,int r){
    l+=N; r+=N;
    S resl=e(), resr=e();
    while(r-l){
      if(l&1) resl=op(resl,V[l++]);
      if(r&1) resr=op(V[--r],resr);
      l/=2; r/=2;
    }
    return op(resl,resr);
  }
  template<class Cmp>
  int max_right(int l,Cmp cmp){
    S x=e(); l+=N; int r=N+N;
    while(l<r){
      if(l&1){
        S tmp=op(x,V[l]);
        if(!cmp(tmp)) break; else{ l++; x=tmp; }
      }
      l/=2; r/=2;
    }
    if(l>=r) return N;
    while(l<N){
      S tmp=op(x,V[l*=2]);
      if(cmp(tmp)){ l++; x=tmp; }
    }
    return l-N;
  }
  template<class Cmp>
  int min_left(int r,Cmp cmp){
    S x=e(); r+=N; int l=N;
    while(l<r && r!=1){
      if(r&1){
        S tmp=op(V[r-1],x);
        if(!cmp(tmp)) break; else{ r--; x=tmp; }
      }
      l/=2; r/=2;
    }
    if(l>=r) return 0;
    while(r<=N){
      S tmp=op(V[(r*=2)-1],x);
      if(cmp(tmp)){ r--; x=tmp; }
    }
    return r-N;
  }
};



const i64 INF = 1001001001001001001;

namespace RQ{
  struct S { i64 l,r; };
  S op(S l, S r) { return { min(l.l,r.l), max(l.r,r.r) }; }
  S e() { return { INF, -INF }; }
  using RQ = segtree<S, op, e>;
}


void testcase(){
  int N,Q; cin >> N >> Q;
  vector<i64> A(N);
  rep(i,N){ int a; cin >> a; A[i] -= a; }
  rep(i,N){ int a; cin >> a; A[i] += a; }
  vector<i64> sumA(N+1,0);
  rep(i,N) sumA[i+1] = sumA[i] + A[i];
  RQ::RQ rq(N+1);
  rep(i,N+1) rq.set(i,{sumA[i],sumA[i]});

  rep(i,Q){
    int l,r; cin >> l >> r; l--;
    if(sumA[l] != sumA[r]){ cout << "-1\n"; continue; }
    auto g = rq.prod(l,r+1);
    if(g.l < sumA[l]){ cout << "-1\n"; continue; }
    cout << (g.r - sumA[l]) << "\n";
  }
}

int main(){
  //int T; cin >> T;
  //rep(t,T)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;