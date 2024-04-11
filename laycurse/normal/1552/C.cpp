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
int K;
int X[300];
int Y[300];
int sz;
int r[300];
int v[300];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    int m;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(K);cTE1_r3A++){
        rd(X[cTE1_r3A]);X[cTE1_r3A] += (-1);
        rd(Y[cTE1_r3A]);Y[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(2*N);i++){
      v[i] = 0;
    }
    for(i=(0);i<(K);i++){
      v[X[i]] = v[Y[i]] = 1;
    }
    sz = 0;
    for(i=(0);i<(2*N);i++){
      if(v[i]==0){
        r[sz++] = i;
      }
    }
    for(i=(0);i<(sz/2);i++){
      auto V9aVTaxx = ((r[i]));
      auto APIVbQlN = (( r[i+sz/2]));
      X[K+i]=V9aVTaxx;
      Y[K+i]=APIVbQlN;
    }
    for(i=(0);i<(N);i++){
      if(X[i] > Y[i]){
        swap(X[i], Y[i]);
      }
      ;
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        m = 0;
        if(X[i] < X[j]  &&  X[j] < Y[i]){
          m ^= 1;
        }
        if(X[i] < Y[j]  &&  Y[j] < Y[i]){
          m ^= 1;
        }
        res += m;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K, X[300], Y[300];
// int sz, r[300], v[300];
// {
//   REP(rd_int()){
//     int res = 0, m;
//     rd(N,K,(X--,Y--)(K));
//     rep(i,2*N) v[i] = 0;
//     rep(i,K) v[X[i]] = v[Y[i]] = 1;
//     sz = 0;
//     rep(i,2*N) if(v[i]==0) r[sz++] = i;
//     rep(i,sz/2) (X[K+i], Y[K+i]) = (r[i], r[i+sz/2]);
//     // wt(K,sz);
//     rep(i,N) sortE(X[i], Y[i]);
//     rep(i,N) rep(j,i+1,N){
//       m = 0;
//       if(X[i] < X[j] < Y[i]) m ^= 1;
//       if(X[i] < Y[j] < Y[i]) m ^= 1;
//       // wt(X[i],Y[i],":",X[j],Y[j],":",m);
//       res += m;
//     }
//     wt(res);
//   }
// }