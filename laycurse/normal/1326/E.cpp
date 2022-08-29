#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_Add_Minval{
  int N;
  int logN;
  T *mn;
  T *addval;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
    addval = new T[i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mn, 2*i, mem);
    walloc1d(&addval, i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
    delete [] addval;
  }
  T& operator[](int i){
    return mn[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        mn[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mn[i] =min_L(mn[2*i], mn[2*i+1]);
    }
    int szDqbNYU = N;
    for(i=(1);i<(szDqbNYU);i++){
      addval[i] = 0;
    }
  }
  inline void push_one(int a, int sz, int st){
    if(addval[a] != 0){
      if(sz > 1){
        addval[a*2] += addval[a];
        addval[a*2+1] += addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      else{
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      addval[a] = 0;
      return;
    }
  }
  inline void push(int a){
    int i;
    int aa = a - N;
    int nd;
    int sz;
    int st;
    for(i=logN;i;i--){
      nd = a>>i;
      sz = 1<<(i-1);
      st = 2 * sz * (aa>>i);
      push_one(nd, sz, st);
    }
  }
  inline void build(int a){
    int sz = 1;
    int st = a - N;
    while(a > 1){
      if(a%2){
        st += sz;
      }
      a /= 2;
      sz *= 2;
      mn[a] =min_L(mn[a*2], mn[a*2+1]);
      if(addval[a] != 0){
        mn[a] += addval[a];
      }
    }
  }
  inline void add(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      mn[a] += val;
      a++;
    }
    if(b%2){
      b--;
      mn[b] += val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        addval[a] += val;
        mn[a] += val;
        a++;
      }
      if(b%2){
        b--;
        addval[b] += val;
        mn[b] += val;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
int P[300000];
int Q[300000];
int place[300000];
int res[300000];
int main(){
  wmem = memarr;
  int i;
  int k;
  segtree_Add_Minval<int> t;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);P[Lj4PdHRW] += (-1);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(Q[e98WHCEY]);Q[e98WHCEY] += (-1);
    }
  }
  t.walloc(N,1);
  for(i=(0);i<(N);i++){
    place[P[i]] = i;
  }
  k = 0;
  for(i=(N)-1;i>=(0);i--){
    t.add(0, place[i]+1, -1);
    while(k < N && t.getMinVal(0,N) < 0){
      res[k] = i + 1;
      t.add(0, Q[k]+1, 1);
      k++;
    }
  }
  {
    int tU__gIr_;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        wt_L(res[tU__gIr_]);
        wt_L(' ');
      }
      wt_L(res[tU__gIr_]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200317-1

// --- original code ---
// //no-unlocked
// int N, P[3d5], Q[3d5];
// int place[3d5];
// int res[3d5];
// {
//   int i, k;
//   segtree_Add_Minval<int> t;
//   rd(N,(P--)(N),(Q--)(N));
//   t.walloc(N,1);
//   rep(i,N) place[P[i]] = i;
//   k = 0;
//   rrep(i,N){
//     t.add(0, place[i]+1, -1);
//     while(k < N && t.getMinVal(0,N) < 0){
//       res[k] = i + 1;
//       t.add(0, Q[k]+1, 1);
//       k++;
//     }
//   }
//   wt(res(N));
// }