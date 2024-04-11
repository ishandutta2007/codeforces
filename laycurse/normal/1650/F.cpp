#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
template<class S, class T, class U> void wAdjEdge_L(const int N, const int M, const int *A, const S *B, const T *C, const U *D, int **res_sz, S ***res_B, T ***res_C, U ***res_D, void **mem = &wmem){
  int i;
  int j;
  int k;
  walloc1d(res_sz, N, mem);
  for(i=(0);i<(N);i++){
    (*res_sz)[i] = 0;
  }
  for(i=(0);i<(M);i++){
    (*res_sz)[A[i]]++;
  }
  walloc1d(res_B, N, mem);
  for(i=(0);i<(N);i++){
    walloc1d(&((*res_B)[i]), (*res_sz)[i], mem);
  }
  walloc1d(res_C, N, mem);
  for(i=(0);i<(N);i++){
    walloc1d(&((*res_C)[i]), (*res_sz)[i], mem);
  }
  walloc1d(res_D, N, mem);
  for(i=(0);i<(N);i++){
    walloc1d(&((*res_D)[i]), (*res_sz)[i], mem);
  }
  for(i=(0);i<(N);i++){
    (*res_sz)[i] = 0;
  }
  for(i=(0);i<(M);i++){
    (*res_B)[A[i]][(*res_sz)[A[i]]] = B[i];
    (*res_C)[A[i]][(*res_sz)[A[i]]] = C[i];
    (*res_D)[A[i]][(*res_sz)[A[i]]] = D[i];
    (*res_sz)[A[i]]++;
  }
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int N;
  int A[100000];
  int M;
  int E[100000];
  int T[100000];
  int P[100000];
  int ind[100000];
  int*sz;
  int**tt;
  int**pp;
  int**id;
  long long t;
  long long dp[201];
  int bs[201];
  int back[201][201];
  int ress;
  int res[100000];
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    rd(N);
    rd(M);
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);
      }
    }
    {
      int YGwFZBGH;
      for(YGwFZBGH=(0);YGwFZBGH<(M);YGwFZBGH++){
        rd(E[YGwFZBGH]);E[YGwFZBGH] += (-1);
        rd(T[YGwFZBGH]);
        rd(P[YGwFZBGH]);
      }
    }
    for(i=(0);i<(M);i++){
      ind[i] = i;
    }
    wAdjEdge_L(N,M,E,T,P,ind,&sz,&tt,&pp,&id);
    t = ress = 0;
    for(i=(0);i<(N);i++){
      int j, m;
      dp[0] = 0;
      ind[0] = -1;
      bs[0] = 0;
      for(j=(1);j<(201);j++){
        dp[j] = 4611686016279904256LL;
      }
      for(j=(0);j<(sz[i]);j++){
        int k;
        for(k=(201)-1;k>=(pp[i][j]);k--){
          if(dp[k] > dp[k-pp[i][j]]+tt[i][j]){
            int m;
            dp[k] = dp[k-pp[i][j]] + tt[i][j];
            bs[k] = bs[k-pp[i][j]] + 1;
            for(m=(0);m<(bs[k]-1);m++){
              back[k][m] = back[k-pp[i][j]][m];
            }
            back[k][m] = j;
          }
        }
      }
      int VwTh6lJ3;
      remove_reference<decltype(dp[VwTh6lJ3])>::type ZcmRJqJU;
      int Jq7Vmy8K = 0;
      int a3zq_coq;
      if((100) > ((201)-1)){
        ZcmRJqJU = 0;
      }
      else{
        for(VwTh6lJ3 = 100; VwTh6lJ3 <= (201)-1; VwTh6lJ3++){
          if(Jq7Vmy8K == 0){
            ZcmRJqJU = dp[VwTh6lJ3];
            a3zq_coq = VwTh6lJ3;
            Jq7Vmy8K = 1;
            continue;
          }
          const auto q6vsg2lB = dp[VwTh6lJ3];
          if(ZcmRJqJU > q6vsg2lB){
            ZcmRJqJU = q6vsg2lB;
            a3zq_coq = VwTh6lJ3;
          }
        }
        if(Jq7Vmy8K==0){
          ZcmRJqJU = 0;
        }
      }
      j =a3zq_coq;
      t += dp[j];
      if(t > A[i]){
        wt_L(-1);
        wt_L('\n');
        goto WKqLrJHZ;
      }
      for(m=(0);m<(bs[j]);m++){
        res[ress++] = id[i][back[j][m]];
      }
    }
    wt_L(ress);
    wt_L('\n');
    {
      int hUQRwZho;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(hUQRwZho=(0);hUQRwZho<(ress-1);hUQRwZho++){
          wt_L(res[hUQRwZho]+1);
          wt_L(' ');
        }
        wt_L(res[hUQRwZho]+1);
        wt_L('\n');
      }
    }
    WKqLrJHZ:;
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// int N, A[1d5], M, E[], T[], P[], ind[];
// int *sz, **tt, **pp, **id;
// ll t, dp[201]; int bs[201], back[201][201];
// int ress, res[1d5];
// REP(rd_int()){
//   rd(N,M,A(N),(E--,T,P)(M));
//   rep(i,M) ind[i] = i;
//   wAdjEdge(N,M,E,T,P,ind,&sz,&tt,&pp,&id);
//   t = ress = 0;
//   rep(i,N){
//     dp[0] = 0; ind[0] = -1; bs[0] = 0;
//     rep(j,1,201) dp[j] = ll_inf;
//     rep(j,sz[i]) rrep(k,pp[i][j],201) if(dp[k] > dp[k-pp[i][j]]+tt[i][j]){
//       dp[k] = dp[k-pp[i][j]] + tt[i][j];
//       bs[k] = bs[k-pp[i][j]] + 1;
//       rep(m,bs[k]-1) back[k][m] = back[k-pp[i][j]][m];
//       back[k][m] = j;
//     }
//     j = argmin[j,100,201](dp[j]);
//     t += dp[j];
//     if(t > A[i]) wt(-1), break_continue;
//     rep(m,bs[j]) res[ress++] = id[i][back[j][m]];
//   }
//   wt(ress);
//   wt(res(ress)+1);
// }