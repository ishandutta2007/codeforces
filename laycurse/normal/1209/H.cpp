#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
inline void rd(double &x){
  scanf("%lf",&x);
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(double x){
  printf("%.15f",x);
}
template <class T> struct LHeap{
  int *hp;
  int *place;
  int size;
  T *val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=0;i<(N);i++){
      place[i]=-1;
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
    T f = val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res = hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
int N;
int L;
int X;
int Y;
double S;
double w[400000];
double s[400000];
double a[400000];
int sz;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int k;
  double gn;
  double nd;
  double y;
  double res = 0;
  LHeap<double> hp;
  i = 0;
  rd(N);
  rd(L);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    rd(X);
    rd(Y);
    rd(S);
    if(i < X){
      w[sz] = X - i;
      s[sz++] = 0;
    }
    w[sz] = Y - X;
    s[sz++] = S;
    i = Y;
  }
  if(i < L){
    w[sz] = L - i;
    s[sz++] = 0;
  }
  for(i=0;i<(sz);i++){
    a[i] = 1;
  }
  hp.walloc(sz);
  hp.init(sz);
  for(k=0;k<(sz);k++){
    while(hp.size){
      i = hp.hp[0];
      if(s[i] <= s[k]){
        break;
      }
      gn = w[i] / s[i] - w[i] / (s[i] + a[i]) * (1 - a[i]);
      nd = w[k] / (s[k] + 2) + w[k] / (s[k] + a[k]) * (1 - a[k]);
      if(nd < gn){
        a[k] = 2;
        y = w[i] / (s[i]+a[i]) * (1-a[i]) + nd;
        a[i] = (w[i] - y * s[i]) / (w[i] + y);
        break;
      }
      else{
        a[i] = 0;
        y = w[k] / (s[k]+a[k]) * (1-a[k]) - gn;
        a[k] = (w[k] - y * s[k]) / (w[k] + y);
        hp.pop();
      }
    }
    if(a[k]){
      hp.change(k, -s[k]);
    }
  }
  for(i=0;i<(sz);i++){
    res += w[i] / (s[i] + a[i]);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, L;
// int X, Y; double S;
// 
// double w[4d5], s[4d5], a[4d5];
// int sz;
// 
// {
//   int i, k;
//   double gn, nd, y;
//   double res = 0;
//   LHeap<double> hp;
// 
//   i = 0;
//   rd(N,L);
//   rep(N){
//     rd(X,Y,S);
//     if(i < X){
//       w[sz] = X - i;
//       s[sz++] = 0;
//     }
//     w[sz] = Y - X;
//     s[sz++] = S;
//     i = Y;
//   }
//   if(i < L){
//     w[sz] = L - i;
//     s[sz++] = 0;
//   }
// 
//   rep(i,sz) a[i] = 1;
//   hp.walloc(sz);
//   hp.init(sz);
// 
//   rep(k,sz){
//     while(hp.size){
//       i = hp.hp[0];
//       if(s[i] <= s[k]) break;
//       gn = w[i] / s[i] - w[i] / (s[i] + a[i]) * (1 - a[i]);
//       nd = w[k] / (s[k] + 2) + w[k] / (s[k] + a[k]) * (1 - a[k]);
//       if(nd < gn){
//         a[k] = 2;
//         y = w[i] / (s[i]+a[i]) * (1-a[i]) + nd;
//         a[i] = (w[i] - y * s[i]) / (w[i] + y);
//         break;
//       } else {
//         a[i] = 0;
//         y = w[k] / (s[k]+a[k]) * (1-a[k]) - gn;
//         a[k] = (w[k] - y * s[k]) / (w[k] + y);
//         hp.pop();
//       }
//     }
//     if(a[k]) hp.change(k, -s[k]);
//   }
// 
//   rep(i,sz) res += w[i] / (s[i] + a[i]);
//   wt(res);
// }