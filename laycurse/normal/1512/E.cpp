#pragma GCC optimize ("Ofast")
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
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
int N;
int L;
int R;
int S;
int P[500];
int us[501];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int mx;
    rd(N);
    rd(L);L += (-1);
    rd(R);R += (-1);
    rd(S);
    for(i=(L);i<(R+1);i++){
      P[i] = i-L+1;
      S -= P[i];
    }
    if(S < 0){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    mx = N - (R - L + 1);
    for(i=(R+1)-1;i>=(L);i--){
      auto t_ynMSdg = (min_L(S, mx)* (1));
      auto KrdatlYV = (min_L(S, mx)* ( -1));
      P[i]+=t_ynMSdg;
      S+=KrdatlYV;
    }
    if(S){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(1);i<(N+1);i++){
      us[i] = 0;
    }
    for(i=(L);i<(R+1);i++){
      us[P[i]] = 1;
    }
    mx = 1;
    for(i=(0);i<(N);i++){
      if(i < L || i > R){
        while(us[mx]){
          mx++;
        }
        us[mx] = 1;
        P[i] = mx;
      }
    }
    {
      int jbtyPBGc;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(jbtyPBGc=(0);jbtyPBGc<(N-1);jbtyPBGc++){
          wt_L(P[jbtyPBGc]);
          wt_L(' ');
        }
        wt_L(P[jbtyPBGc]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, L, R, S, P[500], us[501];
// {
//   REP(rd_int()){
//     int i, mx;
//     rd(N, L--, R--, S);
//     rep(i,L,R+1) P[i] = i-L+1, S -= P[i];
//     if(S < 0) wt(-1), continue;
//     mx = N - (R - L + 1);
//     rrep(i,L,R+1) (P[i], S) += min(S,mx) * (1, -1);
//     if(S) wt(-1), continue;
//     rep(i,1,N+1) us[i] = 0;
//     rep(i,L,R+1) us[P[i]] = 1;
//     mx = 1;
//     rep(i,N) if(i < L || i > R){
//       while(us[mx]) mx++;
//       us[mx] = 1;
//       P[i] = mx;
//     }
//     wt(P(N));
//   }
// }