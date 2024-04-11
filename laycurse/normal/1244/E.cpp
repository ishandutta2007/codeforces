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
void sortF_L(int N, unsigned A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned *arr;
  unsigned c;
  int *sz;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, int A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  int *arr;
  unsigned *send;
  if(N < 256){
    sort(A, A+N);
    return;
  }
  send = (unsigned*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
  }
}
void sortF_L(int N, unsigned long long A[], void *mem = wmem){
  int i;
  int m;
  int bt;
  unsigned long long *arr;
  unsigned c;
  int *sz;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  bt = sizeof(unsigned long long) * 8;
  walloc1d(&arr, N, &mem);
  walloc1d(&sz, N, &mem);
  for(m=0;m<bt;m+=8){
    for(i=(0);i<(257);i++){
      sz[i] = 0;
    }
    for(i=(0);i<(N);i++){
      sz[ 1+((A[i]>>m)&255u) ]++;
    }
    for(i=(1);i<(257);i++){
      sz[i] += sz[i-1];
    }
    for(i=(0);i<(N);i++){
      c = ((A[i]>>m)&255u);
      arr[sz[c]++] = A[i];
    }
    swap(A, arr);
  }
}
void sortF_L(int N, long long A[], void *mem = wmem){
  int i;
  int x;
  int y;
  int z;
  long long *arr;
  unsigned long long *send;
  if(N < 512){
    sort(A, A+N);
    return;
  }
  send = (unsigned long long*)A;
  sortF_L(N, send, mem);
  if(A[0] < 0 || A[N-1] >= 0){
    return;
  }
  x = 0;
  y = N;
  while(x < y){
    z = (x+y) / 2;
    if(A[z] < 0){
      y = z;
    }
    else{
      x = z+1;
    }
  }
  walloc1d(&arr, N, &mem);
  z = 0;
  for(i=(x);i<(N);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(x);i++){
    arr[z++] = A[i];
  }
  for(i=(0);i<(N);i++){
    A[i] = arr[i];
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
inline void rd(long long &x){
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
template<class T> inline T popFirst(multiset<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(multiset<T> &a){
  return *(a.begin());
}
template<class T> inline T popLast(multiset<T> &a){
  T res;
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T getLast(multiset<T> &a){
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> inline T popFirst(set<T> &a){
  T res = *(a.begin());
  a.erase(a.begin());
  return res;
}
template<class T> inline T getFirst(set<T> &a){
  return *(a.begin());
}
template<class T> inline T popLast(set<T> &a){
  T res;
  typename set<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T getLast(set<T> &a){
  typename set<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> int runLength(int N, T *arr, T *val = NULL, int *len = NULL){
  int i;
  int rN;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void *mem = wmem;
    walloc1d(&val, N, &mem);
    walloc1d(&len, N, &mem);
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
int N;
int A[100000];
long long K;
int sz;
int num[100000];
int len[100000];
int main(){
  int i;
  wmem = memarr;
  int res;
  long long mx;
  set< pair<int,int> > s;
  pair<int,int> x;
  pair<int,int> y;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortF_L(N,A);
  sz = runLength(N, A, num, len);
  for(i=(0);i<(sz);i++){
    s.insert( make_pair(num[i], len[i]) );
  }
  for(;;){
    if(s.size()==1){
      break;
    }
    x = getFirst(s);
    y = getLast(s);
    if(x.second <= y.second){
      x = popFirst(s);
      y = getFirst(s);
      mx =min_L(K / x.second, y.first - x.first);
      if(mx == 0){
        s.insert(x);
        break;
      }
      x.first += mx;
      K -= mx * x.second;
      if(y.first == x.first){
        x.second += y.second;
        popFirst(s);
        s.insert(x);
      }
      else{
        s.insert(x);
      }
    }
    else{
      x = popLast(s);
      y = getLast(s);
      mx =min_L(K / x.second, x.first - y.first);
      if(mx == 0){
        s.insert(x);
        break;
      }
      x.first -= mx;
      K -= mx * x.second;
      if(y.first == x.first){
        x.second += y.second;
        popLast(s);
        s.insert(x);
      }
      else{
        s.insert(x);
      }
    }
  }
  if(s.size()==1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  x = getFirst(s);
  y = getLast(s);
  res = y.first - x.first;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, A[1d5]; ll K;
// int sz, num[1d5], len[1d5];
// {
//   int res;
//   ll mx;
//   set< pair<int,int> > s;
//   pair<int,int> x, y;
// 
//   rd(N,K,A(N));
//   sortF(N,A);
//   sz = runLength(N, A, num, len);
//   rep(i,sz) s.insert( make_pair(num[i], len[i]) );
//   for(;;){
//     if(s.size()==1) break;
//     x = getFirst(s);
//     y = getLast(s);
//     if(x.second <= y.second){
//       x = popFirst(s);
//       y = getFirst(s);
//       mx = min(K / x.second, y.first - x.first);
//       if(mx == 0) s.insert(x), break;
//       x.first += mx;
//       K -= mx * x.second;
//       if(y.first == x.first){
//         x.second += y.second;
//         popFirst(s);
//         s.insert(x);
//       } else {
//         s.insert(x);
//       }
//     } else {
//       x = popLast(s);
//       y = getLast(s);
//       mx = min(K / x.second, x.first - y.first);
//       if(mx == 0) s.insert(x), break;
//       x.first -= mx;
//       K -= mx * x.second;
//       if(y.first == x.first){
//         x.second += y.second;
//         popLast(s);
//         s.insert(x);
//       } else {
//         s.insert(x);
//       }
//     }
//   }
//   if(s.size()==1) wt(0), return 0;
//   x = getFirst(s);
//   y = getLast(s);
//   res = y.first - x.first;
//   wt(res);
// }