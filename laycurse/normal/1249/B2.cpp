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
struct Permutation{
  int n;
  int mem;
  int *dat;
  Permutation(){
    n = mem = 0;
  }
  Permutation(const int nn){
    n = mem = nn;
    if(mem > 0){
      dat = new int[mem];
    }
  }
  Permutation(const Permutation &a){
    int i;
    mem = n = a.n;
    dat = new int[mem];
    for(i=(0);i<(mem);i++){
      dat[i] = a.dat[i];
    }
  }
  ~Permutation(){
    if(mem){
      delete [] dat;
    }
  }
  void changeSize(const int nn){
    n = nn;
    if(mem < n){
      if(mem){
        delete [] dat;
      }
      mem = n;
      dat = new int[mem];
    }
  }
  Permutation& operator=(const Permutation &a){
    int i;
    changeSize(a.n);
    n = a.n;
    for(i=(0);i<(n);i++){
      dat[i] = a.dat[i];
    }
    return *this;
  }
  Permutation& operator=(const int a){
    int i;
    for(i=(0);i<(n);i++){
      dat[i] = i;
    }
    return *this;
  }
  Permutation& operator*=(const Permutation &a){
    int i;
    int *m;
    void *mv = wmem;
    if(n==0 || n!=a.n){
      changeSize(0);
      return *this;
    }
    walloc1d(&m, n, &mv);
    for(i=(0);i<(n);i++){
      m[i] = dat[a.dat[i]];
    }
    for(i=(0);i<(n);i++){
      dat[i] = m[i];
    }
    return *this;
  }
  Permutation operator*(const Permutation &a){
    return Permutation(*this) *= a;
  }
  bool operator==(const Permutation &a){
    int i;
    if(n != a.n){
      return false;
    }
    for(i=(0);i<(n);i++){
      if(dat[i] != a.dat[i]){
        return false;
      }
    }
    return true;
  }
  template<class T> void apply(T A[]){
    int i;
    T *B;
    void *mv = wmem;
    walloc1d(&B, n, &mv);
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
    for(i=(0);i<(n);i++){
      A[i] = B[i];
    }
  }
  template<class T> void apply(T A[], T B[]){
    int i;
    for(i=(0);i<(n);i++){
      B[dat[i]] = A[i];
    }
  }
  int cycle_len(int res[] = NULL){
    int i;
    int j;
    int k;
    int sz = 0;
    int *vis;
    void *mv = wmem;
    if(res==NULL){
      walloc1d(&res, n, &mv);
    }
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        res[sz++] = k;
      }
    }
    return sz;
  }
  void cycle_len_EachElement(int res[]){
    int i;
    int j;
    int k;
    int sz = 0;
    int *vis;
    void *mv = wmem;
    walloc1d(&vis, n, &mv);
    for(i=(0);i<(n);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(!vis[i]){
        k = 0;
        j = i;
        while(vis[j]==0){
          vis[j] = 1;
          j = dat[j];
          k++;
        }
        j = i;
        while(vis[j]==1){
          res[j] = k;
          vis[j] = 2;
          j = dat[j];
        }
      }
    }
  }
  inline int& operator[](const int a){
    return dat[a];
  }
}
;
template<class S> inline Permutation pow_L(Permutation a, S b){
  Permutation res;
  res.changeSize(a.n);
  res = 1;
  while(b){
    if(b&1){
      res *= a;
    }
    b >>= 1;
    a *= a;
  }
  return res;
}
int N;
Permutation P;
int res[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    P.changeSize(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(P[cTE1_r3A]);P[cTE1_r3A] += (-1);
      }
    }
    P.cycle_len_EachElement(res);
    {
      int xr20shxY;
      if(N==0){
        putchar('\n');
      }
      else{
        for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
          wt_L(res[xr20shxY]);
          wt_L(' ');
        }
        wt_L(res[xr20shxY]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N;
// Permutation P;
// int res[2d5];
// {
//   REP(rd_int()){
//     rd(N);
//     P.changeSize(N);
//     rd((P--)(N));
//     P.cycle_len_EachElement(res);
//     wt(res(N));
//   }
// }