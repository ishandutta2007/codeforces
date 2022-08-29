#pragma GCC optimize ("Ofast")
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int A[10000];
int ind[10000];
int val[10000];
int ress;
int res1[100000];
int res2[100000];
int res3[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int j;
  int k;
  int tar;
  int sm;
  int go;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int V9aVTaxx;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    if(N==1){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    ress = 0;
    {
      int xr20shxY;
      int WYIGIcGE;
      if(N==0){
        WYIGIcGE = 0;
      }
      else{
        WYIGIcGE = A[0];
        for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
          WYIGIcGE += A[xr20shxY];
        }
      }
      sm =WYIGIcGE;
    }
    if(sm%N){
      wt_L("-1");
      wt_L('\n');
      continue;
    }
    tar = sm / N;
    for(i=(0);i<(N);i++){
      k = A[i] / (i+1);
      if(k){
        arrInsert(ress, ress, res1, i, res2, (i+1)%N, res3, k);
        A[i] -= (i+1) * k;
        A[(i+1)%N] += (i+1) * k;
      }
    }
    for(i=(0);i<(N);i++){
      ind[i] = i;
      val[i] = A[i];
    }
    rsortA_L(N, val, ind);
    for(V9aVTaxx=(0);V9aVTaxx<(N);V9aVTaxx++){
      auto &j = ind[V9aVTaxx];
      if(j){
        go = tar - A[j];
        if(go < 0){
          (go = moddw_L(go,(j+1)));
        }
        if(go){
          arrInsert(ress, ress, res1, 0, res2, j, res3, go);
          A[0] -= go;
          A[j] += go;
        }
        if(A[j] > tar){
          go = (A[j] - tar) / (j+1);
          arrInsert(ress, ress, res1, j, res2, 0, res3, go);
          A[j] -= go * (j+1);
          A[0] += go * (j+1);
        }
      }
    }
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(res1[i]+1);
      wt_L(' ');
      wt_L(res2[i]+1);
      wt_L(' ');
      wt_L(res3[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// //no-unlocked
// int N, A[1d4];
// int ind[1d4], val[1d4];
// int ress, res1[1d5], res2[1d5], res3[1d5];
// {
//   int i, j, k;
//   int tar, sm, go;
//   REP(rd_int()){
//     rd(N,A(N));
//     if(N==1) wt(0), continue;
// 
//     ress = 0;
//     sm = sum(A(N));
//     if(sm%N) wt("-1"), continue;
//     tar = sm / N;
// 
//     rep(i,N){
//       k = A[i] / (i+1);
//       if(k){
//         arrInsert(ress, ress, res1, i, res2, (i+1)%N, res3, k);
//         A[i] -= (i+1) * k;
//         A[(i+1)%N] += (i+1) * k;
//       }
//     }
// 
//     rep(i,N) ind[i] = i, val[i] = A[i];
//     rsortA(N, val, ind);
// 
//     rep[ind](j,N) if(j){
//       go = tar - A[j];
//       if(go < 0) go %%= (j+1);
//       if(go){
//         arrInsert(ress, ress, res1, 0, res2, j, res3, go);
//         A[0] -= go;
//         A[j] += go;
//       }
// 
//       if(A[j] > tar){
//         go = (A[j] - tar) / (j+1);
//         arrInsert(ress, ress, res1, j, res2, 0, res3, go);
//         A[j] -= go * (j+1);
//         A[0] += go * (j+1);
//       }
//     }
// 
//     wt(ress);
//     rep(i,ress) wt(res1[i]+1, res2[i]+1, res3[i]);
//   }
// }