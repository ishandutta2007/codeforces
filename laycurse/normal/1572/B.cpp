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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[200000];
int res[200000];
int ress;
void doit(int i){
  res[ress++] = i;
  auto Lj4PdHRW = (A[i]^A[i+1]^A[i+2]);
  A[i]=Lj4PdHRW;
  A[i+1]=Lj4PdHRW;
  A[i+2]=Lj4PdHRW;
}
int main(){
  int KL2GvlyY;
  int Q5VJL1cS = rd_int();
  for(KL2GvlyY=(0);KL2GvlyY<(Q5VJL1cS);KL2GvlyY++){
    int x;
    int y;
    rd(N);
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
        rd(A[RZTsC2BF]);
      }
    }
    int WYIGIcGE;
    int t_ynMSdg;
    if(N==0){
      t_ynMSdg = 0;
    }
    else{
      t_ynMSdg = A[0];
      for(WYIGIcGE=(1);WYIGIcGE<(N);WYIGIcGE++){
        t_ynMSdg += A[WYIGIcGE];
      }
    }
    if(t_ynMSdg%2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    ress = 0;
    for(x=(0);x<(N);x++){
      if(A[x] == 1){
        break;
      }
    }
    for(y=(x);y<(N);y++){
      if(A[y] == 0){
        break;
      }
    }
    for(;;){
      if(x >= N){
        break;
      }
      if(x==0 && y==N){
        wt_L("NO");
        wt_L('\n');
        goto e98WHCEY;
      }
      if(x >= y){
        for(x=(x);x<(N);x++){
          if(A[x] == 1){
            break;
          }
        }
        for(y=(x);y<(N);y++){
          if(A[y] == 0){
            break;
          }
        }
        continue;
      }
      if( (y - x) % 2 == 0 ){
        if(x){
          doit(x-1);
          x += 2;
        }
        else{
          doit(y-2);
          y -= 2;
        }
      }
      else{
        doit(y-1);
        for(y=(max_L(x, y-2));y<(N);y++){
          if(A[y] == 0){
            break;
          }
        }
      }
    }
    wt_L("YES");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    {
      int BUotOFBp;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(BUotOFBp=(0);BUotOFBp<(ress-1);BUotOFBp++){
          wt_L(res[BUotOFBp]+1);
          wt_L(' ');
        }
        wt_L(res[BUotOFBp]+1);
        wt_L('\n');
      }
    }
    e98WHCEY:;
  }
  return 0;
}
// cLay version 20210917-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], res[], ress;
// 
// void doit(int i){
//   res[ress++] = i;
//   (A[i], A[i+1], A[i+2]) = A[i]^A[i+1]^A[i+2];
// }
// 
// {
//   REP(rd_int()){
//     int x, y;
//     rd(N,A(N));
// 
//     if(sum(A(N))%2) wt("NO"), continue;
//     ress = 0;
// 
//     rep(x,N) if(A[x] == 1) break;
//     rep(y,x,N) if(A[y] == 0) break;
//     for(;;){
//       if(x >= N) break;
//       if(x==0 && y==N) wt("NO"), break_continue;
// 
//       if(x >= y){
//         rep(x,x,N) if(A[x] == 1) break;
//         rep(y,x,N) if(A[y] == 0) break;
//         continue;
//       }
// 
//       if( (y - x) % 2 == 0 ){
//         if(x) doit(x-1), x += 2;
//         else doit(y-2), y -= 2;
//       } else {
//         doit(y-1);
//         rep(y,max(x,y-2),N) if(A[y] == 0) break;
//       }
//     }
// 
//     wt("YES");
//     wt(ress);
//     wt(res(ress)+1);
//   }
// }