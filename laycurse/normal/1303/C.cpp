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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int N;
char S[202];
int edge[26][26];
int deg[26];
char res[30];
int ress;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    N = rd(S);
    for(i=(0);i<(26);i++){
      for(j=(0);j<(26);j++){
        edge[i][j] = 0;
      }
    }
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    for(i=(1);i<(N);i++){
      edge[S[i-1]][S[i]] = edge[S[i]][S[i-1]] = 1;
    }
    for(i=(0);i<(26);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(26);i++){
      for(j=(0);j<(26);j++){
        deg[i] += edge[i][j];
      }
    }
    for(i=(0);i<(26);i++){
      if(deg[i] >= 3){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    ress = 0;
    for(i=(0);i<(26);i++){
      if(0 <= deg[i]  &&  deg[i] <= 1){
        k = i;
        for(;;){
          res[ress++] = 'a' + k;
          if(deg[k]==0){
            deg[k] = -1;
            break;
          }
          for(j=(0);j<(26);j++){
            if(edge[k][j]){
              break;
            }
          }
          deg[k] = -1;
          deg[j]--;
          edge[k][j] = edge[j][k] = 0;
          k = j;
        }
      }
    }
    if(ress<26){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N;
// char S[202];
// int edge[26][26], deg[26];
// char res[30]; int ress;
// {
//   REP(rd_int()){
//     int i, j, k;
// 
//     rd(S@N);
//     rep(i,26) rep(j,26) edge[i][j] = 0;
//     rep(i,N) S[i] -= 'a';
//     rep(i,1,N) edge[S[i-1]][S[i]] = edge[S[i]][S[i-1]] = 1;
//     rep(i,26) deg[i] = 0;
//     rep(i,26) rep(j,26) deg[i] += edge[i][j];
// 
//     rep(i,26) if(deg[i] >= 3) wt("NO"), break_continue;
// 
//     ress = 0;
//     rep(i,26) if(0 <= deg[i] <= 1){
//       k = i;
//       for(;;){
//         res[ress++] = 'a' + k;
//         if(deg[k]==0) deg[k] = -1, break;
//         rep(j,26) if(edge[k][j]) break;
//         deg[k] = -1;
//         deg[j]--;
//         edge[k][j] = edge[j][k] = 0;
//         k = j;
//       }
//     }
// 
//     if(ress<26) wt("NO"), continue;
//     wt("YES");
//     wt(res);
// 
//   }
// }