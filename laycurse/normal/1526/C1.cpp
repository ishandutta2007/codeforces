#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class T> inline T popFirst(multiset<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T popFirst(set<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
int N;
long long A[200000];
int main(){
  int i;
  int res = 0;
  long long cur = 0;
  multiset<long long> s;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(cur+A[i] >= 0){
      cur += A[i];
      res++;
      s.insert(A[i]);
      continue;
    }
    if(s.size() && getFirst(s) < A[i]){
      cur += A[i] - popFirst(s);
      s.insert(A[i]);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210524-1

// --- original code ---
// //no-unlocked
// int N; ll A[2d5];
// {
//   int res = 0;
//   ll cur = 0;
//   multiset<ll> s;
//   rd(N,A(N));
//   rep(i,N){
//     if(cur+A[i] >= 0) cur += A[i], res++, s.insert(A[i]), continue;
//     if(s.size() && getFirst(s) < A[i]) cur += A[i] - popFirst(s), s.insert(A[i]);
//   }
//   wt(res);
// }