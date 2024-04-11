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
long long cost[5][5];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int ao_dF3pO, i;
    long long X;
    long long Y;
    long long C[6];
    long long mn;
    long long mx;
    long long res;
    long long fx;
    long long fy;
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(6);cTE1_r3A++){
        rd(C[cTE1_r3A]);
      }
    }
    for(i=(-2);i<(3);i++){
      int j;
      for(j=(-2);j<(3);j++){
        cost[i+2][j+2] = 4611686016279904256LL;
      }
    }
    cost[0+2][0+2] = 0;
    cost[1+2][1+2] = C[0];
    cost[0+2][1+2] = C[1];
    cost[-1+2][0+2] = C[2];
    cost[-1+2][-1+2] = C[3];
    cost[0+2][-1+2] = C[4];
    cost[1+2][0+2] = C[5];
    for(ao_dF3pO=(0);ao_dF3pO<(5);ao_dF3pO++){
      for(i=(-2);i<(3);i++){
        int j;
        for(j=(-2);j<(3);j++){
          int k;
          for(k=(-2);k<(3);k++){
            int l;
            for(l=(-2);l<(3);l++){
              if(-2 <= i+k  &&  i+k < 3 && -2 <= j+l  &&  j+l < 3){
                chmin(cost[i+k+2][j+l+2], cost[i+2][j+2] + cost[k+2][l+2]);
              }
            }
          }
        }
      }
    }
    mn =min_L(abs(X), abs(Y));
    mx =max_L(abs(X), abs(Y));
    if(X>=0){
      fx =1;
    }
    else{
      fx =-1;
    }
    if(Y>=0){
      fy =1;
    }
    else{
      fy =-1;
    }
    res = mn * cost[fx+2][fy+2];
    if(abs(X) > abs(Y)){
      res += (mx-mn) * cost[fx+2][0+2];
    }
    if(abs(X) < abs(Y)){
      res += (mx-mn) * cost[0+2][fy+2];
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201018-2

// --- original code ---
// //no-unlocked
// ll cost[5][5];
// {
//   REP(rd_int()){
//     ll X, Y, C[6], mn, mx, res, fx, fy;
//     rd(X,Y,C(6));
//     rep(i,-2,3) rep(j,-2,3) cost[i+2][j+2] = ll_inf;
//     cost[0+2][0+2] = 0;
//     cost[1+2][1+2] = C[0];
//     cost[0+2][1+2] = C[1];
//     cost[-1+2][0+2] = C[2];
//     cost[-1+2][-1+2] = C[3];
//     cost[0+2][-1+2] = C[4];
//     cost[1+2][0+2] = C[5];
//     rep(5) rep(i,-2,3) rep(j,-2,3) rep(k,-2,3) rep(l,-2,3) if(-2 <= i+k < 3 && -2 <= j+l < 3) cost[i+k+2][j+l+2] <?= cost[i+2][j+2] + cost[k+2][l+2];
//     mn = min(abs(X), abs(Y));
//     mx = max(abs(X), abs(Y));
//     fx = if[X>=0, 1, -1];
//     fy = if[Y>=0, 1, -1];
//     res = mn * cost[fx+2][fy+2];
//     if(abs(X) > abs(Y)) res += (mx-mn) * cost[fx+2][0+2];
//     if(abs(X) < abs(Y)) res += (mx-mn) * cost[0+2][fy+2];
//     wt(res);
//   }
// }