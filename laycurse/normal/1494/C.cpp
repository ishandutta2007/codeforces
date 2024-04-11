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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[200000];
int B[200000];
int solve(int N, int M, int A[], int B[]){
  int i;
  int res = 0;
  int tmp = 0;
  for(i=(M)-1;i>=(0);i--){
    while(N && A[N-1] > B[i]){
      N--;
    }
    if(N == 0){
      break;
    }
    if(A[N-1] == B[i]){
      tmp++;
      chmax(res, tmp);
      continue;
    }
    int cTE1_r3A;
    int RZTsC2BF;
    int FmcKpFmN;
    cTE1_r3A = 1;
    RZTsC2BF = i+1;
    while(cTE1_r3A < RZTsC2BF){
      if((cTE1_r3A + RZTsC2BF)%2==0){
        FmcKpFmN = (cTE1_r3A + RZTsC2BF) / 2;
      }
      else{
        FmcKpFmN = (cTE1_r3A + RZTsC2BF + 1) / 2;
      }
      if(B[i]-B[i-FmcKpFmN+1] < N){
        cTE1_r3A = FmcKpFmN;
      }
      else{
        RZTsC2BF = FmcKpFmN - 1;
      }
    }
    chmax(res, tmp +RZTsC2BF);
  }
  return res;
}
int main(){
  int t_ynMSdg;
  int KrdatlYV = rd_int();
  for(t_ynMSdg=(0);t_ynMSdg<(KrdatlYV);t_ynMSdg++){
    int k;
    int i;
    int j;
    int res = 0;
    rd(N);
    rd(M);
    {
      int a2conNHc;
      for(a2conNHc=(0);a2conNHc<(N);a2conNHc++){
        rd(A[a2conNHc]);
      }
    }
    {
      int APIVbQlN;
      for(APIVbQlN=(0);APIVbQlN<(M);APIVbQlN++){
        rd(B[APIVbQlN]);
      }
    }
    for(i=(0);i<(N);i++){
      if(A[i] > 0){
        break;
      }
    }
    for(j=(0);j<(M);j++){
      if(B[j] > 0){
        break;
      }
    }
    res += solve(N-i, M-j, A+i, B+j);
    reverse(A, A+i);
    reverse(B, B+j);
    for(k=(0);k<(i);k++){
      A[k] *= -1;
    }
    for(k=(0);k<(j);k++){
      B[k] *= -1;
    }
    res += solve(i, j, A, B);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[];
// int solve(int N, int M, int A[], int B[]){
//   int res = 0, tmp = 0;
//   rrep(i,M){
//     while(N && A[N-1] > B[i]) N--;
//     if(N == 0) break;
//     if(A[N-1] == B[i]) tmp++, res >?= tmp, continue;
//     res >?= tmp + bsearch_max[int,k,1,i+1](B[i]-B[i-k+1] < N);
//   }
//   return res;
// }
// {
//   REP(rd_int()){
//     int i, j, res = 0;
//     rd(N,M,A(N),B(M));
//     rep(i,N) if(A[i] > 0) break;
//     rep(j,M) if(B[j] > 0) break;
//     res += solve(N-i, M-j, A+i, B+j);
//     reverse(A, A+i);
//     reverse(B, B+j);
//     rep(k,i) A[k] *= -1;
//     rep(k,j) B[k] *= -1;
//     res += solve(i, j, A, B);
//     wt(res);
//   }
// }