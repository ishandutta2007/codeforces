#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int N;
int P[100000];
int ri[100000];
int rj[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int ress = 0;
    long long cost = 0;
    rd(N);
    for(i=(0);i<(N);i++){
      P[i] = i;
    }
    for(i=(N/2);i<(N);i++){
      arrInsert(ress, ress, ri, i, rj, 0);
      swap(P[i], P[0]);
    }
    for(i=(1);i<(N/2);i++){
      arrInsert(ress, ress, ri, i, rj, N-1);
      swap(P[i], P[N-1]);
    }
    for(i=(0);i<(ress);i++){
      cost += (long long)(ri[i]-rj[i]) * (ri[i]-rj[i]);
    }
    wt_L(cost);
    wt_L('\n');
    {
      int tU__gIr_;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
          wt_L(P[tU__gIr_]+1);
          wt_L(' ');
        }
        wt_L(P[tU__gIr_]+1);
        wt_L('\n');
      }
    }
    wt_L(N-1);
    wt_L('\n');
    for(i=(N-1)-1;i>=(0);i--){
      wt_L(ri[i]+1);
      wt_L(' ');
      wt_L(rj[i]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, P[1d5];
// int ri[1d5], rj[1d5];
// {
//   REP(rd_int()){
//     int ress = 0;
//     ll cost = 0;
// 
//     rd(N);
//     rep(i,N) P[i] = i;
//     rep(i,N/2,N) arrInsert(ress, ress, ri, i, rj, 0), swap(P[i], P[0]);
//     rep(i,1,N/2) arrInsert(ress, ress, ri, i, rj, N-1), swap(P[i], P[N-1]);
//     rep(i,ress) cost += (ll)(ri[i]-rj[i]) * (ri[i]-rj[i]);
// 
//     wt(cost);
//     wt(P(N)+1);
//     wt(N-1);
//     rrep(i,N-1) wt(ri[i]+1, rj[i]+1);
//   }
// }