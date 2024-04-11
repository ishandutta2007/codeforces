#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
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
template<class T, class S, class U> inline void DigitF_L(T n, int sz, S res[], U b){
  int i;
  for(i=(0);i<(sz);i++){
    res[i] = n % b;
    n /= b;
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M;
char **A;
char **tmp;
int dp[8];
int nx[8];
int arr[3];
int bef[3];
int main(){
  int i, k;
  wmem = memarr;
  int res = 1073709056;
  int x;
  int y;
  int z;
  rd(N);
  rd(M);
  if(N >= 4 && M >= 4){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  if(N <= M){
    walloc2d(&A,N,M+2);
    {
      int Lj4PdHRW;
      for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
        rd(A[Lj4PdHRW]);
      }
    }
  }
  else{
    int i;
    walloc2d(&tmp,N,M+2);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
        rd(tmp[e98WHCEY]);
      }
    }
    swap(N,M);
    walloc2d(&A,N,M+2);
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        A[i][j] = tmp[j][i];
      }
    }
    for(i=(0);i<(N);i++){
      A[i][M] = '\0';
    }
  }
  if(N==1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(M);j++){
      A[i][j] -= '0';
    }
  }
  for(i=(0);i<(1<<N);i++){
    int j;
    dp[i] = 0;
    DigitF_L(i, N, arr, 2);
    for(j=(0);j<(N);j++){
      if(A[j][0] != arr[j]){
        dp[i]++;
      }
    }
  }
  for(k=(1);k<(M);k++){
    for(i=(0);i<(1<<N);i++){
      nx[i] = 1073709056;
    }
    for(i=(0);i<(1<<N);i++){
      int j;
      DigitF_L(i, N, bef, 2);
      for(j=(0);j<(1<<N);j++){
        DigitF_L(j, N, arr, 2);
        for(x=(1);x<(N);x++){
          y = bef[x-1] + bef[x] + arr[x-1] + arr[x];
          if(y%2==0){
            goto Q5rsz4fz;
          }
        }
        z = 0;
        for(x=(0);x<(N);x++){
          if(A[x][k] != arr[x]){
            z++;
          }
        }
        chmin(nx[j], dp[i] + z);
        Q5rsz4fz:;
      }
    }
    for(i=(0);i<(1<<N);i++){
      dp[i] = nx[i];
    }
  }
  for(i=(0);i<(1<<N);i++){
    chmin(res, dp[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M;
// char **A, **tmp;
// int dp[8], nx[8], arr[3], bef[3];
// {
//   int res = int_inf, x, y, z;
// 
//   rd(N,M);
//   if(N >= 4 && M >= 4) wt(-1), return 0;
//   if(N <= M){
//     walloc2d(&A,N,M+2);
//     rd(A(N));
//   } else {
//     walloc2d(&tmp,N,M+2);
//     rd(tmp(N));
//     swap(N,M);
//     walloc2d(&A,N,M+2);
//     rep(i,N) rep(j,M) A[i][j] = tmp[j][i];
//     rep(i,N) A[i][M] = '\0';
//   }
// 
//   if(N==1) wt(0), return 0;
//   rep(i,N) rep(j,M) A[i][j] -= '0';
// 
//   rep(i,1<<N){
//     dp[i] = 0;
//     DigitF(i, N, arr, 2);
//     rep(j,N) if(A[j][0] != arr[j]) dp[i]++;
//   }
//   rep(k,1,M){
//     rep(i,1<<N) nx[i] = int_inf;
//     rep(i,1<<N){
//       DigitF(i, N, bef, 2);
//       rep(j,1<<N){
//         DigitF(j, N, arr, 2);
//         rep(x,1,N){
//           y = bef[x-1] + bef[x] + arr[x-1] + arr[x];
//           if(y%2==0) break_continue;
//         }
//         z = 0;
//         rep(x,N) if(A[x][k] != arr[x]) z++;
//         nx[j] <?= dp[i] + z;
//       }
//     }
//     rep(i,1<<N) dp[i] = nx[i];
//   }
// 
//   rep(i,1<<N) res <?= dp[i];
//   wt(res);
// }