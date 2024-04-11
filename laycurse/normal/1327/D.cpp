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
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> int Divisor_L(T N, T res[], void *mem = wmem){
  int i;
  int j;
  int k;
  int s;
  int sz = 0;
  T *fc;
  int *fs;
  int fsz;
  walloc1d(&fc, 100, &mem);
  walloc1d(&fs, 100, &mem);
  fsz =Factor_L(N, fc, fs);
  res[sz++] = 1;
  for(i=(0);i<(fsz);i++){
    s = sz;
    k = s * fs[i];
    for(j=(0);j<(k);j++){
      res[sz++] = res[j] * fc[i];
    }
  }
  sort(res, res+sz);
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
int C[200000];
int ys;
int y[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 1073709056;
    rd(N);
    IntMap P(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(P[cTE1_r3A]);P[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(C[xr20shxY]);
      }
    }
    P.calcCycle();
    for(i=(0);i<(P.numCycle);i++){
      int tU__gIr_;
      ys =Divisor_L(P.cycleLen[i], y);
      for(tU__gIr_=(0);tU__gIr_<(ys);tU__gIr_++){
        int x;
        auto &k = y[tU__gIr_];
        if(k >= res){
          break;
        }
        for(x=(0);x<(k);x++){
          int z;
          for(z=(x);z<(P.cycleLen[i]);z+=(k)){
            if(C[P.cycle[i][x]] != C[P.cycle[i][z]]){
              break;
            }
          }
          if(z >= P.cycleLen[i]){
            chmin(res, k);
            break;
          }
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, C[2d5];
// int ys, y[2d5];
// {
//   REP(rd_int()){
//     int res = int_inf;
//     rd(N);
//     IntMap P(N);
//     rd((P--)(N), C(N));
//     P.calcCycle();
//     rep(i,P.numCycle){
//       ys = Divisor(P.cycleLen[i], y);
//       rep[y](k,ys){
//         if(k >= res) break;
//         rep(x,k){
//           rep(z,x,P.cycleLen[i],k) if(C[P.cycle[i][x]] != C[P.cycle[i][z]]) break;
//           if(z >= P.cycleLen[i]) res <?= k, break;
//         }
//       }
//     }
//     wt(res);
//   }
// }