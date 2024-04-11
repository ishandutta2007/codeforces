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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
int A[3];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int mask;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(3);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    res = 0;
    for(i=(0);i<(3);i++){
      if(A[i]){
        A[i]--;
        res++;
      }
    }
    rsortA_L(3,A);
    for(i=(0);i<(3);i++){
      int j;
      for(j=(i+1);j<(3);j++){
        if(A[i] && A[j]){
          A[i]--;
          A[j]--;
          res++;
        }
      }
    }
    if(A[0] && A[1] && A[2]){
      res++;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int A[3];
// {
//   int mask, res;
//   REP(rd_int()){
//     rd(A(3));
//     res = 0;
//     rep(i,3) if(A[i]) A[i]--, res++;
//     rsortA(3,A);
//     rep(i,3) rep(j,i+1,3) if(A[i] && A[j]) A[i]--, A[j]--, res++;
//     if(A[0] && A[1] && A[2]) res++;
//     wt(res);
//   }
// }