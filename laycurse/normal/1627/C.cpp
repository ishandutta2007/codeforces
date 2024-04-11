#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
struct graph{
  int N;
  int*es;
  int**edge;
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
  void getDist(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  int getDist(int a, int b, void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    int*d;
    if(a==b){
      return 0;
    }
    walloc1d(&d, N, &mem);
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      d[i] = -1;
    }
    d[a] = 0;
    s = 0;
    z = 1;
    q[0] = a;
    while(z){
      i = q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(d[k] >= 0){
          continue;
        }
        d[k] = d[i] + 1;
        if(k==b){
          return d[k];
        }
        q[s+z++] = k;
      }
    }
    return -1;
  }
  int TreeDiameter(int &a, int &b, void *mem = wmem){
    int i;
    int mx;
    int*d;
    walloc1d(&d, N, &mem);
    getDist(0, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        a = i;
      }
    }
    getDist(a, d, mem);
    mx = -1;
    for(i=(0);i<(N);i++){
      if(mx < d[i]){
        mx = d[i];
        b = i;
      }
    }
    return mx;
  }
  int TreeDiameter(void *mem = wmem){
    int a;
    int b;
    return TreeDiameter(a, b, mem);
  }
}
;
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  graph g;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    int A[N-1];
    int B[N-1];
    int a;
    int b;
    int d;
    int dist[N];
    int res[N-1];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N-1);om7Ebh6q++){
        rd(A[om7Ebh6q]);A[om7Ebh6q] += (-1);
        rd(B[om7Ebh6q]);B[om7Ebh6q] += (-1);
      }
    }
    g.setEdge(N,N-1,A,B);
    d = g.TreeDiameter(a,b);
    if(d != N-1){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    g.getDist(a,dist);
    for(i=(0);i<(N-1);i++){
      if(min_L(dist[A[i]], dist[B[i]])% 2){
        res[i] =2;
      }
      else{
        res[i] =3;
      }
    }
    {
      int pyHJGNQc;
      if(N-1==0){
        wt_L('\n');
      }
      else{
        for(pyHJGNQc=(0);pyHJGNQc<(N-1-1);pyHJGNQc++){
          wt_L(res[pyHJGNQc]);
          wt_L(' ');
        }
        wt_L(res[pyHJGNQc]);
        wt_L('\n');
      }
    }
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
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// graph g;
// REP(rd_int()){
//   int @N, A[N-1], B[N-1], a, b, d, dist[N], res[N-1];
//   rd((A--,B--)(N-1));
//   g.setEdge(N,N-1,A,B);
//   d = g.TreeDiameter(a,b);
//   if(d != N-1) wt(-1), continue;
//   g.getDist(a,dist);
//   rep(i,N-1) res[i] = if[min(dist[A[i]], dist[B[i]]) % 2, 2, 3];
//   wt(res(N-1));
// }