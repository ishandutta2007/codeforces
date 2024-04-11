#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
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
int T;
int N;
char S[200002];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  int b;
  int res;
  rd(T);
  for(Lj4PdHRW=0;Lj4PdHRW<(T);Lj4PdHRW++){
    N = rd(S);
    for(i=0;i<(N);i++){
      S[i] -= '0';
    }
    b = 0;
    res = 0;
    for(i=0;i<(N);i++){
      if(S[i]==0){
        b++;
      }
      if(S[i]==1){
        j = i;
        k = 1;
        res++;
        for(;;){
          j++;
          if(j >= N){
            break;
          }
          k = 2*k + S[j];
          if(k > N){
            break;
          }
          if(b >= k - (j-i+1)){
            res++;
          }
        }
        b = 0;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int T, N;
// char S[200002];
// {
//   int i, j, k, b, res;
//   
//   rd(T);
//   rep(T){
//     rd(S@N);
//     rep(i,N) S[i] -= '0';
//     
//     b = 0;
//     res = 0;
//     rep(i,N){
//       if(S[i]==0) b++;
//       if(S[i]==1){
//         j = i;
//         k = 1;
//         res++;
//         for(;;){
//           j++;
//           if(j >= N) break;
//           k = 2k + S[j];
//           if(k > N) break;
//           if(b >= k - (j-i+1)) res++;
//         }
//         b = 0;
//       }
//     }
//     wt(res);
//   }
// }