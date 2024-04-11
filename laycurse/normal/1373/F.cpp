#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[1000000];
int B[1000000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int st = 0;
    int nw;
    int rem;
    int nd;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);
      }
    }
    k =min_L(A[st%N], B[st%N]);
    nd = A[st%N] - k;
    rem = B[st%N] - k;
    nw = st + 1;
    while(st < 2*N){
      if(nw == st + N){
        if(rem >= nd){
          wt_L("YES");
          wt_L('\n');
        }
        else{
          wt_L("NO");
          wt_L('\n');
        }
        goto Q5VJL1cS;
      }
      k =max_L(0, min_L(A[nw%N]-rem, B[nw%N]));
      if(rem + k < A[nw%N]){
        st = nw;
        k =min_L(A[st%N], B[st%N]);
        nd = A[st%N] - k;
        rem = B[st%N] - k;
        nw = st + 1;
        continue;
      }
      rem = B[nw%N] - k;
      nw++;
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1d6], B[1d6];
// {
//   REP(rd_int()){
//     int st = 0, nw, rem, nd, k;
//     rd(N,A(N),B(N));
// 
//     k = min(A[st%N], B[st%N]);
//     nd = A[st%N] - k; rem = B[st%N] - k;
//     nw = st + 1;
//     while(st < 2*N){
//       if(nw == st + N){
//         wt(if[rem >= nd, "YES", "NO"]);
//         break_continue;
//       }
//       k = max(0, min(A[nw%N]-rem, B[nw%N]));
//       if(rem + k < A[nw%N]){
//         st = nw;
//         k = min(A[st%N], B[st%N]);
//         nd = A[st%N] - k; rem = B[st%N] - k;
//         nw = st + 1;
//         continue;
//       }
//       rem = B[nw%N] - k;
//       nw++;
//     }
//     wt("NO");
//   }
// }