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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
inline void rd(long long &x){
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
int ind[75];
long long A[75];
long long B[75];
long long dp[76][76];
int bk[76][76];
int use[75];
int fg[75];
int ress;
int res[150];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
        rd(B[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      ind[i] = i + 1;
    }
    sortA_L(N, B, A, ind);
    for(i=(0);i<(N);i++){
      fg[i] = 0;
    }
    for(i=(0);i<(N+1);i++){
      for(j=(0);j<(N+1);j++){
        dp[i][j] = -4611686016279904256LL;
      }
    }
    dp[0][0] = 0;
    for(i=(0);i<(N);i++){
      for(j=(0);j<(i+1);j++){
        if(dp[i][j] > -4611686016279904256LL){
          if(dp[i+1][j] < dp[i][j] + B[i]*(K-1)){
            dp[i+1][j] = dp[i][j] + B[i]*(K-1);
            bk[i+1][j] = j;
          }
          if(dp[i+1][j+1] < dp[i][j] + A[i] + B[i]*j){
            dp[i+1][j+1] = dp[i][j] + A[i] + B[i]*j;
            bk[i+1][j+1] = j;
          }
        }
      }
    }
    j = K;
    for(i=(N)-1;i>=(0);i--){
      if(bk[i+1][j] == j){
        continue;
      }
      j--;
      use[j] = i;
      fg[i] = 1;
    }
    ress = 0;
    for(i=(0);i<(K-1);i++){
      res[ress++] = ind[use[i]];
    }
    for(i=(0);i<(N);i++){
      if(!fg[i]){
        res[ress++] = ind[i];
        res[ress++] = -ind[i];
      }
    }
    res[ress++] = ind[use[K-1]];
    wt_L(ress);
    wt_L('\n');
    {
      int BUotOFBp;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(BUotOFBp=(0);BUotOFBp<(ress-1);BUotOFBp++){
          wt_L(res[BUotOFBp]);
          wt_L(' ');
        }
        wt_L(res[BUotOFBp]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K, ind[75];
// ll A[75], B[75];
// 
// ll dp[76][76]; int bk[76][76];
// int use[75], fg[75];
// int ress, res[150];
// {
//   REP(rd_int()){
//     int i, j;
//     rd(N,K,(A,B)(N));
//     rep(i,N) ind[i] = i + 1;
//     sortA(N, B, A, ind);
//     rep(i,N) fg[i] = 0;
// 
//     rep(i,N+1) rep(j,N+1) dp[i][j] = -ll_inf;
//     dp[0][0] = 0;
//     rep(i,N) rep(j,i+1) if(dp[i][j] > -ll_inf){
//       if(dp[i+1][j] < dp[i][j] + B[i]*(K-1)){
//         dp[i+1][j] = dp[i][j] + B[i]*(K-1);
//         bk[i+1][j] = j;
//       }
//       if(dp[i+1][j+1] < dp[i][j] + A[i] + B[i]*j){
//         dp[i+1][j+1] = dp[i][j] + A[i] + B[i]*j;
//         bk[i+1][j+1] = j;
//       }
//     }
// 
//     j = K;
//     rrep(i,N){
//       if(bk[i+1][j] == j) continue;
//       j--;
//       use[j] = i;
//       fg[i] = 1;
//     }
// 
//     ress = 0;
//     rep(i,K-1) res[ress++] = ind[use[i]];
//     rep(i,N) if(!fg[i]){
//       res[ress++] = ind[i];
//       res[ress++] = -ind[i];
//     }
//     res[ress++] = ind[use[K-1]];
//     wt(ress);
//     wt(res(ress));
//   }
// }