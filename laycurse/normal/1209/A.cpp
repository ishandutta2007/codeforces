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
int main(){
  int i;
  wmem = memarr;
  int N;
  int A[100];
  int ok[100];
  int res = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N, A);
  for(i=0;i<(N);i++){
    ok[i] = 0;
  }
  for(i=0;i<(N);i++){
    if(!ok[i]){
      int j;
      res++;
      for(j=0;j<(N);j++){
        if(A[j]%A[i]==0){
          ok[j] = 1;
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// {
//   int N, A[100], ok[100], res = 0;
//   rd(N,A(N));
//   sortA(N, A);
//   rep(i,N) ok[i] = 0;
//   rep(i,N) if(!ok[i]){
//     res++;
//     rep(j,N) if(A[j]%A[i]==0) ok[j] = 1;
//   }
//   wt(res);
// }