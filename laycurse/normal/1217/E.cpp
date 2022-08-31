#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class T> struct segtree_Point_Minval2{
  int N;
  int logN;
  T *mn;
  T *mn2;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
    mn2 = new T[2*i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mn, 2*i, mem);
    walloc1d(&mn2, 2*i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
    delete [] mn2;
  }
  T& operator[](int i){
    return mn[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=0;i<(N);i++){
        mn[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=0;i<(N);i++){
      mn2[N+i] = numeric_limits<T>::max();
    }
    for(i=N-1;i;i--){
      if(mn[2*i] <= mn[2*i+1]){
        mn[i] = mn[2*i];
        mn2[i] =min_L(mn2[2*i], mn[2*i+1]);
      }
      else{
        mn[i] = mn[2*i+1];
        mn2[i] =min_L(mn[2*i], mn2[2*i+1]);
      }
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      if(mn[2*a] <= mn[2*a+1]){
        mn[a] = mn[2*a];
        mn2[a] =min_L(mn2[2*a], mn[2*a+1]);
      }
      else{
        mn[a] = mn[2*a+1];
        mn2[a] =min_L(mn[2*a], mn2[2*a+1]);
      }
    }
  }
  inline void change(int a, T val){
    mn[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mn[a+N] += val;
    build(a+N);
  }
  inline pair<T,T> getMinVal2(int a, int b){
    T res1;
    T res2;
    a += N;
    b += N;
    res1 = res2 = numeric_limits<T>::max();
    while(a < b){
      if(a%2){
        chmin(res2, mn[a]);
        if(res1 > res2){
          swap(res1, res2);
        }
        ;
        chmin(res2, mn2[a]);
        a++;
      }
      if(b%2){
        b--;
        chmin(res2, mn[b]);
        if(res1 > res2){
          swap(res1, res2);
        }
        ;
        chmin(res2, mn2[b]);
      }
      a /= 2;
      b /= 2;
    }
    return make_pair(res1, res2);
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
int M;
int A[200000];
int Q;
int X;
int Y;
int d[9];
void cal(int x){
  int i;
  for(i=0;i<(9);i++){
    d[i] = x%10;
    x/=10;
  }
}
int main(){
  int KL2GvlyY, i;
  wmem = memarr;
  long long res;
  pair<int,int> p;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  segtree_Point_Minval2<int> t[9];
  for(i=0;i<(9);i++){
    t[i].malloc(N);
    t[i].setN(N);
  }
  for(i=0;i<(N);i++){
    int j;
    cal(A[i]);
    for(j=0;j<(9);j++){
      if(d[j]){
        t[j][i] =A[i];
      }
      else{
        t[j][i] =1073709056;
      }
    }
  }
  for(i=0;i<(9);i++){
    t[i].build();
  }
  for(KL2GvlyY=0;KL2GvlyY<(M);KL2GvlyY++){
    rd(Q);
    rd(X);
    rd(Y);
    if(Q==1){
      int j;
      X--;
      cal(Y);
      for(j=0;j<(9);j++){
        if(d[j]){
          t[j].change(X,Y);
        }
        else{
          t[j].change(X,1073709056);
        }
      }
    }
    else{
      int j;
      X--;
      Y--;
      res = 4611686016279904256LL;
      for(j=0;j<(9);j++){
        p = t[j].getMinVal2(X, Y+1);
        if(p.first < 1073709056 && p.second < 1073709056){
          chmin(res, p.first + p.second);
        }
      }
      if(res==4611686016279904256LL){
        res = -1;
      }
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5];
// int Q, X, Y;
// int d[9];
// 
// void cal(int x){
//   rep(i,9) d[i] = x%10, x/=10;
// }
// 
// {
//   ll res;
//   pair<int,int> p;
//   
//   rd(N,M,A(N));
//   segtree_Point_Minval2<int> t[9];
//   rep(i,9){
//     t[i].malloc(N);
//     t[i].setN(N);
//   }
//   rep(i,N){
//     cal(A[i]);
//     rep(j,9) t[j][i] = if[d[j], A[i], int_inf];
//   }
//   rep(i,9) t[i].build();
//   rep(M){
//     rd(Q,X,Y);
//     if(Q==1){
//       X--;
//       cal(Y);
//       rep(j,9) t[j].change(X, if[d[j], Y, int_inf]);
//     } else {
//       X--; Y--;
//       res = ll_inf;
// 
//       rep(j,9){
//         p = t[j].getMinVal2(X, Y+1);
//         if(p.first < int_inf && p.second < int_inf) res <?= p.first + p.second;
//       }
// 
//       if(res==ll_inf) res = -1;
//       wt(res);
//     }
//   }
// }