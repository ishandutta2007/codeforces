#include<bits/stdc++.h>
using namespace std;
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(long long x){
  char f[20];
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
char S[300002];
int arr[10];
int dame[9][1000];
int main(){
  int a, b, c, i, j, k, ok;
  long long res;
  for(N=0;N<9;N++){
    for(k=0;k<1<<N;k++){
      for(i=0;i<N;i++){
        if(k&1<<i){
          arr[i] = 1;
        }
        else{
          arr[i] = 0;
        }
      }
      ok = 1;
      for(i=0;i<N;i++){
        for(j=1;j<N;j++){
          a = i;
          b = a + j;
          c = b + j;
          if(c >= N){
            continue;
          }
          if(arr[a]==arr[b] && arr[b]==arr[c]){
            ok = 0;
          }
        }
      }
      if(ok==1){
        dame[N][k] = 1;
      }
    }
  }
  N = rd(S);
  for(i=0;i<N;i++){
    S[i] -= '0';
  }
  res = (long long)N * (N+1) / 2;
  for(i=0;i<N;i++){
    a = 0;
    for(j=0;j<8;j++){
      if(i+j >= N){
        break;
      }
      a = 2*a + S[i+j];
      res -= dame[j+1][a];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190526-1

// --- original code ---
// //no-unlocked
// 
// int N;
// char S[300002];
// 
// int arr[10];
// int dame[9][1000];
// 
// {
//   int i, j, k, ok;
//   int a, b, c;
//   ll res;
// 
//   rep(N,9){
//     rep(k,1<<N){
//       rep(i,N){
//         if(k&1<<i) arr[i] = 1; else arr[i] = 0;
//       }
//       
//       ok = 1;
//       rep(i,N) rep(j,1,N){
//         a = i;
//         b = a + j;
//         c = b + j;
//         if(c >= N) continue;
//         
//         if(arr[a]==arr[b] && arr[b]==arr[c]) ok = 0;
//       }
// 
//       if(ok==1) dame[N][k] = 1;
//     }
//   }
// 
//   rd(S@N);
//   rep(i,N) S[i] -= '0';
// 
//   res = (ll)N * (N+1) / 2;
//   rep(i,N){
//     a = 0;
//     rep(j,8){
//       if(i+j >= N) break;
//       a = 2a + S[i+j];
//       res -= dame[j+1][a];
//     }
//   }
// 
//   wt(res);
// }