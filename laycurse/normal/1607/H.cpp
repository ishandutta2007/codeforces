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
template<class T1, class T2> void sortA_index_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    b[i] = i;
  }
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
int N;
int A[200000];
int B[200000];
int M[200000];
int val[200000];
int ind[200000];
int l[200000];
int r[200000];
int res;
int res1[200000];
int res2[200000];
void solve(int N, int ind[], int l[], int r[]){
  int i;
  int mn = -1073709056;
  sortA_L(N,r,l,ind);
  for(i=(0);i<(N);i++){
    if(mn < l[i]){
      res++;
      mn = r[i];
    }
    res1[ind[i]] = A[ind[i]] - mn;
    res2[ind[i]] = M[ind[i]] - res1[ind[i]];
  }
}
int main(){
  int Q5VJL1cS;
  wmem = memarr;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    int j;
    int k;
    rd(N);
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(N);FmcKpFmN++){
        rd(A[FmcKpFmN]);
        rd(B[FmcKpFmN]);
        rd(M[FmcKpFmN]);
      }
    }
    for(i=(0);i<(N);i++){
      val[i] = A[i] + B[i] - M[i];
    }
    sortA_index_L(N,val,ind);
    res = 0;
    for(i=(0);i<(N);i++){
      j = i;
      while(j+1 < N && val[i] == val[j+1]){
        j++;
      }
      for(k=(i);k<(j+1);k++){
        auto jbtyPBGc = ((max_L(0, A[ind[k]] - M[ind[k]])));
        auto ZIeRIny5 = (( A[ind[k]] -max_L(0, M[ind[k]] - B[ind[k]])));
        l[k]=jbtyPBGc;
        r[k]=ZIeRIny5;
      }
      solve(j-i+1, ind+i, l+i, r+i);
      i = j;
    }
    wt_L(res);
    wt_L('\n');
    for(i=(0);i<(N);i++){
      wt_L(res1[i]);
      wt_L(' ');
      wt_L(res2[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[], M[], val[], ind[];
// int l[], r[];
// int res, res1[], res2[];
// 
// void solve(int N, int ind[], int l[], int r[]){
//   int mn = -int_inf;
//   sortA(N,r,l,ind);
//   rep(i,N){
//     if(mn < l[i]){
//       res++;
//       mn = r[i];
//     }
//     res1[ind[i]] = A[ind[i]] - mn;
//     res2[ind[i]] = M[ind[i]] - res1[ind[i]];
//   }
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N,(A,B,M)(N));
//     rep(i,N) val[i] = A[i] + B[i] - M[i];
//     sortA_index(N,val,ind);
//     res = 0;
//     rep(i,N){
//       j = i;
//       while(j+1 < N && val[i] == val[j+1]) j++;
//       rep(k,i,j+1) (l[k], r[k]) = (max(0, A[ind[k]] - M[ind[k]]), A[ind[k]] - max(0, M[ind[k]] - B[ind[k]]));
//       solve(j-i+1, ind+i, l+i, r+i);
//       i = j;
//     }
//     wt(res);
//     rep(i,N) wt(res1[i], res2[i]);
//   }
// }