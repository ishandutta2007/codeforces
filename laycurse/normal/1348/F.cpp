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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[200000];
int B[200000];
int ind[200000];
int res1[200000];
int res2[200000];
int sz;
int s1[200000];
int s2[200000];
int mn[200000];
int mx[200000];
void solve(void){
  int i;
  int m = 0;
  set<pair<int,int>> s;
  set<pair<int,int>>::iterator it;
  set<pair<int,int>>::iterator jt;
  for(i=(0);i<(N);i++){
    while(m < N && A[m] == i){
      s.insert(make_pair(B[m], ind[m]));
      m++;
    }
    it = s.begin();
    if(s.size() >= 2 && it->first != i){
      jt = it;
      jt++;
      s1[sz] = it->second;
      s2[sz] = jt->second;
      sz++;
    }
    res1[it->second] = i;
    s.erase(it);
  }
}
int main(){
  int i;
  wmem = memarr;
  int x;
  int y;
  rd(N);
  {
    int cTE1_r3A;
    for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
      rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    ind[i] = i;
  }
  sortA_L(N, A, B, ind);
  solve();
  for(i=(0);i<(N);i++){
    res2[i] = res1[i];
  }
  for(i=(0);i<(N);i++){
    mn[ind[i]] = A[i];
  }
  for(i=(0);i<(N);i++){
    mx[ind[i]] = B[i];
  }
  for(i=(0);i<(sz);i++){
    x = s1[i];
    y = s2[i];
    swap(res2[x], res2[y]);
    if(mn[x] <= res2[x]  &&  res2[x] <= mx[x] && mn[y] <= res2[y]  &&  res2[y] <= mx[y]){
      wt_L("NO");
      wt_L('\n');
      {
        int YREPHmFM;
        if(N==0){
          wt_L('\n');
        }
        else{
          for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
            wt_L(res1[YREPHmFM]+ 1);
            wt_L(' ');
          }
          wt_L(res1[YREPHmFM]+ 1);
          wt_L('\n');
        }
      }
      {
        int ZIeRIny5;
        if(N==0){
          wt_L('\n');
        }
        else{
          for(ZIeRIny5=(0);ZIeRIny5<(N-1);ZIeRIny5++){
            wt_L(res2[ZIeRIny5]+ 1);
            wt_L(' ');
          }
          wt_L(res2[ZIeRIny5]+ 1);
          wt_L('\n');
        }
      }
      return 0;
    }
    swap(res2[x], res2[y]);
  }
  wt_L("YES");
  wt_L('\n');
  {
    int XJIcIBrW;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(XJIcIBrW=(0);XJIcIBrW<(N-1);XJIcIBrW++){
        wt_L(res1[XJIcIBrW]+ 1);
        wt_L(' ');
      }
      wt_L(res1[XJIcIBrW]+ 1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[2d5], ind[2d5];
// 
// int res1[2d5], res2[2d5];
// int sz, s1[2d5], s2[2d5], mn[2d5], mx[2d5];
// 
// void solve(void){
//   int i, m = 0;
//   set<pair<int,int>> s;
//   set<pair<int,int>>::iterator it, jt;
// 
//   rep(i,N){
//     while(m < N && A[m] == i){
//       s.insert(make_pair(B[m], ind[m]));
//       m++;
//     }
//     it = s.begin();
//     if(s.size() >= 2 && it->first != i){
//       jt = it;
//       jt++;
//       s1[sz] = it->second;
//       s2[sz] = jt->second;
//       sz++;
//     }
//     res1[it->second] = i;
//     s.erase(it);
//   }
// }
// 
// {
//   int x, y;
//   rd(N,(A--,B--)(N));
//   rep(i,N) ind[i] = i;
//   sortA(N, A, B, ind);
//   solve();
//   rep(i,N) res2[i] = res1[i];
//   rep(i,N) mn[ind[i]] = A[i];
//   rep(i,N) mx[ind[i]] = B[i];
//   rep(i,sz){
//     x = s1[i];
//     y = s2[i];
//     swap(res2[x], res2[y]);
//     if(mn[x] <= res2[x] <= mx[x] && mn[y] <= res2[y] <= mx[y]){
//       wt("NO");
//       wt(res1(N) + 1);
//       wt(res2(N) + 1);
//       return 0;
//     }
//     swap(res2[x], res2[y]);
//   }
//   wt("YES");
//   wt(res1(N) + 1);
// }