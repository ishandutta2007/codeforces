#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
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
inline void rd(long long &x){
  int k, m=0;
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
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
template<class T> struct fenwick{
  T *data;
  int memory, size;
  void malloc(int mem){
    memory = mem;
    data = (T*)std::malloc(sizeof(T)*mem);
  }
  void walloc(int mem, void **workMemory=&wmem){
    memory = mem;
    walloc1d(&data, mem, workMemory);
  }
  void free(void){
    memory = 0;
    free(data);
  }
  void init(int N){
    size = N;
    memset(data,0,sizeof(T)*N);
  }
  void add(int k, T val){
    while(k < size){
      data[k] += val;
      k |= k+1;
    }
  }
  T get(int k){
    T res=0;
    while(k>=0){
      res += data[k];
      k = (k&(k+1))-1;
    }
    return res;
  }
  T range(int a, int b){
    if(b==-1){
      b=size-1;
    }
    return get(b) - get(a-1);
  }
  int kth(T k){
    T v;
    int c, i=0, j=size;
    while(i<j){
      c = (i+j)/2;
      v = get(c);
      if(v <= k){
        i=c+1;
      }
      else{
        j=c;
      }
    }
    return i==size?-1:i;
  }
}
;
char memarr[96000000];
int N;
long long S[200000];
int res[200000];
int main(){
  fenwick<long long> f;
  int i, j, k;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  f.walloc(N+1);
  f.init(N+1);
  for(i=(1);i<(N+1);i++){
    f.add(i, i);
  }
  for(i=N-1;i>=0;i--){
    int KL2GvlyY, Q5VJL1cS, e98WHCEY;
    KL2GvlyY = 1;
    Q5VJL1cS = N;
    while(KL2GvlyY < Q5VJL1cS){
      if((KL2GvlyY + Q5VJL1cS)%2==0){
        e98WHCEY = (KL2GvlyY + Q5VJL1cS) / 2;
      }
      else{
        e98WHCEY = (KL2GvlyY + Q5VJL1cS + 1) / 2;
      }
      if( f.get(e98WHCEY-1) <= S[i] ){
        KL2GvlyY = e98WHCEY;
      }
      else{
        Q5VJL1cS = e98WHCEY - 1;
      }
    }
    k =Q5VJL1cS;
    res[i] = k;
    f.add(k, -k);
  }
  {
    int cTE1_r3A;
    if(N==0){
      putchar('\n');
    }
    else{
      for(cTE1_r3A=0;cTE1_r3A<(N-1);cTE1_r3A++){
        wt_L(res[cTE1_r3A]);
        wt_L(' ');
      }
      wt_L(res[cTE1_r3A]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N; ll S[2d5];
// int res[2d5];
// {
//   int i, j, k;
//   fenwick<ll> f;
//   rd(N,S(N));
// 
//   f.walloc(N+1);
//   f.init(N+1);
//   rep(i,1,N+1) f.add(i, i);
//   for(i=N-1;i>=0;i--){
//     k = bsearch_max[int,x,1,N]( f.get(x-1) <= S[i] );
//     res[i] = k;
//     f.add(k, -k);
//   }
//   wt(res(N));
// }