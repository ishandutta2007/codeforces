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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    walloc1d(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int*deg;
    int*q;
    int qs = 0;
    int qe = 0;
    walloc1d(&deg, N, &mem);
    walloc1d(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
int N;
int M;
int sz;
int ind[600000];
int p[600000];
int s[600000];
int c[600000];
int mm;
int aa[700000];
int bb[700000];
int dp[300000];
int ord[300000];
int nx[300000];
graph g;
int ress;
int res[300000];
int use[300000];
int main(){
  int FmcKpFmN, Lj4PdHRW;
  wmem = memarr;
  int i;
  int j;
  int k;
  set<int> st;
  set<int>::iterator it1;
  set<int>::iterator it2;
  rd(N);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    rd(k);k += (-1);
    arrInsert(sz, sz, ind, i, p, 2*j, s, 1);
    arrInsert(sz, sz, ind, i, p, 2*k+1, s, -1);
  }
  sortA_L(sz, p, ind, s);
  for(i=(0);i<(sz);i++){
    c[ind[i]] += s[i];
    if(s[i] == 1 && c[ind[i]]==1){
      it1 = it2 = st.insert(ind[i]).first;
      if(it1 != st.begin()){
        it1--;
        arrInsert(mm, mm, aa, *it1, bb, ind[i]);
      }
      it2++;
      if(it2 != st.end()){
        arrInsert(mm, mm, aa, ind[i], bb, *it2);
      }
    }
    if(s[i] == -1 && c[ind[i]]==0){
      st.erase(ind[i]);
    }
  }
  g.setDirectEdge(N,mm,aa,bb);
  g.TopologicalSort(ord);
  for(FmcKpFmN=(N)-1;FmcKpFmN>=(0);FmcKpFmN--){
    int t_ynMSdg;
    auto&i = ord[FmcKpFmN];
    for(t_ynMSdg=(0);t_ynMSdg<(g.es[i]);t_ynMSdg++){
      auto&j = g.edge[i][t_ynMSdg];
      if(dp[i] < dp[j] + 1){
        dp[i] = dp[j] + 1;
        nx[i] = j;
      }
    }
  }
  int a2conNHc;
  remove_reference<decltype(dp[a2conNHc])>::type hCmBdyQB;
  int V9aVTaxx = 0;
  int APIVbQlN;
  if((0) > ((N)-1)){
    hCmBdyQB = 0;
  }
  else{
    for(a2conNHc = 0; a2conNHc <= (N)-1; a2conNHc++){
      if(V9aVTaxx == 0){
        hCmBdyQB = dp[a2conNHc];
        APIVbQlN = a2conNHc;
        V9aVTaxx = 1;
        continue;
      }
      const auto YREPHmFM = dp[a2conNHc];
      if(hCmBdyQB < YREPHmFM){
        hCmBdyQB = YREPHmFM;
        APIVbQlN = a2conNHc;
      }
    }
    if(V9aVTaxx==0){
      hCmBdyQB = 0;
    }
  }
  i =APIVbQlN;
  use[i] = 1;
  while(dp[i]){
    i = nx[i];
    use[i] = 1;
  }
  for(i=(0);i<(N);i++){
    if(!use[i]){
      res[ress++] = i;
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int jPV_0s1p;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(jPV_0s1p=(0);jPV_0s1p<(ress-1);jPV_0s1p++){
        wt_L(res[jPV_0s1p]+1);
        wt_L(' ');
      }
      wt_L(res[jPV_0s1p]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M;
// int sz, ind[6d5], p[], s[], c[];
// int mm, aa[7d5], bb[];
// int dp[3d5], ord[], nx[];
// graph g;
// int ress, res[], use[];
// {
//   int i, j, k;
//   set<int> st;
//   set<int>::iterator it1, it2;
//   rd(N);
//   REP(rd_int()){
//     rd(i--, j--, k--);
//     arrInsert(sz, sz, ind, i, p, 2*j, s, 1);
//     arrInsert(sz, sz, ind, i, p, 2*k+1, s, -1);
//   }
//   sortA(sz, p, ind, s);
//   rep(i,sz){
//     c[ind[i]] += s[i];
//     if(s[i] == 1 && c[ind[i]]==1){
//       it1 = it2 = st.insert(ind[i]).first;
//       if(it1 != st.begin()){
//         it1--;
//         arrInsert(mm, mm, aa, *it1, bb, ind[i]);
//       }
//       it2++;
//       if(it2 != st.end()){
//         arrInsert(mm, mm, aa, ind[i], bb, *it2);
//       }
//     }
//     if(s[i] == -1 && c[ind[i]]==0){
//       st.erase(ind[i]);
//     }
//   }
// 
//   g.setDirectEdge(N,mm,aa,bb);
//   g.TopologicalSort(ord);
//   rrep[ord](i,N){
//     rep[g.edge[i]](j,g.es[i]){
//       if(dp[i] < dp[j] + 1){
//         dp[i] = dp[j] + 1;
//         nx[i] = j;
//       }
//     }
//   }
//   i = argmax(dp(N));
//   use[i] = 1;
//   while(dp[i]){
//     i = nx[i];
//     use[i] = 1;
//   }
//   rep(i,N) if(!use[i]) res[ress++] = i;
//   wt(ress);
//   wt(res(ress)+1);
// }