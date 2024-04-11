#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
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
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
template <class T> struct LHeap{
  int*hp;
  int*place;
  int size;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void malloc(int N, int ini){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
    if(ini){
      init(N);
    }
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void walloc(int N, int ini, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
    if(ini){
      init(N);
    }
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    T f = val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res = hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
template<class T> struct segtree_Point_Maxval{
  int N;
  int logN;
  T*mx;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mx = new T[2*i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mx, 2*i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mx;
  }
  T& operator[](int i){
    return mx[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        mx[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mx[i] =max_L(mx[2*i], mx[2*i+1]);
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mx[a] =max_L(mx[2*a], mx[2*a+1]);
    }
  }
  inline void change(int a, T val){
    mx[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mx[a+N] += val;
    build(a+N);
  }
  inline T getMaxVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    while(a < b){
      if(a%2){
        if(fga){
          res =max_L(res, mx[a]);
        }
        else{
          res = mx[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =max_L(mx[b], tmp);
        }
        else{
          tmp = mx[b];
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
      res =max_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
char E[200000];
int A[200000];
int lf[100000];
int rg[100000];
int id[100000];
int sz;
int res[100000];
segtree_Point_Maxval<int> t;
LHeap<int> hp;
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  for(i=(0);i<(2*N);i++){
    rd(E[i]);
    if(E[i]=='-'){
      rd(A[i]);A[i] += (-1);
    }
  }
  t.walloc(N, 1);
  for(i=(0);i<(2*N);i++){
    if(E[i]=='-'){
      t.change(A[i], i);
      if(A[i]==N-1){
        j =0;
      }
      else{
        j =t.getMaxVal(A[i]+1, N);
      }
      {
        auto cTE1_r3A = (j);
        auto RZTsC2BF = ( i);
        auto FmcKpFmN = ( A[i]);
        lf[A[i]] = cTE1_r3A;
        rg[A[i]] = RZTsC2BF;
        id[A[i]] = FmcKpFmN;
      }
    }
  }
  sortA_L(N, lf, rg, id);
  hp.walloc(N, 1);
  k = 0;
  for(i=(0);i<(2*N);i++){
    while(k < N && lf[k] == i){
      hp.change(k, rg[k]);
      k++;
    }
    if(E[i]=='-'){
      continue;
    }
    if(hp.size==0){
      wt_L("NO");
      wt_L('\n');
      return 0;
    }
    j = hp.pop();
    if(rg[j] < i){
      wt_L("NO");
      wt_L('\n');
      return 0;
    }
    res[sz++] = id[j];
  }
  wt_L("YES");
  wt_L('\n');
  {
    int ao_dF3pO;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(ao_dF3pO=(0);ao_dF3pO<(N-1);ao_dF3pO++){
        wt_L(res[ao_dF3pO]+1);
        wt_L(' ');
      }
      wt_L(res[ao_dF3pO]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20201115-1

// --- original code ---
// //no-unlocked
// int N;
// char E[2d5]; int A[2d5];
// int lf[1d5], rg[1d5], id[1d5];
// int sz, res[1d5];
// segtree_Point_Maxval<int> t;
// LHeap<int> hp;
// {
//   int i, j, k;
//   rd(N);
//   rep(i,2N){
//     rd(E[i]);
//     if(E[i]=='-') rd(A[i]--);
//   }
// 
//   t.walloc(N, 1);
//   rep(i,2N) if(E[i]=='-'){
//     t.change(A[i], i);
//     j = if[A[i]==N-1, 0, t.getMaxVal(A[i]+1, N)];
//     (lf[A[i]], rg[A[i]], id[A[i]]) = (j, i, A[i]);
//   }
//   sortA(N, lf, rg, id);
// 
//   hp.walloc(N, 1);
//   k = 0;
//   rep(i,2N){
//     while(k < N && lf[k] == i){
//       hp.change(k, rg[k]);
//       k++;
//     }
//     if(E[i]=='-') continue;
//     if(hp.size==0) wt("NO"), return 0;
//     j = hp.pop();
//     if(rg[j] < i) wt("NO"), return 0;
//     res[sz++] = id[j];
//   }
//   wt("YES");
//   wt(res(N)+1);
// }