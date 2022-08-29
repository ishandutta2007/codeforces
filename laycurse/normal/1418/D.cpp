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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T getLast(multiset<T> &a){
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
template<class T> inline T getLast(set<T> &a){
  typename set<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
int N;
int Q;
int T;
int X;
set<int> s;
multiset<int> sa;
void ad(int x){
  set<int>::iterator it;
  set<int>::iterator it1;
  set<int>::iterator it2;
  s.insert(x);
  it = it1 = it2 = s.lower_bound(x);
  it2++;
  if(it1 != s.begin()){
    it1--;
    if(it2 != s.end()){
      sa.erase(sa.find(*it2 - *it1));
    }
    sa.insert(*it - *it1);
  }
  if(it2 != s.end()){
    sa.insert(*it2 - *it);
  }
}
void dl(int x){
  set<int>::iterator it;
  set<int>::iterator it1;
  set<int>::iterator it2;
  it = it1 = it2 = s.lower_bound(x);
  it2++;
  if(it1 != s.begin()){
    it1--;
    if(it2 != s.end()){
      sa.insert(*it2 - *it1);
    }
    sa.erase(sa.find(*it - *it1));
  }
  if(it2 != s.end()){
    sa.erase(sa.find(*it2 - *it));
  }
  s.erase(it);
}
int main(){
  int Lj4PdHRW, e98WHCEY;
  rd(N);
  rd(Q);
  for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
    ad(rd_int());
  }
  if(sa.size()){
    wt_L(getLast(s) - getFirst(s) - getLast(sa));
    wt_L('\n');
  }
  else{
    wt_L(0);
    wt_L('\n');
  }
  for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
    rd(T);
    rd(X);
    if(T==0){
      dl(X);
    }
    else{
      ad(X);
    }
    if(sa.size()){
      wt_L(getLast(s) - getFirst(s) - getLast(sa));
      wt_L('\n');
    }
    else{
      wt_L(0);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200913-1

// --- original code ---
// //no-unlocked
// int N, Q, T, X;
// set<int> s;
// multiset<int> sa;
// 
// void ad(int x){
//   set<int>::iterator it, it1, it2;
//   s.insert(x);
//   it = it1 = it2 = s.lower_bound(x);
//   it2++;
//   if(it1 != s.begin()){
//     it1--;
//     if(it2 != s.end()) sa.erase(sa.find(*it2 - *it1));
//     sa.insert(*it - *it1);
//   }
//   if(it2 != s.end()) sa.insert(*it2 - *it);
// }
// 
// void dl(int x){
//   set<int>::iterator it, it1, it2;
//   it = it1 = it2 = s.lower_bound(x);
//   it2++;
//   if(it1 != s.begin()){
//     it1--;
//     if(it2 != s.end()) sa.insert(*it2 - *it1);
//     sa.erase(sa.find(*it - *it1));
//   }
//   if(it2 != s.end()) sa.erase(sa.find(*it2 - *it));
//   s.erase(it);
// }
// 
// {
//   rd(N,Q);
//   rep(N) ad(rd_int());
//   wt(if[sa.size(), getLast(s) - getFirst(s) - getLast(sa), 0]);
//   rep(Q){
//     rd(T,X);
//     if[T==0, dl(X), ad(X)];
//     wt(if[sa.size(), getLast(s) - getFirst(s) - getLast(sa), 0]);
//   }
// }