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
int N;
int M;
int A[200000+2];
int B[200000+2];
int L[200000+2];
int R[200000+2];
int ok[200000+2];
long long s[200000+2];
int sz;
int st[200000+2];
vector<int> ind[200000+2];
set<int> p;
set<int>::iterator it;
void do_del(int i){
  p.erase(i);
  for(int j : ind[i]){
    ok[j]++;
    if(ok[j]==2){
      st[sz++] = j;
    }
  }
}
int main(){
  int WKqLrJHZ;
  int QAAnbtfa = rd_int();
  for(WKqLrJHZ=(0);WKqLrJHZ<(QAAnbtfa);WKqLrJHZ++){
    int i;
    int j;
    rd(N);
    rd(M);
    {
      int R5MtCiij;
      for(R5MtCiij=(0);R5MtCiij<(N);R5MtCiij++){
        rd(A[R5MtCiij]);
      }
    }
    {
      int ATMZloZo;
      for(ATMZloZo=(0);ATMZloZo<(N);ATMZloZo++){
        rd(B[ATMZloZo]);
      }
    }
    {
      int QBN4sCMC;
      for(QBN4sCMC=(0);QBN4sCMC<(M);QBN4sCMC++){
        rd(L[QBN4sCMC]);L[QBN4sCMC] += (-1);
        rd(R[QBN4sCMC]);
      }
    }
    for(i=(0);i<(N);i++){
      s[i+1] = s[i] + A[i] - B[i];
    }
    p.clear();
    sz = 0;
    for(i=(0);i<(M);i++){
      ok[i] = 0;
    }
    for(i=(0);i<(N+1);i++){
      ind[i].clear();
    }
    for(i=(0);i<(M);i++){
      ind[L[i]].push_back(i);
      ind[R[i]].push_back(i);
    }
    for(i=(0);i<(N+1);i++){
      p.insert(i);
    }
    for(i=(0);i<(N+1);i++){
      if(s[i]==0){
        do_del(i);
      }
    }
    while(sz){
      i = st[--sz];
      for(;;){
        it = p.lower_bound(L[i]);
        if(it == p.end() || *it > R[i]){
          break;
        }
        do_del(*it);
      }
    }
    if(p.size()){
      wt_L("NO");
      wt_L('\n');
    }
    else{
      wt_L("YES");
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
// cLay version 20220506-1 [+]

// --- original code ---
// //no-unlocked
// int N, M, A[2d5+2], B[], L[], R[], ok[];
// ll s[];
// int sz, st[];
// VI ind[];
// set<int> p;
// set<int>::iterator it;
// 
// void do_del(int i){
//   p.erase(i);
//   for(int j : ind[i]){
//     ok[j]++;
//     if(ok[j]==2) st[sz++] = j;
//   }
// }
// 
// {
//   REP(rd_int()){
//     int i, j;
//     rd(N,M,A(N),B(N),(L--,R)(M));
//     rep(i,N) s[i+1] = s[i] + A[i] - B[i];
// 
//     p.clear();
//     sz = 0;
//     rep(i,M) ok[i] = 0;
//     rep(i,N+1) ind[i].clear();
//     rep(i,M) ind[L[i]].push_back(i), ind[R[i]].push_back(i);
//     rep(i,N+1) p.insert(i);
// 
//     rep(i,N+1) if(s[i]==0) do_del(i);
//     while(sz){
//       i = st[--sz];
//       for(;;){
//         it = p.lower_bound(L[i]);
//         if(it == p.end() || *it > R[i]) break;
//         do_del(*it);
//       }
//     }
// 
//     wt(if[p.size(), "NO", "YES"]);
//   }
// }