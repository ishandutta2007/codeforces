#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline long long rd_ll(void){
  long long x;
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
template<class T> inline T getLast(multiset<T> &a){
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> inline T getLast(set<T> &a){
  typename set<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int N;
int M;
long long A[200000];
vector<long long> B[200000];
long long bsum[200000];
vector<int> res[200000];
multiset<long long> s;
int era(int x, int y, multiset<long long> &m){
  int i;
  long long v;
  multiset<long long>::iterator it;
  for(i=(x);i<(y);i++){
    v =(divup_L(bsum[i],((int)B[i].size())));
    it = s.lower_bound(v);
    if(it == s.end()){
      return 0;
    }
    m.insert(*it);
    s.erase(it);
  }
  return 1;
}
void solve(int x, int y){
  int z;
  int sz;
  long long aa;
  multiset<long long> m;
  if(x == y-1){
    int i;
    sz = B[x].size();
    aa = getLast(s) * (sz-1);
    for(i=(0);i<(sz);i++){
      if(bsum[x] - B[x][i] <= aa){
        res[x].push_back(1);
      }
      else{
        res[x].push_back(0);
      }
    }
    return;
  }
  z = (x+y) / 2;
  if(era(z,y,m)){
    solve(x,z);
  }
  while(m.size()){
    s.insert(*m.begin());
    m.erase(m.begin());
  }
  if(era(x,z,m)){
    solve(z,y);
  }
  while(m.size()){
    s.insert(*m.begin());
    m.erase(m.begin());
  }
}
int main(){
  int WYIGIcGE;
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    int i;
    rd(N);
    rd(M);
    {
      int tU__gIr_;
      for(tU__gIr_=(0);tU__gIr_<(N);tU__gIr_++){
        rd(A[tU__gIr_]);
      }
    }
    for(i=(0);i<(M);i++){
      B[i].clear();
      res[i].clear();
    }
    for(i=(0);i<(M);i++){
      int jbtyPBGc;
      int ZIeRIny5 = rd_int();
      for(jbtyPBGc=(0);jbtyPBGc<(ZIeRIny5);jbtyPBGc++){
        B[i].push_back(rd_ll());
      }
    }
    for(i=(0);i<(M);i++){
      int BUotOFBp;
      cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type Q5rsz4fz;
      if(B[i].size()==0){
        Q5rsz4fz = 0;
      }
      else{
        Q5rsz4fz = B[i][0];
        for(BUotOFBp=(1);BUotOFBp<(B[i].size());BUotOFBp++){
          Q5rsz4fz += B[i][BUotOFBp];
        }
      }
      bsum[i] =Q5rsz4fz;
    }
    s.clear();
    for(i=(0);i<(N);i++){
      s.insert(A[i]);
    }
    solve(0,M);
    for(i=(0);i<(M);i++){
      if(res[i].size() == 0){
        int X9Iss0pP;
        for(X9Iss0pP=(0);X9Iss0pP<(B[i].size());X9Iss0pP++){
          wt_L(0);
        }
      }
      else{
        {
          int O3U4gd88;
          for(O3U4gd88=(0);O3U4gd88<(res[i].size());O3U4gd88++){
            wt_L(res[i][O3U4gd88]);
          }
        }
      }
    }
    wt_L("");
    wt_L('\n');
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
// cLay version 20211231-1

// --- original code ---
// //no-unlocked
// int N, M; ll A[2d5]; vector<ll> B[2d5]; ll bsum[2d5]; VI res[2d5];
// multiset<ll> s;
// 
// int era(int x, int y, multiset<ll> &m){
//   ll v;
//   multiset<ll>::iterator it;
//   rep(i,x,y){
//     v = bsum[i] /+ ((int)B[i].size());
//     it = s.lower_bound(v);
//     if(it == s.end()) return 0;
//     m.insert(*it);
//     s.erase(it);
//   }
//   return 1;
// }
// 
// void solve(int x, int y){
//   int z, sz;
//   ll aa;
//   multiset<ll> m;
// 
//   if(x == y-1){
//     sz = B[x].size();
//     aa = getLast(s) * (sz-1);
//     rep(i,sz) res[x].push_back(if[bsum[x] - B[x][i] <= aa, 1, 0]);
//     return;
//   }
// 
//   z = (x+y) / 2;
// 
//   if(era(z,y,m)) solve(x,z);
//   while(m.size()) s.insert(*m.begin()), m.erase(m.begin());
//   if(era(x,z,m)) solve(z,y);
//   while(m.size()) s.insert(*m.begin()), m.erase(m.begin());
// }
// 
// {
//   REP(rd_int()){
//     rd(N,M,A(N));
//     rep(i,M) B[i].clear(), res[i].clear();
//     rep(i,M) REP(rd_int()) B[i].push_back(rd_ll());
//     rep(i,M) bsum[i] = sum(B[i](B[i].size()));
//     s.clear();
//     rep(i,N) s.insert(A[i]);
//     solve(0,M);
// 
//     rep(i,M){
//       if(res[i].size() == 0){
//         rep(B[i].size()) wtN(0);
//       } else {
//         wtN(res[i](res[i].size()));
//       }
//     }
//     wt("");
//   }
// }