#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int Q;
int P[400000];
int V;
int TYPE;
long long A[400000];
long long C[400000];
long long W;
int up[20][400000];
int main(){
  int k, q;
  rd(Q);
  rd(A[0]);
  rd(C[0]);
  P[0] = -1;
  for(k=(0);k<(20);k++){
    up[k][0] = -1;
  }
  for(q=(0);q<(Q);q++){
    rd(TYPE);
    if(TYPE==1){
      int i;
      rd(P[q+1]);
      rd(A[q+1]);
      rd(C[q+1]);
      up[0][q+1] = P[q+1];
      for(i=(1);i<(20);i++){
        if(up[i-1][q+1] >= 0){
          up[i][q+1] =up[i-1][up[i-1][q+1]];
        }
        else{
          up[i][q+1] =-1;
        }
      }
    }
    else{
      long long cur;
      long long res1 = 0;
      long long res2 = 0;
      rd(V);
      rd(W);
      while(W && A[V]){
        cur = V;
        for(k=(20)-1;k>=(0);k--){
          if(up[k][cur] >= 0 && A[up[k][cur]] > 0){
            cur = up[k][cur];
          }
        }
        auto ao_dF3pO = (min_L(W, A[cur])* (-1));
        auto tU__gIr_ = (min_L(W, A[cur])* ( -1));
        auto a2conNHc = (min_L(W, A[cur])* ( 1));
        auto hCmBdyQB = (min_L(W, A[cur])* ( C[cur]));
        W+=ao_dF3pO;
        A[cur]+=tU__gIr_;
        res1+=a2conNHc;
        res2+=hCmBdyQB;
      }
      wt_L(res1);
      wt_L(' ');
      wt_L(res2);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //interactive
// int Q, P[4d5], V, TYPE; ll A[], C[], W;
// int up[20][4d5];
// {
//   rd(Q,A[0],C[0]);
//   P[0] = -1;
//   rep(k,20) up[k][0] = -1;
//   rep(q,Q){
//     rd(TYPE);
//     if(TYPE==1){
//       rd(P[q+1], A[q+1], C[q+1]);
//       up[0][q+1] = P[q+1];
//       rep(i,1,20) up[i][q+1] = if[up[i-1][q+1] >= 0, up[i-1][up[i-1][q+1]], -1];
//     } else {
//       ll cur, res1 = 0, res2 = 0;
//       rd(V, W);
//       while(W && A[V]){
//         cur = V;
//         rrep(k,20) if(up[k][cur] >= 0 && A[up[k][cur]] > 0) cur = up[k][cur];
//         (W, A[cur], res1, res2) += min(W,A[cur]) * (-1, -1, 1, C[cur]);
//       }
//       wt(res1, res2);
//     }
//   }
// }