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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
template<class T> struct Arr1d{
  int n;
  int mem;
  T*d;
  T& operator[](int a){
    return d[a];
  }
  void sort(){
    reset();
    std::sort(d, d+n);
  }
  int set_cumulative_sum;
  int cumulative_sum_mem;
  T*cumulative_sum;
  void setSum(void){
    int i;
    set_cumulative_sum = 1;
    if(cumulative_sum_mem < n+1){
      delete[] cumulative_sum;
      cumulative_sum = new T[n+1];
      cumulative_sum_mem = n+1;
    }
    cumulative_sum[0] = 0;
    for(i=(0);i<(n);i++){
      cumulative_sum[i+1] = cumulative_sum[i] + d[i];
    }
  }
  T getSum(int i, int j){
    if(set_cumulative_sum==0){
      setSum();
    }
    return cumulative_sum[j+1] - cumulative_sum[i];
  }
  void reset(){
    set_cumulative_sum = 0;
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    cumulative_sum = NULL;
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    set_cumulative_sum = 0;
    cumulative_sum_mem = 0;
    delete[] cumulative_sum;
    cumulative_sum = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void memory_expand(int nn){
    if(mem < nn){
      delete[] d;
      d = new T[nn];
      mem = nn;
    }
  }
  void malloc(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn, T val){
    int i;
    reset();
    memory_expand(nn);
    n = nn;
    for(i=(0);i<(n);i++){
      d[i] = val;
    }
  }
  void set(vector<T> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void set(int nn, T a[]){
    int i;
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void free(){
    destructor();
  }
  Arr1d(){
    constructor();
  }
  Arr1d(int nn){
    constructor(nn);
  }
  ~Arr1d(){
    destructor();
  }
}
;
int N;
int Q;
int L;
int R;
char S[300000+2];
Arr1d<int> a;
int ress;
int resarr[2];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int FmcKpFmN, i;
    int res;
    int fg;
    rd(N);
    rd(Q);
    rd(S);
    a.setN(N);
    for(i=(0);i<(N);i++){
      if(S[i]=='+'){
        if(i%2==0){
          a[i] =1*1;
        }
        else{
          a[i] =1*(-1);
        }
      }
      else{
        if(i%2==0){
          a[i] =(-1)*1;
        }
        else{
          a[i] =(-1)*(-1);
        }
      }
    }
    for(FmcKpFmN=(0);FmcKpFmN<(Q);FmcKpFmN++){
      rd(L);L += (-1);
      rd(R);R += (-1);
      res = abs(a.getSum(L,R));
      res -=max_L(0, (res-1)/2)* 2;
      wt_L(res);
      wt_L('\n');
      if(res==0){
        continue;
      }
      ress = 0;
      if(res==2){
        resarr[ress++] = R;
        R--;
      }
      if(a.getSum(L,R) > 0){
        fg =1;
      }
      else{
        fg =-1;
      }
      int KrdatlYV;
      int ao_dF3pO;
      int tU__gIr_;
      KrdatlYV = L;
      ao_dF3pO = R;
      while(KrdatlYV < ao_dF3pO){
        if((KrdatlYV + ao_dF3pO)%2==0){
          tU__gIr_ = (KrdatlYV + ao_dF3pO) / 2;
        }
        else{
          tU__gIr_ = (KrdatlYV + ao_dF3pO + 1) / 2;
        }
        if( fg * (a.getSum(L,tU__gIr_-1) - a.getSum(tU__gIr_+1,R)) <= 0 ){
          KrdatlYV = tU__gIr_;
        }
        else{
          ao_dF3pO = tU__gIr_ - 1;
        }
      }
      resarr[ress++] =ao_dF3pO;
      {
        int V9aVTaxx;
        if(ress==0){
          wt_L('\n');
        }
        else{
          for(V9aVTaxx=(0);V9aVTaxx<(ress-1);V9aVTaxx++){
            wt_L(resarr[V9aVTaxx]+1);
            wt_L(' ');
          }
          wt_L(resarr[V9aVTaxx]+1);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //no-unlocked
// int N, Q, L, R;
// char S[3d5+2];
// Arr1d<int> a;
// int ress, resarr[2];
// {
//   REP(rd_int()){
//     int res, fg;
//     rd(N,Q,S);
//     a.setN(N);
//     rep(i,N) a[i] = if[S[i]=='+', 1, (-1)] * if[i%2==0, 1, (-1)];
//     rep(Q){
//       rd(L--,R--);
//       res = abs(a.getSum(L,R));
//       res -= max(0, (res-1)/2) * 2;
//       wt(res);
//       if(res==0) continue;
//       ress = 0;
//       if(res==2){
//         resarr[ress++] = R;
//         R--;
//       }
//       fg = if[a.getSum(L,R) > 0, 1, -1];
//       resarr[ress++] = bsearch_max[int,x,L,R]( fg * (a.getSum(L,x-1) - a.getSum(x+1,R)) <= 0 );
//       wt(resarr(ress)+1);
//     }
//   }
// }