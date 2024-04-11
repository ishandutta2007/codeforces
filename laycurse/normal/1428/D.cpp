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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[100000];
int ress;
int res1[300000];
int res2[300000];
int y;
int main(){
  int i;
  int j = 0;
  int k;
  int t = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i]){
      if(A[i]==1){
        arrInsert(ress, ress, res1, y, res2, i);
        y++;
        A[i] = 0;
        continue;
      }
      {
        auto RZTsC2BF = (i+1);
        chmax(j, RZTsC2BF);
        chmax(t, RZTsC2BF);
      }
      while(j < N && A[j] != 1){
        j++;
      }
      while(t < N && A[t] == 0){
        t++;
      }
      if(A[i]==2){
        if(j==N){
          wt_L("-1");
          wt_L('\n');
          return 0;
        }
        arrInsert(ress,ress,res1,y,res2,i);
        arrInsert(ress,ress,res1,y,res2,j);
        y++;
        A[i] = A[j] = 0;
      }
      else{
        if(t==N){
          wt_L("-1");
          wt_L('\n');
          return 0;
        }
        arrInsert(ress,ress,res1,y,res2,i);
        arrInsert(ress,ress,res1,y,res2,t);
        y++;
        A[i] = 0;
      }
    }
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
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int ress, res1[3d5], res2[3d5], y;
// 
// {
//   int i, j = 0, k, t = 0;
//   rd(N,A(N));
//   rep(i,N) if(A[i]){
//     if(A[i]==1){
//       arrInsert(ress, ress, res1, y, res2, i);
//       y++;
//       A[i] = 0;
//       continue;
//     }
// 
//     (j, t) >?= i+1;
//     while(j < N && A[j] != 1) j++;
//     while(t < N && A[t] == 0) t++;
// 
//     if(A[i]==2){
//       if(j==N) wt("-1"), return 0;
//       arrInsert(ress,ress,res1,y,res2,i);
//       arrInsert(ress,ress,res1,y,res2,j);
//       y++;
//       A[i] = A[j] = 0;
//     } else {
//       if(t==N) wt("-1"), return 0;
//       arrInsert(ress,ress,res1,y,res2,i);
//       arrInsert(ress,ress,res1,y,res2,t);
//       y++;
//       A[i] = 0;
//     }
//   }
// 
//   wt(ress);
//   rep(i,ress) wt(res1[i]+1, res2[i]+1);
// }