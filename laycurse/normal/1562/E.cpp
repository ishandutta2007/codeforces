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
template<class T> void SuffixArray(T *s, int N, int K, int *SA, int *LCP = NULL, void *mem = wmem){
  int i;
  int j;
  int d;
  int m;
  int*s1;
  int name;
  int prev;
  int pos;
  char*t;
  char*lms;
  int*cnt;
  int*cnt1;
  int*cnt2;
  walloc1d(&t, N+1, &mem);
  walloc1d(&lms, N+1, &mem);
  walloc1d(&cnt, K+1, &mem);
  walloc1d(&cnt1, K+1, &mem);
  walloc1d(&cnt2, K+1, &mem);
  N++;
  s[N-1] = 0;
  t[N-1] = 1;
  t[N-2] = 0;
  for(i=N-3;i>=0;i--){
    if(s[i] < s[i+1] || (s[i]==s[i+1] && t[i+1])){
      t[i] = 1;
    }
    else{
      t[i] = 0;
    }
  }
  lms[0] = 0;
  int KaFyNJB9 = N;
  for(i=(1);i<(KaFyNJB9);i++){
    if(t[i] && !t[i-1]){
      lms[i] = 1;
    }
    else{
      lms[i] = 0;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt1[i] = 0;
  }
  for(i=(0);i<(N);i++){
    cnt1[s[i]]++;
  }
  j = 0;
  for(i=(0);i<(K+1);i++){
    j += cnt1[i];
    cnt2[i] = j - cnt1[i];
    cnt1[i] = j;
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=0; i<N; i++){
    SA[i] = -1;
  }
  for(i=1; i<N; i++){
    if(lms[i]){
      SA[--cnt[s[i]]]=i;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt2[i];
  }
  for(i=(0);i<(N);i++){
    j = SA[i]-1;
    if(j>=0 && !t[j]){
      SA[cnt[s[j]]++] = j;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=N-1;i>=0;i--){
    j = SA[i] - 1;
    if(j>=0 && t[j]){
      SA[--cnt[s[j]]] = j;
    }
  }
  m = 0;
  for(i=(0);i<(N);i++){
    if(lms[SA[i]]){
      SA[m++] = SA[i];
    }
  }
  int mRLrOZDI = N;
  for(i=(m);i<(mRLrOZDI);i++){
    SA[i] = -1;
  }
  name=0;
  prev=-1;
  for(i=(0);i<(m);i++){
    pos = SA[i];
    for(d=(0);d<(N);d++){
      if(prev==-1 || s[pos+d]!=s[prev+d] || t[pos+d]!=t[prev+d]){
        name++;
        prev=pos;
        break;
      }
      else if(d>0 && (lms[pos+d] || lms[prev+d])){
        break;
      }
    }
    pos /= 2;
    SA[m+pos]=name-1;
  }
  for(i=N-1, j=N-1; i>=m; i--){
    if(SA[i]>=0){
      SA[j--]=SA[i];
    }
  }
  s1 = SA+N-m;
  if(name<m){
    SuffixArray(s1, m-1, name-1, SA, NULL, mem);
  }
  else{
    for(i=0; i<m; i++){
      SA[s1[i]] = i;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=1, j=0; i<N; i++){
    if(lms[i]){
      s1[j++]=i;
    }
  }
  for(i=0; i<m; i++){
    SA[i]=s1[SA[i]];
  }
  for(i=m; i<N; i++){
    SA[i]=-1;
  }
  for(i=m-1; i>=0; i--){
    j=SA[i];
    SA[i]=-1;
    SA[--cnt[s[j]]]=j;
  }
  for(i=(0);i<(N);i++){
    j = SA[i]-1;
    if(j>=0 && !t[j]){
      SA[cnt2[s[j]]++] = j;
    }
  }
  for(i=N-1;i>=0;i--){
    j = SA[i] - 1;
    if(j>=0 && t[j]){
      SA[--cnt1[s[j]]] = j;
    }
  }
  if(LCP != NULL){
    cnt = (int*)t;
    d = 0;
    for(i=(0);i<(N);i++){
      cnt[SA[i]] = i;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        for(j=SA[cnt[i]-1]; j+d<N-1&&i+d<N-1&&s[j+d]==s[i+d];d++){
          ;
        }
        LCP[cnt[i]]=d;
      }
      else{
        LCP[cnt[i]] = -1;
      }
      if(d>0){
        d--;
      }
    }
  }
}
int N;
char S[5002];
int sa[5002];
int lcp[5002];
int dp[5002];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    SuffixArray(S,N,128,sa,lcp);
    for(i=(0);i<(N+1);i++){
      dp[i] = 0;
    }
    for(i=(1);i<(N+1);i++){
      int j;
      int mx = 1073709056;
      for(j=(i)-1;j>=(1);j--){
        chmin(mx, lcp[j+1]);
        if(sa[j] < sa[i]){
          chmax(dp[sa[i]], dp[sa[j]] - mx);
        }
      }
      dp[sa[i]] += N - sa[i];
    }
    int KrdatlYV;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type ao_dF3pO;
    if(N==0){
      ao_dF3pO = 0;
    }
    else{
      ao_dF3pO = dp[0];
      for(KrdatlYV=(1);KrdatlYV<(N);KrdatlYV++){
        ao_dF3pO = max_L(ao_dF3pO, dp[KrdatlYV]);
      }
    }
    wt_L(ao_dF3pO);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[5002];
// int sa[], lcp[], dp[];
// {
//   REP(rd_int()){
//     rd(N,S);
//     SuffixArray(S,N,128,sa,lcp);
//     rep(i,N+1) dp[i] = 0;
//     rep(i,1,N+1){
//       int mx = int_inf;
//       rrep(j,1,i){
//         mx <?= lcp[j+1];
//         if(sa[j] < sa[i]) dp[sa[i]] >?= dp[sa[j]] - mx;
//       }
//       dp[sa[i]] += N - sa[i];
//     }
//     wt(max(dp(N)));
//   }
// }