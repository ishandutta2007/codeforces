#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[419430400];
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
template<class T> void malloc1d(T **arr, int x){
  (*arr) = (T*)malloc(x*sizeof(T));
}
template<class T> void free1d(T *arr){
  free(arr);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T1, class T2> struct rangeTree2d_nw{
  int N;
  int N2;
  int*sz;
  T1**d1;
  T2*d2;
  inline void build(int nn, T1 dd1[], T2 dd2[], void **mem = &wmem){
    int i;
    int j;
    int i1;
    int i2;
    int k1;
    int k2;
    int s;
    int s1;
    int s2;
    T1*ddd1;
    N = nn;
    for(N2=1;N2<N;N2*=2){
      ;
    }
    walloc1d(&sz,2*N2,mem);
    walloc1d(&d1,2*N2,mem);
    walloc1d(&d2,nn,mem);
    malloc1d(&ddd1,nn);
    for(i=(0);i<(N);i++){
      ddd1[i] = dd1[i];
    }
    for(i=(0);i<(N);i++){
      d2[i] = dd2[i];
    }
    sortA_L(N,d2,ddd1);
    for(i=(0);i<(N);i++){
      sz[N2+i] = 1;
      walloc1d(&d1[N2+i], 1, mem);
      d1[N2+i][0] = ddd1[i];
    }
    for(i=(N);i<(N2);i++){
      sz[N2+i] = 0;
    }
    for(i=(N2)-1;i>=(1);i--){
      i1 = 2*i;
      i2 = 2*i + 1;
      s1 = sz[i1];
      s2 = sz[i2];
      sz[i] = s1 + s2;
      s = k1 = k2 = 0;
      walloc1d(&d1[i], sz[i], mem);
      while(k1 < s1 || k2 < s2){
        if(k2==s2){
          d1[i][s] = d1[i1][k1];
          s++;
          k1++;
          continue;
        }
        if(k1==s1){
          d1[i][s] = d1[i2][k2];
          s++;
          k2++;
          continue;
        }
        if(d1[i1][k1] < d1[i2][k2]){
          d1[i][s] = d1[i1][k1];
          s++;
          k1++;
          continue;
        }
        else{
          d1[i][s] = d1[i2][k2];
          s++;
          k2++;
          continue;
        }
      }
    }
    free1d(ddd1);
  }
  inline int query(T1 x1, T1 x2, T2 y1, T2 y2){
    int res = 0;
    int a;
    int b;
    int z1;
    int z2;
    a = lower_bound(d2, d2+N, y1) - d2 + N2;
    b = lower_bound(d2, d2+N, y2) - d2 + N2;
    while(a < b){
      if(a%2){
        z1 = lower_bound(d1[a], d1[a]+sz[a], x1) - d1[a];
        z2 = lower_bound(d1[a], d1[a]+sz[a], x2) - d1[a];
        if(z1 < z2){
          res += z2-z1;
        }
        a++;
      }
      if(b%2){
        b--;
        z1 = lower_bound(d1[b], d1[b]+sz[b], x1) - d1[b];
        z2 = lower_bound(d1[b], d1[b]+sz[b], x2) - d1[b];
        if(z1 < z2){
          res += z2-z1;
        }
      }
      a /= 2;
      b /= 2;
    }
    return res;
  }
}
;
int N;
int M;
int Q;
int C[200000+2];
int L[200000+2];
int R[200000+2];
int y[200000+2];
char res[200000+2];
rangeTree2d_nw<int,int> t;
int main(){
  int b;
  wmem = memarr;
  int i;
  int j;
  int k;
  int s;
  int e;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(C[Lj4PdHRW]);
    }
  }
  rd(Q);
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
      rd(L[e98WHCEY]);
      rd(R[e98WHCEY]);
    }
  }
  for(i=(0);i<(Q);i++){
    res[i] = 'B';
  }
  sortA_L(N,C);
  k = 0;
  for(i=(0);i<(N);i++){
    if(k && C[k-1] == C[i]){
      k--;
      continue;
    }
    C[k++] = C[i];
  }
  N = k;
  void*mem = wmem;
  for(b=(0);b<(18);b++){
    wmem = mem;
    for(i=(0);i<(N);i++){
      y[i] = C[i] % (1<<(b+1));
    }
    t.build(N,C,y);
    for(i=(0);i<(Q);i++){
      if(res[i]=='B'){
        s = (L[i] + (1<<b)) % (1<<(b+1));
        e = s + (1<<b);
        if(e <= (1<<(b+1))){
          j = t.query(L[i], R[i]+1, s, e);
        }
        else{
          j = t.query(L[i], R[i]+1, s, (1<<(b+1))) + t.query(L[i], R[i]+1, 0, e-(1<<(b+1)));
        }
        if(j%2){
          res[i] = 'A';
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// //working_memory=400m
// int N, M, Q, C[2d5+2], L[], R[], y[];
// char res[];
// rangeTree2d_nw<int,int> t;
// {
//   int i, j, k, s, e;
//   rd(N,M,C(N),Q,(L,R)(Q));
//   rep(i,Q) res[i] = 'B';
// 
//   sortA(N,C);
//   k = 0;
//   rep(i,N){
//     if(k && C[k-1] == C[i]) k--, continue;
//     C[k++] = C[i];
//   }
//   N = k;
// 
//   void *mem = wmem;
//   rep(b,18){
//     wmem = mem;
//     rep(i,N) y[i] = C[i] % (1<<(b+1));
//     t.build(N,C,y);
//     rep(i,Q) if(res[i]=='B'){
//       s = (L[i] + (1<<b)) % (1<<(b+1));
//       e = s + (1<<b);
//       if(e <= (1<<(b+1))){
//         j = t.query(L[i], R[i]+1, s, e);
//       } else {
//         j = t.query(L[i], R[i]+1, s, (1<<(b+1))) + t.query(L[i], R[i]+1, 0, e-(1<<(b+1)));
//       }
//       if(j%2) res[i] = 'A';
//     }
//   }
// 
//   wt(res);
// }