#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
int N;
int A[100000][3];
unionFind uf;
deque<int> g[100000];
set<int> tri[100000];
int st[100000];
int sts;
int res1[100000];
int res2[100000];
int ress;
void merge(int i, int j){
  int ii;
  int jj;
  int x;
  int y;
  int z;
  int d;
  int v;
  x = ii = uf(i);
  y = jj = uf(j);
  uf(i,j);
  z = uf(i);
  d = (z^x^y);
  if(g[z].front() == i || g[z].front() == j){
    if(g[d].front() == i || g[d].front() == j){
      while(g[d].size()){
        g[z].push_front(g[d].front());
        g[d].pop_front();
      }
    }
    else{
      while(g[d].size()){
        g[z].push_front(g[d].back());
        g[d].pop_back();
      }
    }
  }
  else{
    if(g[d].front() == i || g[d].front() == j){
      while(g[d].size()){
        g[z].push_back(g[d].front());
        g[d].pop_front();
      }
    }
    else{
      while(g[d].size()){
        g[z].push_back(g[d].back());
        g[d].pop_back();
      }
    }
  }
}
int main(){
  int WYIGIcGE;
  wmem = memarr;
  int i;
  int j;
  int k;
  int t;
  int a;
  uf.malloc(100000);
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    rd(N);
    for(i=(0);i<(N-2);i++){
      {
        int hCmBdyQB;
        for(hCmBdyQB=(0);hCmBdyQB<(3);hCmBdyQB++){
          rd(A[i][hCmBdyQB]);A[i][hCmBdyQB] += (-1);
        }
      }
    }
    uf.init(N);
    for(i=(0);i<(N);i++){
      g[i].clear();
      g[i].push_back(i);
    }
    sts = 0;
    for(i=(0);i<(N);i++){
      tri[i].clear();
    }
    for(i=(0);i<(N-2);i++){
      for(j=(0);j<(3);j++){
        tri[A[i][j]].insert(i);
      }
    }
    for(i=(0);i<(N);i++){
      if(tri[i].size()==1){
        st[sts++] = i;
      }
    }
    ress = 0;
    while(sts){
      i = st[--sts];
      if(tri[i].size() == 0){
        continue;
      }
      t = *(tri[i].begin());
      res2[ress++] = t;
      j = k = -1;
      for(a=(0);a<(3);a++){
        if(A[t][a]==i){
          continue;
        }
        if(j==-1){
          j = A[t][a];
          continue;
        }
        k = A[t][a];
      }
      tri[i].erase(t);
      tri[j].erase(t);
      if(tri[j].size()==1){
        st[sts++] = j;
      }
      tri[k].erase(t);
      if(tri[k].size()==1){
        st[sts++] = k;
      }
      if(uf(i) != uf(j)){
        merge(i, j);
      }
      if(uf(i) != uf(k)){
        merge(i, k);
      }
    }
    i = uf(0);
    k = 0;
    for(int x : g[i]){
      res1[k++] = x;
    }
    {
      int X9Iss0pP;
      if(N==0){
        putchar('\n');
      }
      else{
        for(X9Iss0pP=(0);X9Iss0pP<(N-1);X9Iss0pP++){
          wt_L(res1[X9Iss0pP]+1);
          wt_L(' ');
        }
        wt_L(res1[X9Iss0pP]+1);
        wt_L('\n');
      }
    }
    {
      int O3U4gd88;
      if(ress==0){
        putchar('\n');
      }
      else{
        for(O3U4gd88=(0);O3U4gd88<(ress-1);O3U4gd88++){
          wt_L(res2[O3U4gd88]+1);
          wt_L(' ');
        }
        wt_L(res2[O3U4gd88]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N;
// int A[1d5][3];
// 
// unionFind uf;
// deque<int> g[1d5];
// set<int> tri[1d5];
// int st[1d5], sts;
// 
// int res1[1d5];
// int res2[1d5], ress;
// 
// void merge(int i, int j){
//   int ii, jj, x, y, z, d, v;
//   x = ii = uf(i);
//   y = jj = uf(j);
//   uf(i,j);
//   z = uf(i);
//   d = (z^x^y);
// 
//   if(g[z].front() == i || g[z].front() == j){
//     if(g[d].front() == i || g[d].front() == j){
//       while(g[d].size()) g[z].push_front(g[d].front()), g[d].pop_front();
//     } else {
//       while(g[d].size()) g[z].push_front(g[d].back()), g[d].pop_back();
//     }
//   } else {
//     if(g[d].front() == i || g[d].front() == j){
//       while(g[d].size()) g[z].push_back(g[d].front()), g[d].pop_front();
//     } else {
//       while(g[d].size()) g[z].push_back(g[d].back()), g[d].pop_back();
//     }
//   }
// 
// }
// 
// {
//   int i, j, k, t, a;
// 
//   uf.malloc(1d5);
//   REP(rd_int()){
//     rd(N);
//     rep(i,N-2) rd((A[i]--)(3));
// 
//     uf.init(N);
//     rep(i,N){
//       g[i].clear();
//       g[i].push_back(i);
//     }
// 
//     sts = 0;
//     rep(i,N) tri[i].clear();
//     rep(i,N-2) rep(j,3) tri[A[i][j]].insert(i);
//     rep(i,N) if(tri[i].size()==1) st[sts++] = i;
// 
//     ress = 0;
//     while(sts){
//       i = st[--sts];
//       if(tri[i].size() == 0) continue;
//       t = *(tri[i].begin());
//       res2[ress++] = t;
// 
//       j = k = -1;
//       rep(a,3){
//         if(A[t][a]==i) continue;
//         if(j==-1) j = A[t][a], continue;
//         k = A[t][a];
//       }
//       tri[i].erase(t);
//       tri[j].erase(t); if(tri[j].size()==1) st[sts++] = j;
//       tri[k].erase(t); if(tri[k].size()==1) st[sts++] = k;
// 
//       if(uf(i) != uf(j)) merge(i, j);
//       if(uf(i) != uf(k)) merge(i, k);
//     }
// 
//     i = uf(0);
//     k = 0;
//     for(int x : g[i]) res1[k++] = x;
//     wt(res1(N)+1);
//     wt(res2(ress)+1);
//   }
// }