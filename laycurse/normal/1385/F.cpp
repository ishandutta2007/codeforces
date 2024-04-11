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
struct graph{
  int N;
  int *es;
  int **edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
}
;
int N;
int K;
int A[200000];
int B[200000];
graph g;
int liv[200000];
int deg[200000];
vector<int> con[200000];
set<int> s;
int getnext(int i){
  int Lj4PdHRW;
  for(Lj4PdHRW=(0);Lj4PdHRW<(g.es[i]);Lj4PdHRW++){
    auto &k = g.edge[i][Lj4PdHRW];
    if(liv[k]){
      return k;
    }
  }
  return -1;
}
int main(){
  int e98WHCEY;
  wmem = memarr;
  int cTE1_r3A = rd_int();
  for(e98WHCEY=(0);e98WHCEY<(cTE1_r3A);e98WHCEY++){
    int i;
    int j;
    int k;
    int res = 0;
    rd(N);
    rd(K);
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
        rd(A[xr20shxY]);A[xr20shxY] += (-1);
        rd(B[xr20shxY]);B[xr20shxY] += (-1);
      }
    }
    if(K==1){
      wt_L(N-1);
      wt_L('\n');
      continue;
    }
    g.setEdge(N,N-1,A,B);
    for(i=(0);i<(N);i++){
      liv[i] = 1;
    }
    for(i=(0);i<(N);i++){
      con[i].clear();
    }
    s.clear();
    for(i=(0);i<(N);i++){
      deg[i] = g.es[i];
    }
    for(i=(0);i<(N);i++){
      if(deg[i] == 1){
        j = getnext(i);
        con[j].push_back(i);
        if(con[j].size()==K){
          s.insert(j);
        }
      }
    }
    while(s.size()){
      int ZIeRIny5;
      k = getFirst(s);
      if(con[k].size() < K){
        popFirst(s);
        continue;
      }
      res++;
      for(ZIeRIny5=(0);ZIeRIny5<(K);ZIeRIny5++){
        i = con[k].back();
        con[k].pop_back();
        liv[i] = 0;
        deg[k]--;
        if(deg[k]==1){
          j = getnext(k);
          con[j].push_back(k);
          if(con[j].size()==K){
            s.insert(j);
          }
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K, A[2d5], B[2d5];
// graph g;
// int liv[2d5], deg[2d5];
// vector<int> con[2d5];
// set<int> s;
// 
// int getnext(int i){
//   rep[g.edge[i]](k,g.es[i]) if(liv[k]) return k;
//   return -1;
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k, res = 0;
//     rd(N,K,(A--,B--)(N-1));
//     if(K==1) wt(N-1), continue;
// 
//     g.setEdge(N,N-1,A,B);
// 
//     rep(i,N) liv[i] = 1;
//     rep(i,N) con[i].clear();
//     s.clear();
// 
//     rep(i,N) deg[i] = g.es[i];
//     rep(i,N) if(deg[i] == 1){
//       j = getnext(i);
//       con[j].push_back(i);
//       if(con[j].size()==K) s.insert(j);
//     }
// 
//     while(s.size()){
//       k = getFirst(s);
//       if(con[k].size() < K) popFirst(s), continue;
// 
//       res++;
//       rep(K){
//         i = con[k].back();
//         con[k].pop_back();
//         liv[i] = 0;
//         deg[k]--;
//         if(deg[k]==1){
//           j = getnext(k);
//           con[j].push_back(k);
//           if(con[j].size()==K) s.insert(j);
//         }
//       }
//     }
// 
//     wt(res);
//   }
// }