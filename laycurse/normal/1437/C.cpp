#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[200];
int dp[400];
int nx[400];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    sortA_L(N,A);
    for(i=(0);i<(400);i++){
      dp[i] = 0;
    }
    for(k=(0);k<(N);k++){
      for(i=(0);i<(400);i++){
        nx[i] = 1073709056;
      }
      for(i=(0);i<(400);i++){
        int j;
        for(j=(i+1);j<(400);j++){
          chmin(nx[j], dp[i] + abs(A[k]-j));
        }
      }
      for(i=(0);i<(400);i++){
        dp[i] = nx[i];
      }
    }
    {
      int jbtyPBGc;
      int ZIeRIny5;
      if(400==0){
        ZIeRIny5 = 0;
      }
      else{
        ZIeRIny5 = nx[0];
        for(jbtyPBGc=(1);jbtyPBGc<(400);jbtyPBGc++){
          ZIeRIny5 = min_L(ZIeRIny5, nx[jbtyPBGc]);
        }
      }
      wt_L(ZIeRIny5);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, A[200];
// int dp[400], nx[400];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     sortA(N,A);
//     rep(i,400) dp[i] = 0;
//     rep(k,N){
//       rep(i,400) nx[i] = int_inf;
//       rep(i,400) rep(j,i+1,400) nx[j] <?= dp[i] + abs(A[k]-j);
//       rep(i,400) dp[i] = nx[i];
//     }
//     wt(min(nx(400)));
//   }
// }