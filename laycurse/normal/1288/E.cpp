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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr;
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
template<class T1, class T2, class T3, class T4> void sortA_L(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem = wmem){
  int i;
  pair<pair<T1, T2>, pair<T3, T4> > *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first.first = a[i];
    arr[i].first.second = b[i];
    arr[i].second.first = c[i];
    arr[i].second.second = d[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first.first;
    b[i] = arr[i].first.second;
    c[i] = arr[i].second.first;
    d[i] = arr[i].second.second;
  }
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int M;
int A[600000];
int res1[300000];
int res2[300000];
vector<int> p[300000];
int qs;
int qa[600000];
int qb[600000];
int qi[600000];
int qv[600000];
int a;
int b;
int cnt[300000];
int val;
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(M);
  M += N;
  for(i=(0);i<(N);i++){
    A[i] = N-1-i;
  }
  for(i=(N);i<(M);i++){
    A[i] = rd_int() - 1;
  }
  for(i=(0);i<(N);i++){
    res1[i] = i;
  }
  for(i=(N);i<(M);i++){
    res1[A[i]] = 0;
  }
  for(i=(0);i<(M);i++){
    p[A[i]].push_back(i);
  }
  for(i=(0);i<(N);i++){
    p[i].push_back(M);
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(1);j<(p[i].size());j++){
      arrInsert(qs,qs,qa,p[i][j-1]+1,qb,p[i][j],qi,i);
    }
  }
  for(i=(0);i<(qs);i++){
    qv[i] = qa[i] / 550;
  }
  sortA_L(qs,qv,qb,qa,qi);
  for(i=(0);i<(qs);i++){
    while(b < qb[i]){
      if(cnt[A[b]]==0){
        val++;
      }
      cnt[A[b]]++;
      b++;
    }
    while(a > qa[i]){
      a--;
      if(cnt[A[a]]==0){
        val++;
      }
      cnt[A[a]]++;
    }
    while(b > qb[i]){
      b--;
      if(cnt[A[b]]==1){
        val--;
      }
      cnt[A[b]]--;
    }
    while(a < qa[i]){
      if(cnt[A[a]]==1){
        val--;
      }
      cnt[A[a]]--;
      a++;
    }
    chmax(res2[qi[i]], val);
  }
  for(i=(0);i<(N);i++){
    wt_L(res1[i]+1);
    wt_L(' ');
    wt_L(res2[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200112-1

// --- original code ---
// //no-unlocked
// int N, M, A[6d5];
// int res1[3d5], res2[3d5];
// 
// vector<int> p[3d5];
// int qs, qa[6d5], qb[6d5], qi[6d5], qv[6d5];
// 
// int a, b, cnt[3d5], val;
// 
// {
//   rd(N,M);
//   M += N;
//   rep(i,N) A[i] = N-1-i;
//   rep(i,N,M) A[i] = rd_int() - 1;
//   rep(i,N) res1[i] = i;
//   rep(i,N,M) res1[A[i]] = 0;
// 
//   rep(i,M) p[A[i]].push_back(i);
//   rep(i,N) p[i].push_back(M);
//   rep(i,N) rep(j,1,p[i].size()) arrInsert(qs,qs,qa,p[i][j-1]+1,qb,p[i][j],qi,i);
//   rep(i,qs) qv[i] = qa[i] / 550;
//   sortA(qs,qv,qb,qa,qi);
// 
//   rep(i,qs){
//     while(b < qb[i]){
//       if(cnt[A[b]]==0) val++;
//       cnt[A[b]]++;
//       b++;
//     }
//     while(a > qa[i]){
//       a--;
//       if(cnt[A[a]]==0) val++;
//       cnt[A[a]]++;
//     }
//     while(b > qb[i]){
//       b--;
//       if(cnt[A[b]]==1) val--;
//       cnt[A[b]]--;
//     }
//     while(a < qa[i]){
//       if(cnt[A[a]]==1) val--;
//       cnt[A[a]]--;
//       a++;
//     }
//     res2[qi[i]] >?= val;
//   }
// 
//   rep(i,N) wt(res1[i]+1, res2[i]+1);
// }