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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int X;
int Y;
int A[100][100];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k;
    int l;
    int v[4];
    long long res = 0;
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(Y);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    for(i=(0);i<((divup_L(X,2)));i++){
      int j;
      for(j=(0);j<((divup_L(Y,2)));j++){
        int m;
        k = X - 1 - i;
        l = Y - 1 - j;
        if(i == k && j == l){
          continue;
        }
        if(i == k || j == l){
          res += abs(A[i][j]-A[k][l]);
          continue;
        }
        {
          auto hCmBdyQB = (A[i][j]);
          auto V9aVTaxx = ( A[i][l]);
          auto APIVbQlN = ( A[k][j]);
          auto YREPHmFM = ( A[k][l]);
          v[0] = hCmBdyQB;
          v[1] = V9aVTaxx;
          v[2] = APIVbQlN;
          v[3] = YREPHmFM;
        }
        sort(v, v+4);
        for(m=(0);m<(4);m++){
          res += abs(v[m] - v[1]);
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int X, Y, A[100][100];
// {
//   REP(rd_int()){
//     int k, l;
//     int v[4];
//     ll res = 0;
//     rd(X,Y,A(X,Y));
//     rep(i,X/+2) rep(j,Y/+2){
//       k = X - 1 - i;
//       l = Y - 1 - j;
//       if(i == k && j == l) continue;
//       if(i == k || j == l) res += abs(A[i][j]-A[k][l]), continue;
//       (v[0], v[1], v[2], v[3]) = (A[i][j], A[i][l], A[k][j], A[k][l]);
//       sort(v, v+4);
//       rep(m,4) res += abs(v[m] - v[1]);
//     }
//     wt(res);
//   }
// }