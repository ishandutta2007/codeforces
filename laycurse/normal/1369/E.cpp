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
template<class T> inline T popFirst(multiset<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T popFirst(set<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
int N;
int M;
int W[100000];
int X[200000];
int Y[200000];
int ress;
int res[200000];
vector<int> arr[100000];
int ok[200000];
int main(){
  int i;
  int k;
  set<int> s;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(W[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(X[e98WHCEY]);X[e98WHCEY] += (-1);
      rd(Y[e98WHCEY]);Y[e98WHCEY] += (-1);
    }
  }
  for(i=(0);i<(M);i++){
    arr[X[i]].push_back(i);
  }
  for(i=(0);i<(M);i++){
    arr[Y[i]].push_back(i);
  }
  for(i=(0);i<(M);i++){
    W[X[i]]--;
    W[Y[i]]--;
  }
  for(i=(0);i<(N);i++){
    if(W[i] >= 0){
      for(int j : arr[i]){
        s.insert(j);
      }
    }
  }
  while(s.size()){
    int loop;
    i = popFirst(s);
    if(ok[i]){
      continue;
    }
    ok[i] = 1;
    res[ress++] = i;
    for(loop=(0);loop<(2);loop++){
      if(loop==0){
        k =X[i];
      }
      else{
        k =Y[i];
      }
      W[k]++;
      if(W[k]==0){
        for(int j : arr[k]){
          s.insert(j);
        }
      }
    }
  }
  if(ress < M){
    wt_L("DEAD");
    wt_L('\n');
    return 0;
  }
  reverse(res, res+ress);
  wt_L("ALIVE");
  wt_L('\n');
  {
    int AlM5nNnR;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(AlM5nNnR=(0);AlM5nNnR<(ress-1);AlM5nNnR++){
        wt_L(res[AlM5nNnR]+1);
        wt_L(' ');
      }
      wt_L(res[AlM5nNnR]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, W[1d5];
// int X[2d5], Y[2d5];
// 
// int ress, res[2d5];
// vector<int> arr[1d5];
// int ok[2d5];
// {
//   int i, k;
//   set<int> s;
//   rd(N,M,W(N),(X--,Y--)(M));
//   
//   rep(i,M) arr[X[i]].push_back(i);
//   rep(i,M) arr[Y[i]].push_back(i);
// 
//   rep(i,M) W[X[i]]--, W[Y[i]]--;
//   rep(i,N) if(W[i] >= 0) for(int j : arr[i]) s.insert(j);
// 
//   while(s.size()){
//     i = popFirst(s);
//     if(ok[i]) continue;
//     ok[i] = 1;
//     res[ress++] = i;
//     rep(loop,2){
//       k = if[loop==0, X[i], Y[i]];
//       W[k]++;
//       if(W[k]==0) for(int j : arr[k]) s.insert(j);
//     }
//   }
//   if(ress < M) wt("DEAD"), return 0;
// 
//   reverse(res, res+ress);
//   wt("ALIVE");
//   wt(res(ress)+1);
// }