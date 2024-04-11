#include<bits/stdc++.h>
using namespace std;
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
int N;
int M;
int A[300000];
int main(){
  int i, j, k, ok, s, x, y, z;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  x = 0;
  y = M;
  while(x < y){
    z = (x+y) / 2;
    k = 0;
    for(i=0;i<N;i++){
      s = M + 1;
      if(A[i] >= k){
        s = A[i];
      }
      else if(A[i]+z >= k){
        s = k;
      }
      if(A[i]+z >= M+k){
        s = k;
      }
      if(s==M+1){
        break;
      }
      k = s;
    }
    if(i==N){
      y = z;
    }
    else{
      x = z + 1;
    }
  }
  wt_L(x);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190526-1

// --- original code ---
// //no-unlocked
// 
// int N, M;
// int A[3d5];
// 
// {
//   int i, j, k, s, ok;
//   int x, y, z;
// 
//   rd(N,M,A(N));
// 
//   x = 0;
//   y = M;
//   while(x < y){
//     z = (x+y) / 2;
//     k = 0;
//     rep(i,N){
//       s = M + 1;
// 
//       if(A[i] >= k){
//         s = A[i];
//       } else if(A[i]+z >= k){
//         s = k;
//       }
// 
//       if(A[i]+z >= M+k){
//         s = k;
//       }
// 
//       if(s==M+1) break;
//       k = s;
//     }
// 
//     if(i==N) y = z; else x = z + 1;
//   }
// 
//   wt(x);
// }