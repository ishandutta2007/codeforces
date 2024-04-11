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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[100000];
char S[5];
int len;
int pl;
int ti;
int mi;
char res[100000];
int sz;
long long m[100000];
long long lf[100000];
long long rg[100000];
void solve(int x, int y){
  int i;
  int j;
  int k;
  int mask;
  int opt;
  long long mx;
  long long tmp;
  long long cur;
  if(x >= y){
    return;
  }
  for(i=(x);i<(y+1);i++){
    if(A[i] == 0){
      if(i > x){
        res[i-1] = '+';
      }
      if(i < y){
        res[i] = '+';
      }
      solve(x, i-1);
      solve(i+1, y);
      return;
    }
  }
  if(A[x] == 1){
    res[x] = '+';
    solve(x+1, y);
    return;
  }
  if(A[y] == 1){
    res[y-1] = '+';
    solve(x, y-1);
    return;
  }
  sz = 0;
  for(i=(x);i<(y+1);i++){
    if(A[i] > 1){
      if(sz%2==0){
        sz++;
        m[sz-1] = 1;
        lf[sz-1] = i;
      }
      m[sz-1] *= A[i];
      chmin(m[sz-1], 1073709056);
      rg[sz-1] = i;
      continue;
    }
    else{
      if(sz%2==1){
        sz++;
        m[sz-1] = 0;
        lf[sz-1] = i;
      }
      m[sz-1]++;
      rg[sz-1] = i;
    }
  }
  for(i=(x);i<(y);i++){
    res[i] = '*';
  }
  mx = 1;
  for(i=(0);i<(sz);i+=(2)){
    mx *= m[i];
    chmin(mx, 1073709056);
  }
  if(mx >= 10*(y-x+1)){
    return;
  }
  mx = -1;
  k = sz / 2;
  for(mask=(0);mask<(1<<k);mask++){
    tmp = 0;
    cur = m[0];
    for(i=(0);i<(k);i++){
      if(((mask) &(1<<(i)))){
        cur *= m[2*i+2];
      }
      else{
        tmp += cur + m[2*i+1];
        cur = m[2*i+2];
      }
    }
    tmp += cur;
    if(mx < tmp){
      mx = tmp;
      opt = mask;
    }
  }
  for(i=(0);i<(k);i++){
    if(!((opt) &(1<<(i)))){
      for(j=(lf[2*i+1]-1);j<(rg[2*i+1]+1);j++){
        res[j] = '+';
      }
    }
  }
}
int main(){
  int i;
  char c;
  rd(N);
  {
    int APIVbQlN;
    for(APIVbQlN=(0);APIVbQlN<(N);APIVbQlN++){
      rd(A[APIVbQlN]);
    }
  }
  len = rd(S);
  for(i=(0);i<(N);i++){
    res[i] = '?';
  }
  if(arrCountVal(len,S,'+')){
    pl = 1;
  }
  if(arrCountVal(len,S,'-')){
    mi = 1;
  }
  if(arrCountVal(len,S,'*')){
    ti = 1;
  }
  if(pl && mi){
    mi = 0;
    len--;
  }
  if(len==1){
    if(pl){
      c = '+';
    }
    if(mi){
      c = '-';
    }
    if(ti){
      c = '*';
    }
    wt_L(A[0]);
    for(i=(1);i<(N);i++){
      wt_L(c);
      wt_L(A[i]);
    }
    wt_L("");
    wt_L('\n');
    return 0;
  }
  if(pl && ti){
    solve(0, N-1);
    wt_L(A[0]);
    for(i=(1);i<(N);i++){
      wt_L(res[i-1]);
      wt_L(A[i]);
    }
    wt_L("");
    wt_L('\n');
    return 0;
  }
  if(mi && ti){
    wt_L(A[0]);
    for(i=(1);i<(N);i++){
      if(A[i]==0){
        wt_L('-');
        wt_L(A[i]);
      }
      else{
        wt_L('*');
        wt_L(A[i]);
      }
    }
    wt_L("");
    wt_L('\n');
    return 0;
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// char S[5]; int len, pl, ti, mi;
// char res[1d5];
// 
// int sz;
// ll m[1d5], lf[1d5], rg[1d5];
// 
// void solve(int x, int y){
//   int i, j, k, mask, opt;
//   ll mx, tmp, cur;
// 
//   if(x >= y) return;
//   rep(i,x,y+1) if(A[i] == 0){
//     if(i > x) res[i-1] = '+';
//     if(i < y) res[i] = '+';
//     solve(x, i-1);
//     solve(i+1, y);
//     return;
//   }
// 
//   if(A[x] == 1){
//     res[x] = '+';
//     solve(x+1, y);
//     return;
//   }
// 
//   if(A[y] == 1){
//     res[y-1] = '+';
//     solve(x, y-1);
//     return;
//   }
// 
//   sz = 0;
//   rep(i,x,y+1){
//     if(A[i] > 1){
//       if(sz%2==0) sz++, m[sz-1] = 1, lf[sz-1] = i;
//       m[sz-1] *= A[i];
//       m[sz-1] <?= int_inf;
//       rg[sz-1] = i;
//       continue;
//     } else {
//       if(sz%2==1) sz++, m[sz-1] = 0, lf[sz-1] = i;
//       m[sz-1]++;
//       rg[sz-1] = i;
//     }
//   }
// 
//   rep(i,x,y) res[i] = '*';
// 
//   mx = 1;
//   rep(i,0,sz,2) mx *= m[i], mx <?= int_inf;
//   if(mx >= 10*(y-x+1)) return;
// 
//   mx = -1;
//   k = sz / 2;
//   rep(mask,1<<k){
//     tmp = 0;
//     cur = m[0];
//     rep(i,k){
//       if(BIT_ith(mask,i)){
//         cur *= m[2*i+2];
//       } else {
//         tmp += cur + m[2*i+1];
//         cur = m[2*i+2];
//       }
//     }
//     tmp += cur;
//     if(mx < tmp){
//       mx = tmp;
//       opt = mask;
//     }
//   }
// 
//   rep(i,k) if(!BIT_ith(opt,i)){
//     rep(j,lf[2*i+1]-1,rg[2*i+1]+1) res[j] = '+';
//   }
// }
// 
// {
//   char c;
//   rd(N,A(N),S@len);
//   rep(i,N) res[i] = '?';
//   if(arrCountVal(len,S,'+')) pl = 1;
//   if(arrCountVal(len,S,'-')) mi = 1;
//   if(arrCountVal(len,S,'*')) ti = 1;
// 
//   if(pl && mi){
//     mi = 0;
//     len--;
//   }
// 
//   if(len==1){
//     if(pl) c = '+';
//     if(mi) c = '-';
//     if(ti) c = '*';
//     wtN(A[0]);
//     rep(i,1,N) wtN(c,A[i]);
//     wt("");
//     return 0;
//   }
// 
//   if(pl && ti){
//     solve(0, N-1);
//     wtN(A[0]);
//     rep(i,1,N) wtN(res[i-1], A[i]);
//     wt("");
//     return 0;
//   }
// 
//   if(mi && ti){
//     wtN(A[0]);
//     rep(i,1,N) wtN(if[A[i]==0,'-','*'],A[i]);
//     wt("");
//     return 0;
//   }
// }