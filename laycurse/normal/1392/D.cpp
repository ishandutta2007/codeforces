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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> void arrRot(int k, int N, T A[], T B[] = NULL, void *mem = wmem){
  int i;
  int fg = 0;
  (k = moddw_L(k,N));
  if(B==NULL){
    walloc1d(&B, N, &mem);
    fg = 1;
  }
  for(i=(k);i<(N);i++){
    B[i-k] = A[i];
  }
  for(i=(0);i<(k);i++){
    B[N-k+i] = A[i];
  }
  if(fg){
    for(i=(0);i<(N);i++){
      A[i] = B[i];
    }
  }
}
int N;
char S[200000+2];
int dp[200000+2];
int Hamming(int n, const char a[], const char b[]){
  int i;
  int res = 0;
  for(i=(0);i<(n);i++){
    if(a[i] != b[i]){
      res++;
    }
  }
  return res;
}
int main(){
  int Q5VJL1cS;
  wmem = memarr;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int FmcKpFmN;
    int res = 1073709056;
    rd(N);
    rd(S);
    for(FmcKpFmN=(0);FmcKpFmN<(4);FmcKpFmN++){
      int i;
      dp[0] = 0;
      for(i=(1);i<(N+1);i++){
        dp[i] = 1073709056;
      }
      for(i=(0);i<(N);i++){
        if(dp[i] < 1073709056){
          if(i+2 <= N){
            chmin(dp[i+2], dp[i] + Hamming(2, S+i, "RL"));
          }
          if(i+3 <= N){
            chmin(dp[i+3], dp[i] + Hamming(3, S+i, "RRL"));
          }
          if(i+3 <= N){
            chmin(dp[i+3], dp[i] + Hamming(3, S+i, "RLL"));
          }
          if(i+4 <= N){
            chmin(dp[i+4], dp[i] + Hamming(4, S+i, "RRLL"));
          }
        }
      }
      chmin(res, dp[N]);
      arrRot(1, N, S);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[2d5+2];
// int dp[2d5+2];
// 
// int Hamming(int n, const char a[], const char b[]){
//   int res = 0;
//   rep(i,n) if(a[i] != b[i]) res++;
//   return res;
// }
// 
// {
//   REP(rd_int()){
//     int res = int_inf;
//     rd(N,S);
//     rep(4){
//       dp[0] = 0;
//       rep(i,1,N+1) dp[i] = int_inf;
//       rep(i,N) if(dp[i] < int_inf){
//         if(i+2 <= N) dp[i+2] <?= dp[i] + Hamming(2, S+i, "RL");
//         if(i+3 <= N) dp[i+3] <?= dp[i] + Hamming(3, S+i, "RRL");
//         if(i+3 <= N) dp[i+3] <?= dp[i] + Hamming(3, S+i, "RLL");
//         if(i+4 <= N) dp[i+4] <?= dp[i] + Hamming(4, S+i, "RRLL");
//       }
//       res <?= dp[N];
//       arrRot(1, N, S);
//     }
//     wt(res);
//   }
// }