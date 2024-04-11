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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S> int arrCountVal(string A, S val){
  int i;
  int res = 0;
  for(i=(0);i<(A.size());i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class T> int coordcomp_L(int n1, T arr1[], int n2, T arr2[], int res1[] = NULL, int res2[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
  walloc1d(&r, n1+n2, &mem);
  for(i=(0);i<(n1);i++){
    r[i].first = arr1[i];
    r[i].second = i;
  }
  for(i=(0);i<(n2);i++){
    r[n1+i].first = arr2[i];
    r[n1+i].second = n1+i;
  }
  sort(r, r+n1+n2);
  for(i=(0);i<(n1+n2);i++){
    if(i && r[i].first != r[i-1].first){
      k++;
    }
    if(r[i].second < n1){
      if(res1!=NULL){
        res1[r[i].second] = k;
      }
      else{
        arr1[r[i].second] = k;
      }
    }
    else{
      if(res2!=NULL){
        res2[r[i].second-n1] = k;
      }
      else{
        arr2[r[i].second-n1] = k;
      }
    }
  }
  return k+1;
}
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
long long inversion_range(int N, int A[], int mn, int mx, void *mem=wmem){
  int i;
  int j;
  int k;
  long long res = 0;
  fenwick<int> t;
  t.walloc(mx-mn+1, &mem);
  t.init(mx-mn+1);
  for(i=N-1;i>=0;i--){
    res += t.get(A[i]-mn-1);
    t.add(A[i]-mn,1);
  }
  return res;
}
template<class T> long long inversion(int N, T A[], void *mem=wmem){
  int i;
  int j;
  int k;
  int p;
  int n1;
  int n2;
  T*x;
  T*y;
  long long res = 0;
  walloc1d(&x, N, &mem);
  walloc1d(&y, N, &mem);
  for(i=(0);i<(N);i++){
    x[i] = A[i];
  }
  for(k=0;k<N;k+=4){
    n1 =min_L(4, N-k);
    for(j=n1;j;j--){
      int AAsEZMFe = j;
      for(i=(1);i<(AAsEZMFe);i++){
        if(x[k+i-1] > x[k+i]){
          swap(x[k+i-1], x[k+i]);
          res++;
        }
      }
    }
  }
  p = 4;
  while(p<N){
    for(k=0;k<N;k+=2*p){
      n1 =min_L(p, N-k);
      n2 =min_L(p, N-k-n1);
      i = j = 0;
      while(i<n1 && j<n2){
        if(x[k+i] <= x[k+n1+j]){
          y[k+i+j] = x[k+i];
          i++;
        }
        else{
          y[k+i+j] = x[k+n1+j];
          res += n1-i;
          j++;
        }
      }
      while(i<n1){
        y[k+i+j] = x[k+i];
        i++;
      }
      while(j<n2){
        y[k+i+j] = x[k+n1+j];
        j++;
      }
    }
    swap(x,y);
    p *= 2;
  }
  return res;
}
template<class T> long long inversion(int N, T A[], T B[], void *mem = wmem){
  int i;
  int k;
  int sz;
  int*aa;
  int*bb;
  int*hist1;
  int*hist2;
  int**ind;
  walloc1d(&aa, N, &mem);
  walloc1d(&bb, N, &mem);
  sz =coordcomp_L(N,A,N,B,aa,bb,mem);
  if(sz > N){
    return -1;
  }
  walloc1d(&hist1, sz, &mem);
  walloc1d(&hist2, sz, &mem);
  for(i=(0);i<(sz);i++){
    hist1[i] = 0;
  }
  for(i=(0);i<(sz);i++){
    hist2[i] = 0;
  }
  for(i=(0);i<(N);i++){
    hist1[aa[i]]++;
  }
  for(i=(0);i<(N);i++){
    hist2[bb[i]]++;
  }
  for(i=(0);i<(sz);i++){
    if(hist1[i] != hist2[i]){
      return -1;
    }
  }
  walloc1d(&ind, sz, &mem);
  for(i=(0);i<(sz);i++){
    walloc1d(&ind[i], hist2[i], &mem);
  }
  for(i=(0);i<(sz);i++){
    hist2[i] = 0;
  }
  for(i=(0);i<(N);i++){
    k = bb[i];
    ind[k][hist2[k]++] = i;
  }
  for(i=(N)-1;i>=(0);i--){
    k = aa[i];
    aa[i] = ind[k][--hist1[k]];
  }
  return inversion_range(N,aa,0,N-1,mem);
}
int N;
char S[100000+2];
int ind[4];
int rev[4];
int arr[100000];
int ress;
char res[100000+2];
const char a[6] = "ANTO";
int r[128];
int main(){
  int Q5VJL1cS, i;
  wmem = memarr;
  for(i=(0);i<(4);i++){
    r[a[i]] = i;
  }
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    int j;
    int k;
    long long opt = -1;
    long long cur;
    N = rd(S);
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(4);FmcKpFmN++){
      ind[FmcKpFmN] = FmcKpFmN;
    }
    do{
      {
        for(i=(0);i<(4);i++){
          rev[ind[i]] = i;
        }
        for(i=(0);i<(N);i++){
          arr[i] = rev[r[S[i]]];
        }
        cur = inversion(N,arr);
        if(opt < cur){
          int V9aVTaxx;
          opt = cur;
          ress = 0;
          for(V9aVTaxx=(0);V9aVTaxx<(4);V9aVTaxx++){
            int jZyWAPpY;
            auto&i = ind[V9aVTaxx];
            int jbtyPBGc = arrCountVal(N,S,a[i]);
            for(jZyWAPpY=(0);jZyWAPpY<(jbtyPBGc);jZyWAPpY++){
              res[ress++] = a[i];
            }
          }
        }
      }
    }
    while(next_permutation(ind,ind+4));
    res[N] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(a < 0){
    a = 0;
  }
  if(b >= size){
    b = size - 1;
  }
  if(b < a){
    return 0;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int N; char S[1d5+2];
// int ind[4], rev[4], arr[1d5];
// int ress; char res[1d5+2];
// const char a[6] = "ANTO"; int r[128];
// {
//   rep(i,4) r[a[i]] = i;
//   REP(rd_int()){
//     int i, j, k;
//     ll opt = -1, cur;
//     rd(S@N);
//     rep_perm(ind,4){
//       rep(i,4) rev[ind[i]] = i;
//       rep(i,N) arr[i] = rev[r[S[i]]];
//       cur = inversion(N,arr);
//       if(opt < cur){
//         opt = cur;
//         ress = 0;
//         rep[ind](i,4) REP(arrCountVal(N,S,a[i])) res[ress++] = a[i];
//       }
//     }
//     res[N] = '\0';
//     wt(res);
//   }
// }