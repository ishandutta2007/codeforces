#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[31457280];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> void malloc2d(T ***arr, int x, int y){
  int i;
  (*arr) = (T**)malloc(x*sizeof(T*));
  (*arr)[0] = (T*)malloc(x*y*sizeof(T));
  int XJIcIBrW = x;
  for(i=(1);i<(XJIcIBrW);i++){
    (*arr)[i]=(*arr)[i-1]+y;
  }
}
template<class T> void free2d(T **arr){
  free(arr[0]);
  free(arr);
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
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
    i = my_getchar();
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
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
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
int N;
int M;
char S[4000][4001];
char tmp[2000][2002];
Grid2d<int> g;
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int x;
  int y;
  int z;
  int len;
  long long res = 0;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(tmp[Lj4PdHRW]);
    }
  }
  k = N + M - 1;
  for(i=(0);i<(k);i++){
    for(j=(0);j<(k);j++){
      S[i][j] = '@';
    }
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      S[i+j][i-j+M-1] = tmp[i][j];
    }
  }
  N = k;
  g.malloc(N,N);
  for(k=(0);k<(26);k++){
    for(i=(0);i<(N);i++){
      for(j=(0);j<(N);j++){
        if(S[i][j]=='a'+k){
          g[i][j] =1;
        }
        else{
          g[i][j] =0;
        }
      }
    }
    g.setSum();
    for(i=(0);i<(N);i++){
      y = 0;
      for(x=((i+M-1)%2);x<(N);x+=(2)){
        if(g[i][x]==1){
          chmax(y, x);
          while(y+2 < N && g[i][y+2] == 1){
            len = y - x + 3;
            if(i + len - 1 >= N){
              break;
            }
            if(g.getSum(i, x, i + len - 1, y + 2) < len * len / 2 + 1){
              break;
            }
            y += 2;
          }
          res += (y-x)/2 + 1;
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// //working_memory=30m
// int N, M;
// char S[4000][4001], tmp[2000][2002];
// Grid2d<int> g;
// {
//   int i, j, k, x, y, z, len;
//   ll res = 0;
//   rd(N,M,tmp(N));
// 
//   k = N + M - 1;
//   rep(i,k) rep(j,k) S[i][j] = '@';
//   rep(i,N) rep(j,M) S[i+j][i-j+M-1] = tmp[i][j];
//   N = k;
// 
//   g.malloc(N,N);
//   rep(k,26){
//     rep(i,N) rep(j,N) g[i][j] = if[S[i][j]=='a'+k, 1, 0];
//     g.setSum();
// 
//     rep(i,N){
//       y = 0;
//       rep(x,(i+M-1)%2,N,2) if(g[i][x]==1){
//         y >?= x;
//         while(y+2 < N && g[i][y+2] == 1){
//           len = y - x + 3;
//           if(i + len - 1 >= N) break;
//           if(g.getSum(i, x, i + len - 1, y + 2) < len * len / 2 + 1) break;
//           y += 2;
//         }
//         res += (y-x)/2 + 1;
//       }
//     }
//   }
// 
//   wt(res);
// }