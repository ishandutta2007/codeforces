#pragma GCC optimize ("Ofast")
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
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
template <class T> struct LHeap{
  int*hp;
  int*place;
  int size;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void malloc(int N, int ini){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
    if(ini){
      init(N);
    }
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void walloc(int N, int ini, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
    if(ini){
      init(N);
    }
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    T f = val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res = hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
struct graph{
  int N;
  int*es;
  int**edge;
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
unsigned long long HashMap_ullP_L[4];
template<class KEY, class VAL> struct HashMap{
  char*used;
  KEY*key;
  VAL*val;
  int mem;
  int n;
  int mask;
  HashMap(){
    mem = 0;
  }
  ~HashMap(){
    free();
  }
  void expand(int nn){
    if(mem >= nn){
      return;
    }
    if(mem){
      free();
    }
    mem = nn;
    used = new char[nn];
    key = new KEY[nn];
    val = new VAL[nn];
  }
  void free(){
    if(mem){
      mem = 0;
      delete[] used;
      delete[] key;
      delete[] val;
    }
  }
  void init(int nn){
    int i;
    n = 1;
    nn = nn + (nn + 1) / 2;
    while(n < nn){
      n *= 2;
    }
    mask = n - 1;
    expand(n);
    for(i=(0);i<(n);i++){
      used[i] = 0;
    }
  }
  inline int getHash(const int a){
    unsigned long long d = a;
    d = (((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) & mask;
    return d;
  }
  inline int getHash(const unsigned a){
    unsigned long long d = a;
    d = (((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) & mask;
    return d;
  }
  inline int getHash(const long long a){
    unsigned long long d = a;
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline int getHash(const unsigned long long a){
    unsigned long long d = a;
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline int getHash(const pair<int,int> a){
    unsigned long long d = (((unsigned long long)a.first) << 32) + ((unsigned long long)a.second);
    d = (((((d * HashMap_ullP_L[0]) >> 32) * HashMap_ullP_L[1]) >> 32) * HashMap_ullP_L[2]) & mask;
    return d;
  }
  inline VAL& operator[](const KEY a){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        break;
      }
      if(used[k]==0){
        used[k] = 1;
        key[k] = a;
        break;
      }
      k = (k+1) & mask;
    }
    return val[k];
  }
  inline bool exist(const KEY a){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        return true;
      }
      if(used[k]==0){
        break;
      }
      k = (k+1) & mask;
    }
    return false;
  }
  template<class S> inline bool exist(const KEY a, S &res){
    int k = getHash(a);
    for(;;){
      if(used[k]==1 && key[k]==a){
        res = val[k];
        return true;
      }
      if(used[k]==0){
        break;
      }
      k = (k+1) & mask;
    }
    return false;
  }
}
;
int N;
int M;
int K;
int A[100000];
int B[100000];
int deg[100000];
int ok[100000];
HashMap<int,int> hs[100000];
graph g;
int ress;
int res[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  {
    int i;
    int j;
    int k;
    Rand rnd;
    for(i=(0);i<(20);i++){
      rnd.get(2);
    }
    for(i=(0);i<(4);i++){
      for(j=(0);j<(32);j++){
        k = rnd.get(1,62);
        HashMap_ullP_L[i] |= (1ULL << k);
      }
      HashMap_ullP_L[i] |= (1ULL << 0);
      HashMap_ullP_L[i] |= (1ULL << 63);
    }
  }
  int i;
  int j;
  LHeap<int> hp;
  hp.walloc(100000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(M);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    g.setEdge(N,M,A,B);
    for(i=(0);i<(N);i++){
      deg[i] = g.es[i];
    }
    for(i=(0);i<(N);i++){
      hs[i].init(deg[i]);
    }
    for(i=(0);i<(M);i++){
      hs[A[i]][B[i]] = hs[B[i]][A[i]] = 1;
    }
    hp.init(N);
    for(i=(0);i<(N);i++){
      hp.change(i,deg[i]);
    }
    for(i=(0);i<(N);i++){
      ok[i] = 1;
    }
    while(hp.size){
      int szDqbNYU;
      i = hp.pop();
      if(deg[i] >= K){
        ress = 0;
        for(j=(0);j<(N);j++){
          if(ok[j]){
            res[ress++] = j;
          }
        }
        wt_L(1);
        wt_L(' ');
        wt_L(ress);
        wt_L('\n');
        {
          int iMWUTgY_;
          if(ress==0){
            wt_L('\n');
          }
          else{
            for(iMWUTgY_=(0);iMWUTgY_<(ress-1);iMWUTgY_++){
              wt_L(res[iMWUTgY_]+ 1);
              wt_L(' ');
            }
            wt_L(res[iMWUTgY_]+ 1);
            wt_L('\n');
          }
        }
        goto Q5VJL1cS;
      }
      if(deg[i] == K-1){
        int jPV_0s1p, x;
        ress = 0;
        res[ress++] = i;
        for(jPV_0s1p=(0);jPV_0s1p<(g.es[i]);jPV_0s1p++){
          auto &j = g.edge[i][jPV_0s1p];
          if(ok[j]){
            res[ress++] = j;
          }
        }
        for(x=(1);x<(ress);x++){
          int y;
          for(y=(x+1);y<(ress);y++){
            if(!hs[res[x]].exist(res[y])){
              ress = 0;
              goto gEg5UqEA;
            }
          }
        }
        gEg5UqEA:;
        if(ress){
          wt_L(2);
          wt_L('\n');
          {
            int zT28qSmp;
            if(ress==0){
              wt_L('\n');
            }
            else{
              for(zT28qSmp=(0);zT28qSmp<(ress-1);zT28qSmp++){
                wt_L(res[zT28qSmp]+ 1);
                wt_L(' ');
              }
              wt_L(res[zT28qSmp]+ 1);
              wt_L('\n');
            }
          }
          goto Q5VJL1cS;
        }
      }
      ok[i] = 0;
      for(szDqbNYU=(0);szDqbNYU<(g.es[i]);szDqbNYU++){
        auto &j = g.edge[i][szDqbNYU];
        if(ok[j]){
          deg[j]--;
          hp.change(j,deg[j]);
        }
      }
    }
    wt_L(-1);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20201121-1

// --- original code ---
// //no-unlocked
// int N, M, K, A[1d5], B[1d5];
// int deg[1d5], ok[1d5];
// HashMap<int,int> hs[1d5];
// graph g;
// int ress, res[1d5];
// {
//   int i, j;
//   LHeap<int> hp;
//   hp.walloc(1d5);
//   REP(rd_int()){
//     rd(N,M,K,(A--,B--)(M));
//     g.setEdge(N,M,A,B);
//     rep(i,N) deg[i] = g.es[i];
//     rep(i,N) hs[i].init(deg[i]);
//     rep(i,M) hs[A[i]][B[i]] = hs[B[i]][A[i]] = 1;
//     hp.init(N);
//     rep(i,N) hp.change(i,deg[i]);
//     rep(i,N) ok[i] = 1;
// 
//     while(hp.size){
//       i = hp.pop();
//       if(deg[i] >= K){
//         ress = 0;
//         rep(j,N) if(ok[j]) res[ress++] = j;
//         wt(1, ress);
//         wt(res(ress) + 1);
//         break_continue;
//       }
//       if(deg[i] == K-1){
//         ress = 0;
//         res[ress++] = i;
//         rep[g.edge[i]](j,g.es[i]) if(ok[j]) res[ress++] = j;
//         rep(x,1,ress) rep(y,x+1,ress) if(!hs[res[x]].exist(res[y])) ress = 0, break_break;
//         if(ress){
//           wt(2);
//           wt(res(ress) + 1);
//           break_continue;
//         }
//       }
//       ok[i] = 0;
//       rep[g.edge[i]](j,g.es[i]) if(ok[j]){
//         deg[j]--;
//         hp.change(j,deg[j]);
//       }
//     }
// 
//     wt(-1);
//   }
// }