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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int X;
int Y;
char S[2000][2002];
int dp[2000][2000];
int vis[2000][2000];
int s[4000000+2];
int sz;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int ni;
    int nj;
    int ti;
    int tj;
    int going;
    int tmp;
    int ad;
    int res;
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    dimcomp2 dm(X,Y);
    going = 0;
    for(i=(0);i<(X);i++){
      for(j=(0);j<(Y);j++){
        dp[i][j] = vis[i][j] = -1;
      }
    }
    for(i=(0);i<(X);i++){
      for(j=(0);j<(Y);j++){
        if(dp[i][j] == -1){
          sz = 0;
          ad = 0;
          auto V9aVTaxx = ((i));
          auto APIVbQlN = ((j));
          ni=V9aVTaxx;
          nj=APIVbQlN;
          s[sz++] = dm(ni,nj);
          vis[ni][nj] = ++going;
          for(;;){
            if(S[ni][nj] == 'U'){
              ni--;
            }
            else if(S[ni][nj] == 'D'){
              ni++;
            }
            else if(S[ni][nj] == 'L'){
              nj--;
            }
            else if(S[ni][nj] == 'R'){
              nj++;
            }
            if(ni < 0 || nj < 0 || ni >= X || nj >= Y){
              break;
            }
            if(vis[ni][nj] == going){
              break;
            }
            if(dp[ni][nj] > 0){
              ad = dp[ni][nj];
              break;
            }
            vis[ni][nj] = going;
            s[sz++] = dm(ni,nj);
          }
          tmp = -1;
          for(k=(0);k<(sz);k++){
            dm(s[k], ti, tj);
            if(ti == ni && tj == nj){
              tmp = sz - k;
            }
            dp[ti][tj] =max_L(sz - k, tmp)+ ad;
          }
        }
      }
    }
    res = 0;
    for(i=(0);i<(X);i++){
      for(j=(0);j<(Y);j++){
        chmax(res, dp[i][j]);
      }
    }
    for(i=(0);i<(X);i++){
      for(j=(0);j<(Y);j++){
        if(res==dp[i][j]){
          wt_L(i+1);
          wt_L(' ');
          wt_L(j+1);
          wt_L(' ');
          wt_L(res);
          wt_L('\n');
          goto GgkpftXM;
        }
      }
    }
    GgkpftXM:;
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// //working_memory=1m
// int X, Y; char S[2000][2002];
// int dp[2000][2000], vis[2000][2000];
// int s[4d6+2], sz;
// 
// {
//   REP(rd_int()){
//     int i, j, k, ni, nj, ti, tj, going, tmp, ad, res;
//     rd(X,Y,S(X));
//     dimcomp2 dm(X,Y);
// 
//     going = 0;
//     rep(i,X) rep(j,Y) dp[i][j] = vis[i][j] = -1;
//     rep(i,X) rep(j,Y) if(dp[i][j] == -1){
//       sz = 0;
//       ad = 0;
//       (ni,nj) = (i,j);
//       s[sz++] = dm(ni,nj);
//       vis[ni][nj] = ++going;
//       for(;;){
//         if(S[ni][nj] == 'U') ni--;
//         else if(S[ni][nj] == 'D') ni++;
//         else if(S[ni][nj] == 'L') nj--;
//         else if(S[ni][nj] == 'R') nj++;
// 
//         if(ni < 0 || nj < 0 || ni >= X || nj >= Y) break;
//         if(vis[ni][nj] == going) break;
//         if(dp[ni][nj] > 0) ad = dp[ni][nj], break;
//         vis[ni][nj] = going;
//         s[sz++] = dm(ni,nj);
//       }
//       tmp = -1;
//       rep(k,sz){
//         dm(s[k], ti, tj);
//         if(ti == ni && tj == nj) tmp = sz - k;
//         dp[ti][tj] = max(sz - k, tmp) + ad;
//       }
//     }
// 
//     res = 0;
//     rep(i,X) rep(j,Y) res >?= dp[i][j];
//     rep(i,X) rep(j,Y) if(res==dp[i][j]){
//       wt(i+1,j+1,res);
//       break_break;
//     }
//   }
// }