#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_unsigned =
  typename conditional<
    is_integral<T>::value,
    make_unsigned<T>,
    cLtraits_identity<T>
    >::type;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
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
inline int Ilog2_f_L(const int n){
  int res;
  if(n <= 0){
    return -1;
  }
  res = sizeof(int) * 8 - __builtin_clz(n) - 1;
  return res;
}
inline int Ilog2_f_L(const long long n){
  int res;
  if(n <= 0){
    return -1;
  }
  res = sizeof(long long) * 8 - __builtin_clzll(n) - 1;
  return res;
}
template<class T1> void sortI(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortI(int N, T1 a[], T2 b[], void *mem = wmem){
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
template<class T1, class T2, class T3> void sortI(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
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
template<class T1, class T2, class T3, class T4> void sortI(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  int i;
  pair<pair<T1, T2>, pair<T3, T4> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = a[i];
    arr[i].first.second = b[i];
    arr[i].second.first = c[i];
    arr[i].second.second = d[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first.first;
    b[i] = arr[i].first.second;
    c[i] = arr[i].second.first;
    d[i] = arr[i].second.second;
  }
}
template<class T> inline int sort_helper_getbit(T A[]){
  return -1;
}
template<> inline int sort_helper_getbit(int A[]){
  return sizeof(int)*8;
}
template<> inline int sort_helper_getbit(unsigned A[]){
  return sizeof(unsigned)*8;
}
template<> inline int sort_helper_getbit(long long A[]){
  return sizeof(long long)*8;
}
template<> inline int sort_helper_getbit(unsigned long long A[]){
  return sizeof(unsigned long long)*8;
}
template<> inline int sort_helper_getbit(char A[]){
  return sizeof(char)*8;
}
template<class T> void sortA_1_int_L(int N, T A[], void *mem = wmem){
  int i;
  int j;
  int k;
  int b;
  int s;
  int ok;
  ok = 1;
  for(i=(1);i<(N);i++){
    if(A[i-1] > A[i]){
      ok = 0;
      break;
    }
  }
  if(ok){
    return;
  }
  if(N < 128){
    sort(A,A+N);
    return;
  }
  b = sort_helper_getbit(A);
  if(b==-1){
    sort(A,A+N);
    return;
  }
  T mn;
  T mx;
  mn = mx = A[0];
  for(i=(1);i<(N);i++){
    chmin(mn, A[i]);
  }
  for(i=(1);i<(N);i++){
    chmax(mx, A[i]);
  }
  ok = 1;
  if(mn < 0 && mx > 0 && (mn < -N || mx > N)){
    ok = 0;
  }
  if(ok && mx - mn > N){
    ok = 0;
  }
  if(ok){
    int*tmp;
    walloc1d(&tmp, mx-mn+1, &mem);
    for(i=(0);i<(mx-mn+1);i++){
      tmp[i] = 0;
    }
    for(i=(0);i<(N);i++){
      tmp[A[i]-mn]++;
    }
    k = 0;
    for(i=(0);i<(mx-mn+1);i++){
      while(tmp[i] > 0){
        tmp[i]--;
        A[k++] = i+mn;
      }
    }
    return;
  }
  {
    typename make_unsigned<T>::type *t[2];
    typename make_unsigned<T>::type  mask;
    typename make_unsigned<T>::type  cur;
    typename make_unsigned<T>::type  one = 1;
    T tone = 1;
    int*pos;
    int nn = 0;
    int ss;
    s =Ilog2_f_L(N);
    if(s > 8){
      s = (8 + (s-7)/2);
    }
    ss = 1;
    for(;;){
      if(ss >= b){
        break;
      }
      if( mx >= 0 && (tone << (ss-1)) < mx ){
        ss++;
        continue;
      }
      if( mn < 0 && -(tone << (ss-1)) >= mn ){
        ss++;
        continue;
      }
      break;
    }
    k =(divup_L(ss,s));
    s =(divup_L(ss,k));
    mask = 0;
    for(i=(0);i<(b);i++){
      if(i < s*k){
        mask |= one << i;
      }
    }
    t[0] = (typename make_unsigned<T>::type *) A;
    walloc1d(&t[1], N, &mem);
    walloc1d(&pos, (1<<s)+1, &mem);
    for(j=(0);j<(k);j++){
      cur = 0;
      for(i=(0);i<(b);i++){
        if(s*j <= i && i < s*(j+1) && i < b){
          cur |= one << i;
        }
      }
      for(i=(0);i<((1<<s)+1);i++){
        pos[i] = 0;
      }
      for(i=(0);i<(N);i++){
        pos[((t[nn][i]&cur)>>(s*j))+1]++;
      }
      for(i=(0);i<((1<<s));i++){
        pos[i+1] += pos[i];
      }
      for(i=(0);i<(N);i++){
        t[nn^1][pos[(t[nn][i]&cur)>>(s*j)]++] = t[nn][i];
      }
      nn ^= 1;
      mask ^= cur;
    }
    if(mn < 0 && mx >= 0){
      k = 0;
      for(i=(0);i<(N);i++){
        if(A[i] < 0){
          k++;
        }
      }
      for(i=(0);i<(k);i++){
        t[nn^1][i] = t[nn][N-k+i];
      }
      for(i=(k);i<(N);i++){
        t[nn^1][i] = t[nn][i-k];
      }
      nn ^= 1;
    }
    if(nn==1){
      for(i=(0);i<(N);i++){
        t[0][i] = t[1][i];
      }
    }
    return;
  }
  sort(A, A+N);
}
template<class T> void sortA_1_nonint_L(int N, T A[], void *mem = wmem){
  sort(A,A+N);
}
template<class T> void sortA_1_call_L(int N, T A[], void *mem = wmem){
  sortA_1_nonint_L(N, A, mem);
}
template<> void sortA_1_call_L(int N, int A[], void *mem){
  sortA_1_int_L(N, A, mem);
}
template<> void sortA_1_call_L(int N, unsigned A[], void *mem){
  sortA_1_int_L(N, A, mem);
}
template<> void sortA_1_call_L(int N, long long A[], void *mem){
  sortA_1_int_L(N, A, mem);
}
template<> void sortA_1_call_L(int N, unsigned long long A[], void *mem){
  sortA_1_int_L(N, A, mem);
}
template<> void sortA_1_call_L(int N, char A[], void *mem){
  sortA_1_int_L(N, A, mem);
}
template<class T1> void sortA(int N, T1 a[], void *mem = wmem){
  sortA_1_call_L(N, a, mem);
}
template<class T1, class T2> void sortA_2_int_L(int N, T1 A[], T2 B[], void *mem = wmem){
  int i;
  int b_a;
  int b_b;
  int s1;
  int s2;
  int so2;
  T1 mn1;
  T1 mx1;
  T2 mn2;
  T2 mx2;
  typename cLtraits_try_make_unsigned<T1>::type r1;
  typename cLtraits_try_make_unsigned<T2>::type r2;
  so2 = 1;
  for(i=(1);i<(N);i++){
    if(A[i-1] > A[i] || (A[i-1]==A[i] && B[i-1] > B[i])){
      so2 = 0;
      break;
    }
  }
  if(so2){
    return;
  }
  so2 = 1;
  for(i=(1);i<(N);i++){
    if(A[i-1] > A[i]){
      so2 = 0;
      break;
    }
  }
  if(so2==1){
    int k = 0;
    for(i=(1);i<(N);i++){
      if(A[i] != A[i-1]){
        sortA_1_call_L(i-k, B+k, mem);
        k = i;
      }
    }
    sortA_1_call_L(N-k, B+k, mem);
    return;
  }
  if(N < 128){
    sortI(N,A,B,mem);
    return;
  }
  b_a = sort_helper_getbit(A);
  b_b = sort_helper_getbit(B);
  if(b_a == -1 || b_b == -1){
    sortI(N,A,B,mem);
    return;
  }
  mn1 = mx1 = A[0];
  for(i=(1);i<(N);i++){
    chmin(mn1, A[i]);
  }
  for(i=(1);i<(N);i++){
    chmax(mx1, A[i]);
  }
  mn2 = mx2 = B[0];
  for(i=(1);i<(N);i++){
    chmin(mn2, B[i]);
  }
  for(i=(1);i<(N);i++){
    chmax(mx2, B[i]);
  }
  if(mn1 < -4611686016279904256LL || mn2 < -4611686016279904256LL || mx1 > 4611686016279904256LL || mx2 > 4611686016279904256LL || mx1-mn1 > 4611686016279904256LL || mx2-mn2 > 4611686016279904256LL){
    sortI(N,A,B,mem);
    return;
  }
  r1 = (typename cLtraits_try_make_unsigned<T1>::type)(mx1) - (typename cLtraits_try_make_unsigned<T1>::type)(mn1);
  r2 = (typename cLtraits_try_make_unsigned<T2>::type)(mx2) - (typename cLtraits_try_make_unsigned<T2>::type)(mn2);
  if(r1 == 0){
    sortA_1_call_L(N, B, mem);
    return;
  }
  if(r2 == 0){
    sortA_1_call_L(N, A, mem);
    return;
  }
  if(r1 <= N){
    so2 = 1;
    for(i=(1);i<(N);i++){
      if(B[i-1] > B[i]){
        so2 = 0;
        break;
      }
    }
    if(so2 == 1){
      T1*aa;
      T2*bb;
      int*pos;
      int k;
      walloc1d(&aa,N,&mem);
      walloc1d(&bb,N,&mem);
      walloc1d(&pos,r1+2,&mem);
      for(i=(0);i<(r1+2);i++){
        pos[i] = 0;
      }
      for(i=(0);i<(N);i++){
        aa[i] = A[i];
      }
      for(i=(0);i<(N);i++){
        bb[i] = B[i];
      }
      for(i=(0);i<(N);i++){
        pos[(typename cLtraits_try_make_unsigned<T1>::type)((typename cLtraits_try_make_unsigned<T1>::type)aa[i]-(typename cLtraits_try_make_unsigned<T1>::type)mn1)+1]++;
      }
      for(i=(1);i<(r1+2);i++){
        pos[i] += pos[i-1];
      }
      for(i=(0);i<(N);i++){
        k = pos[(typename cLtraits_try_make_unsigned<T1>::type)((typename cLtraits_try_make_unsigned<T1>::type)aa[i]-(typename cLtraits_try_make_unsigned<T1>::type)mn1)+0]++;
        A[k] = aa[i];
        B[k] = bb[i];
      }
      return;
    }
  }
  s1 = s2 = 1;
  while( s1 < 64 && r1 >= (1ULL<<s1) ){
    s1++;
  }
  while( s2 < 64 && r2 >= (1ULL<<s2) ){
    s2++;
  }
  if(s1 + s2 <= 32){
    unsigned*tmp;
    walloc1d(&tmp,N,&mem);
    for(i=(0);i<(N);i++){
      tmp[i] = (((unsigned)((int)A[i]-(int)mn1)) << s2) | ((unsigned)((int)B[i]-(int)mn2));
    }
    sortA_1_call_L(N, tmp, mem);
    for(i=(0);i<(N);i++){
      A[i] = ((int)(tmp[i] >> s2)) + ((int)mn1);
      B[i] = ((int)(tmp[i] & ((1U<<s2)-1))) + ((int)mn2);
    }
    return;
  }
  if(s1 + s2 <= 64){
    unsigned long long*tmp;
    walloc1d(&tmp,N,&mem);
    for(i=(0);i<(N);i++){
      tmp[i] = (((unsigned long long)((long long)A[i]-(long long)mn1)) << s2) | ((unsigned long long)((long long)B[i]-(long long)mn2));
    }
    sortA_1_call_L(N, tmp, mem);
    for(i=(0);i<(N);i++){
      A[i] = ((long long)(tmp[i] >> s2)) + ((long long)mn1);
      B[i] = ((long long)(tmp[i] & ((1ULL<<s2)-1))) + ((long long)mn2);
    }
    return;
  }
  sortI(N,A,B,mem);
}
template<class T1, class T2> void sortA_2_nonint_L(int N, T1 A[], T2 B[], void *mem = wmem){
  sortI(N,A,B,mem);
}
template<class T1, class T2> void sortA_2_call_L(int N, T1 A[], T2 B[], void *mem = wmem){
  sortA_2_nonint_L(N, A, B, mem);
}
template<class T2> void sortA_2_call_L(int N, int A[], T2 B[], void *mem){
  sortA_2_int_L(N, A, B, mem);
}
template<class T2> void sortA_2_call_L(int N, unsigned A[], T2 B[], void *mem){
  sortA_2_int_L(N, A, B, mem);
}
template<class T2> void sortA_2_call_L(int N, long long A[], T2 B[], void *mem){
  sortA_2_int_L(N, A, B, mem);
}
template<class T2> void sortA_2_call_L(int N, unsigned long long A[], T2 B[], void *mem){
  sortA_2_int_L(N, A, B, mem);
}
template<class T2> void sortA_2_call_L(int N, char A[], T2 B[], void *mem){
  sortA_2_int_L(N, A, B, mem);
}
template<class T1, class T2> void sortA(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_2_call_L(N, a, b, mem);
}
template<class T1, class T2, class T3> void sortA(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
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
template<class T1, class T2, class T3, class T4> void sortA(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  int i;
  pair<pair<T1, T2>, pair<T3, T4> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = a[i];
    arr[i].first.second = b[i];
    arr[i].second.first = c[i];
    arr[i].second.second = d[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first.first;
    b[i] = arr[i].first.second;
    c[i] = arr[i].second.first;
    d[i] = arr[i].second.second;
  }
}
template<class T1> void rsortA(int N, T1 a[], void *mem = wmem){
  sortA(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
template<class T1, class T2, class T3> void rsortA(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  sortA(N, a, b, c, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
}
template<class T1, class T2, class T3, class T4> void rsortA(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  sortA(N, a, b, c, d, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
  reverse(d, d+N);
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
template<class S> S arrErase(int k, int &sz, S a[]){
  int i;
  S res;
  res = a[k];
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  return res;
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
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
int main(){
  int i;
  wmem = memarr;
  int N;
  rd(N);
  int M;
  rd(M);
  long long A[N];
  {
    int Nzj9Y0kE;
    for(Nzj9Y0kE=(0);Nzj9Y0kE<(N);Nzj9Y0kE++){
      rd(A[Nzj9Y0kE]);
    }
  }
  int ress = 0;
  long long res1[100000];
  long long res2[100000];
  long long x;
  long long y;
  rsortA(N,A);
  while(N > 0){
    int i;
    x = A[0];
    arrErase(0, N, A);
    if(3*x <= M){
      arrInsert(ress, ress, res1, 3*x, res2, 2*x);
      continue;
    }
    y = -1;
    for(i=(0);i<(N);i++){
      if(x%A[i]==0 && x+A[i]+x <= M){
        y = A[i];
        arrErase(i, N, A);
        break;
      }
    }
    if(y==-1){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    arrInsert(ress, ress, res1, x+x+y, res2, x+y);
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]);
    wt_L(' ');
    wt_L(res2[i]);
    wt_L('\n');
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
// cLay version 20220506-1

// --- original code ---
// //no-unlocked
// int @N, @M; ll @A[N];
// int ress = 0; ll res1[1d5], res2[1d5], x, y;
// rsortA(N,A);
// 
// while(N > 0){
//   x = A[0];
//   arrErase(0, N, A);
//   if(3*x <= M){
//     arrInsert(ress, ress, res1, 3*x, res2, 2*x);
//     continue;
//   }
// 
//   y = -1;
//   rep(i,N) if(x%A[i]==0 && x+A[i]+x <= M){
//     y = A[i];
//     arrErase(i, N, A);
//     break;
//   }
//   if(y==-1) wt(-1), return 0;
// 
//   arrInsert(ress, ress, res1, x+x+y, res2, x+y);
// }
// 
// wt(ress);
// rep(i,ress) wt(res1[i], res2[i]);