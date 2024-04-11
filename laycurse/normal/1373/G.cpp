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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_pg{
  int N;
  int logN;
  T *val;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  T& operator[](int i);
  void setN(int n, int zerofill = 1, int dobuild = 1);
  void build(void);
  inline void build(int a);
  inline void change(int a, T v);
  inline T get(int a, int b);
}
;
int N;
int K;
int M;
int X;
int Y;
set<long long> exs;
struct hoge{
  int st;
  int ed;
  int go;
  int sm;
}
;
void segtree_pg_func(hoge &res, hoge a, hoge b){
  int up;
  res.st = a.st;
  res.ed = b.ed;
  res.sm = a.sm + b.sm;
  res.go =max_L(a.go, b.go);
  up =max_L(0, a.go - a.ed);
  if(up > 0){
    chmax(res.go, b.st + b.sm + up - 1);
  }
  if(res.sm > 0){
    chmax(res.go, res.st + res.sm - 1);
  }
}
hoge tmp[800000];
segtree_pg<hoge> t;
int main(){
  int FmcKpFmN, i;
  wmem = memarr;
  int res;
  int nn;
  rd(N);
  rd(K);K += (-1);
  rd(M);
  nn = 1;
  while(nn < 2*N){
    nn *= 2;
  }
  t.malloc(nn);
  t.setN(nn);
  for(i=(0);i<(nn);i++){
    tmp[i].st = tmp[i].ed = i;
    tmp[i].go = -1073709056;
    tmp[i].sm = 0;
    t[i] = tmp[i];
  }
  t.build();
  for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){
    rd(X);X += (-1);
    rd(Y);Y += (-1);
    long long xy = (long long) X * 1000000000 + Y;
    Y += abs(K-X);
    if(exs.count(xy)){
      exs.erase(xy);
      tmp[Y].sm--;
    }
    else{
      exs.insert(xy);
      tmp[Y].sm++;
    }
    if(tmp[Y].sm==0){
      tmp[Y].go =-1073709056;
    }
    else{
      tmp[Y].go =Y + tmp[Y].sm - 1;
    }
    t.change(Y, tmp[Y]);
    res = t.get(0, 2*N).go - (N-1);
    chmax(res, 0);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> void segtree_pg<T>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new T[2*i];
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_pg<T>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_pg<T>::free(void){
  delete [] val;
}
template<class T> T& segtree_pg<T>::operator[](int i){
  return val[N+i];
}
template<class T> void segtree_pg<T>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  N = i;
  if(dobuild){
    build();
  }
}
template<class T> void segtree_pg<T>::build(void){
  for(int i=N-1;i;i--){
    segtree_pg_func(val[i], val[2*i], val[2*i+1]);
  }
}
template<class T> inline void segtree_pg<T>::build(int a){
  while(a > 1){
    a /= 2;
    segtree_pg_func(val[a], val[2*a], val[2*a+1]);
  }
}
template<class T> inline void segtree_pg<T>::change(int a, T v){
  val[a+N] = v;
  build(a+N);
}
template<class T> inline T segtree_pg<T>::get(int a, int b){
  T res;
  T tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  while(a < b){
    if(a%2){
      if(fga){
        segtree_pg_func(res, res, val[a]);
      }
      else{
        res = val[a];
        fga = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      if(fgb){
        segtree_pg_func(tmp, val[b], tmp);
      }
      else{
        tmp = val[b];
        fgb = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  if(fga==1 && fgb==0){
    return res;
  }
  if(fga==0 && fgb==1){
    return tmp;
  }
  if(fga==1 && fgb==1){
    segtree_pg_func(res, res, tmp);
    return res;
  }
  return res;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K, M, X, Y;
// set<ll> exs;
// 
// struct hoge {
//   int st, ed, go, sm;
// };
// 
// void segtree_pg_func(hoge &res, hoge a, hoge b){
//   int up;
//   res.st = a.st;
//   res.ed = b.ed;
//   res.sm = a.sm + b.sm;
//   res.go = max(a.go, b.go);
//   up = max(0, a.go - a.ed);
//   if(up > 0) res.go >?= b.st + b.sm + up - 1;
//   if(res.sm > 0) res.go >?= res.st + res.sm - 1;
// }
// 
// hoge tmp[8d5];
// segtree_pg<hoge> t;
// 
// {
//   int res, nn;
//   rd(N,K--,M);
// 
//   nn = 1;
//   while(nn < 2*N) nn *= 2;
//   t.malloc(nn);
//   t.setN(nn);
//   rep(i,nn){
//     tmp[i].st = tmp[i].ed = i;
//     tmp[i].go = -int_inf;
//     tmp[i].sm = 0;
//     t[i] = tmp[i];
//   }
//   t.build();
// 
//   rep(M){
//     rd(X--, Y--);
//     ll xy = (ll) X * 1d9 + Y;
//     Y += abs(K-X);
//     if(exs.count(xy)){
//       exs.erase(xy);
//       tmp[Y].sm--;
//     } else {
//       exs.insert(xy);
//       tmp[Y].sm++;
//     }
//     tmp[Y].go = if[tmp[Y].sm==0, -int_inf, Y + tmp[Y].sm - 1];
//     t.change(Y, tmp[Y]);
//     res = t.get(0, 2*N).go - (N-1);
//     res >?= 0;
//     wt(res);
//   }
// }