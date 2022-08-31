#pragma GCC optimize ("Ofast")
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int M;
int P[1000000];
int dist[100][100];
char c;
int res[1000000];
int ress;
int main(){
  int i, j, k;
  rd(N);
  for(i=0;i<(N);i++){
    for(j=0;j<(N);j++){
      dist[i][j] = 1073709056;
    }
  }
  for(i=0;i<(N);i++){
    dist[i][i] = 0;
  }
  for(i=0;i<(N);i++){
    for(j=0;j<(N);j++){
      rd(c);
      if(c=='1'){
        dist[i][j] = 1;
      }
    }
  }
  for(k=0;k<(N);k++){
    for(i=0;i<(N);i++){
      for(j=0;j<(N);j++){
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(M);Lj4PdHRW++){
      rd(P[Lj4PdHRW]);P[Lj4PdHRW] += (-1);
    }
  }
  res[ress++] = P[0];
  i = 0;
  while(i < M - 1){
    j = i;
    while(j+1 < M && dist[P[i]][P[j+1]] == (j+1) - i){
      j++;
    }
    res[ress++] = P[j];
    i = j;
  }
  wt_L(ress);
  wt_L('\n');
  {
    int KL2GvlyY;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(KL2GvlyY=0;KL2GvlyY<(ress-1);KL2GvlyY++){
        wt_L(res[KL2GvlyY]+1);
        wt_L(' ');
      }
      wt_L(res[KL2GvlyY]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, M, P[1d6];
// int dist[100][100];
// 
// char c;
// int res[1d6], ress;
// {
//   int i, j, k;
//   
//   rd(N);
//   rep(i,N) rep(j,N) dist[i][j] = int_inf;
//   rep(i,N) dist[i][i] = 0;
//   rep(i,N) rep(j,N){
//     rd(c);
//     if(c=='1') dist[i][j] = 1;
//   }
//   rep(k,N) rep(i,N) rep(j,N) dist[i][j] <?= dist[i][k] + dist[k][j];
// 
//   rd(M,(P--)(M));
// 
//   res[ress++] = P[0];
//   i = 0;
//   while(i < M - 1){
//     j = i;
//     while(j+1 < M && dist[P[i]][P[j+1]] == (j+1) - i) j++;
//     res[ress++] = P[j];
//     i = j;
//   }
// 
//   wt(ress);
//   wt(res(ress)+1);
// }