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
int P[500];
int res[500][500];
int sz;
int arr[500];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    sz = 0;
    for(j=(0);j<(N);j++){
      if(P[j] >= N-i){
        arr[sz++] = P[j];
      }
    }
    for(j=(0);j<(i+1);j++){
      res[N-1-i+j][j] = arr[j];
    }
  }
  for(i=(0);i<(N);i++){
    {
      int ao_dF3pO;
      if(i+1==0){
        wt_L('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(i+1-1);ao_dF3pO++){
          wt_L(res[i][ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(res[i][ao_dF3pO]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, P[500];
// int res[500][500];
// int sz, arr[500];
// {
//   rd(N,P(N));
//   rep(i,N){
//     sz = 0;
//     rep(j,N) if(P[j] >= N-i) arr[sz++] = P[j];
//     rep(j,i+1) res[N-1-i+j][j] = arr[j];
//   }
//   rep(i,N) wt(res[i](i+1));
// }