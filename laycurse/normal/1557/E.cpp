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
  return getchar();
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int mp[8][8];
int nx[8][8];
void q(int x, int y, int &dx, int &dy){
  string s;
  wt_L(x+1);
  wt_L(' ');
  wt_L(y+1);
  wt_L('\n');
  rd(s);
  if(s=="Right"){
    dx = 0;
    dy = 1;
  }
  if(s=="Left"){
    dx = 0;
    dy = -1;
  }
  if(s=="Up"){
    dx = -1;
    dy = 0;
  }
  if(s=="Down"){
    dx = 1;
    dy = 0;
  }
  if(s=="Down-Right"){
    dx = 1;
    dy = 1;
  }
  if(s=="Down-Left"){
    dx = 1;
    dy = -1;
  }
  if(s=="Up-Left"){
    dx = -1;
    dy = -1;
  }
  if(s=="Up-Right"){
    dx = -1;
    dy = 1;
  }
  if(s=="Done"){
    dx = dy = -2;
  }
}
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x = 0;
    int y = 0;
    int dx;
    int dy;
    int ni;
    int nj;
    int md;
    int oi;
    int oj;
    int d;
    for(i=(0);i<(8);i++){
      int j;
      for(j=(0);j<(8);j++){
        mp[i][j] = 1;
      }
    }
    for(;;){
      int k;
      q(x,y,dx,dy);
      if(dx==-2){
        break;
      }
      for(i=(0);i<(8);i++){
        int j;
        for(j=(0);j<(8);j++){
          nx[i][j] = 0;
        }
      }
      for(i=(0);i<(8);i++){
        int j;
        for(j=(0);j<(8);j++){
          if(mp[i][j] && 0 <= i+dx  &&  i+dx < 8 && 0 <= j+dy  &&  j+dy < 8){
            nx[i+dx][j+dy] = 1;
          }
        }
      }
      for(i=(0);i<(8);i++){
        int j;
        for(j=(0);j<(8);j++){
          mp[i][j] = nx[i][j];
        }
      }
      for(k=(0);k<(8);k++){
        int di;
        for(di=(-1);di<(2);di++){
          int dj;
          for(dj=(-1);dj<(2);dj++){
            ni = x + di * k;
            nj = y + dj * k;
            if(0 <= ni  &&  ni < 8 && 0 <= nj  &&  nj < 8){
              mp[ni][nj] = 0;
            }
          }
        }
      }
      md = 1073709056;
      for(k=(0);k<(8);k++){
        int di;
        for(di=(-1);di<(2);di++){
          int dj;
          for(dj=(-1);dj<(2);dj++){
            ni = x + di * k;
            nj = y + dj * k;
            if(ni < 0 || nj < 0 || ni >= 8 || nj >= 8){
              continue;
            }
            d = 1073709056;
            for(i=(0);i<(8);i++){
              int j;
              for(j=(0);j<(8);j++){
                if(mp[i][j]){
                  chmin(d, max_L(abs(i-ni), abs(j-nj)));
                }
              }
            }
            if(md > d){
              md = d;
              oi = ni;
              oj = nj;
            }
          }
        }
      }
      auto OC5CYxKD = ((oi));
      auto o3WxPXbE = (( oj));
      x=OC5CYxKD;
      y=o3WxPXbE;
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //interactive
// int mp[8][8], nx[8][8];
// 
// void q(int x, int y, int &dx, int &dy){
//   string s;
//   wt(x+1,y+1);
//   rd(s);
//   if(s=="Right") dx = 0, dy = 1;
//   if(s=="Left") dx = 0, dy = -1;
//   if(s=="Up") dx = -1, dy = 0;
//   if(s=="Down") dx = 1, dy = 0;
//   if(s=="Down-Right") dx = 1, dy = 1;
//   if(s=="Down-Left") dx = 1, dy = -1;
//   if(s=="Up-Left") dx = -1, dy = -1;
//   if(s=="Up-Right") dx = -1, dy = 1;
//   if(s=="Done") dx = dy = -2;
// }
// 
// {
//   REP(rd_int()){
//     int x = 0, y = 0, dx, dy, ni, nj, md, oi, oj, d;
//     rep(i,8) rep(j,8) mp[i][j] = 1;
//     for(;;){
//       // wt(mp(8,8));
//       q(x,y,dx,dy);
//       if(dx==-2) break;
//       rep(i,8) rep(j,8) nx[i][j] = 0;
//       rep(i,8) rep(j,8) if(mp[i][j] && 0 <= i+dx < 8 && 0 <= j+dy < 8) nx[i+dx][j+dy] = 1;
//       rep(i,8) rep(j,8) mp[i][j] = nx[i][j];
//       rep(k,8) rep(di,-1,2) rep(dj,-1,2){
//         ni = x + di * k;
//         nj = y + dj * k;
//         if(0 <= ni < 8 && 0 <= nj < 8) mp[ni][nj] = 0;
//       }
//       md = int_inf;
//       rep(k,8) rep(di,-1,2) rep(dj,-1,2){
//         ni = x + di * k;
//         nj = y + dj * k;
//         if(ni < 0 || nj < 0 || ni >= 8 || nj >= 8) continue;
//         d = int_inf;
//         rep(i,8) rep(j,8) if(mp[i][j]) d <?= max(abs(i-ni), abs(j-nj));
//         if(md > d) md = d, oi = ni, oj = nj;
//       }
//       (x, y) = (oi, oj);
//     }
//   }
// }