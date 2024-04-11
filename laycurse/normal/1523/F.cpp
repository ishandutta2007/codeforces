#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
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
template <class T> struct DijkstraHeap{
  int*hp;
  int*place;
  int size;
  char*visited;
  T*val;
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
  void malloc(int N, int init_fg){
    malloc(N);
    if(init_fg){
      init(N);
    }
  }
  void walloc(int N, int init_fg, void **mem=&wmem){
    walloc(N,mem);
    if(init_fg){
      init(N);
    }
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
struct dimcomp2{
  int B;
  dimcomp2(){
  }
  dimcomp2(int b){
    B = b;
  }
  dimcomp2(int a, int b){
    B = b;
  }
  inline void set(int b){
    B = b;
  }
  inline void set(int a, int b){
    B = b;
  }
  inline int mask(int a, int b){
    return a * B + b;
  }
  inline int operator()(int a, int b){
    return a * B + b;
  }
  inline void para(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
  inline void operator()(int mask, int &a, int &b){
    a = mask / B;
    b = mask % B;
  }
}
;
int N;
int M;
int TX[20];
int TY[20];
int QX[100];
int QY[100];
int QT[100];
int mxs[101][17000];
int mincost1[20][17000];
int mincost2[100][17000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int res = 0;
  int nx;
  int ct;
  int dmask;
  int score;
  int mask;
  dimcomp2 dm(101,17000);
  DijkstraHeap<int> hp;
  hp.walloc(101*17000,1);
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(TX[Lj4PdHRW]);
      rd(TY[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(QX[e98WHCEY]);
      rd(QY[e98WHCEY]);
      rd(QT[e98WHCEY]);
    }
  }
  sortA_L(M,QT,QX,QY);
  for(i=(0);i<(N);i++){
    for(mask=(0);mask<(1<<N);mask++){
      mincost1[i][mask] = 1073709056;
      for(k=(0);k<(N);k++){
        if(((mask) &(1<<(k)))){
          chmin(mincost1[i][mask], abs(TX[k]-TX[i]) + abs(TY[k]-TY[i]));
        }
      }
    }
  }
  for(i=(0);i<(M);i++){
    for(mask=(0);mask<(1<<N);mask++){
      mincost2[i][mask] = 1073709056;
      for(k=(0);k<(N);k++){
        if(((mask) &(1<<(k)))){
          chmin(mincost2[i][mask], abs(TX[k]-QX[i]) + abs(TY[k]-QY[i]));
        }
      }
    }
  }
  for(i=(0);i<(M);i++){
    for(j=(0);j<(1<<N);j++){
      mxs[i][j] = -1;
    }
  }
  for(i=(0);i<(M);i++){
    mxs[i][0] = 1;
  }
  for(i=(0);i<(N);i++){
    hp.change(dm(0,1<<i), 0);
  }
  k = 0;
  while(k < M){
    if(hp.size){
      nx =hp.val[hp.hp[0]];
    }
    else{
      nx =1073709056;
    }
    if(QT[k] <= nx){
      for(mask=(0);mask<(1<<N);mask++){
        if(mxs[k][mask] >= 0){
          chmax(res, mxs[k][mask]);
          score = mxs[k][mask];
          ct = QT[k];
          if(mask){
            for(j=(0);j<(N);j++){
              if(!((mask) &(1<<(j)))){
                hp.change(dm(score, mask|(1<<j)), ct + mincost1[j][mask]);
              }
            }
            for(j=(0);j<(M);j++){
              if(ct + mincost2[j][mask] <= QT[j]){
                chmax(mxs[j][mask], score + 1);
              }
            }
          }
          for(j=(0);j<(N);j++){
            if(!((mask) &(1<<(j)))){
              hp.change(dm(score, mask|(1<<j)), ct + abs(TX[j]-QX[k]) + abs(TY[j]-QY[k]));
            }
          }
          for(j=(k+1);j<(M);j++){
            if(ct + abs(QX[j]-QX[k]) + abs(QY[j]-QY[k]) > QT[j]){
              continue;
            }
            chmax(mxs[j][mask], score + 1);
          }
        }
      }
      k++;
    }
    else{
      dmask = hp.pop();
      dm(dmask, score, mask);
      ct = hp.val[dmask];
      for(j=(0);j<(N);j++){
        if(!((mask) &(1<<(j)))){
          hp.change(dm(score, mask|(1<<j)), ct + mincost1[j][mask]);
        }
      }
      for(j=(k);j<(M);j++){
        if(ct + mincost2[j][mask] <= QT[j]){
          chmax(mxs[j][mask], score + 1);
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int N, M, TX[20], TY[], QX[100], QY[], QT[];
// int mxs[101][17000];
// int mincost1[20][17000];
// int mincost2[100][17000];
// {
//   int i, j, k, res = 0, nx, ct, dmask, score, mask;
//   dimcomp2 dm(101,17000);
//   DijkstraHeap<int> hp;
//   hp.walloc(101*17000,1);
// 
//   rd(N,M,(TX,TY)(N),(QX,QY,QT)(M));
//   sortA(M,QT,QX,QY);
// 
//   rep(i,N) rep(mask,1<<N){
//     mincost1[i][mask] = int_inf;
//     rep(k,N) if(BIT_ith(mask,k)) mincost1[i][mask] <?= abs(TX[k]-TX[i]) + abs(TY[k]-TY[i]);
//   }
//   rep(i,M) rep(mask,1<<N){
//     mincost2[i][mask] = int_inf;
//     rep(k,N) if(BIT_ith(mask,k)) mincost2[i][mask] <?= abs(TX[k]-QX[i]) + abs(TY[k]-QY[i]);
//   }
// 
//   rep(i,M) rep(j,1<<N) mxs[i][j] = -1;
//   rep(i,M) mxs[i][0] = 1;
//   rep(i,N) hp.change(dm(0,1<<i), 0);
// 
//   k = 0;
//   while(k < M){
//     nx = if[hp.size, hp.val[hp.hp[0]], int_inf];
//     if(QT[k] <= nx){
//       rep(mask,1<<N) if(mxs[k][mask] >= 0){
//         res >?= mxs[k][mask];
//         score = mxs[k][mask];
//         ct = QT[k];
// 
//         if(mask){
//           rep(j,N) if(!BIT_ith(mask,j)) hp.change(dm(score, mask|(1<<j)), ct + mincost1[j][mask]);
//           rep(j,M) if(ct + mincost2[j][mask] <= QT[j]) mxs[j][mask] >?= score + 1;
//         }
// 
//         rep(j,N) if(!BIT_ith(mask,j)) hp.change(dm(score, mask|(1<<j)), ct + abs(TX[j]-QX[k]) + abs(TY[j]-QY[k]));
//         rep(j,k+1,M){
//           if(ct + abs(QX[j]-QX[k]) + abs(QY[j]-QY[k]) > QT[j]) continue;
//           mxs[j][mask] >?= score + 1;
//         }
//       }
//       k++;
//     } else {
//       dmask = hp.pop();
//       dm(dmask, score, mask);
//       ct = hp.val[dmask];
//       rep(j,N) if(!BIT_ith(mask,j)) hp.change(dm(score, mask|(1<<j)), ct + mincost1[j][mask]);
//       rep(j,k,M) if(ct + mincost2[j][mask] <= QT[j]) mxs[j][mask] >?= score + 1;
//     }
//   }
// 
//   wt(res);
// }