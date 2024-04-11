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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int TEST;
int N;
char S[200002];
char T[200002];
int nx[10][400001];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  int r;
  rd(TEST);
  for(Lj4PdHRW=0;Lj4PdHRW<(TEST);Lj4PdHRW++){
    rd(N);
    rd(S);
    for(i=0;i<(N);i++){
      S[i] -= '0';
    }
    for(k=0;k<(10);k++){
      nx[k][2*N] = 1073709056;
      for(i=2*N-1;i>=0;i--){
        nx[k][i] = nx[k][i+1];
        if(S[i%N]==k){
          nx[k][i] = i;
        }
      }
    }
    for(i=0;i<(N);i++){
      T[i] = 0;
    }
    i = k = 0;
    r = 1;
    for(;;){
      if(k==10 || r > 2){
        break;
      }
      if(nx[k][i]==1073709056){
        k++;
        continue;
      }
      j = nx[k][i] % N;
      if(T[j]){
        k++;
        continue;
      }
      if(nx[k][i] >= N){
        r++;
      }
      if(r > 2){
        break;
      }
      T[j] = r;
      i = j + 1;
      if(i >= N){
        i-=N;
        r++;
      }
    }
    for(i=0;i<(N);i++){
      if(T[i]==0){
        break;
      }
    }
    if(i<N){
      wt_L("-");
      wt_L('\n');
      continue;
    }
    for(i=0;i<(N);i++){
      T[i] += '0';
    }
    T[N] = '\0';
    wt_L(T);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int TEST, N;
// char S[200002];
// char T[200002];
// 
// int nx[10][400001];
// 
// {
//   int i, j, k, r;
//   
//   rd(TEST);
//   rep(TEST){
//     rd(N,S);
//     rep(i,N) S[i] -= '0';
// 
//     rep(k,10){
//       nx[k][2N] = int_inf;
//       for(i=2N-1;i>=0;i--){
//         nx[k][i] = nx[k][i+1];
//         if(S[i%N]==k) nx[k][i] = i;
//       }
//     }
// 
//     rep(i,N) T[i] = 0;
//     i = k = 0;
//     r = 1;
//     for(;;){
//       if(k==10 || r > 2) break;
//       if(nx[k][i]==int_inf) k++, continue;
//       j = nx[k][i] % N;
//       if(T[j]) k++, continue;
//       if(nx[k][i] >= N) r++;
//       if(r > 2) break;
//       T[j] = r;
//       i = j + 1;
//       if(i >= N) i-=N, r++;
//     }
//     
//     rep(i,N) if(T[i]==0) break;
//     if(i<N) wt("-"), continue;
// 
//     rep(i,N) T[i] += '0';
//     T[N] = '\0';
//     wt(T);
//   }
// }