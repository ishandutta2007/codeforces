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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[500];
int sz;
int arr[500];
int len[500][500];
int dp[501];
int doit(int sz, int arr[]){
  int i;
  int k = 0;
  for(i=(0);i<(sz);i++){
    arr[k++] = arr[i];
    while(k >= 2 && arr[k-2]==arr[k-1]){
      k--;
      arr[k-1]++;
    }
  }
  return k;
}
int main(){
  int i;
  rd(N);
  {
    int cTE1_r3A;
    for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
      rd(A[cTE1_r3A]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i);j<(N);j++){
      int k;
      sz = 0;
      for(k=(i);k<(j+1);k++){
        arr[sz++] = A[k];
      }
      len[i][j] = doit(sz, arr);
    }
  }
  dp[0] = 0;
  for(i=(1);i<(N+1);i++){
    dp[i] = 1073709056;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i);j<(N);j++){
      chmin(dp[j+1], dp[i] + len[i][j]);
    }
  }
  wt_L(dp[N]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200308-1

// --- original code ---
// //no-unlocked
// int N, A[500];
// 
// int sz, arr[500], len[500][500], dp[501];
// 
// int doit(int sz, int arr[]){
//   int k = 0;
//   rep(i,sz){
//     arr[k++] = arr[i];
//     while(k >= 2 && arr[k-2]==arr[k-1]){
//       k--;
//       arr[k-1]++;
//     }
//   }
//   return k;
// }
// 
// {
//   rd(N,A(N));
//   rep(i,N) rep(j,i,N){
//     sz = 0;
//     rep(k,i,j+1) arr[sz++] = A[k];
//     len[i][j] = doit(sz, arr);
//   }
// 
//   dp[0] = 0;
//   rep(i,1,N+1) dp[i] = int_inf;
//   rep(i,N) rep(j,i,N) dp[j+1] <?= dp[i] + len[i][j];
//   wt(dp[N]);
// }