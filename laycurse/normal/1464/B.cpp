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
inline void rd(long long &x){
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_ph{
  int N;
  int logN;
  T*val;
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
char S[100000+2];
long long X;
long long Y;
struct segval{
  int zero;
  int one;
  long long cost;
}
;
segval segtree_ph_func(segval a, segval b){
  return {a.zero+b.zero, a.one+b.one, a.cost+b.cost+X*a.zero*b.one+Y*a.one*b.zero};
}
segtree_ph<segval> t;
int main(){
  int i;
  wmem = memarr;
  long long res;
  N = rd(S);
  rd(X);
  rd(Y);
  t.walloc(N);
  t.setN(N);
  for(i=(0);i<(N);i++){
    if(S[i]=='1'){
      t[i] ={0,1,0};
    }
    else{
      t[i] ={1,0,0};
    }
  }
  t.build();
  res = t.get(0, N).cost;
  for(i=(0);i<(N);i++){
    if(S[i] == '?'){
      t.change(i, {0, 1, 0});
    }
    chmin(res, t.get(0, N).cost);
  }
  for(i=(0);i<(N);i++){
    if(S[i] == '?'){
      t.change(i, {1, 0, 0});
    }
    chmin(res, t.get(0, N).cost);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
template<class T> void segtree_ph<T>::malloc(int maxN, int once /*= 0*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new T[2*i];
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_ph<T>::walloc(int maxN, int once /*= 0*/, void **mem /*= &wmem*/){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  walloc1d(&val, 2*i, mem);
  if(once){
    setN(maxN);
  }
}
template<class T> void segtree_ph<T>::free(void){
  delete [] val;
}
template<class T> T& segtree_ph<T>::operator[](int i){
  return val[N+i];
}
template<class T> void segtree_ph<T>::setN(int n, int zerofill /*= 1*/, int dobuild /*= 1*/){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  N = i;
  if(dobuild){
    build();
  }
}
template<class T> void segtree_ph<T>::build(void){
  for(int i=N-1;i;i--){
    val[i] = segtree_ph_func(val[2*i], val[2*i+1]);
  }
}
template<class T> inline void segtree_ph<T>::build(int a){
  while(a > 1){
    a /= 2;
    val[a] = segtree_ph_func(val[2*a], val[2*a+1]);
  }
}
template<class T> inline void segtree_ph<T>::change(int a, T v){
  val[a+N] = v;
  build(a+N);
}
template<class T> inline T segtree_ph<T>::get(int a, int b){
  T res;
  T tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  while(a < b){
    if(a%2){
      if(fga){
        res = segtree_ph_func(res, val[a]);
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
        tmp = segtree_ph_func(val[b], tmp);
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
    return segtree_ph_func(res, tmp);
  }
  return res;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int N; char S[1d5+2]; ll X, Y;
// 
// struct segval{ int zero, one; ll cost;};
// segval segtree_ph_func(segval a, segval b){
//   return {a.zero+b.zero, a.one+b.one, a.cost+b.cost+X*a.zero*b.one+Y*a.one*b.zero};
// }
// 
// segtree_ph<segval> t;
// {
//   ll res;
//   rd(S@N,X,Y);
//   t.walloc(N);
//   t.setN(N);
//   rep(i,N) t[i] = if[S[i]=='1', {0,1,0}, {1,0,0}];
//   t.build();
//   res = t.get(0, N).cost;
// 
//   rep(i,N){
//     if(S[i] == '?') t.change(i, {0, 1, 0});
//     res <?= t.get(0, N).cost;
//   }
//   rep(i,N){
//     if(S[i] == '?') t.change(i, {1, 0, 0});
//     res <?= t.get(0, N).cost;
//   }
//   wt(res);
// }