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
vector<int> s[15000];
int sz;
int f;
int ress;
int res1[1000000];
int res2[1000000];
int main(){
  int i;
  int j;
  int k;
  int x;
  int y;
  rd(N);
  for(i=(0);i<(N);i++){
    s[i].push_back(i+1);
  }
  sz = N;
  while(sz > 2){
    f = 0;
    for(i=(1);i<(sz);i++){
      if(s[i-1].size() == s[i].size()){
        for(j=(0);j<(s[i].size());j++){
          arrInsert(ress, ress, res1, s[i-1][j], res2, s[i][j]);
        }
        for(j=(0);j<(s[i].size());j++){
          s[i-1].push_back(s[i][j]);
        }
        s[i].clear();
        f++;
      }
    }
    if(f){
      k = 0;
      for(i=(0);i<(sz);i++){
        if(s[i].size()){
          s[k++] = s[i];
        }
      }
      sz = k;
      continue;
    }
    x = s[0].size();
    y = s[sz-1].size();
    for(j=(0);j<(y);j++){
      arrInsert(ress, ress, res1, s[0][x-1-j], res2, s[sz-1][j]);
    }
    for(j=(0);j<(y);j++){
      s[sz-1].push_back(s[0].back());
      s[0].pop_back();
    }
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]);
    wt_L(' ');
    wt_L(res2[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// //no-unlocked
// int N;
// vector<int> s[15000];
// int sz, f;
// int ress, res1[1d6], res2[1d6];
// {
//   int i, j, k, x, y;
// 
//   rd(N);
//   rep(i,N) s[i].push_back(i+1);
//   sz = N;
// 
//   while(sz > 2){
//     f = 0;
//     rep(i,1,sz) if(s[i-1].size() == s[i].size()){
//       rep(j,s[i].size()) arrInsert(ress, ress, res1, s[i-1][j], res2, s[i][j]);
//       rep(j,s[i].size()) s[i-1].push_back(s[i][j]);
//       s[i].clear();
//       f++;
//     }
//     if(f){
//       k = 0;
//       rep(i,sz) if(s[i].size()) s[k++] = s[i];
//       sz = k;
//       continue;
//     }
//     x = s[0].size();
//     y = s[sz-1].size();
//     rep(j,y) arrInsert(ress, ress, res1, s[0][x-1-j], res2, s[sz-1][j]);
//     rep(j,y) s[sz-1].push_back(s[0].back()), s[0].pop_back();
//   }
// 
//   wt(ress);
//   rep(i,ress) wt(res1[i], res2[i]);
// }