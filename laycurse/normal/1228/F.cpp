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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
struct graph{
  int N;
  int *es;
  int **edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
}
;
int D;
int N;
int A[140000];
int B[140000];
int cnt[5];
int ress;
int res[10];
graph g;
int solve(int n, int b, int sp, int rm){
  int i;
  int j;
  int lis[3];
  int s = 0;
  int x;
  int y;
  if(rm < 0){
    return 0;
  }
  for(i=(0);i<(g.es[n]);i++){
    j = g.edge[n][i];
    if(j != b){
      lis[s++] = j;
    }
  }
  if(s==0 && rm==0 && sp!=n){
    return 1;
  }
  if(s==0){
    return 0;
  }
  if(s==1 && sp==n){
    return solve(lis[0], n, sp, rm-1);
  }
  if(s==1){
    return 0;
  }
  if(s==2 && sp!=n){
    for(i=(0);i<(2);i++){
      if(!solve(lis[i], n, sp, rm-1)){
        return 0;
      }
    }
    return 1;
  }
  if(s==2){
    return 0;
  }
  if(s==3 && sp==n){
    x = 1;
    y = 2;
    for(i=(0);i<(3);i++){
      if(x && solve(lis[i], n, sp, rm-1)){
        x--;
        continue;
      }
      if(y && solve(lis[i], n, sp, rm-2)){
        y--;
        continue;
      }
      return 0;
    }
    return 1;
  }
  return 0;
}
int main(){
  int i;
  wmem = memarr;
  rd(D);
  N = (1<<D) - 2;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
    }
  }
  g.setEdge(N,N-1,A,B);
  for(i=(0);i<(N);i++){
    if(g.es[i] > 4){
      wt_L(0);
      wt_L('\n');
      return 0;
    }
  }
  for(i=(0);i<(N);i++){
    cnt[g.es[i]]++;
  }
  if(D==2){
    res[ress++] = 0;
    res[ress++] = 1;
    wt_L(ress);
    wt_L('\n');
    {
      int KL2GvlyY;
      if(ress==0){
        putchar('\n');
      }
      else{
        for(KL2GvlyY=(0);KL2GvlyY<(ress-1);KL2GvlyY++){
          wt_L(res[KL2GvlyY]+1);
          wt_L(' ');
        }
        wt_L(res[KL2GvlyY]+1);
        wt_L('\n');
      }
    }
    return 0;
  }
  if(cnt[4]==1 && cnt[2]==1){
    int k;
    for(i=(0);i<(N);i++){
      if(g.es[i] == 4){
        break;
      }
    }
    for(k=(0);k<(N);k++){
      if(g.es[k] == 2){
        break;
      }
    }
    if(solve(k,-1,i,D-1)){
      res[ress++] = i;
    }
  }
  else if(cnt[2] == 2){
    int j;
    for(i=(0);i<(N);i++){
      if(g.es[i] == 2){
        break;
      }
    }
    for(j=(i+1);j<(N);j++){
      if(g.es[j] == 2){
        break;
      }
    }
    if(solve(i,-1,j,D-1)){
      res[ress++] = j;
    }
    if(solve(j,-1,i,D-1)){
      res[ress++] = i;
    }
  }
  else{
    for(i=(0);i<(N);i++){
      if(g.es[i]==3 && solve(i,-1,i,D-1)){
        res[ress++] = i;
      }
    }
  }
  sortA_L(ress, res);
  wt_L(ress);
  wt_L('\n');
  {
    int Q5VJL1cS;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=(0);Q5VJL1cS<(ress-1);Q5VJL1cS++){
        wt_L(res[Q5VJL1cS]+1);
        wt_L(' ');
      }
      wt_L(res[Q5VJL1cS]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191006-1

// --- original code ---
// //no-unlocked
// int D, N, A[140000], B[140000];
// int cnt[5];
// int ress, res[10];
// graph g;
// 
// int solve(int n, int b, int sp, int rm){
//   int i, j, lis[3], s = 0, x, y;
// 
//   if(rm < 0) return 0;
// 
//   rep(i,g.es[n]){
//     j = g.edge[n][i];
//     if(j != b) lis[s++] = j;
//   }
// 
//   if(s==0 && rm==0 && sp!=n) return 1;
//   if(s==0) return 0;
// 
//   if(s==1 && sp==n) return solve(lis[0], n, sp, rm-1);
//   if(s==1) return 0;
// 
//   if(s==2 && sp!=n){
//     rep(i,2) if(!solve(lis[i], n, sp, rm-1)) return 0;
//     return 1;
//   }
//   if(s==2) return 0;
// 
//   if(s==3 && sp==n){
//     x = 1;
//     y = 2;
//     rep(i,3){
//       if(x && solve(lis[i], n, sp, rm-1)) x--, continue;
//       if(y && solve(lis[i], n, sp, rm-2)) y--, continue;
//       return 0;
//     }
//     return 1;
//   }
// 
//   return 0;
// }
// 
// {
//   rd(D);
//   N = (1<<D) - 2;
//   rd((A--,B--)(N-1));
//   g.setEdge(N,N-1,A,B);
//   rep(i,N) if(g.es[i] > 4) wt(0), return 0;
//   rep(i,N) cnt[g.es[i]]++;
// 
//   if(D==2){
//     res[ress++] = 0;
//     res[ress++] = 1;
//     wt(ress);
//     wt(res(ress)+1);
//     return 0;
//   }
// 
//   if(cnt[4]==1 && cnt[2]==1){
//     rep(i,N) if(g.es[i] == 4) break;
//     rep(k,N) if(g.es[k] == 2) break;
//     if(solve(k,-1,i,D-1)) res[ress++] = i;
//   } else if(cnt[2] == 2) {
//     rep(i,N) if(g.es[i] == 2) break;
//     rep(j,i+1,N) if(g.es[j] == 2) break;
//     if(solve(i,-1,j,D-1)) res[ress++] = j;
//     if(solve(j,-1,i,D-1)) res[ress++] = i;
//   } else {
//     rep(i,N) if(g.es[i]==3 && solve(i,-1,i,D-1)) res[ress++] = i;
//   }
// 
//   sortA(ress, res);
//   wt(ress);
//   wt(res(ress)+1);
// }