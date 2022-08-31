#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
int N;
long long L;
long long R;
int res[100000];
int ress;
void push(int n){
  if(L){
    L--;
    R--;
    return;
  }
  if(R){
    res[ress++] = n;
    R--;
  }
}
void push(int n1, int n2){
  push(n1);
  push(n2);
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int skip;
    ress = 0;
    rd(N);
    rd(L);L += (-1);
    rd(R);
    for(i=(0);i<(N);i++){
      skip =min_L(L/2, N-1-i);
      {
        auto xr20shxY = (2 * skip);
        L -= xr20shxY;
        R -= xr20shxY;
      }
      {
        auto WYIGIcGE = (0);
        chmax(L, WYIGIcGE);
        chmax(R, WYIGIcGE);
      }
      if(R==0){
        break;
      }
      for(j=(i+1+skip);j<(N);j++){
        push(i+1, j+1);
      }
    }
    push(1);
    {
      int ao_dF3pO;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(ress-1);ao_dF3pO++){
          wt_L(res[ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(res[ao_dF3pO]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200408-1

// --- original code ---
// //no-unlocked
// int N; ll L, R;
// int res[1d5], ress;
// 
// void push(int n){
//   if(L) L--, R--, return;
//   if(R) res[ress++] = n, R--;
// }
// 
// void push(int n1, int n2){
//   push(n1); push(n2);
// }
// 
// {
//   REP(rd_int()){
//     int i, j, skip;
//     ress = 0;
//     rd(N, L--, R);
//     rep(i,N){
//       skip = min(L/2, N-1-i);
//       (L, R) -= 2 * skip;
//       (L, R) >?= 0;
//       if(R==0) break;
//       rep(j,i+1+skip,N) push(i+1, j+1);
//     }
//     push(1);
//     wt(res(ress));
//   }
// }