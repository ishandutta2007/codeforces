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
template<class T, class S> inline int Digit_L(T n, S b){
  int res = 0;
  while(n){
    res++;
    n /= b;
  }
  return res;
}
template<class T, class S> inline int Digit_L(T n, S res[]){
  int sz = 0;
  while(n){
    res[sz++] = n % 10;
    n /= 10;
  }
  return sz;
}
template<class T, class S> inline T pow_L(T a, S b){
  T res = 1;
  res = 1;
  for(;;){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    if(b==0){
      break;
    }
    a *= a;
  }
  return res;
}
inline double pow_L(double a, double b){
  return pow(a,b);
}
int S;
int N;
int sz;
int d[10];
int ds;
int ress;
int res[100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(S);
    rd(N);
    sz =Digit_L(S,d);
    int cTE1_r3A;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type RZTsC2BF;
    if(sz==0){
      RZTsC2BF = 0;
    }
    else{
      RZTsC2BF = d[0];
      for(cTE1_r3A=(1);cTE1_r3A<(sz);cTE1_r3A++){
        RZTsC2BF += d[cTE1_r3A];
      }
    }
    ds =RZTsC2BF;
    while(ds < N){
      int i;
      for(i=(1);i<(sz);i++){
        if(d[i]){
          d[i]--;
          d[i-1]+=10;
          ds += 9;
          break;
        }
      }
    }
    ress = 0;
    for(i=(sz)-1;i>=(0);i--){
      int hCmBdyQB;
      for(hCmBdyQB=(0);hCmBdyQB<(d[i]);hCmBdyQB++){
        if(ress < N){
          res[ress++] =(pow_L(10,i));
          S -=(pow_L(10,i));
        }
      }
    }
    res[ress-1] += S;
    {
      int YREPHmFM;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(ress-1);YREPHmFM++){
          wt_L(res[YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[YREPHmFM]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210904-1

// --- original code ---
// //no-unlocked
// int S, N;
// int sz, d[10], ds;
// int ress, res[100];
// {
//   REP(rd_int()){
//     rd(S,N);
//     sz = Digit(S,d);
//     ds = sum(d(sz));
//     while(ds < N){
//       rep(i,1,sz) if(d[i]){
//         d[i]--;
//         d[i-1]+=10;
//         ds += 9;
//         break;
//       }
//     }
//     ress = 0;
//     rrep(i,sz) rep(d[i]) if(ress < N){
//       res[ress++] = 10 ** i;
//       S -= 10 ** i;
//     }
//     res[ress-1] += S;
//     wt(res(ress));
//   }
// }