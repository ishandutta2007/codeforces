#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int N;
int M;
int A[1000000];
int B[1000000];
graph g;
int dep[500000];
int up[500000];
int vis[500000];
int ind[500000];
int ress;
int res1[500000];
int res2[500000];
void dfs(int n, int b, int d){
  int Lj4PdHRW;
  vis[n] = 1;
  up[n] = b;
  dep[n] = d;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[n]);Lj4PdHRW++){
    auto &i = g.edge[n][Lj4PdHRW];
    if(vis[i]){
      continue;
    }
    dfs(i, n, d+1);
  }
}
int main(){
  int e98WHCEY;
  wmem = memarr;
  int cTE1_r3A = rd_int();
  for(e98WHCEY=(0);e98WHCEY<(cTE1_r3A);e98WHCEY++){
    int i;
    int mx;
    int mxi;
    rd(N);
    rd(M);
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(M);xr20shxY++){
        rd(A[xr20shxY]);A[xr20shxY] += (-1);
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    g.setEdge(N,M,A,B);
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    dfs(0,-1,0);
    ress = 0;
    {
      int tU__gIr_;
      int a2conNHc;
      if(N==0){
        a2conNHc = 0;
      }
      else{
        a2conNHc = dep[0];
        for(tU__gIr_=(1);tU__gIr_<(N);tU__gIr_++){
          a2conNHc = max_L(a2conNHc, dep[tU__gIr_]);
        }
      }
      mx =a2conNHc;
    }
    if(mx+1 >= (N+1)/2){
      {
        int YREPHmFM;
        int jZyWAPpY = 0;
        int jbtyPBGc;
        int ZIeRIny5;
        int iMWUTgY_;
        for(YREPHmFM=(0);YREPHmFM<(((N)-1)+1);YREPHmFM++){
          ZIeRIny5 = dep[YREPHmFM];
          if(jZyWAPpY==0 || jbtyPBGc<ZIeRIny5){
            jbtyPBGc = ZIeRIny5;
            jZyWAPpY = 1;
            iMWUTgY_ = YREPHmFM;
          }
        }
        mxi =iMWUTgY_;
      }
      while(mxi != -1){
        res1[ress++] = mxi;
        mxi = up[mxi];
      }
      wt_L("PATH");
      wt_L('\n');
      wt_L(ress);
      wt_L('\n');
      {
        int Q5rsz4fz;
        if(ress==0){
          wt_L('\n');
        }
        else{
          for(Q5rsz4fz=(0);Q5rsz4fz<(ress-1);Q5rsz4fz++){
            wt_L(res1[Q5rsz4fz]+1);
            wt_L(' ');
          }
          wt_L(res1[Q5rsz4fz]+1);
          wt_L('\n');
        }
      }
      continue;
    }
    for(i=(0);i<(N);i++){
      ind[i] = i;
    }
    sortA_L(N, dep, ind);
    for(i=(0);i<(N);i++){
      if(i+1 < N && dep[i]==dep[i+1]){
        arrInsert(ress, ress, res1, ind[i], res2, ind[i+1]);
        i++;
      }
    }
    wt_L("PAIRING");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(res1[i]+1);
      wt_L(' ');
      wt_L(res2[i]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d6], B[1d6];
// 
// graph g;
// int dep[5d5], up[5d5], vis[5d5], ind[5d5];
// int ress, res1[5d5], res2[5d5];
// 
// void dfs(int n, int b, int d){
//   vis[n] = 1;
//   up[n] = b;
//   dep[n] = d;
//   rep[g.edge[n]](i,g.es[n]){
//     if(vis[i]) continue;
//     dfs(i, n, d+1);
//   }
// }
// 
// {
//   REP(rd_int()){
//     int mx, mxi;
//     rd(N,M,(A--,B--)(M));
//     g.setEdge(N,M,A,B);
//     rep(i,N) vis[i] = 0;
//     dfs(0,-1,0);
// 
//     ress = 0;
// 
//     mx = max(dep(N));
//     if(mx+1 >= (N+1)/2){
//       mxi = argmax(dep(N));
//       while(mxi != -1){
//         res1[ress++] = mxi;
//         mxi = up[mxi];
//       }
//       wt("PATH");
//       wt(ress);
//       wt(res1(ress)+1);
//       continue;
//     }
// 
//     rep(i,N) ind[i] = i;
//     sortA(N, dep, ind);
//     rep(i,N) if(i+1 < N && dep[i]==dep[i+1]){
//       arrInsert(ress, ress, res1, ind[i], res2, ind[i+1]);
//       i++;
//     }
//     wt("PAIRING");
//     wt(ress);
//     rep(i,ress) wt(res1[i]+1, res2[i]+1);
//   }
// }