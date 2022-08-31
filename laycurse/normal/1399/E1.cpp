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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template <class T> struct LHeap{
  int *hp;
  int *place;
  int size;
  T *val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
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
  void getDist(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int*q;
    int s;
    int z;
    walloc1d(&q, N, &mem);
    for(i=(0);i<(N);i++){
      res[i]=-1;
    }
    res[root]=0;
    s=0;
    z=1;
    q[0]=root;
    while(z){
      i=q[s++];
      z--;
      for(j=(0);j<(es[i]);j++){
        k=edge[i][j];
        if(res[k]>=0){
          continue;
        }
        res[k]=res[i]+1;
        q[s+z++]=k;
      }
    }
  }
  template<class S> void SubTreeWeight(int root, S weight[], S res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int m;
    int *q;
    int qs = 0;
    int qe = 1;
    walloc1d(&q,N,&mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    res[root] = 0;
    q[0] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(res[k]==0){
          continue;
        }
        res[k] = 0;
        q[qe++] = k;
      }
    }
    for(m=(N)-1;m>=(0);m--){
      i = q[m];
      res[i] = weight[i];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        res[i] += res[k];
      }
    }
  }
}
;
int N;
int A[100000];
int B[100000];
int W[100000];
int C[100000];
int lf[100000];
int wmemo[100000];
long long S;
graph g;
int dis[100000];
int nsz[100000];
long long sz[100000];
LHeap<long long> hp1;
LHeap<long long> hp2;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  hp1.malloc(100000);
  hp2.malloc(100000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, odd;
    long long cur;
    long long tmp;
    long long res = 4611686016279904256LL;
    int x1;
    int x2;
    int y;
    long long x1c;
    long long x2c;
    long long yc;
    long long zc;
    rd(N);
    rd(S);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
        rd(W[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N-1);i++){
      C[i] = 1;
    }
    g.setEdge(N,N-1,A,B);
    g.getDist(0, dis);
    for(i=(0);i<(N);i++){
      lf[i] = 0;
    }
    for(i=(1);i<(N);i++){
      if(g.es[i]==1){
        lf[i] = 1;
      }
    }
    g.SubTreeWeight(0, lf, nsz);
    for(i=(0);i<(N-1);i++){
      if(dis[A[i]] > dis[B[i]]){
        swap(A[i], B[i]);
      }
      sz[i] = nsz[B[i]];
    }
    for(i=(0);i<(N-1);i++){
      wmemo[i] = W[i];
    }
    for(odd=(0);odd<(2);odd++){
      for(i=(0);i<(N-1);i++){
        W[i] = wmemo[i];
      }
      cur = tmp = 0;
      for(i=(0);i<(N-1);i++){
        cur += sz[i] * W[i];
      }
      hp1.init(N-1);
      hp2.init(N-1);
      for(i=(0);i<(N-1);i++){
        if(C[i]==1){
          hp1.change(i, sz[i]*(W[i]/2-W[i]));
        }
      }
      for(i=(0);i<(N-1);i++){
        if(C[i]==2){
          hp2.change(i, sz[i]*(W[i]/2-W[i]));
        }
      }
      if(odd && hp1.size==0){
        continue;
      }
      if(odd){
        x1 = hp1.pop();
        x1c = hp1.val[x1];
        cur += x1c;
        W[x1] /= 2;
        tmp++;
        if(W[x1] > 0){
          hp1.change(x1, sz[x1]*(W[x1]/2-W[x1]));
        }
      }
      while(cur > S){
        x1 = x2 = y = -1;
        x1c = x2c = yc = 4611686016279904256LL;
        if(hp1.size){
          x1 = hp1.pop();
          x1c = hp1.val[x1];
        }
        if(hp1.size){
          x2 = hp1.pop();
          x2c = hp1.val[x2];
        }
        if(hp2.size){
          y = hp2.pop();
          yc = hp2.val[y];
        }
        zc = 4611686016279904256LL;
        if(x1 >= 0){
          zc = sz[x1] * (W[x1]/4 - W[x1]);
        }
        if(cur + x1c <= S){
          tmp++;
          break;
        }
        if(cur + yc <= S || cur + zc <= S){
          tmp+=2;
          break;
        }
        if(x1c + x2c > 0 && yc > 0 && zc > 0){
          tmp=4611686016279904256LL;
          break;
        }
        if(zc <= x1c + x2c && zc <= yc){
          cur += zc;
          tmp += 2;
          W[x1] /= 4;
        }
        else if(x1c + x2c <= yc){
          cur += x1c + x2c;
          tmp += 2;
          W[x1] /= 2;
          W[x2] /= 2;
        }
        else{
          cur += yc;
          tmp += 2;
          W[y] /= 2;
        }
        if(x1 >= 0 && W[x1] > 0){
          hp1.change(x1, sz[x1]*(W[x1]/2-W[x1]));
        }
        if(x2 >= 0 && W[x2] > 0){
          hp1.change(x2, sz[x2]*(W[x2]/2-W[x2]));
        }
        if(y  >= 0 && W[y ] > 0){
          hp2.change(y , sz[y ]*(W[y ]/2-W[y ]));
        }
      }
      chmin(res, tmp);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1d5], B[1d5], W[1d5], C[1d5], lf[1d5], wmemo[1d5];
// ll S;
// graph g;
// int dis[1d5], nsz[1d5]; ll sz[1d5];
// LHeap<ll> hp1, hp2;
// {
//   hp1.malloc(1d5);
//   hp2.malloc(1d5);
//   REP(rd_int()){
//     ll cur, tmp, res = ll_inf;
//     int x1, x2, y;
//     ll x1c, x2c, yc, zc;
// 
//     rd(N,S,(A--,B--,W)(N-1));
//     rep(i,N-1) C[i] = 1;
//     g.setEdge(N,N-1,A,B);
//     g.getDist(0, dis);
//     rep(i,N) lf[i] = 0;
//     rep(i,1,N) if(g.es[i]==1) lf[i] = 1;
//     g.SubTreeWeight(0, lf, nsz);
//     rep(i,N-1){
//       if(dis[A[i]] > dis[B[i]]) swap(A[i], B[i]);
//       sz[i] = nsz[B[i]];
//     }
//     rep(i,N-1) wmemo[i] = W[i];
// 
//     rep(odd,2){
//       rep(i,N-1) W[i] = wmemo[i];
//       cur = tmp = 0;
//       rep(i,N-1) cur += sz[i] * W[i];
//       hp1.init(N-1);
//       hp2.init(N-1);
//       rep(i,N-1) if(C[i]==1) hp1.change(i, sz[i]*(W[i]/2-W[i]));
//       rep(i,N-1) if(C[i]==2) hp2.change(i, sz[i]*(W[i]/2-W[i]));
// 
//       if(odd && hp1.size==0) continue;
//       if(odd){
//         x1 = hp1.pop();
//         x1c = hp1.val[x1];
//         cur += x1c;
//         W[x1] /= 2;
//         tmp++;
//         if(W[x1] > 0) hp1.change(x1, sz[x1]*(W[x1]/2-W[x1]));
//       }
// 
//       while(cur > S){
//         x1 = x2 = y = -1;
//         x1c = x2c = yc = ll_inf;
//         if(hp1.size) x1 = hp1.pop(), x1c = hp1.val[x1];
//         if(hp1.size) x2 = hp1.pop(), x2c = hp1.val[x2];
//         if(hp2.size) y = hp2.pop(), yc = hp2.val[y];
//         
//         zc = ll_inf;
//         if(x1 >= 0) zc = sz[x1] * (W[x1]/4 - W[x1]);
// 
//         if(cur + x1c <= S) tmp++, break;
//         if(cur + yc <= S || cur + zc <= S) tmp+=2, break;
//         if(x1c + x2c > 0 && yc > 0 && zc > 0) tmp=ll_inf, break;
//         if(zc <= x1c + x2c && zc <= yc){
//           cur += zc;
//           tmp += 2;
//           W[x1] /= 4;
//         } else if(x1c + x2c <= yc){
//           cur += x1c + x2c;
//           tmp += 2;
//           W[x1] /= 2;
//           W[x2] /= 2;
//         } else {
//           cur += yc;
//           tmp += 2;
//           W[y] /= 2;
//         }
// 
//         if(x1 >= 0 && W[x1] > 0) hp1.change(x1, sz[x1]*(W[x1]/2-W[x1]));
//         if(x2 >= 0 && W[x2] > 0) hp1.change(x2, sz[x2]*(W[x2]/2-W[x2]));
//         if(y  >= 0 && W[y ] > 0) hp2.change(y , sz[y ]*(W[y ]/2-W[y ]));
//       }
//       res <?= tmp;
//     }
// 
//     wt(res);
//   }
// }