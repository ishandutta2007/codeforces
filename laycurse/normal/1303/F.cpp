#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[10485760];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
int N;
int M;
int Q;
int X;
int Y;
int C;
int res[2000000+2];
int mp[300][300];
vector<int> tmm[2000000+1];
vector<int> type[2000000+1];
vector<int> place[2000000+1];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int c;
  int t;
  int x;
  int y;
  int nx;
  int ny;
  int d;
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,-1,1};
  unionFind uf;
  rd(N);
  rd(M);
  rd(Q);
  for(i=(0);i<(N*M);i++){
    tmm[0].push_back(0);
    type[0].push_back(1);
    place[0].push_back(i);
  }
  for(i=(0);i<(Q);i++){
    rd(X);X += (-1);
    rd(Y);Y += (-1);
    rd(C);
    if(mp[X][Y]==C){
      continue;
    }
    k = mp[X][Y];
    tmm[k].push_back(i+1);
    type[k].push_back(-1);
    place[k].push_back(X*M+Y);
    k = mp[X][Y] = C;
    tmm[k].push_back(i+1);
    type[k].push_back(1);
    place[k].push_back(X*M+Y);
  }
  for(i=(0);i<(N*M);i++){
    k = mp[i/M][i%M];
    tmm[k].push_back(Q+1);
    type[k].push_back(-1);
    place[k].push_back(i);
  }
  uf.walloc(N*M);
  for(k=(0);k<(2000000+1);k++){
    if(tmm[k].size()){
      for(i=(0);i<(N);i++){
        for(j=(0);j<(M);j++){
          mp[i][j] = 0;
        }
      }
      uf.init(N*M);
      t = c = 0;
      for(i=(0);i<(tmm[k].size());i++){
        if(tmm[k][i] != t){
          res[t] += c;
          t = tmm[k][i];
          res[t] -= c;
        }
        if(type[k][i]==-1){
          break;
        }
        x = place[k][i] / M;
        y = place[k][i] % M;
        mp[x][y] = 1;
        c++;
        for(d=(0);d<(4);d++){
          nx = x + dx[d];
          ny = y + dy[d];
          if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
          }
          if(mp[nx][ny]==1){
            c -= uf(x*M+y, nx*M+ny);
          }
        }
      }
      for(i=(0);i<(N);i++){
        for(j=(0);j<(M);j++){
          mp[i][j] = 0;
        }
      }
      uf.init(N*M);
      t = Q+1;
      c = 0;
      for(i=(tmm[k].size())-1;i>=(0);i--){
        if(type[k][i]==1){
          break;
        }
        if(tmm[k][i] != t){
          res[t] -= c;
          t = tmm[k][i];
          res[t] += c;
        }
        x = place[k][i] / M;
        y = place[k][i] % M;
        mp[x][y] = 1;
        c++;
        for(d=(0);d<(4);d++){
          nx = x + dx[d];
          ny = y + dy[d];
          if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
          }
          if(mp[nx][ny]==1){
            c -= uf(x*M+y, nx*M+ny);
          }
        }
      }
    }
  }
  for(i=(1);i<(Q+1);i++){
    res[i] += res[i-1];
    wt_L(res[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// //working_memory=10m
// int N, M, Q;
// int X, Y, C;
// 
// int res[2d6+2];
// int mp[300][300];
// 
// vector<int> tmm[2d6+1], type[2d6+1], place[2d6+1];
// 
// {
//   int i, j, k, c, t, x, y, nx, ny, d;
//   int dx[4] = {-1,1,0,0};
//   int dy[4] = {0,0,-1,1};
//   unionFind uf;
//   rd(N,M,Q);
// 
//   rep(i,N*M){
//     tmm[0].push_back(0);
//     type[0].push_back(1);
//     place[0].push_back(i);
//   }
//   rep(i,Q){
//     rd(X--,Y--,C);
//     if(mp[X][Y]==C) continue;
// 
//     k = mp[X][Y];
//     tmm[k].push_back(i+1);
//     type[k].push_back(-1);
//     place[k].push_back(X*M+Y);
// 
//     k = mp[X][Y] = C;
//     tmm[k].push_back(i+1);
//     type[k].push_back(1);
//     place[k].push_back(X*M+Y);
//   }
//   rep(i,N*M){
//     k = mp[i/M][i%M];
//     tmm[k].push_back(Q+1);
//     type[k].push_back(-1);
//     place[k].push_back(i);
//   }
// 
//   uf.walloc(N*M);
//   rep(k,2d6+1) if(tmm[k].size()){
//     rep(i,N) rep(j,M) mp[i][j] = 0;
//     uf.init(N*M);
//     t = c = 0;
//     rep(i,tmm[k].size()){
//       if(tmm[k][i] != t){
//         res[t] += c;
//         t = tmm[k][i];
//         res[t] -= c;
//       }
//       if(type[k][i]==-1) break;
// 
//       x = place[k][i] / M;
//       y = place[k][i] % M;
//       mp[x][y] = 1;
//       c++;
//       rep(d,4){
//         nx = x + dx[d];
//         ny = y + dy[d];
//         if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
//         if(mp[nx][ny]==1) c -= uf(x*M+y, nx*M+ny);
//       }
//     }
// 
//     rep(i,N) rep(j,M) mp[i][j] = 0;
//     uf.init(N*M);
//     t = Q+1;
//     c = 0;
//     rrep(i,tmm[k].size()){
//       if(type[k][i]==1) break;
// 
//       if(tmm[k][i] != t){
//         res[t] -= c;
//         t = tmm[k][i];
//         res[t] += c;
//       }
// 
//       x = place[k][i] / M;
//       y = place[k][i] % M;
//       mp[x][y] = 1;
//       c++;
//       rep(d,4){
//         nx = x + dx[d];
//         ny = y + dy[d];
//         if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
//         if(mp[nx][ny]==1) c -= uf(x*M+y, nx*M+ny);
//       }
//     }
//   }
// 
//   rep(i,1,Q+1){
//     res[i] += res[i-1];
//     wt(res[i]);
//   }
// }