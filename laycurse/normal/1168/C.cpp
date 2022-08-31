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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int Q;
int A[300000];
int nx[171][300000];
int cnv[19][19];
int main(){
  int KL2GvlyY, i, j, k, mask, ok, s, x, y, z;
  rd(N);
  rd(Q);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  k = 0;
  for(i=0;i<19;i++){
    for(j=i+1;j<19;j++){
      cnv[i][j] = cnv[j][i] = k++;
    }
  }
  for(i=0;i<19;i++){
    for(j=i+1;j<19;j++){
      mask = ((1<<i) | (1<<j));
      k = cnv[i][j];
      nx[k][N-1] = N;
      for(x=N-2;x>=0;x--){
        nx[k][x] = nx[k][x+1];
        if( (mask & A[x+1])==mask ){
          nx[k][x] = x+1;
        }
      }
    }
  }
  for(KL2GvlyY=0;KL2GvlyY<Q;KL2GvlyY++){
    rd(x);
    rd(y);
    x--;
    y--;
    z = A[x];
    ok = 0;
    while(x <= y){
      if(z & A[y]){
        ok = 1;
        break;
      }
      s = N;
      for(i=0;i<19;i++){
        if(z & 1<<i){
          for(j=0;j<19;j++){
            if(!(z & 1<<j)){
              chmin(s, nx[cnv[i][j]][x]);
            }
          }
        }
      }
      x = s;
      z |= A[x];
    }
    if(ok){
      wt_L("Shi");
      wt_L('\n');
    }
    else{
      wt_L("Fou");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190526-1

// --- original code ---
// //no-unlocked
// 
// int N, Q, A[3d5];
// 
// int nx[171][3d5];
// int cnv[19][19];
// 
// {
//   int i, j, k, mask;
//   int x, y, z, s, ok;
// 
//   rd(N,Q,A(N));
// 
//   k = 0;
//   rep(i,19) REP(j,i+1,19) cnv[i][j] = cnv[j][i] = k++;
// 
//   rep(i,19) rep(j,i+1,19){
//     mask = ((1<<i) | (1<<j));
//     k = cnv[i][j];
//     nx[k][N-1] = N;
//     for(x=N-2;x>=0;x--){
//       nx[k][x] = nx[k][x+1];
//       if( (mask & A[x+1])==mask ) nx[k][x] = x+1;
//     }
//   }
// 
//   rep(Q){
//     rd(x,y);
//     x--; y--;
//     z = A[x];
// 
//     ok = 0;
//     while(x <= y){
//       if(z & A[y]){ok = 1; break;}
//       s = N;
//       rep(i,19) if(z & 1<<i) rep(j,19) if(!(z & 1<<j)){
//         s <?= nx[cnv[i][j]][x];
//       }
//       x = s;
//       z |= A[x];
//     }
// 
//     if(ok) wt("Shi"); else wt("Fou");
//   }
// }
//