#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int Q;
int S;
int D;
int A[200000];
int T[200000];
int K[200000];
int ind[200000];
int res[200000];
set<int> ok;
set<pair<int,int>> ng;
set<pair<int,int>> nx;
void doit(int s, int d, int k){
  int i;
  int mn;
  set<pair<int,int>>::iterator it;
  it = ng.lower_bound({A[s]+d-k,-1});
  if(it != ng.end() && A[s] + d - k <= it->first  &&  it->first <= A[s] + d + k){
    i = it->second;
    ng.erase(it);
    ok.insert(i);
    doit(s, d, k);
    doit(i, d, k);
    doit(i, -d, k);
    return;
  }
  mn = 1073709056;
  if(it != ng.end()){
    chmin(mn, it->first - (A[s] + d));
  }
  if(it != ng.begin()){
    it--;
    chmin(mn, (A[s] + d) - it->first);
  }
  nx.insert({mn, s});
}
int main(){
  int q;
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  rd(Q);
  rd(S);S += (-1);
  rd(D);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(Q);e98WHCEY++){
      rd(T[e98WHCEY]);T[e98WHCEY] += (-1);
      rd(K[e98WHCEY]);
    }
  }
  for(i=(0);i<(Q);i++){
    ind[i] = i;
  }
  sortA_L(Q,K,T,ind);
  ok.insert(S);
  for(i=(0);i<(N);i++){
    if(i!=S){
      ng.insert({A[i],i});
    }
  }
  doit(S, -D, 0);
  doit(S, D, 0);
  for(q=(0);q<(Q);q++){
    k = K[q];
    while(nx.size() && nx.begin()->first <= K[q]){
      i = nx.begin()->second;
      nx.erase(nx.begin());
      doit(i, -D, K[q]);
      doit(i, D, K[q]);
    }
    res[ind[q]] = ok.count(T[q]);
  }
  for(i=(0);i<(Q);i++){
    if(res[i]){
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
// cLay version 20210708-1

// --- original code ---
// //no-unlocked
// int N, Q, S, D, A[2d5], T[], K[], ind[], res[];
// set<int> ok;
// set<pair<int,int>> ng, nx;
// 
// void doit(int s, int d, int k){
//   int i, mn;
//   set<pair<int,int>>::iterator it;
//   it = ng.lower_bound({A[s]+d-k,-1});
//   if(it != ng.end() && A[s] + d - k <= it->first <= A[s] + d + k){
//     i = it->second;
//     ng.erase(it);
//     ok.insert(i);
//     doit(s, d, k);
//     doit(i, d, k); doit(i, -d, k);
//     return;
//   }
//   mn = int_inf;
//   if(it != ng.end()) mn <?= it->first - (A[s] + d);
//   if(it != ng.begin()) it--, mn <?= (A[s] + d) - it->first;
//   nx.insert({mn, s});
// }
// 
// {
//   int i, j, k;
//   rd(N,Q,S--,D,A(N),(T--,K)(Q));
//   rep(i,Q) ind[i] = i;
//   sortA(Q,K,T,ind);
// 
//   ok.insert(S);
//   rep(i,N) if(i!=S) ng.insert({A[i],i});
//   doit(S, -D, 0); doit(S, D, 0);
// 
//   rep(q,Q){
//     k = K[q];
//     while(nx.size() && nx.begin()->first <= K[q]){
//       i = nx.begin()->second;
//       nx.erase(nx.begin());
//       doit(i, -D, K[q]); doit(i, D, K[q]);
//     }
//     res[ind[q]] = ok.count(T[q]);
//   }
//   rep(i,Q) wt(if[res[i], "Yes", "No"]);
// }