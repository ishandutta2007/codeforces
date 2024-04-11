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
template<class T> void malloc1d(T **arr, int x){
  (*arr) = (T*)malloc(x*sizeof(T));
}
template<class T> void free1d(T *arr){
  free(arr);
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int> *r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
template<class T> int coordcomp_L(int n1, T arr1[], int n2, T arr2[], int res1[] = NULL, int res2[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int> *r;
  walloc1d(&r, n1+n2, &mem);
  for(i=(0);i<(n1);i++){
    r[i].first = arr1[i];
    r[i].second = i;
  }
  for(i=(0);i<(n2);i++){
    r[n1+i].first = arr2[i];
    r[n1+i].second = n1+i;
  }
  sort(r, r+n1+n2);
  for(i=(0);i<(n1+n2);i++){
    if(i && r[i].first != r[i-1].first){
      k++;
    }
    if(r[i].second < n1){
      if(res1!=NULL){
        res1[r[i].second] = k;
      }
      else{
        arr1[r[i].second] = k;
      }
    }
    else{
      if(res2!=NULL){
        res2[r[i].second-n1] = k;
      }
      else{
        arr2[r[i].second-n1] = k;
      }
    }
  }
  return k+1;
}
template<class T> struct Grid1d{
  int n;
  T *d;
  int set_s;
  int set_d;
  T *d_s;
  int *up;
  int *dw;
  int *lf;
  int *rg;
  void malloc(const int nn){
    n = nn;
    set_s = 0;
    set_d = 0;
    malloc1d(&d, n);
  }
  void free(void){
    free1d(d);
    if(set_s){
      free1d(d_s);
    }
    if(set_d){
      free1d(up);
      free1d(dw);
    }
  }
  T& operator[](int a){
    return d[a];
  }
  void setSum(void){
    int i;
    if(set_s == 0){
      set_s = 1;
      malloc1d(&d_s, n+1);
    }
    d_s[0] = 0;
    for(i=(0);i<(n);i++){
      d_s[i+1] = d_s[i] + d[i];
    }
  }
  void setDir(void){
    int i;
    if(set_d == 0){
      set_d = 1;
      malloc1d(&up, n);
      malloc1d(&dw, n);
      lf = dw;
      rg = up;
    }
    lf[0] = 1;
    for(i=(1);i<(n);i++){
      if(d[i]==d[i-1]){
        lf[i] = 1 + lf[i-1];
      }
      else{
        lf[i] = 1 ;
      }
    }
    rg[n-1] = 1;
    for(i=n-2;i>=0;i--){
      if(d[i]==d[i+1]){
        rg[i] = 1 + rg[i+1];
      }
      else{
        rg[i] = 1 ;
      }
    }
  }
  void setDirMatch(const T v){
    int i;
    if(set_d == 0){
      set_d = 1;
      malloc1d(&up, n);
      malloc1d(&dw, n);
      lf = dw;
      rg = up;
    }
    if(d[0]==v){
      lf[0] =1;
    }
    else{
      lf[0] =0;
    }
    for(i=(1);i<(n);i++){
      if(d[i]==v){
        lf[i] =1 + lf[i-1];
      }
      else{
        lf[i] =0;
      }
    }
    if(d[n-1]==v){
      rg[n-1] =1;
    }
    else{
      rg[n-1] =0;
    }
    for(i=n-2;i>=0;i--){
      if(d[i]==v){
        rg[i] =1 + rg[i+1];
      }
      else{
        rg[i] =0;
      }
    }
  }
  inline T getSum(const int a, const int b){
    return d_s[b+1] - d_s[a];
  }
}
;
int N;
int SA[100000];
int EA[100000];
int SB[100000];
int EB[100000];
Rand rnd;
long long w[100000];
Grid1d<long long> sm1;
Grid1d<long long> sm2;
long long wa[100000];
long long wb[100000];
int main(){
  int loop;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(SA[Lj4PdHRW]);
      rd(EA[Lj4PdHRW]);
      rd(SB[Lj4PdHRW]);
      rd(EB[Lj4PdHRW]);
    }
  }
  coordcomp_L(N,SA,N,EA);
  coordcomp_L(N,SB,N,EB);
  sm1.malloc(2*N);
  sm2.malloc(2*N);
  for(loop=(0);loop<(10);loop++){
    int i;
    for(i=(0);i<(N);i++){
      w[i] = rnd.get(1LL,1000000000000LL);
    }
    for(i=(0);i<(2*N);i++){
      sm1[i] = sm2[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sm1[SA[i]] += w[i];
    }
    for(i=(0);i<(N);i++){
      sm2[EA[i]] += w[i];
    }
    sm1.setSum();
    sm2.setSum();
    for(i=(0);i<(N);i++){
      wa[i] = sm2.getSum(0,SA[i]-1) + sm1.getSum(EA[i]+1,2*N-1);
    }
    for(i=(0);i<(2*N);i++){
      sm1[i] = sm2[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sm1[SB[i]] += w[i];
    }
    for(i=(0);i<(N);i++){
      sm2[EB[i]] += w[i];
    }
    sm1.setSum();
    sm2.setSum();
    for(i=(0);i<(N);i++){
      wb[i] = sm2.getSum(0,SB[i]-1) + sm1.getSum(EB[i]+1,2*N-1);
    }
    for(i=(0);i<(N);i++){
      if(wa[i]!=wb[i]){
        wt_L("NO");
        wt_L('\n');
        return 0;
      }
    }
  }
  wt_L("YES");
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// 
// int N, SA[1d5], EA[1d5], SB[1d5], EB[1d5];
// Rand rnd;
// 
// ll w[1d5];
// Grid1d<ll> sm1, sm2;
// ll wa[1d5], wb[1d5];
// {
//   rd(N,(SA,EA,SB,EB)(N));
// 
// /*  N = 1d5;
//   rep(i,N) SA[i] = rnd.get(0,1d9+1);
//   rep(i,N) SB[i] = rnd.get(0,1d9+1);
//   rep(i,N) EA[i] = rnd.get(0,1d9+1);
//   rep(i,N) EB[i] = rnd.get(0,1d9+1);
//   rep(i,N) sortE(SA[i],EA[i]);
//   rep(i,N) sortE(SB[i],EB[i]);*/
// 
//   coordcomp(N,SA,N,EA);
//   coordcomp(N,SB,N,EB);
//   sm1.malloc(2N);
//   sm2.malloc(2N);
//   rep(loop,10){
//     rep(i,N) w[i] = rnd.get(1LL,1d12);
// 
//     rep(i,2N) sm1[i] = sm2[i] = 0;
//     rep(i,N) sm1[SA[i]] += w[i];
//     rep(i,N) sm2[EA[i]] += w[i];
//     sm1.setSum();
//     sm2.setSum();
//     rep(i,N) wa[i] = sm2.getSum(0,SA[i]-1) + sm1.getSum(EA[i]+1,2N-1);
// 
//     rep(i,2N) sm1[i] = sm2[i] = 0;
//     rep(i,N) sm1[SB[i]] += w[i];
//     rep(i,N) sm2[EB[i]] += w[i];
//     sm1.setSum();
//     sm2.setSum();
//     rep(i,N) wb[i] = sm2.getSum(0,SB[i]-1) + sm1.getSum(EB[i]+1,2N-1);
// 
//     rep(i,N) if(wa[i]!=wb[i]) wt("NO"), return 0;
//   }
//   wt("YES");
// }