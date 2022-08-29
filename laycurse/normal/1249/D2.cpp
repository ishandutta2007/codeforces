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
template<class T> inline T popFirst(multiset<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T popLast(multiset<T> &a){
  T res;
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T popFirst(set<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
template<class T> inline T popLast(set<T> &a){
  T res;
  typename set<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class S, class T> void wAdjEdge_L(const int N, const int M, const int *A, const S *B, const T *C, int **res_sz, S ***res_B, T ***res_C, void **mem = &wmem){
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
  for(i=(0);i<(N);i++){
    (*res_sz)[i] = 0;
  }
  for(i=(0);i<(M);i++){
    (*res_B)[A[i]][(*res_sz)[A[i]]] = B[i];
    (*res_C)[A[i]][(*res_sz)[A[i]]] = C[i];
    (*res_sz)[A[i]]++;
  }
}
int N;
int K;
int LL[200000];
int RR[200000];
int indd[200000];
int *num;
int **R;
int **ind;
int ress;
int res[200000];
int main(){
  int i;
  wmem = memarr;
  set<pair<int,int>> s;
  pair<int,int> p;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(LL[Lj4PdHRW]);LL[Lj4PdHRW] += (-1);
      rd(RR[Lj4PdHRW]);RR[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    indd[i] = i+1;
  }
  wAdjEdge_L(200000, N, LL, RR, indd, &num, &R, &ind);
  for(i=(0);i<(200000);i++){
    int j;
    for(j=(0);j<(num[i]);j++){
      s.insert( make_pair(R[i][j], ind[i][j]) );
    }
    while(s.size() > K){
      p = popLast(s);
      res[ress++] = p.second;
    }
    while(s.size()){
      p = getFirst(s);
      if(p.first == i){
        popFirst(s);
        continue;
      }
      break;
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int a2conNHc;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(a2conNHc=(0);a2conNHc<(ress-1);a2conNHc++){
        wt_L(res[a2conNHc]);
        wt_L(' ');
      }
      wt_L(res[a2conNHc]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, K, LL[2d5], RR[2d5], indd[2d5];
// int *num, **R, **ind;
// int ress, res[2d5];
// {
//   set<pair<int,int>> s;
//   pair<int,int> p;
// 
//   rd(N,K,(LL--,RR--)(N));
//   rep(i,N) indd[i] = i+1;
//   wAdjEdge(2d5, N, LL, RR, indd, &num, &R, &ind);
// 
//   rep(i,2d5){
//     rep(j,num[i]) s.insert( make_pair(R[i][j], ind[i][j]) );
//     while(s.size() > K){
//       p = popLast(s);
//       res[ress++] = p.second;
//     }
//     while(s.size()){
//       p = getFirst(s);
//       if(p.first == i) popFirst(s), continue;
//       break;
//     }
//   }
//   wt(ress);
//   wt(res(ress));
// }