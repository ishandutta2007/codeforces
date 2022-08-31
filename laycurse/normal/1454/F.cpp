#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
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
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_Point_Minval{
  int N;
  int logN;
  T*mn;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
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
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
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
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mn[a] =min_L(mn[2*a], mn[2*a+1]);
    }
  }
  inline void change(int a, T val){
    mn[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mn[a+N] += val;
    build(a+N);
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
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
int A[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  segtree_Point_Minval<int> t;
  t.walloc(200000);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x;
    int z;
    int a;
    int b;
    int c;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    t.setN(N);
    for(i=(0);i<(N);i++){
      t[i] = A[i];
    }
    t.build();
    x = 1;
    a = A[0];
    z = 1;
    c = A[N-1];
    while(x+z < N){
      if(a < c){
        chmax(a, A[x++]);
        continue;
      }
      if(a > c){
        chmax(c, A[N-(++z)]);
        continue;
      }
      b = t.getMinVal(x, N-z);
      if(b==a){
        wt_L("YES");
        wt_L('\n');
        wt_L(x);
        wt_L(' ');
        wt_L(N-x-z);
        wt_L(' ');
        wt_L(z);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      if(A[x] < A[N-1-z] || (x+1 < N && N-2-z >= 0 && A[x] == A[N-1-z] && A[x+1] < A[N-2-z])){
        chmax(a, A[x++]);
      }
      else{
        chmax(c, A[N-(++z)]);
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// {
//   segtree_Point_Minval<int> t;
//   t.walloc(2d5);
//   REP(rd_int()){
//     int x, z, a, b, c;
//     rd(N,A(N));
//     t.setN(N);
//     rep(i,N) t[i] = A[i];
//     t.build();
//     x = 1; a = A[0];
//     z = 1; c = A[N-1];
//     while(x+z < N){
//       if(a < c) a >?= A[x++], continue;
//       if(a > c) c >?= A[N-(++z)], continue;
// 
//       b = t.getMinVal(x, N-z);
//       if(b==a) wt("YES"), wt(x, N-x-z, z), break_continue;
// 
//       if(A[x] < A[N-1-z] || (x+1 < N && N-2-z >= 0 && A[x] == A[N-1-z] && A[x+1] < A[N-2-z])){
//         a >?= A[x++];
//       } else {
//         c >?= A[N-(++z)];
//       }
//     }
//     wt("NO");
//   }
// }