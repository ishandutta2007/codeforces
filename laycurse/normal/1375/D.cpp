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
int A[1000];
int ress;
int res[3000];
int cnt[1001];
int getm(void){
  int i;
  for(i=(0);i<(N+1);i++){
    cnt[i] = 0;
  }
  for(i=(0);i<(N);i++){
    cnt[A[i]] = 1;
  }
  for(i=(0);i<(N+1);i++){
    if(cnt[i]==0){
      break;
    }
  }
  return i;
}
int main(){
  int FmcKpFmN;
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    int i;
    int j;
    int k;
    rd(N);
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(N);KrdatlYV++){
        rd(A[KrdatlYV]);
      }
    }
    ress = 0;
    for(;;){
      for(i=(1);i<(N);i++){
        if(A[i-1] > A[i]){
          break;
        }
      }
      if(i==N){
        break;
      }
      j = k = getm();
      if(j==N){
        for(j=(0);j<(N);j++){
          if(A[j] != j){
            break;
          }
        }
      }
      A[j] = k;
      res[ress++] = j;
    }
    wt_L(ress);
    wt_L('\n');
    {
      int jbtyPBGc;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(jbtyPBGc=(0);jbtyPBGc<(ress-1);jbtyPBGc++){
          wt_L(res[jbtyPBGc]+1);
          wt_L(' ');
        }
        wt_L(res[jbtyPBGc]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1000];
// int ress, res[3000];
// 
// int cnt[1001];
// int getm(void){
//   int i;
//   rep(i,N+1) cnt[i] = 0;
//   rep(i,N) cnt[A[i]] = 1;
//   rep(i,N+1) if(cnt[i]==0) break;
//   return i;
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N,A(N));
//     ress = 0;
// 
//     for(;;){
//       rep(i,1,N) if(A[i-1] > A[i]) break;
//       if(i==N) break;
// 
//       j = k = getm();
//       if(j==N) rep(j,N) if(A[j] != j) break;
//       A[j] = k;
//       res[ress++] = j;
//     }
// 
//     wt(ress);
//     wt(res(ress)+1);
//   }
// }