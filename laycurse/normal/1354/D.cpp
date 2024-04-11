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
int Q;
int A[1000000];
int K[1000000];
int main(){
  int i;
  int res;
  int rem;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
      rd(K[e98WHCEY]);
    }
  }
  rem = N;
  for(i=(0);i<(Q);i++){
    if(K[i] > 0){
      rem++;
    }
    else{
      rem--;
    }
  }
  if(rem==0){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  int WYIGIcGE;
  int t_ynMSdg;
  int KrdatlYV;
  WYIGIcGE = 1;
  t_ynMSdg = N;
  while(WYIGIcGE < t_ynMSdg){
    if((WYIGIcGE + t_ynMSdg)%2==0){
      KrdatlYV = (WYIGIcGE + t_ynMSdg) / 2;
    }
    else{
      KrdatlYV = (WYIGIcGE + t_ynMSdg - 1) / 2;
    }
    rem = 0;
    for(i=(0);i<(N);i++){
      if(A[i] <= KrdatlYV){
        rem++;
      }
    }
    for(i=(0);i<(Q);i++){
      if(K[i] > KrdatlYV){
        continue;
      }
      if(K[i] > 0){
        rem++;
        continue;
      }
      if((-K[i]) <= rem){
        rem--;
      }
    }
    if(rem){
      t_ynMSdg = KrdatlYV;
    }
    else{
      WYIGIcGE = KrdatlYV + 1;
    }
  }
  res =t_ynMSdg;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// //working_memory=1m
// int N, Q, A[1d6], K[1d6];
// {
//   int res, rem;
//   rd(N,Q,A(N),K(Q));
// 
//   rem = N;
//   rep(i,Q) if[K[i] > 0, rem++, rem--];
//   if(rem==0) wt(0), return 0;
// 
//   res = bsearch_min[int,x,1,N][
//     rem = 0;
//     rep(i,N) if(A[i] <= x) rem++;
//     rep(i,Q){
//       if(K[i] > x) continue;
//       if(K[i] > 0) rem++, continue;
//       if((-K[i]) <= rem) rem--;
//     }
//   ](rem);
// 
//   wt(res);
// }