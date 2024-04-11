#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> void malloc2d(T ***arr, int x, int y){
  int i;
  (*arr) = (T**)malloc(x*sizeof(T*));
  (*arr)[0] = (T*)malloc(x*y*sizeof(T));
  for(i=(1);i<(x);i++){
    (*arr)[i]=(*arr)[i-1]+y;
  }
}
template<class T> void free2d(T **arr){
  free(arr[0]);
  free(arr);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Grid2d{
  T **d, **d_s;
  int c, **dw, **lf, r, **rg, set_d, set_s, **up;
  void malloc(const int rr, const int cc){
    r = rr;
    c = cc;
    set_s = 0;
    set_d = 0;
    malloc2d(&d, r, c);
  }
  void free(void){
    free2d(d);
    if(set_s){
      free2d(d_s);
    }
    if(set_d){
      free2d(up);
      free2d(dw);
      free2d(lf);
      free2d(rg);
    }
  }
  T*operator[](int a){
    return d[a];
  }
  void setSum(void){
    int i, j;
    if(set_s == 0){
      set_s = 1;
      malloc2d(&d_s, r+1, c+1);
    }
    for(i=0;i<(r+1);i++){
      d_s[i][0] = 0;
    }
    for(j=0;j<(c+1);j++){
      d_s[0][j] = 0;
    }
    for(i=0;i<(r);i++){
      for(j=0;j<(c);j++){
        d_s[i+1][j+1] = d_s[i][j+1] + d_s[i+1][j] - d_s[i][j] + d[i][j];
      }
    }
  }
  void setDir(void){
    int i, j;
    if(set_d == 0){
      set_d = 1;
      malloc2d(&up, r, c);
      malloc2d(&dw, r, c);
      malloc2d(&lf, r, c);
      malloc2d(&rg, r, c);
    }
    for(j=0;j<(c);j++){
      up[0][j] = 1;
    }
    for(i=(1);i<(r);i++){
      for(j=0;j<(c);j++){
        if(d[i][j]==d[i-1][j]){
          up[i][j] = 1 + up[i-1][j];
        }
        else{
          up[i][j] = 1 ;
        }
      }
    }
    for(j=0;j<(c);j++){
      dw[r-1][j] = 1;
    }
    for(i=r-2;i>=0;i--){
      for(j=0;j<(c);j++){
        if(d[i][j]==d[i+1][j]){
          dw[i][j] = 1 + dw[i+1][j];
        }
        else{
          dw[i][j] = 1 ;
        }
      }
    }
    for(i=0;i<(r);i++){
      lf[i][0] = 1;
      for(j=(1);j<(c);j++){
        if(d[i][j]==d[i][j-1]){
          lf[i][j] = 1 + lf[i][j-1];
        }
        else{
          lf[i][j] = 1 ;
        }
      }
    }
    for(i=0;i<(r);i++){
      rg[i][c-1] = 1;
      for(j=c-2;j>=0;j--){
        if(d[i][j]==d[i][j+1]){
          rg[i][j] = 1 + rg[i][j+1];
        }
        else{
          rg[i][j] = 1 ;
        }
      }
    }
  }
  void setDirMatch(const T v){
    int i, j;
    if(set_d == 0){
      set_d = 1;
      malloc2d(&up, r, c);
      malloc2d(&dw, r, c);
      malloc2d(&lf, r, c);
      malloc2d(&rg, r, c);
    }
    for(j=0;j<(c);j++){
      if(d[0][j]==v){
        up[0][j] =1;
      }
      else{
        up[0][j] =0;
      }
    }
    for(i=(1);i<(r);i++){
      for(j=0;j<(c);j++){
        if(d[i][j]==v){
          up[i][j] =1 + up[i-1][j];
        }
        else{
          up[i][j] =0;
        }
      }
    }
    for(j=0;j<(c);j++){
      if(d[r-1][j]==v){
        dw[r-1][j] =1;
      }
      else{
        dw[r-1][j] =0;
      }
    }
    for(i=r-2;i>=0;i--){
      for(j=0;j<(c);j++){
        if(d[i][j]==v){
          dw[i][j] =1 + dw[i+1][j];
        }
        else{
          dw[i][j] =0;
        }
      }
    }
    for(i=0;i<(r);i++){
      if(d[i][0]==v){
        lf[i][0] =1;
      }
      else{
        lf[i][0] =0;
      }
      for(j=(1);j<(c);j++){
        if(d[i][j]==v){
          lf[i][j] =1 + lf[i][j-1];
        }
        else{
          lf[i][j] =0;
        }
      }
    }
    for(i=0;i<(r);i++){
      if(d[i][c-1]==v){
        rg[i][c-1] =1;
      }
      else{
        rg[i][c-1] =0;
      }
      for(j=c-2;j>=0;j--){
        if(d[i][j]==v){
          rg[i][j] =1 + rg[i][j+1];
        }
        else{
          rg[i][j] =0;
        }
      }
    }
  }
  inline T getSum(const int r1, const int c1, const int r2, const int c2){
    return d_s[r2+1][c2+1] - d_s[r1][c2+1] - d_s[r2+1][c1] + d_s[r1][c1];
  }
}
;
int N;
int K;
char S[2000][2002];
int main(){
  Grid2d<int> g;
  int i, j, k, mn, mx, res=0;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  g.malloc(N+1,N+1);
  for(i=0;i<(N+1);i++){
    for(j=0;j<(N+1);j++){
      g[i][j] = 0;
    }
  }
  for(i=0;i<(N);i++){
    mn = 1073709056;
    mx = -1073709056;
    for(j=0;j<(N);j++){
      if(S[i][j]=='B'){
        chmin(mn, j);
        chmax(mx, j);
      }
    }
    if(mn > mx){
      g[0][0]++;
    }
    else if(mx - mn + 1 <= K){
      j = K - (mx-mn+1);
      k = K - 1;
      g[i+1][mn+1]++;
      g[max_L(0, i-k)][mn+1]--;
      g[i+1][max_L(0, mn-j)]--;
      g[max_L(0, i-k)][max_L(0, mn-j)]++;
    }
  }
  for(i=0;i<(N);i++){
    mn = 1073709056;
    mx = -1073709056;
    for(j=0;j<(N);j++){
      if(S[j][i]=='B'){
        chmin(mn, j);
        chmax(mx, j);
      }
    }
    if(mn > mx){
      g[0][0]++;
    }
    else if(mx - mn + 1 <= K){
      j = K - (mx-mn+1);
      k = K - 1;
      g[mn+1][i+1]++;
      g[mn+1][max_L(0, i-k)]--;
      g[max_L(0, mn-j)][i+1]--;
      g[max_L(0, mn-j)][max_L(0, i-k)]++;
    }
  }
  g.setSum();
  for(i=0;i<(N+1);i++){
    for(j=0;j<(N+1);j++){
      chmax(res, g.d_s[i][j]);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[2000][2002];
// {
//   int i, j, k;
//   int mn, mx;
//   int res = 0;
//   Grid2d<int> g;
// 
//   rd(N,K,S(N));
//   g.malloc(N+1,N+1);
//   rep(i,N+1) rep(j,N+1) g[i][j] = 0;
// 
//   rep(i,N){
//     mn = int_inf;
//     mx = -int_inf;
//     rep(j,N) if(S[i][j]=='B'){
//       mn <?= j;
//       mx >?= j;
//     }
//     if(mn > mx){
//       g[0][0]++;
//     } else if(mx - mn + 1 <= K) {
//       j = K - (mx-mn+1);
//       k = K - 1;
//       g[i+1][mn+1]++;
//       g[max(0,i-k)][mn+1]--;
//       g[i+1][max(0,mn-j)]--;
//       g[max(0,i-k)][max(0,mn-j)]++;
//     }
//   }
//   
//   rep(i,N){
//     mn = int_inf;
//     mx = -int_inf;
//     rep(j,N) if(S[j][i]=='B'){
//       mn <?= j;
//       mx >?= j;
//     }
//     if(mn > mx){
//       g[0][0]++;
//     } else if(mx - mn + 1 <= K) {
//       j = K - (mx-mn+1);
//       k = K - 1;
//       g[mn+1][i+1]++;
//       g[mn+1][max(0,i-k)]--;
//       g[max(0,mn-j)][i+1]--;
//       g[max(0,mn-j)][max(0,i-k)]++;
//     }
//   }
// 
//   g.setSum();
//   rep(i,N+1) rep(j,N+1) res >?= g.d_s[i][j];
//   wt(res);
// }