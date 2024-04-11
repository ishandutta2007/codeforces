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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void rd(string &x){
  char*buf = (char *)wmem;
  rd(buf);
  x = buf;
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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T*val = (T*) val_s;
  int*len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void*mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
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
int N;
long long A;
long long B;
long long C;
string S;
long long baka_dfs(string s, int nx){
  long long res = 0;
  long long tmp;
  if(nx == 0){
    int i;
    for(i=(0);i<(s.size());i++){
      if(s[i]=='0'){
        tmp = 0;
        if(s[i+1] == '0'){
          tmp = A;
        }
        else{
          tmp = -C;
        }
        tmp += baka_dfs(s.substr(0,i) + s.substr(i+1), 1);
        chmax(res, tmp);
      }
    }
  }
  else{
    int i;
    for(i=(1);i<(s.size());i++){
      if(s[i]==s[i-1] && s[i-1]=='1'){
        tmp = baka_dfs(s.substr(0,i) + s.substr(i+1), 0) + B;
        chmax(res, tmp);
      }
    }
  }
  return res;
}
long long baka(string s){
  return max_L(baka_dfs(s, 0), baka_dfs(s, 1));
}
int nn;
int arrr[200000];
int sz;
int arr[200000];
int len[200000];
int s;
int a[200000];
int l[200000];
int ss;
int v[200000];
int g[200000];
long long solve1(){
  int i;
  int z = 0;
  int o = 0;
  s = sz;
  for(i=(0);i<(s);i++){
    auto xr20shxY = ((arr[i]));
    auto WYIGIcGE = (( len[i]));
    a[i]=xr20shxY;
    l[i]=WYIGIcGE;
  }
  for(i=(0);i<(s);i++){
    if(a[i]==0){
      z += l[i] - 1;
    }
  }
  for(i=(0);i<(s);i++){
    if(a[i]==1){
      o += l[i] - 1;
    }
  }
  chmin(z, o+1);
  chmin(o, z+1);
  return z * A + o * B;
}
long long solve2(int f, int r){
  int o = 0;
  int i;
  int j;
  long long res = 0;
  long long tmp = 0;
  s = sz;
  for(i=(0);i<(s);i++){
    auto V9aVTaxx = ((arr[i]));
    auto APIVbQlN = (( len[i]));
    a[i]=V9aVTaxx;
    l[i]=APIVbQlN;
  }
  ss = 0;
  for(i=(1);i<(s-1);i++){
    if(a[i]==0){
      arrInsert(ss, ss, v, len[i], g, 1);
    }
  }
  if(a[0]==0){
    arrInsert(ss, ss, v, len[0], g, 0);
  }
  if(a[s-1]==0){
    arrInsert(ss, ss, v, len[s-1], g, 0);
  }
  if(((r) &(1<<(0)))){
    for(i=(0);i<(ss);i++){
      g[i] = -g[i];
    }
  }
  if(((r) &(1<<(1)))){
    for(i=(0);i<(ss);i++){
      v[i] = -v[i];
    }
  }
  if(((r) &(1<<(3)))){
    sortA_L(ss, g, v);
  }
  else{
    sortA_L(ss, v, g);
  }
  if(((r) &(1<<(0)))){
    for(i=(0);i<(ss);i++){
      g[i] = -g[i];
    }
  }
  if(((r) &(1<<(1)))){
    for(i=(0);i<(ss);i++){
      v[i] = -v[i];
    }
  }
  if(((r) &(1<<(2)))){
    reverse(g,g+ss);
    reverse(v,v+ss);
  }
  for(i=(0);i<(s);i++){
    if(a[i]==1){
      o += l[i] - 1;
    }
  }
  i = 0;
  if(f && o){
    tmp += B;
    o--;
    chmax(res, tmp);
  }
  while(i < ss){
    if(i+1 < ss && g[i]==g[i+1] && g[i+1]==0){
      if(v[i+1] > v[i]){
        swap(v[i+1], v[i]);
      }
      ;
    }
    if(v[i] > 1){
      v[i]--;
      tmp += A;
      chmax(res, tmp);
    }
    else{
      v[i]--;
      tmp -= C;
      o += g[i];
      i++;
      chmax(res, tmp);
    }
    if(!o){
      break;
    }
    tmp += B;
    o--;
    chmax(res, tmp);
  }
  return res;
}
long long solve(string s){
  int i;
  long long res = 0;
  long long tmp = 0;
  nn = s.size();
  for(i=(0);i<(nn);i++){
    arrr[i] = s[i] - '0';
  }
  sz = runLength(nn, arrr, arr, len);
  chmax(res, solve1());
  for(i=(0);i<(2);i++){
    int k;
    for(k=(0);k<(16);k++){
      chmax(res, solve2(i, k));
    }
  }
  return res;
}
int main(){
  int H31bcJ8S;
  wmem = memarr;
  int dtiCQK_a = rd_int();
  for(H31bcJ8S=(0);H31bcJ8S<(dtiCQK_a);H31bcJ8S++){
    rd(N);
    rd(A);
    rd(B);
    rd(C);
    rd(S);
    wt_L(solve(S));
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
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int N; ll A, B, C;
// string S;
// 
// ll baka_dfs(string s, int nx){
//   ll res = 0, tmp;
//   if(nx == 0){
//     rep(i,s.size()) if(s[i]=='0'){
//       tmp = 0;
//       if(s[i+1] == '0') tmp = A;
//       else              tmp = -C;
//       tmp += baka_dfs(s.substr(0,i) + s.substr(i+1), 1);
//       res >?= tmp;
//     }
//   } else {
//     rep(i,1,s.size()) if(s[i]==s[i-1]=='1'){
//       tmp = baka_dfs(s.substr(0,i) + s.substr(i+1), 0) + B;
//       res >?= tmp;
//     }
//   }
//   return res;
// }
// 
// ll baka(string s){
//   return max(baka_dfs(s, 0), baka_dfs(s, 1));
// }
// 
// 
// int nn, arrr[2d5];
// int sz, arr[], len[];
// int s, a[], l[], ss, v[], g[];
// 
// ll solve1(){
//   int z = 0, o = 0;
// 
//   s = sz;
//   rep(i,s) (a[i], l[i]) = (arr[i], len[i]);
// 
//   rep(i,s) if(a[i]==0) z += l[i] - 1;
//   rep(i,s) if(a[i]==1) o += l[i] - 1;
//   z <?= o+1;
//   o <?= z+1;
//   return z * A + o * B;
// }
// 
// ll solve2(int f, int r){
//   int o = 0, i, j;
//   ll res = 0, tmp = 0;
// 
//   s = sz;
//   rep(i,s) (a[i], l[i]) = (arr[i], len[i]);
// 
//   ss = 0;
//   rep(i,1,s-1) if(a[i]==0) arrInsert(ss, ss, v, len[i], g, 1);
//   if(a[0]==0) arrInsert(ss, ss, v, len[0], g, 0);
//   if(a[s-1]==0) arrInsert(ss, ss, v, len[s-1], g, 0);
// 
//   if(BIT_ith(r,0)) rep(i,ss) g[i] = -g[i];
//   if(BIT_ith(r,1)) rep(i,ss) v[i] = -v[i];
//   if(BIT_ith(r,3)) sortA(ss, g, v); else sortA(ss, v, g);
//   if(BIT_ith(r,0)) rep(i,ss) g[i] = -g[i];
//   if(BIT_ith(r,1)) rep(i,ss) v[i] = -v[i];
//   if(BIT_ith(r,2)) reverse(g,g+ss), reverse(v,v+ss);
// 
//   rep(i,s) if(a[i]==1) o += l[i] - 1;
// 
//   i = 0;
//   if(f && o){
//     tmp += B;
//     o--;
//     res >?= tmp;
//   }
//   while(i < ss){
//     if(i+1 < ss && g[i]==g[i+1]==0) sortE(v[i+1], v[i]);
//     if(v[i] > 1){
//       v[i]--;
//       tmp += A;
//       res >?= tmp;
//     } else {
//       v[i]--;
//       tmp -= C;
//       o += g[i];
//       i++;
//       res >?= tmp;
//     }
//     if(!o) break;
//     tmp += B;
//     o--;
//     res >?= tmp;
//   }
// 
//   return res;
// }
// 
// ll solve(string s){
//   ll res = 0, tmp = 0;
// 
//   nn = s.size();
//   rep(i,nn) arrr[i] = s[i] - '0';
//   sz = runLength(nn, arrr, arr, len);
// 
//   res >?= solve1();
//   rep(i,2) rep(k,16) res >?= solve2(i, k);
// 
//   return res;
// }
// 
// {
//   // for(;;){
//   //   ll baka_res, res;
//   //   A = rand()%100 + 1;
//   //   B = rand()%100 + 1;
//   //   C = rand()%100 + 1;
//   //   N = rand()%10 + 2;
//   //   S = "";
//   //   rep(i,N) S += (char)(rand()%2 + '0');
// 
//   //   baka_res = baka(S);
//   //   res = solve(S);
// 
//   //   wt(S, A, B, C);
//   //   wt(baka_res, res);
//   //   assert(baka_res == res);
//   // }
//   // puts("");
// 
//   REP(rd_int()){
//     rd(N,A,B,C,S);
//     wt(solve(S));
//   }
// }