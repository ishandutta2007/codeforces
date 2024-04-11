#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mode;
    int X;
    rd(X);
    int Y;
    rd(Y);
    int res = 0;
    int tmp;
    char S[X][Y];
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(Y);RZTsC2BF++){
          rd(S[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    int A[X][Y];
    for(mode=(0);mode<(2);mode++){
      int i, j;
      for(i=(0);i<(X);i++){
        int j;
        for(j=(0);j<(Y);j++){
          A[i][j] = 0;
          if((i+j)%2==mode && S[i][j]=='1'){
            A[i][j] = 1;
          }
        }
      }
      for(j=(0);j<(Y);j++){
        if(j >= 2){
          for(i=(0);i<(X);i++){
            chmax(A[i][j], A[i][j] + A[i][j-2]);
          }
        }
        if(j >= 1){
          for(i=(0);i<(X);i++){
            if(i-1 >= 0){
              chmax(A[i][j], A[i-1][j-1]);
            }
            if(i+1 <  X){
              chmax(A[i][j], A[i+1][j-1]);
            }
          }
        }
      }
      tmp = 0;
      for(i=(0);i<(X);i++){
        for(j=(0);j<(Y);j++){
          chmax(tmp, A[i][j]);
        }
      }
      res += tmp;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @X, @Y, res = 0, tmp;
//   char @S[X][Y]; int A[X][Y];
// 
//   rep(mode,2){
//     rep(i,X) rep(j,Y){
//       A[i][j] = 0;
//       if((i+j)%2==mode && S[i][j]=='1') A[i][j] = 1;
//     }
//     rep(j,Y){
//       if(j >= 2) rep(i,X) A[i][j] >?= A[i][j] + A[i][j-2];
//       if(j >= 1) rep(i,X){
//         if(i-1 >= 0) A[i][j] >?= A[i-1][j-1];
//         if(i+1 <  X) A[i][j] >?= A[i+1][j-1];
//       }
//     }
//     tmp = 0;
//     rep(i,X) rep(j,Y) tmp >?= A[i][j];
//     res += tmp;
//   }
//   wt(res);
// }