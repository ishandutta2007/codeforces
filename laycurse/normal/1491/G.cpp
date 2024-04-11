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
int A[200000+2];
int r[200000+2];
int ress;
int res1[200000+2];
int res2[200000+2];
int vis[200000+2];
int sz;
vector<int> p[200000+2];
void myswap(int i, int j){
  swap(A[i], A[j]);
  auto Lj4PdHRW = (-1);
  A[i]*=Lj4PdHRW;
  A[j]*=Lj4PdHRW;
  arrInsert(ress, ress, res1, i, res2, j);
}
void do1(vector<int> p){
  int i;
  int sz = p.size();
  int x;
  if(sz == 2){
    for(x=0;;x++){
      int i;
      for(i=(0);i<(sz);i++){
        if(p[i]==x){
          goto KL2GvlyY;
        }
      }
      break;
      KL2GvlyY:;
    }
    myswap(p[0], x);
    myswap(p[1], x);
    myswap(p[0], x);
    return;
  }
  myswap(p[0], p[1]);
  for(i=(sz)-1;i>=(3);i--){
    myswap(p[1], p[i]);
  }
  myswap(p[0], p[2]);
  myswap(p[1], p[2]);
  myswap(p[0], p[1]);
}
void do2(vector<int> p1, vector<int> p2){
  int i;
  int sz1 = p1.size();
  int sz2 = p2.size();
  myswap(p1[0], p2[0]);
  for(i=(sz1)-1;i>=(1);i--){
    myswap(p1[i], p2[0]);
  }
  for(i=(sz2)-1;i>=(1);i--){
    myswap(p2[i], p1[0]);
  }
  myswap(p1[0], p2[0]);
}
int main(){
  int i;
  int j;
  int k;
  rd(N);
  {
    int ao_dF3pO;
    for(ao_dF3pO=(0);ao_dF3pO<(N);ao_dF3pO++){
      rd(A[ao_dF3pO]);
    }
  }
  for(i=(0);i<(N);i++){
    r[A[i]-1] = i;
  }
  for(i=(0);i<(N);i++){
    if(!vis[i]){
      if(r[i] == i){
        continue;
      }
      k = i;
      while(!vis[k]){
        p[sz].push_back(k);
        vis[k] = 1;
        k = r[k];
      }
      sz++;
    }
  }
  while(sz >= 2){
    do2(p[sz-2], p[sz-1]);
    sz -= 2;
  }
  if(sz){
    do1(p[0]);
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]+1);
    wt_L(' ');
    wt_L(res2[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, A[2d5+2], r[];
// int ress, res1[], res2[], vis[];
// int sz; VI p[];
// 
// void myswap(int i, int j){
//   swap(A[i], A[j]);
//   (A[i], A[j]) *= -1;
//   arrInsert(ress, ress, res1, i, res2, j);
// }
// 
// void do1(VI p){
//   int sz = p.size();
//   int x;
// 
//   if(sz == 2){
//     for(x=0;;x++){
//       rep(i,sz) if(p[i]==x) break_continue;
//       break;
//     }
//     myswap(p[0], x);
//     myswap(p[1], x);
//     myswap(p[0], x);
//     return;
//   }
// 
//   myswap(p[0], p[1]);
//   rrep(i,3,sz) myswap(p[1], p[i]);
//   myswap(p[0], p[2]);
//   myswap(p[1], p[2]);
//   myswap(p[0], p[1]);
// }
// 
// void do2(VI p1, VI p2){
//   int sz1 = p1.size(), sz2 = p2.size();
//   myswap(p1[0], p2[0]);
//   rrep(i,1,sz1) myswap(p1[i], p2[0]);
//   rrep(i,1,sz2) myswap(p2[i], p1[0]);
//   myswap(p1[0], p2[0]);
// }
// 
// {
//   int i, j, k;
//   rd(N,A(N));
//   rep(i,N) r[A[i]-1] = i;
//   rep(i,N) if(!vis[i]){
//     if(r[i] == i) continue;
//     k = i;
//     while(!vis[k]){
//       p[sz].push_back(k);
//       vis[k] = 1;
//       k = r[k];
//     }
//     sz++;
//   }
//   while(sz >= 2) do2(p[sz-2], p[sz-1]), sz -= 2;
//   if(sz) do1(p[0]);
// 
//   wt(ress);
//   rep(i,ress) wt(res1[i]+1, res2[i]+1);
//   // wt(A(N));
// }