#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
}
template<class T> void malloc2d(T ***arr, int x, int y){
  int i;
  (*arr) = (T**)malloc(x*sizeof(T*));
  (*arr)[0] = (T*)malloc(x*y*sizeof(T));
  int o3WxPXbE = x;
  for(i=(1);i<(o3WxPXbE);i++){
    (*arr)[i]=(*arr)[i-1]+y;
  }
}
template<class T> void free2d(T **arr){
  free(arr[0]);
  free(arr);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template <class T> struct DijkstraHeap{
  int *hp;
  int *place;
  int size;
  char *visited;
  T *val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place = (int*)std::malloc(N*sizeof(int));
    visited = (char*)std::malloc(N*sizeof(char));
    val = (T*)std::malloc(N*sizeof(T));
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(visited);
    std::free(val);
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&visited, N, mem);
    walloc1d(&val, N, mem);
  }
  void init(int N){
    int i;
    size = 0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
    for(i=(0);i<(N);i++){
      visited[i]=0;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    if(visited[n]||(place[n]>=0&&val[n]<=v)){
      return;
    }
    val[n]=v;
    if(place[n]==-1){
      place[n]=size;
      hp[size++]=n;
      up(place[n]);
    }
    else{
      up(place[n]);
    }
  }
  int pop(void){
    int res=hp[0];
    place[res]=-1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    visited[res]=1;
    return res;
  }
}
;
template<class T> struct Grid2d{
  int r;
  int c;
  T **d;
  int set_s;
  int set_d;
  T **d_s;
  int **up;
  int **dw;
  int **lf;
  int **rg;
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
    int i;
    int j;
    if(set_s == 0){
      set_s = 1;
      malloc2d(&d_s, r+1, c+1);
    }
    for(i=(0);i<(r+1);i++){
      d_s[i][0] = 0;
    }
    for(j=(0);j<(c+1);j++){
      d_s[0][j] = 0;
    }
    for(i=(0);i<(r);i++){
      for(j=(0);j<(c);j++){
        d_s[i+1][j+1] = d_s[i][j+1] + d_s[i+1][j] - d_s[i][j] + d[i][j];
      }
    }
  }
  void setDir(void){
    int i;
    int j;
    if(set_d == 0){
      set_d = 1;
      malloc2d(&up, r, c);
      malloc2d(&dw, r, c);
      malloc2d(&lf, r, c);
      malloc2d(&rg, r, c);
    }
    for(j=(0);j<(c);j++){
      up[0][j] = 1;
    }
    for(i=(1);i<(r);i++){
      for(j=(0);j<(c);j++){
        if(d[i][j]==d[i-1][j]){
          up[i][j] = 1 + up[i-1][j];
        }
        else{
          up[i][j] = 1 ;
        }
      }
    }
    for(j=(0);j<(c);j++){
      dw[r-1][j] = 1;
    }
    for(i=r-2;i>=0;i--){
      for(j=(0);j<(c);j++){
        if(d[i][j]==d[i+1][j]){
          dw[i][j] = 1 + dw[i+1][j];
        }
        else{
          dw[i][j] = 1 ;
        }
      }
    }
    for(i=(0);i<(r);i++){
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
    for(i=(0);i<(r);i++){
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
    int i;
    int j;
    if(set_d == 0){
      set_d = 1;
      malloc2d(&up, r, c);
      malloc2d(&dw, r, c);
      malloc2d(&lf, r, c);
      malloc2d(&rg, r, c);
    }
    for(j=(0);j<(c);j++){
      if(d[0][j]==v){
        up[0][j] =1;
      }
      else{
        up[0][j] =0;
      }
    }
    for(i=(1);i<(r);i++){
      for(j=(0);j<(c);j++){
        if(d[i][j]==v){
          up[i][j] =1 + up[i-1][j];
        }
        else{
          up[i][j] =0;
        }
      }
    }
    for(j=(0);j<(c);j++){
      if(d[r-1][j]==v){
        dw[r-1][j] =1;
      }
      else{
        dw[r-1][j] =0;
      }
    }
    for(i=r-2;i>=0;i--){
      for(j=(0);j<(c);j++){
        if(d[i][j]==v){
          dw[i][j] =1 + dw[i+1][j];
        }
        else{
          dw[i][j] =0;
        }
      }
    }
    for(i=(0);i<(r);i++){
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
    for(i=(0);i<(r);i++){
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
  template<class S> inline void getDist4(int sr, int sc, S **res, void *mem = wmem){
    int i;
    int j;
    int k;
    DijkstraHeap<S> hp;
    hp.walloc(r*c);
    hp.init(r*c);
    if(d[sr][sc] >= 0){
      hp.change(sr*c+sc, d[sr][sc]);
    }
    while(hp.size){
      k = hp.pop();
      i = k / c;
      j = k % c;
      if(i-1 >= 0 && d[i-1][j] >= 0){
        hp.change((i-1)*c+j, hp.val[k]+d[i-1][j]);
      }
      if(i+1 <  r && d[i+1][j] >= 0){
        hp.change((i+1)*c+j, hp.val[k]+d[i+1][j]);
      }
      if(j-1 >= 0 && d[i][j-1] >= 0){
        hp.change(i*c+(j-1), hp.val[k]+d[i][j-1]);
      }
      if(j+1 <  c && d[i][j+1] >= 0){
        hp.change(i*c+(j+1), hp.val[k]+d[i][j+1]);
      }
    }
    for(i=(0);i<(r);i++){
      for(j=(0);j<(c);j++){
        if(hp.visited[i*c+j]){
          res[i][j] =hp.val[i*c+j];
        }
        else{
          res[i][j] =-1;
        }
      }
    }
  }
  template<class S> inline void getDist4_BFS(int sr, int sc, S **res, void *mem = wmem){
    int i;
    int j;
    int k;
    int *q;
    int qs=0;
    int qe=0;
    walloc1d(&q,r*c,&mem);
    for(i=(0);i<(r);i++){
      for(j=(0);j<(c);j++){
        res[i][j] = -1;
      }
    }
    if(d[sr][sc] >= 0){
      res[sr][sc] = 1;
    }
    q[qe++] = sr*c+sc;
    while(qs < qe){
      k = q[qs++];
      i = k / c;
      j = k % c;
      if(i-1 >= 0 && d[i-1][j] >= 0 && res[i-1][j]==-1){
        res[i-1][j] = res[i][j] + 1;
        q[qe++] = (i-1)*c + j;
      }
      if(i+1 <  r && d[i+1][j] >= 0 && res[i+1][j]==-1){
        res[i+1][j] = res[i][j] + 1;
        q[qe++] = (i+1)*c + j;
      }
      if(j-1 >= 0 && d[i][j-1] >= 0 && res[i][j-1]==-1){
        res[i][j-1] = res[i][j] + 1;
        q[qe++] = i*c + (j-1);
      }
      if(j+1 <  c && d[i][j+1] >= 0 && res[i][j+1]==-1){
        res[i][j+1] = res[i][j] + 1;
        q[qe++] = i*c + (j+1);
      }
    }
  }
}
;
int X;
int Y;
char C;
Grid2d<int> S;
Grid2d<int> T;
char **mp;
int main(){
  int i;
  wmem = memarr;
  int x;
  int mx;
  int k;
  int ok;
  rd(X);
  rd(Y);
  S.malloc(X,Y);
  T.malloc(X,Y);
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      rd(C);
      if(C=='X'){
        S[i][j] =1;
      }
      else{
        S[i][j] =0;
      }
    }
  }
  S.setSum();
  walloc2d(&mp, X, Y+2);
  for(i=(0);i<(X);i++){
    mp[i][Y] = '\0';
  }
  mx = (min_L(X, Y)-1)/2;
  int xr20shxY;
  int WYIGIcGE;
  int t_ynMSdg;
  xr20shxY = 0;
  WYIGIcGE = mx;
  while(xr20shxY < WYIGIcGE){
    if((xr20shxY + WYIGIcGE)%2==0){
      t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
    }
    else{
      t_ynMSdg = (xr20shxY + WYIGIcGE + 1) / 2;
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        k = S.getSum(max_L(0, i-t_ynMSdg),max_L(0, j-t_ynMSdg),min_L(X-1, i+t_ynMSdg),min_L(Y-1, j+t_ynMSdg));
        if(k==(pow2_L((2*t_ynMSdg+1)))){
          T[i][j] =1;
        }
        else{
          T[i][j] =0;
        }
      }
    }
    ok = 1;
    T.setSum();
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        k = T.getSum(max_L(0, i-t_ynMSdg),max_L(0, j-t_ynMSdg),min_L(X-1, i+t_ynMSdg),min_L(Y-1, j+t_ynMSdg));
        chmin(k, 1);
        if(S[i][j] != k){
          ok = 0;
          goto iMWUTgY_;
        }
      }
    }
    iMWUTgY_:;
    if(ok){
      xr20shxY = t_ynMSdg;
    }
    else{
      WYIGIcGE = t_ynMSdg - 1;
    }
  }
  x =WYIGIcGE;
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      k = S.getSum(max_L(0, i-x),max_L(0, j-x),min_L(X-1, i+x),min_L(Y-1, j+x));
      if(k==(pow2_L((2*x+1)))){
        mp[i][j] ='X';
      }
      else{
        mp[i][j] ='.';
      }
    }
  }
  wt_L(x);
  wt_L('\n');
  for(i=(0);i<(X);i++){
    wt_L(mp[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200227-1

// --- original code ---
// //no-unlocked
// int X, Y;
// char C;
// Grid2d<int> S, T;
// char **mp;
// {
//   int x, mx, k, ok;
// 
//   rd(X,Y);
//   S.malloc(X,Y);
//   T.malloc(X,Y);
//   rep(i,X) rep(j,Y){
//     rd(C);
//     S[i][j] = if[C=='X', 1, 0];
//   }
//   S.setSum();
// 
//   walloc2d(&mp, X, Y+2);
//   rep(i,X) mp[i][Y] = '\0';
// 
//   mx = (min(X,Y)-1)/2;
//   x = bsearch_max[int,x,0,mx][
//     rep(i,X) rep(j,Y){
//       k = S.getSum(max(0,i-x),max(0,j-x),min(X-1,i+x),min(Y-1,j+x));
//       T[i][j] = if[k==((2*x+1)**2), 1, 0];
//     }
//     ok = 1;
//     T.setSum();
//     rep(i,X) rep(j,Y){
//       k = T.getSum(max(0,i-x),max(0,j-x),min(X-1,i+x),min(Y-1,j+x));
//       k <?= 1;
//       if(S[i][j] != k) ok = 0, break_break;
//     }
//   ](ok);
// 
//   rep(i,X) rep(j,Y){
//     k = S.getSum(max(0,i-x),max(0,j-x),min(X-1,i+x),min(Y-1,j+x));
//     mp[i][j] = if[k==((2*x+1)**2), 'X', '.'];
//   }
// 
//   wt(x);
//   rep(i,X) wt(mp[i]);
// }