#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr=(pair<T1, T2> *) mem;
  for(i=0;i<N;i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<N;i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
char memarr[96000000];
int N;
int A[300000];
int B[300000];
int ind[300000];
int x[300000];
int sz;
int ress;
int res[300000];
int tmps;
int tmp[300000];
void update(void){
  int i;
  if(ress < sz){
    ress = sz;
    for(i=0;i<ress;i++){
      res[i] = ind[i];
    }
  }
}
int main(){
  int KL2GvlyY, i, j, k;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  for(KL2GvlyY=0;KL2GvlyY<2;KL2GvlyY++){
    sz = 0;
    for(i=0;i<N;i++){
      if(A[i] < B[i]){
        ind[sz] = i+1;
        x[sz] = -A[i];
        sz++;
      }
    }
    sortA_L(sz, x, ind);
    update();
    for(i=0;i<N;i++){
      A[i] *= -1;
    }
    for(i=0;i<N;i++){
      B[i] *= -1;
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int Q5VJL1cS;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=0;Q5VJL1cS<ress-1;Q5VJL1cS++){
        wt_L(res[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(res[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// //no-unlocked
// int N, A[3d5], B[3d5];
// 
// int ind[3d5], x[3d5], sz;
// int ress, res[3d5];
// int tmps, tmp[3d5];
// 
// void update(void){
//   int i;
//   if(ress < sz){
//     ress = sz;
//     rep(i,ress) res[i] = ind[i];
//   }
// }
// 
// {
//   int i, j, k;
//   rd(N,(A,B)(N));
// 
//   rep(2){
//     sz = 0;
//     rep(i,N) if(A[i] < B[i]){
//       ind[sz] = i+1;
//       x[sz] = -A[i];
//       sz++;
//     }
//     sortA(sz, x, ind);
//     update();
// 
//     rep(i,N) A[i] *= -1;
//     rep(i,N) B[i] *= -1;
//   }
// 
//   wt(ress);
//   wt(res(ress));
// }