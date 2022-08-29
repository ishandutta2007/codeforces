#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N[3];
long long s[3];
long long mn[3] = {4611686016279904256LL, 4611686016279904256LL, 4611686016279904256LL};
int main(){
  int i;
  long long res = 4611686016279904256LL;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(3);Lj4PdHRW++){
      rd(N[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(3);i++){
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N[i]);RZTsC2BF++){
      int A;
      rd(A);
      s[i] += A;
      chmin(mn[i], A);
    }
  }
  {
    int WYIGIcGE;
    long long t_ynMSdg;
    if(3==0){
      t_ynMSdg = 0;
    }
    else{
      t_ynMSdg = mn[0];
      for(WYIGIcGE=(1);WYIGIcGE<(3);WYIGIcGE++){
        t_ynMSdg = max_L(t_ynMSdg, mn[WYIGIcGE]);
      }
    }
    {
      int tU__gIr_;
      long long a2conNHc;
      if(3==0){
        a2conNHc = 0;
      }
      else{
        a2conNHc = mn[0];
        for(tU__gIr_=(1);tU__gIr_<(3);tU__gIr_++){
          a2conNHc += mn[tU__gIr_];
        }
      }
      chmin(res, a2conNHc-t_ynMSdg);
    }
  }
  {
    int APIVbQlN;
    long long YREPHmFM;
    if(3==0){
      YREPHmFM = 0;
    }
    else{
      YREPHmFM = s[0];
      for(APIVbQlN=(1);APIVbQlN<(3);APIVbQlN++){
        YREPHmFM = min_L(YREPHmFM, s[APIVbQlN]);
      }
    }
    chmin(res, YREPHmFM);
  }
  {
    int ZIeRIny5;
    long long iMWUTgY_;
    if(3==0){
      iMWUTgY_ = 0;
    }
    else{
      iMWUTgY_ = s[0];
      for(ZIeRIny5=(1);ZIeRIny5<(3);ZIeRIny5++){
        iMWUTgY_ += s[ZIeRIny5];
      }
    }
    wt_L(iMWUTgY_- 2*res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N[3]; ll s[3], mn[3] = {ll_inf, ll_inf, ll_inf};
// {
//   ll res = ll_inf;
//   rd(N(3));
//   rep(i,3) rep(N[i]){
//     int @A;
//     s[i] += A;
//     mn[i] <?= A;
//   }
//   res <?= sum(mn(3)) - max(mn(3));
//   res <?= min(s(3));
//   wt(sum(s(3)) - 2*res);
// }