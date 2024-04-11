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
int N;
int A[100000];
long long K;
long long B[100000];
int main(){
  int i;
  wmem = memarr;
  long long v;
  long long cnt;
  LHeap<long long> hp;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  long long e98WHCEY;
  long long cTE1_r3A;
  long long RZTsC2BF;
  e98WHCEY = -10000000000LL;
  cTE1_r3A = 4000000000000000000LL;
  while(e98WHCEY < cTE1_r3A){
    int i;
    if((e98WHCEY + cTE1_r3A)%2==0){
      RZTsC2BF = (e98WHCEY + cTE1_r3A) / 2;
    }
    else{
      RZTsC2BF = (e98WHCEY + cTE1_r3A + 1) / 2;
    }
    cnt = 0;
    for(i=(0);i<(N);i++){
      long long KrdatlYV;
      long long ao_dF3pO;
      long long tU__gIr_;
      KrdatlYV = 0;
      ao_dF3pO = A[i];
      while(KrdatlYV < ao_dF3pO){
        if((KrdatlYV + ao_dF3pO)%2==0){
          tU__gIr_ = (KrdatlYV + ao_dF3pO) / 2;
        }
        else{
          tU__gIr_ = (KrdatlYV + ao_dF3pO + 1) / 2;
        }
        if(3*tU__gIr_*tU__gIr_ - 3*tU__gIr_ + 1 - A[i] <= RZTsC2BF){
          KrdatlYV = tU__gIr_;
        }
        else{
          ao_dF3pO = tU__gIr_ - 1;
        }
      }
      cnt +=ao_dF3pO;
      if(cnt > K){
        break;
      }
    }
    if(cnt <= K){
      e98WHCEY = RZTsC2BF;
    }
    else{
      cTE1_r3A = RZTsC2BF - 1;
    }
  }
  v =cTE1_r3A;
  for(i=(0);i<(N);i++){
    long long YREPHmFM;
    long long jZyWAPpY;
    long long jbtyPBGc;
    YREPHmFM = 0;
    jZyWAPpY = A[i];
    while(YREPHmFM < jZyWAPpY){
      if((YREPHmFM + jZyWAPpY)%2==0){
        jbtyPBGc = (YREPHmFM + jZyWAPpY) / 2;
      }
      else{
        jbtyPBGc = (YREPHmFM + jZyWAPpY + 1) / 2;
      }
      if(3*jbtyPBGc*jbtyPBGc - 3*jbtyPBGc + 1 - A[i] <= v){
        YREPHmFM = jbtyPBGc;
      }
      else{
        jZyWAPpY = jbtyPBGc - 1;
      }
    }
    B[i] =jZyWAPpY;
  }
  for(i=(0);i<(N);i++){
    K -= B[i];
  }
  hp.walloc(N);
  hp.init(N);
  for(i=(0);i<(N);i++){
    if(B[i]+1 <= A[i]){
      hp.change(i, 3*(B[i]+1)*(B[i]+1) - 3*(B[i]+1) + 1 - A[i]);
    }
  }
  while(K){
    i = hp.pop();
    B[i]++;
    K--;
    if(B[i]+1 <= A[i]){
      hp.change(i, 3*(B[i]+1)*(B[i]+1) - 3*(B[i]+1) + 1 - A[i]);
    }
  }
  {
    int gEg5UqEA;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(gEg5UqEA=(0);gEg5UqEA<(N-1);gEg5UqEA++){
        wt_L(B[gEg5UqEA]);
        wt_L(' ');
      }
      wt_L(B[gEg5UqEA]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// ll K;
// 
// ll B[1d5];
// {
//   ll v, cnt;
//   LHeap<ll> hp;
// 
//   rd(N,K,A(N));
// 
//   v = bsearch_max[ll,v,-1d10,4d18][
//     cnt = 0;
//     rep(i,N){
//       cnt += bsearch_max[ll,x,0,A[i]](3*x*x - 3*x + 1 - A[i] <= v);
//       if(cnt > K) break;
//     }
//   ](cnt <= K);
// 
//   rep(i,N) B[i] = bsearch_max[ll,x,0,A[i]](3*x*x - 3*x + 1 - A[i] <= v);
// 
//   rep(i,N) K -= B[i];
//   hp.walloc(N);
//   hp.init(N);
//   rep(i,N) if(B[i]+1 <= A[i]) hp.change(i, 3*(B[i]+1)*(B[i]+1) - 3*(B[i]+1) + 1 - A[i]);
// 
//   while(K){
//     i = hp.pop();
//     B[i]++; K--;
//     if(B[i]+1 <= A[i]) hp.change(i, 3*(B[i]+1)*(B[i]+1) - 3*(B[i]+1) + 1 - A[i]);
//   }
// 
//   wt(B(N));
// }