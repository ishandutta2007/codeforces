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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int N;
char S[200][202];
int ress;
int res1[4];
int res2[4];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, loop;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        S[i][j] -= '0';
      }
    }
    for(loop=(0);loop<(2);loop++){
      ress = 0;
      if(S[0][1] == 1){
        arrInsert(ress, ress, res1, 0, res2, 1);
      }
      if(S[1][0] == 1){
        arrInsert(ress, ress, res1, 1, res2, 0);
      }
      if(S[N-1][N-2] == 0){
        arrInsert(ress, ress, res1, N-1, res2, N-2);
      }
      if(S[N-2][N-1] == 0){
        arrInsert(ress, ress, res1, N-2, res2, N-1);
      }
      if(ress <= 2){
        break;
      }
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          S[i][j] ^= 1;
        }
      }
    }
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(res1[i]+1);
      wt_L(' ');
      wt_L(res2[i]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20201018-2

// --- original code ---
// //no-unlocked
// int N; char S[200][202];
// int ress, res1[4], res2[4];
// {
//   REP(rd_int()){
//     rd(N,S(N));
//     rep(i,N) rep(j,N) S[i][j] -= '0';
//     rep(loop,2){
//       ress = 0;
//       if(S[0][1] == 1) arrInsert(ress, ress, res1, 0, res2, 1);
//       if(S[1][0] == 1) arrInsert(ress, ress, res1, 1, res2, 0);
//       if(S[N-1][N-2] == 0) arrInsert(ress, ress, res1, N-1, res2, N-2);
//       if(S[N-2][N-1] == 0) arrInsert(ress, ress, res1, N-2, res2, N-1);
//       if(ress <= 2) break;
//       rep(i,N) rep(j,N) S[i][j] ^= 1;
//     }
//     wt(ress);
//     rep(i,ress) wt(res1[i]+1, res2[i]+1);
//   }
// }