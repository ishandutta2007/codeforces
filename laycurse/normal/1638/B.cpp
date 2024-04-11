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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> int isSorted(int N, const T A[]){
  int i;
  for(i=(1);i<(N);i++){
    if(A[i-1] > A[i]){
      return 0;
    }
  }
  return 1;
}
int main(){
  int WKqLrJHZ;
  int QAAnbtfa = rd_int();
  for(WKqLrJHZ=(0);WKqLrJHZ<(QAAnbtfa);WKqLrJHZ++){
    int i;
    int N;
    rd(N);
    int A[N];
    {
      int R5MtCiij;
      for(R5MtCiij=(0);R5MtCiij<(N);R5MtCiij++){
        rd(A[R5MtCiij]);
      }
    }
    int xs = 0;
    int ys = 0;
    int x[N];
    int y[N];
    for(i=(0);i<(N);i++){
      if(A[i]%2){
        x[xs++]= A[i];
      }
      else{
        y[ys++]= A[i];
      }
    }
    if(isSorted(xs,x) && isSorted(ys,y)){
      wt_L("Yes");
      wt_L('\n');
    }
    else{
      wt_L("No");
      wt_L('\n');
    }
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// template<class T>
// int isSorted(int N, const T A[]){
//   int i;
//   rep(i,1,N) if(A[i-1] > A[i]) return 0;
//   return 1;
// }
// 
// {
//   REP(rd_int()){
//     int @N, @A[N];
//     int xs = 0, ys = 0, x[N], y[N];
//     rep(i,N) if[A[i]%2, x[xs++], y[ys++]] = A[i];
//     wt(if[isSorted(xs,x) && isSorted(ys,y), "Yes", "No"]);
//   }
// }