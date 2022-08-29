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
template<class T> int Factor_L(T N, T fac[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    N /= 2;
    while(N%2==0){
      N /= 2;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      N /= i;
      while(N%i==0){
        N /= i;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    sz++;
  }
  return sz;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct IntMap{
  int n;
  int mem;
  int logn;
  int*dat;
  int**nx;
  int calc_nx;
  int numCycle;
  int*cycleLen;
  int**cycle;
  int*int2c;
  int*int2cInd;
  IntMap(){
    n = mem = logn = 0;
    calc_nx = 0;
    numCycle = 0;
  }
  IntMap(int nn){
    n = mem = nn;
    for(logn=0; (1<<logn)<n; logn++){
      ;
    }
    logn++;
    if(mem > 0){
      dat = new int[mem];
    }
    calc_nx = 0;
    numCycle = 0;
  }
  ~IntMap(){
    if(mem){
      delete[] dat;
    }
    if(calc_nx){
      int i;
      for(i=(0);i<(logn);i++){
        delete[] nx[i];
      }
      delete[] nx;
    }
    if(numCycle > 0){
      int i;
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
    }
  }
  void changeSize(const int nn){
    int old_logn = logn;
    n = nn;
    for(logn=0; (1<<logn)<n; logn++){
      ;
    }
    logn++;
    if(mem < n){
      if(mem){
        delete [] dat;
      }
      mem = n;
      dat = new int [mem];
    }
    if(calc_nx){
      int i;
      for(i=(0);i<(old_logn);i++){
        delete[] nx[i];
      }
      delete[] nx;
      calc_nx = 0;
    }
    if(numCycle > 0){
      int i;
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
      numCycle = 0;
    }
  }
  int calcCycle(void){
    int i;
    int j;
    int k;
    if(numCycle){
      delete[] cycleLen;
      for(i=(0);i<(numCycle);i++){
        delete[] cycle[i];
      }
      delete[] cycle;
      delete[] int2c;
      delete[] int2cInd;
      numCycle = 0;
    }
    int2c = new int[n];
    int2cInd = new int[n];
    for(i=(0);i<(n);i++){
      int2c[i] = -2;
    }
    for(i=(0);i<(n);i++){
      int2cInd[i] = -1;
    }
    numCycle = 0;
    for(i=(0);i<(n);i++){
      if(int2c[i] == -2){
        j = i;
        for(;;){
          if(int2c[j] != -2){
            break;
          }
          int2c[j] = -3;
          j = dat[j];
        }
        if(int2c[j] == -3){
          k = 0;
          for(;;){
            if(int2c[j] != -3){
              break;
            }
            int2c[j] = numCycle;
            int2cInd[j] = k++;
            j = dat[j];
          }
          numCycle++;
        }
        j = i;
        for(;;){
          if(int2c[j] != -3){
            break;
          }
          int2c[j] = -1;
          j = dat[j];
        }
      }
    }
    cycleLen = new int[numCycle];
    for(i=(0);i<(numCycle);i++){
      cycleLen[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(int2c[i] >= 0){
        cycleLen[int2c[i]]++;
      }
    }
    cycle = new int*[numCycle];
    for(i=(0);i<(numCycle);i++){
      cycle[i] = new int[cycleLen[i]];
    }
    for(i=(0);i<(n);i++){
      if(int2c[i] >= 0){
        cycle[int2c[i]][int2cInd[i]] = i;
      }
    }
    return numCycle;
  }
  void calcNext(int recalc = 1){
    int i, k;
    if(recalc || numCycle==0){
      calcCycle();
    }
    if(calc_nx == 0){
      int i;
      calc_nx = 1;
      nx = new int*[logn];
      for(i=(0);i<(logn);i++){
        nx[i] = new int[n];
      }
    }
    for(i=(0);i<(n);i++){
      nx[0][i] = dat[i];
    }
    for(k=(1);k<(logn);k++){
      for(i=(0);i<(n);i++){
        nx[k][i] = nx[k-1][nx[k-1][i]];
      }
    }
  }
  template<class T> int getNext(int x, T s){
    int i;
    if(calc_nx==0){
      calcNext();
    }
    if(s >= (1<<(logn-1))){
      x = nx[logn-1][x];
      s -= (1<<(logn-1));
      return cycle[int2c[x]][(int2cInd[x]+s)%cycleLen[int2c[x]]];
    }
    for(i=(0);i<(logn);i++){
      if(s&1<<i){
        x = nx[i][x];
      }
    }
    return x;
  }
  inline int& operator[](const int a){
    return dat[a];
  }
}
;
int N;
int Q;
int A[100000];
int L;
int R;
int fs;
int fc[30];
vector<int> ip[100000+1];
int main(){
  int V9aVTaxx, i;
  int res;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    fs =Factor_L(A[i], fc);
    for(j=(0);j<(fs);j++){
      ip[fc[j]].push_back(i);
    }
  }
  IntMap f(N+1);
  for(i=(0);i<(N+1);i++){
    f[i] = N;
  }
  for(i=(0);i<(100000+1);i++){
    int j;
    for(j=(1);j<(ip[i].size());j++){
      chmin(f[ip[i][j-1]], ip[i][j]);
    }
  }
  for(i=(N)-1;i>=(0);i--){
    chmin(f[i], f[i+1]);
  }
  for(V9aVTaxx=(0);V9aVTaxx<(Q);V9aVTaxx++){
    rd(L);L += (-1);
    rd(R);
    int jZyWAPpY;
    int jbtyPBGc;
    int ZIeRIny5;
    jZyWAPpY = 0;
    jbtyPBGc = 100000+1;
    while(jZyWAPpY < jbtyPBGc){
      if((jZyWAPpY + jbtyPBGc)%2==0){
        ZIeRIny5 = (jZyWAPpY + jbtyPBGc) / 2;
      }
      else{
        ZIeRIny5 = (jZyWAPpY + jbtyPBGc + 1) / 2;
      }
      if(f.getNext(L,ZIeRIny5) < R){
        jZyWAPpY = ZIeRIny5;
      }
      else{
        jbtyPBGc = ZIeRIny5 - 1;
      }
    }
    res =jbtyPBGc+ 1;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, Q, A[1d5], L, R;
// int fs, fc[30];
// VI ip[1d5+1];
// {
//   int res;
//   rd(N,Q,A(N));
// 
//   rep(i,N){
//     fs = Factor(A[i], fc);
//     rep(j,fs) ip[fc[j]].push_back(i);
//   }
// 
//   IntMap f(N+1);
//   rep(i,N+1) f[i] = N;
//   rep(i,1d5+1) rep(j,1,ip[i].size()) f[ip[i][j-1]] <?= ip[i][j];
//   rrep(i,N) f[i] <?= f[i+1];
//   rep(Q){
//     rd(L--,R);
//     res = bsearch_max[int,x,0,1d5+1](f.getNext(L,x) < R) + 1;
//     wt(res);
//   }
// }