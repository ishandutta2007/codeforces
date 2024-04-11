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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T, class S> int subsetSum(int n, T a[], S res[]){
  int i;
  int k;
  int sz = 1;
  res[0] = 0;
  for(k=(0);k<(n);k++){
    for(i=(0);i<(sz);i++){
      res[sz+i] = res[i] + a[k];
    }
    sz *= 2;
  }
  return sz;
}
int main(){
  int i, mask;
  wmem = memarr;
  int N;
  rd(N);
  int tot[N] = {};
  int mnv[N] = {};
  int mnt[N] = {};
  map<int,int> mp[N];
  int dp[1<<N] = {};
  int sm[1<<N];
  int res = 0;
  for(i=(0);i<(N);i++){
    int j;
    string S;
    rd(S);
    for(j=(0);j<(S.size());j++){
      if(S[j]=='('){
        tot[i] +=1;
      }
      else{
        tot[i] +=-1;
      }
      if(mnv[i] > tot[i]){
        mnv[i] = tot[i];
        mnt[i] = 0;
      }
      if(mnv[i] == tot[i]){
        mnt[i]++;
      }
      if(mnv[i] == tot[i]){
        mp[i][tot[i]]++;
      }
    }
  }
  subsetSum(N, tot, sm);
  for(i=(1);i<(1<<N);i++){
    dp[i] = -1073709056;
  }
  for(mask=(0);mask<(1<<N);mask++){
    if(dp[mask] >= 0 && sm[mask] >= 0){
      for(i=(0);i<(N);i++){
        if(!((mask) &(1<<(i)))){
          if(sm[mask] + mnv[i] < 0){
            chmax(res, dp[mask] + mp[i][-sm[mask]]);
            continue;
          }
          if(sm[mask] + mnv[i] == 0){
            chmax(dp[mask|(1<<i)], dp[mask] +mnt[i]);
          }
          else{
            chmax(dp[mask|(1<<i)], dp[mask] +0);
          }
        }
      }
    }
  }
  int KrdatlYV;
  cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type ao_dF3pO;
  if(1<<N==0){
    ao_dF3pO = 0;
  }
  else{
    ao_dF3pO = dp[0];
    for(KrdatlYV=(1);KrdatlYV<(1<<N);KrdatlYV++){
      ao_dF3pO = max_L(ao_dF3pO, dp[KrdatlYV]);
    }
  }
  chmax(res, ao_dF3pO);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @N, tot[N] = {}, mnv[N] = {}, mnt[N] = {}; map<int,int> mp[N];
// int dp[1<<N] = {}, sm[1<<N], res = 0;
// rep(i,N){
//   string @S;
//   rep(j,S.size()){
//     tot[i] += if[S[j]=='(', 1, -1];
//     if(mnv[i] > tot[i]) mnv[i] = tot[i], mnt[i] = 0;
//     if(mnv[i] == tot[i]) mnt[i]++;
//     if(mnv[i] == tot[i]) mp[i][tot[i]]++;
//   }
// }
// subsetSum(N, tot, sm);
// rep(i,1,1<<N) dp[i] = -int_inf;
// rep(mask,1<<N) if(dp[mask] >= 0 && sm[mask] >= 0) rep(i,N) if(!BIT_ith(mask,i)){
//   if(sm[mask] + mnv[i] < 0){
//     res >?= dp[mask] + mp[i][-sm[mask]];
//     continue;
//   }
//   dp[mask|(1<<i)] >?= dp[mask] + if[sm[mask] + mnv[i] == 0, mnt[i], 0];
// }
// res >?= max(dp(1<<N));
// wt(res);