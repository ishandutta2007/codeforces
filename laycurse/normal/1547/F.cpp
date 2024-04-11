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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> void maxFactorList(int N, T res[]){
  int i;
  int j;
  if(N <= 2){
    for(i=(0);i<(N);i++){
      res[i] = i;
    }
    return;
  }
  res[0] = 0;
  res[1] = 1;
  for(i=2;i<N;i+=2){
    res[i] = 2;
  }
  for(i=3;i<N;i+=2){
    res[i] = i;
  }
  for(i=3;i*i<=N;i+=2){
    if(res[i]==i){
      for(j=i*i;j<=N;j+=i){
        if(res[j]==j){
          res[j] = i;
        }
      }
    }
  }
}
int N;
int A[200000];
int f[1000000+1];
int del(int &A, int f){
  int res = 0;
  while(A%f==0){
    A/=f;
    res++;
  }
  return res;
}
int main(){
  int Q5VJL1cS;
  maxFactorList(1000000+1, f);
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    int j;
    int k;
    int t;
    int res = 0;
    rd(N);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        rd(A[FmcKpFmN]);
      }
    }
    int t_ynMSdg;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type KrdatlYV;
    if(N==0){
      KrdatlYV = 0;
    }
    else{
      KrdatlYV = A[0];
      for(t_ynMSdg=(1);t_ynMSdg<(N);t_ynMSdg++){
        KrdatlYV = GCD_L(KrdatlYV, A[t_ynMSdg]);
      }
    }
    k =KrdatlYV;
    for(i=(0);i<(N);i++){
      A[i] /= k;
    }
    for(i=(0);i<(N);i++){
      while(A[i] > 1){
        k = f[A[i]];
        t = 1;
        del(A[i], k);
        for(j=(i+1);j<(2*N);j++){
          if(!del(A[(moddw_L(j,N))],k)){
            break;
          }
          t++;
        }
        for(j=(i)-1;j>=(-N);j--){
          if(!del(A[(moddw_L(j,N))],k)){
            break;
          }
          t++;
        }
        chmax(res, t);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], f[1d6+1];
// int del(int &A, int f){ int res = 0; while(A%f==0) A/=f, res++; return res; }
// {
//   maxFactorList(1d6+1, f);
//   REP(rd_int()){
//     int i, j, k, t, res = 0;
//     rd(N,A(N));
//     k = gcd(A(N));
//     rep(i,N) A[i] /= k;
//     rep(i,N) while(A[i] > 1){
//       k = f[A[i]];
//       t = 1;
//       del(A[i], k);
//       rep(j,i+1,2N){
//         if(!del(A[j%%N],k)) break;
//         t++;
//       }
//       rrep(j,-N,i){
//         if(!del(A[j%%N],k)) break;
//         t++;
//       }
//       res >?= t;
//     }
//     wt(res);
//   }
// }