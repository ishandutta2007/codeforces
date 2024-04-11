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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
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
struct Permutation{
  int n;
  int mem;
  int*dat;
  Permutation(){
    n = mem = 0;
  }
  Permutation(const int nn){
    n = mem = nn;
    if(mem > 0){
      dat = new int[mem];
    }
  }
  Permutation(const Permutation &a){
    int i;
    mem = n = a.n;
    dat = new int[mem];
    for(i=(0);i<(mem);i++){
      dat[i] = a.dat[i];
    }
  }
  ~Permutation(){
    if(mem){
      delete [] dat;
    }
  }
  void changeSize(const int nn){
    n = nn;
    if(mem < n){
      if(mem){
        delete [] dat;
      }
      mem = n;
      dat = new int[mem];
    }
  }
  Permutation& operator=(const Permutation &a){
    int i;
    changeSize(a.n);
    n = a.n;
    for(i=(0);i<(n);i++){
      dat[i] = a.dat[i];
    }
    return *this;
  }
  Permutation& operator=(const int a){
    int i;
    for(i=(0);i<(n);i++){
      dat[i] = i;
    }
    return *this;
  }
  Permutation& operator*=(const Permutation &a){
    int i;
    int*m;
    void*mv = wmem;
    if(n==0 || n!=a.n){
      changeSize(0);
      return *this;
    }
    walloc1d(&m, n, &mv);
    for(i=(0);i<(n);i++){
      m[i] = dat[a.dat[i]];
    }
    for(i=(0);i<(n);i++){
      dat[i] = m[i];
    }
    return *this;
  }
  Permutation operator*(const Permutation &a){
    return Permutation(*this) *= a;
  }
  bool operator==(const Permutation &a){
    int i;
    if(n != a.n){
      return false;
    }
    for(i=(0);i<(n);i++){
      if(dat[i] != a.dat[i]){
        return false;
      }
    }
    return true;
  }
  template<class T> void apply(T A[]){
    int i;
    T*B;
    void*mv = wmem;
    walloc1d(&B, n, &mv);
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
    for(i=(0);i<(n);i++){
      A[i] = B[i];
    }
  }
  template<class T> void apply(T A[], T B[]){
    int i;
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
  }
  int cycle_len(int res[] = NULL){
    int i;
    int j;
    int k;
    int sz = 0;
    int*vis;
    void*mv = wmem;
    if(res==NULL){
      walloc1d(&res, n, &mv);
    }
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        res[sz++] = k;
      }
    }
    return sz;
  }
  void cycle_len_EachElement(int res[]){
    int i;
    int j;
    int k;
    int sz = 0;
    int*vis;
    void*mv = wmem;
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        j = i;
        while(vis[j]==1){
          res[j] = k;
          vis[j] = 2;
          j = dat[j];
        }
      }
    }
  }
  template<class T> inline T getIndex(void *mem = wmem){
    int i;
    fenwick<int> t;
    T res;
    T*fac;
    walloc1d(&fac,n,&mem);
    fac[0] = 1;
    for(i=(1);i<(n);i++){
      fac[i] = i * fac[i-1];
    }
    t.walloc(n,&mem);
    t.init(n);
    for(i=(0);i<(n);i++){
      t.add(i,1);
    }
    res = 0;
    for(i=(0);i<(n);i++){
      t.add(dat[i], -1);
      res += fac[n-1-i] * t.get(dat[i]-1);
    }
    return res;
  }
  inline int& operator[](const int a){
    return dat[a];
  }
}
;
template<class S> inline Permutation pow_L(Permutation a, S b){
  Permutation res;
  res.changeSize(a.n);
  res = 1;
  while(b){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    a *= a;
  }
  return res;
}
int N;
int A[200000];
int B[200000];
int sz;
int len[200000];
Permutation P;
long long solve(){
  int i, m;
  int x;
  int y;
  int odd;
  sortA(N,A,B);
  P.changeSize(N);
  for(i=(0);i<(N);i++){
    P[i] = B[i];
  }
  sz = P.cycle_len(len);
  auto WKqLrJHZ = ((0));
  auto QAAnbtfa = (( 0));
  x=WKqLrJHZ;
  y=QAAnbtfa;
  rsortA(sz, len);
  int om7Ebh6q;
  remove_reference<decltype(len[om7Ebh6q]%2)>::type bs24PFPc;
  int R5MtCiij = 0;
  if((0) > ((sz)-1)){
    bs24PFPc = 0;
  }
  else{
    for(om7Ebh6q = 0; om7Ebh6q <= (sz)-1; om7Ebh6q++){
      if(R5MtCiij == 0){
        bs24PFPc = len[om7Ebh6q]%2;
        R5MtCiij = 1;
        continue;
      }
      bs24PFPc += len[om7Ebh6q]%2;
    }
    if(R5MtCiij==0){
      bs24PFPc = 0;
    }
  }
  odd =bs24PFPc;
  for(i=(0);i<(N);i++){
    A[i] = abs( i - (N-1-i) );
  }
  sortA(N,A);
  for(i=(0);i<(odd);i++){
    A[i] = 0;
  }
  int myTeyldV;
  long long PON0fmpo;
  int QDGVCdl1 = 0;
  if((0) > ((N)-1)){
    PON0fmpo = 0;
  }
  else{
    for(myTeyldV = 0; myTeyldV <= (N)-1; myTeyldV++){
      if(QDGVCdl1 == 0){
        PON0fmpo = A[myTeyldV];
        QDGVCdl1 = 1;
        continue;
      }
      PON0fmpo += A[myTeyldV];
    }
    if(QDGVCdl1==0){
      PON0fmpo = 0;
    }
  }
  return PON0fmpo;
  for(m=(0);m<(2);m++){
    for(i=(0);i<(sz);i++){
      if(len[i]%2==m){
        while(len[i] >= 2){
          len[i] -= 2;
          A[x] = N-1-y;
          A[N-1-y] = x;
          x++;
          y++;
        }
        while(len[i] >= 1){
          len[i] -= 1;
          if(x <= y){
            A[x] = x;
            x++;
          }
          else{
            A[N-1-y] = N-1-y;
            y++;
          }
        }
      }
    }
  }
  int EEPmwYOn;
  long long hUQRwZho;
  int Wrqvy1ft = 0;
  if((0) > ((N)-1)){
    hUQRwZho = 0;
  }
  else{
    for(EEPmwYOn = 0; EEPmwYOn <= (N)-1; EEPmwYOn++){
      if(Wrqvy1ft == 0){
        hUQRwZho = abs(A[EEPmwYOn]-EEPmwYOn);
        Wrqvy1ft = 1;
        continue;
      }
      hUQRwZho += abs(A[EEPmwYOn]-EEPmwYOn);
    }
    if(Wrqvy1ft==0){
      hUQRwZho = 0;
    }
  }
  return hUQRwZho;
}
long long baka(){
  long long res = -1;
  int p[N];
  {
    int EMcy9lTZ;
    for(EMcy9lTZ=(0);EMcy9lTZ<(N);EMcy9lTZ++){
      p[EMcy9lTZ] = EMcy9lTZ;
    }
    do{
      int tJNX206o;
      remove_reference<decltype(abs(p[A[tJNX206o]] - p[B[tJNX206o]]))>::type eqyD9srr;
      int bjcqzcDo = 0;
      if((0) > ((N)-1)){
        eqyD9srr = 0;
      }
      else{
        for(tJNX206o = 0; tJNX206o <= (N)-1; tJNX206o++){
          if(bjcqzcDo == 0){
            eqyD9srr = abs(p[A[tJNX206o]] - p[B[tJNX206o]]);
            bjcqzcDo = 1;
            continue;
          }
          eqyD9srr += abs(p[A[tJNX206o]] - p[B[tJNX206o]]);
        }
        if(bjcqzcDo==0){
          eqyD9srr = 0;
        }
      }
      chmax(res, eqyD9srr);
    }
    while(next_permutation(p,p+N));
  }
  return res;
}
int main(){
  int SIhclzWv;
  wmem = memarr;
  int uqw8QKdv = rd_int();
  for(SIhclzWv=(0);SIhclzWv<(uqw8QKdv);SIhclzWv++){
    rd(N);
    {
      int bU36gMow;
      for(bU36gMow=(0);bU36gMow<(N);bU36gMow++){
        rd(A[bU36gMow]);A[bU36gMow] += (-1);
      }
    }
    {
      int gx9SJKIt;
      for(gx9SJKIt=(0);gx9SJKIt<(N);gx9SJKIt++){
        rd(B[gx9SJKIt]);B[gx9SJKIt] += (-1);
      }
    }
    wt_L(solve());
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
// cLay version 20220506-1

// --- original code ---
// //no-unlocked
// 
// int N, A[2d5], B[];
// int sz, len[];
// Permutation P;
// 
// ll solve(){
//   int x, y, odd;
//   sortA(N,A,B);
//   P.changeSize(N);
//   rep(i,N) P[i] = B[i];
//   sz = P.cycle_len(len);
// 
//   (x, y) = (0, 0);
//   rsortA(sz, len);
//   odd = sum[i,0,sz](len[i]%2);
//   rep(i,N) A[i] = abs( i - (N-1-i) );
//   sortA(N,A);
//   rep(i,odd) A[i] = 0;
//   return sum[ll][i,0,N](A[i]);
// 
//   rep(m,2) rep(i,sz) if(len[i]%2==m){
//     while(len[i] >= 2){
//       len[i] -= 2;
//       A[x] = N-1-y;
//       A[N-1-y] = x;
//       x++; y++;
//     }
//     while(len[i] >= 1){
//       len[i] -= 1;
//       if(x <= y){
//         A[x] = x;
//         x++;
//       } else {
//         A[N-1-y] = N-1-y;
//         y++;
//       }
//     }
//   }
//   return sum[ll][i,0,N](abs(A[i]-i));
// }
// 
// ll baka(){
//   ll res = -1;
//   int p[N];
//   rep_perm(p,N) res >?= sum[i,0,N](abs(p[A[i]] - p[B[i]]));
//   return res;
// }
// 
// {
//   // for(;;){
//   //   ll r1, r2;
//   //   N = rand()%9 + 1;
//   //   rep(i,N) A[i] = B[i] = i;
//   //   // random_shuffle(A,A+N);
//   //   random_shuffle(B,B+N);
//   //   wt(N, ":", A(N), ":", B(N));
//   //   r1 = baka();
//   //   r2 = solve();
//   //   wt(r1, r2);
//   //   assert(r1==r2);
//   // }
//   // return 0;
//   // puts("");
// 
//   REP(rd_int()){
//     rd(N,(A--)(N),(B--)(N));
//     // wt(baka());
//     wt(solve());
//   }
// }