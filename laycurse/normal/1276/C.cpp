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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T *val = (T*) val_s;
  int *len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void *mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[400000];
int sz;
int num[400000];
int len[400000];
int ad[400001];
int **res;
int main(){
  wmem = memarr;
  int p = -1;
  int x;
  int y;
  int i;
  int j;
  int k;
  int s;
  int t;
  int ok;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N,A);
  sz = runLength(N,A,num,len);
  rsortA_L(sz,len,num);
  for(i=(0);i<(sz);i++){
    for(j=(0);j<(len[i]);j++){
      ad[j+1]++;
    }
  }
  ok = 0;
  for(i=1;i*i<=N;i++){
    ok += ad[i];
    j = ok / i;
    if(j < i){
      break;
    }
    if(p < i * j){
      p = i * j;
      x = i;
      y = j;
    }
  }
  walloc2d(&res,x,y);
  for(i=(0);i<(sz);i++){
    chmin(len[i], x);
  }
  k = 0;
  for(i=(0);i<(sz);i++){
    for(j=(0);j<(len[i]);j++){
      if(k==x*y){
        goto tU__gIr_;
      }
      s = k % x;
      t = (k / x + s) % y;
      res[s][t] = num[i];
      k++;
    }
  }
  tU__gIr_:;
  wt_L(p);
  wt_L('\n');
  wt_L(x);
  wt_L(' ');
  wt_L(y);
  wt_L('\n');
  for(i=(0);i<(x);i++){
    {
      int YREPHmFM;
      if(y==0){
        putchar('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(y-1);YREPHmFM++){
          wt_L(res[i][YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[i][YREPHmFM]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191208-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[4d5];
// int sz, num[4d5], len[4d5];
// int ad[400001];
// int **res;
// {
//   int p = -1, x, y;
//   int i, j, k, s, t, ok;
// 
//   rd(N,A(N));
//   sortA(N,A);
//   sz = runLength(N,A,num,len);
//   rsortA(sz,len,num);
//   rep(i,sz) rep(j,len[i]) ad[j+1]++;
// 
// 
//   ok = 0;
//   for(i=1;i*i<=N;i++){
//     ok += ad[i];
//     j = ok / i;
//     if(j < i) break;
//     if(p < i * j){
//       p = i * j;
//       x = i;
//       y = j;
//     }
//   }
// 
//   walloc2d(&res,x,y);
//   rep(i,sz) len[i] <?= x;
//   k = 0;
//   rep(i,sz) rep(j,len[i]){
//     if(k==x*y) break_break;
//     s = k % x;
//     t = (k / x + s) % y;
//     res[s][t] = num[i];
//     k++;
//   }
// 
//   wt(p);
//   wt(x,y);
//   rep(i,x) wt(res[i](y));
// }