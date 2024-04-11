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
int K;
char S[3002];
int sz[3000];
int ind[3000][3000];
int t;
int main(){
  int i;
  rd(N);
  rd(K);
  rd(S);
  for(;;){
    int i;
    for(i=(1);i<(N);i++){
      if(S[i-1]=='R' && S[i]=='L'){
        arrInsert(sz[t], sz[t], ind[t], i);
      }
    }
    for(i=(0);i<(sz[t]);i++){
      swap(S[ind[t][i]-1], S[ind[t][i]]);
    }
    if(sz[t]==0){
      break;
    }
    t++;
  }
  int FmcKpFmN;
  int xr20shxY;
  if(t==0){
    xr20shxY = 0;
  }
  else{
    xr20shxY = sz[0];
    for(FmcKpFmN=(1);FmcKpFmN<(t);FmcKpFmN++){
      xr20shxY += sz[FmcKpFmN];
    }
  }
  if(K < t || K >xr20shxY){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(t);i++){
    while(t-i < K && sz[i] > 1){
      wt_L(1);
      wt_L(' ');
      wt_L(ind[i][--sz[i]]);
      wt_L('\n');
      K--;
    }
    wt_L(sz[i]);
    wt_L(' ');
    {
      int hCmBdyQB;
      if(sz[i]==0){
        wt_L('\n');
      }
      else{
        for(hCmBdyQB=(0);hCmBdyQB<(sz[i]-1);hCmBdyQB++){
          wt_L(ind[i][hCmBdyQB]);
          wt_L(' ');
        }
        wt_L(ind[i][hCmBdyQB]);
        wt_L('\n');
      }
    }
    K--;
  }
  return 0;
}
// cLay varsion 20200408-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[3002];
// 
// int sz[3000], ind[3000][3000], t;
// 
// {
//   rd(N,K,S);
//   for(;;){
//     rep(i,1,N) if(S[i-1]=='R' && S[i]=='L') arrInsert(sz[t], sz[t], ind[t], i);
//     rep(i,sz[t]) swap(S[ind[t][i]-1], S[ind[t][i]]);
//     if(sz[t]==0) break;
//     t++;
//   }
// 
//   if(K < t || K > sum(sz(t))) wt(-1), return 0;
// 
//   rep(i,t){
//     while(t-i < K && sz[i] > 1){
//       wt(1, ind[i][--sz[i]]);
//       K--;
//     }
//     wt(sz[i], ind[i](sz[i]));
//     K--;
//   }
// }