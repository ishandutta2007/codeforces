#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
template<class T> struct segtree_Point_Minval{
  int N;
  int logN;
  T*mn;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mn, 2*i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
  }
  T& operator[](int i){
    return mn[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        mn[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mn[i] =min_L(mn[2*i], mn[2*i+1]);
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mn[a] =min_L(mn[2*a], mn[2*a+1]);
    }
  }
  inline void change(int a, T val){
    mn[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mn[a+N] += val;
    build(a+N);
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
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
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
int A[100000];
int fnd[100000+2];
int main(){
  wmem = memarr;
  int i;
  int k;
  int b;
  segtree_Point_Minval<int> t;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  t.walloc(N+1);
  t.setN(N+1);
  for(i=(0);i<(N+1);i++){
    t[i] = -1;
  }
  t.build();
  for(i=(0);i<(N);i++){
    k = A[i];
    b = t.getMinVal(k, k+1);
    if(b+1 < i && fnd[k] == 0 && (k==0 || t.getMinVal(0, k) > b)){
      fnd[k] = 1;
    }
    t.change(k, i);
  }
  for(k=(0);k<(N+1);k++){
    b = t.getMinVal(k, k+1);
    if(b+1 < i && fnd[k] == 0 && (k==0 || t.getMinVal(0, k) > b)){
      fnd[k] = 1;
    }
  }
  for(i=0;fnd[i];i++){
    ;
  }
  wt_L(i+1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int fnd[1d5+2];
// {
//   int i, k, b;
//   segtree_Point_Minval<int> t;
// 
//   rd(N,(A--)(N));
// 
//   t.walloc(N+1);
//   t.setN(N+1);
//   rep(i,N+1) t[i] = -1;
//   t.build();
// 
//   rep(i,N){
//     k = A[i];
//     b = t.getMinVal(k, k+1);
//     if(b+1 < i && fnd[k] == 0 && (k==0 || t.getMinVal(0, k) > b)) fnd[k] = 1;
//     t.change(k, i);
//   }
//   rep(k,N+1){
//     b = t.getMinVal(k, k+1);
//     if(b+1 < i && fnd[k] == 0 && (k==0 || t.getMinVal(0, k) > b)) fnd[k] = 1;
//   }
// 
//   for(i=0;fnd[i];i++);
//   wt(i+1);
// }