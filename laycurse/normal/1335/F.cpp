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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
struct IntMap{
  int n;
  int mem;
  int logn;
  int *dat;
  int **nx;
  int calc_nx;
  int numCycle;
  int *cycleLen;
  int **cycle;
  int *int2c;
  int *int2cInd;
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
int M;
char C[1000000+2];
char S[1000000+2];
vector<int> g[1000000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res1 = 0;
    int res2 = 0;
    rd(N);
    rd(M);
    for(i=(0);i<(N);i++){
      rd(C+i*M);
    }
    for(i=(0);i<(N);i++){
      rd(S+i*M);
    }
    IntMap m(N*M);
    for(i=(0);i<(N*M);i++){
      if(S[i]=='U'){
        m[i] = i - M;
      }
      if(S[i]=='D'){
        m[i] = i + M;
      }
      if(S[i]=='L'){
        m[i] = i - 1;
      }
      if(S[i]=='R'){
        m[i] = i + 1;
      }
    }
    for(i=(0);i<(N*M);i++){
      g[i].clear();
    }
    for(i=(0);i<(N*M);i++){
      g[m.getNext(i, 4611686016279904256LL)].push_back(i);
    }
    for(i=(0);i<(N*M);i++){
      if(g[i].size()){
        int j;
        res1++;
        for(j=(0);j<(g[i].size());j++){
          if(C[g[i][j]]=='0'){
            res2++;
            break;
          }
        }
      }
    }
    wt_L(res1);
    wt_L(' ');
    wt_L(res2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, M;
// char C[1d6+2], S[1d6+2];
// vector<int> g[1d6];
// {
//   REP(rd_int()){
//     int res1 = 0, res2 = 0;
// 
//     rd(N,M);
//     rep(i,N) rd(C+i*M);
//     rep(i,N) rd(S+i*M);
//     IntMap m(N*M);
//     rep(i,N*M){
//       if(S[i]=='U') m[i] = i - M;
//       if(S[i]=='D') m[i] = i + M;
//       if(S[i]=='L') m[i] = i - 1;
//       if(S[i]=='R') m[i] = i + 1;
//     }
// 
//     rep(i,N*M) g[i].clear();
//     rep(i,N*M) g[m.getNext(i, ll_inf)].push_back(i);
// 
//     rep(i,N*M) if(g[i].size()){
//       res1++;
//       rep(j,g[i].size()) if(C[g[i][j]]=='0') res2++, break;
//     }
//     wt(res1, res2);
//   }
// }