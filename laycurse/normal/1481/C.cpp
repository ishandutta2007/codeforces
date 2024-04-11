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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int N;
int M;
int A[100000];
int B[100000];
int C[100000];
vector<int> ind[100000];
int res[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    {
      int KrdatlYV;
      for(KrdatlYV=(0);KrdatlYV<(M);KrdatlYV++){
        rd(C[KrdatlYV]);C[KrdatlYV] += (-1);
      }
    }
    if(arrCountVal(N,B,C[M-1])==0){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      ind[i].clear();
    }
    for(i=(0);i<(N);i++){
      if(A[i] != B[i]){
        ind[B[i]].push_back(i);
      }
    }
    for(i=(0);i<(M);i++){
      res[i] = -1;
    }
    for(i=(0);i<(M);i++){
      if(ind[C[i]].size()){
        res[i] = ind[C[i]].back();
        ind[C[i]].pop_back();
      }
    }
    for(i=(0);i<(N);i++){
      if(ind[i].size()){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("YES");
    wt_L('\n');
    if(res[M-1] == -1){
      for(i=(0);i<(N);i++){
        if(B[i] == C[M-1]){
          res[M-1] = i;
          break;
        }
      }
    }
    for(i=(0);i<(M);i++){
      if(res[i]==-1){
        res[i] = res[M-1];
      }
    }
    {
      int GgkpftXM;
      if(M==0){
        wt_L('\n');
      }
      else{
        for(GgkpftXM=(0);GgkpftXM<(M-1);GgkpftXM++){
          wt_L(res[GgkpftXM]+1);
          wt_L(' ');
        }
        wt_L(res[GgkpftXM]+1);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], B[1d5], C[1d5];
// VI ind[1d5];
// int res[1d5];
// {
//   REP(rd_int()){
//     rd(N,M,(A--)(N),(B--)(N),(C--)(M));
//     if(arrCountVal(N,B,C[M-1])==0) wt("NO"), continue;
//     rep(i,N) ind[i].clear();
//     rep(i,N) if(A[i] != B[i]) ind[B[i]].push_back(i);
// 
//     rep(i,M) res[i] = -1;
//     rep(i,M){
//       if(ind[C[i]].size()){
//         res[i] = ind[C[i]].back();
//         ind[C[i]].pop_back();
//       }
//     }
//     rep(i,N) if(ind[i].size()) wt("NO"), break_continue;
// 
//     wt("YES");
//     if(res[M-1] == -1) rep(i,N) if(B[i] == C[M-1]) res[M-1] = i, break;
//     rep(i,M) if(res[i]==-1) res[i] = res[M-1];
//     wt(res(M)+1);
//   }
// }