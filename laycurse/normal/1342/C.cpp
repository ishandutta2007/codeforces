#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class T, class U> inline T LCM_L(T a, U b){
  return a/GCD_L(a,b)*b;
}
int A;
int B;
int Q;
long long L;
long long R;
long long res[500];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int q;
    rd(A);
    rd(B);
    rd(Q);
    if(A > B){
      swap(A, B);
    }
    ;
    int m =LCM_L(A, B);
    for(q=(0);q<(Q);q++){
      int i;
      rd(L);L += (-1);
      rd(R);
      res[q] = R - L;
      for(i=(0);i<(B);i++){
        if(R >= i){
          res[q] -= (R - i) / m + 1;
        }
        if(L >= i){
          res[q] += (L - i) / m + 1;
        }
      }
    }
    {
      int KrdatlYV;
      if(Q==0){
        wt_L('\n');
      }
      else{
        for(KrdatlYV=(0);KrdatlYV<(Q-1);KrdatlYV++){
          wt_L(res[KrdatlYV]);
          wt_L(' ');
        }
        wt_L(res[KrdatlYV]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int A, B, Q; ll L, R;
// ll res[500];
// {
//   REP(rd_int()){
//     rd(A,B,Q);
//     sortE(A,B);
//     int m = lcm(A,B);
//     rep(q,Q){
//       rd(L--,R);
//       res[q] = R - L;
//       rep(i,B){
//         if(R >= i) res[q] -= (R - i) / m + 1;
//         if(L >= i) res[q] += (L - i) / m + 1;
//       }
//     }
//     wt(res(Q));
//   }
// }