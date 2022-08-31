#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
long long A[200000];
long long B[200000];
int ress;
char res[5000000];
long long cnt;
int main(){
  long long s;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(B[e98WHCEY]);
    }
  }
  if(N==1){
    if(A[0]==B[0]){
      wt_L("SMALL\n0\n");
      wt_L('\n');
    }
    else{
      wt_L("IMPOSSIBLE");
      wt_L('\n');
    }
    return 0;
  }
  for(;;){
    int i;
    for(i=(0);i<(N);i++){
      if(A[i] != B[i]){
        break;
      }
    }
    if(i==N){
      break;
    }
    for(i=(0);i<(N);i++){
      if(A[i] != B[N-1-i]){
        break;
      }
    }
    if(i==N){
      res[ress++] = 'R';
      break;
    }
    if(B[0] > B[N-1]){
      res[ress++] = 'R';
      reverse(B, B+N);
    }
    if(N==2){
      s = (B[1] -max_L(A[0], A[1])) / B[0];
      if(s <= 0){
        s = 1;
      }
      cnt += s;
      if(cnt <= 200000){
        int a2conNHc;
        for(a2conNHc=(0);a2conNHc<(s);a2conNHc++){
          res[ress++] = 'P';
        }
      }
      B[1] -= B[0] * s;
    }
    else{
      cnt++;
      res[ress++] = 'P';
      s = 0;
      for(i=(0);i<(N);i++){
        B[i] -= s;
        s += B[i];
      }
    }
    for(i=(0);i<(N);i++){
      if(B[i] <= 0){
        wt_L("IMPOSSIBLE");
        wt_L('\n');
        return 0;
      }
    }
    if(max_L(A[0], A[N-1])>max_L(B[0], B[N-1])){
      wt_L("IMPOSSIBLE");
      wt_L('\n');
      return 0;
    }
  }
  if(cnt > 200000){
    wt_L("BIG");
    wt_L('\n');
    wt_L(cnt);
    wt_L('\n');
  }
  else{
    reverse(res, res+ress);
    wt_L("SMALL");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N; ll A[2d5], B[2d5];
// 
// int ress; char res[5d6];
// ll cnt;
// {
//   ll s;
//   rd(N,A(N),B(N));
// 
//   if(N==1){
//     wt(if[A[0]==B[0], "SMALL\n0\n", "IMPOSSIBLE"]);
//     return 0;
//   }
// 
//   for(;;){
//     rep(i,N) if(A[i] != B[i]) break;
//     if(i==N) break;
//     rep(i,N) if(A[i] != B[N-1-i]) break;
//     if(i==N) res[ress++] = 'R', break;
// 
//     if(B[0] > B[N-1]){
//       res[ress++] = 'R';
//       reverse(B, B+N);
//     }
// 
//     if(N==2){
//       s = (B[1] - max(A[0], A[1])) / B[0];
//       if(s <= 0) s = 1;
//       cnt += s;
//       if(cnt <= 2d5) rep(s) res[ress++] = 'P';
//       B[1] -= B[0] * s;
//     } else {
//       cnt++;
//       res[ress++] = 'P';
//       s = 0;
//       rep(i,N){
//         B[i] -= s;
//         s += B[i];
//       }
//     }
// 
//     rep(i,N) if(B[i] <= 0) wt("IMPOSSIBLE"), return 0;
//     if(max(A[0],A[N-1]) > max(B[0],B[N-1])) wt("IMPOSSIBLE"), return 0;
//   }
// 
//   if(cnt > 2d5){
//     wt("BIG");
//     wt(cnt);
//   } else {
//     reverse(res, res+ress);
//     wt("SMALL");
//     wt(ress);
//     wt(res);
//   }
// }