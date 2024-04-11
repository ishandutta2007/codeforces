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
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
template<class T1, class T2, class T3> void rsortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  sortA_L(N, a, b, c, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
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
int main(){
  int cTE1_r3A;
  wmem = memarr;
  int M = 52;
  int i;
  int j;
  int k;
  int sm;
  int c;
  int mask;
  int nc;
  int nmask;
  int d;
  int x;
  int y;
  int cnv[256];
  int rev[256];
  for(i=(0);i<(26);i++){
    cnv['a' + i] = i;
    rev[i] = 'a' + i;
  }
  for(i=(26);i<(52);i++){
    cnv['A' + i - 26] = i;
    rev[i] = 'A' + i - 26;
  }
  static int dp[52][1025];
  static int go1[52][1025];
  static int go2[52][1025];
  static int sz;
  static int s1[100000];
  static int s2[100000];
  static int v[100000];
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    int m;
    int N;
    rd(N);
    int len[N];
    char S[N][150];
    int cnt[N][M];
    int ind[N][M][2];
    int ress = 0;
    char res[150] = {};
    {
      int WYIGIcGE;
      for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
        len[WYIGIcGE] = rd(S[WYIGIcGE]);
      }
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(len[i]);j++){
        S[i][j] = cnv[S[i][j]];
      }
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(M);j++){
        cnt[i][j] = 0;
      }
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(len[i]);j++){
        k = S[i][j];
        ind[i][k][cnt[i][k]++] = j;
      }
    }
    sz = 0;
    for(i=(0);i<(M);i++){
      for(j=(0);j<(1<<N);j++){
        for(k=(0);k<(N);k++){
          if(cnt[k][i]==0){
            goto BUotOFBp;
          }
        }
        for(k=(0);k<(N);k++){
          if(((j) &(1<<(k)))&& cnt[k][i]<=1){
            goto BUotOFBp;
          }
        }
        sm = 0;
        for(k=(0);k<(N);k++){
          if(((j) &(1<<(k)))){
            sm +=ind[k][i][1];
          }
          else{
            sm +=ind[k][i][0];
          }
        }
        arrInsert(sz, sz, s1, i, s2, j, v, sm);
        BUotOFBp:;
      }
    }
    rsortA_L(sz, v, s1, s2);
    for(i=(0);i<(M);i++){
      for(j=(0);j<(1<<N);j++){
        dp[i][j] = go1[i][j] = go2[i][j] = -1;
      }
    }
    for(m=(0);m<(sz);m++){
      auto OC5CYxKD = ((s1[m]));
      auto o3WxPXbE = (( s2[m]));
      c=OC5CYxKD;
      mask=o3WxPXbE;
      dp[c][mask] = 1;
      for(nc=(0);nc<(M);nc++){
        nmask = 0;
        for(i=(0);i<(N);i++){
          if(((mask) &(1<<(i)))){
            d =ind[i][c][1];
          }
          else{
            d =ind[i][c][0];
          }
          x = y = -1;
          if(cnt[i][nc] >= 1){
            x = ind[i][nc][0];
          }
          if(cnt[i][nc] >= 2){
            y = ind[i][nc][1];
          }
          if(d < x){
            continue;
          }
          if(d < y){
            nmask |= (1<<i);
            continue;
          }
          goto lQU550vz;
        }
        if(dp[c][mask] < dp[nc][nmask] + 1){
          dp[c][mask] = dp[nc][nmask] + 1;
          go1[c][mask] = nc;
          go2[c][mask] = nmask;
        }
        lQU550vz:;
      }
    }
    sm = 0;
    c = mask = -1;
    for(i=(0);i<(M);i++){
      for(j=(0);j<(1<<N);j++){
        if(sm < dp[i][j]){
          auto sMcf5Tpe = ((i));
          auto aWpYLTGo = (( j));
          auto p1eY1vyF = (( dp[i][j]));
          c=sMcf5Tpe;
          mask=aWpYLTGo;
          sm=p1eY1vyF;
        }
      }
    }
    while(c >= 0){
      res[ress++] = rev[c];
      auto xtzQOlbs = ((go1[c][mask]));
      auto aFgbOQYS = (( go2[c][mask]));
      c=xtzQOlbs;
      mask=aFgbOQYS;
    }
    wt_L(ress);
    wt_L('\n');
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// int M = 52;
// 
// int i, j, k, sm, c, mask, nc, nmask, d, x, y;
// int cnv[256], rev[256];
// rep(i,26) cnv['a' + i] = i, rev[i] = 'a' + i;
// rep(i,26,52) cnv['A' + i - 26] = i, rev[i] = 'A' + i - 26;
// 
// static int dp[52][1025], go1[52][1025], go2[52][1025];
// static int sz, s1[1d5], s2[1d5], v[1d5];
// 
// REP(rd_int()){
//   int @N, len[N]; char S[N][150];
//   int cnt[N][M], ind[N][M][2];
//   int ress = 0; char res[150] = {};
// 
//   rd(S@len(N));
//   rep(i,N) rep(j,len[i]) S[i][j] = cnv[S[i][j]];
// 
//   rep(i,N) rep(j,M) cnt[i][j] = 0;
//   rep(i,N) rep(j,len[i]){
//     k = S[i][j];
//     ind[i][k][cnt[i][k]++] = j;
//   }
// 
//   sz = 0;
//   rep(i,M) rep(j,1<<N){
//     rep(k,N) if(cnt[k][i]==0) break_continue;
//     rep(k,N) if(BIT_ith(j,k) && cnt[k][i]<=1) break_continue;
//     sm = 0;
//     rep(k,N) sm += if[BIT_ith(j,k), ind[k][i][1], ind[k][i][0]];
//     arrInsert(sz, sz, s1, i, s2, j, v, sm);
//   }
//   rsortA(sz, v, s1, s2);
// 
//   rep(i,M) rep(j,1<<N) dp[i][j] = go1[i][j] = go2[i][j] = -1;
//   rep(m,sz){
//     (c, mask) = (s1[m], s2[m]);
//     dp[c][mask] = 1;
//     rep(nc,M){
//       nmask = 0;
//       rep(i,N){
//         d = if[BIT_ith(mask,i), ind[i][c][1], ind[i][c][0]];
//         x = y = -1;
//         if(cnt[i][nc] >= 1) x = ind[i][nc][0];
//         if(cnt[i][nc] >= 2) y = ind[i][nc][1];
//         if(d < x) continue;
//         if(d < y) nmask |= (1<<i), continue;
//         break_continue;
//       }
//       if(dp[c][mask] < dp[nc][nmask] + 1){
//         dp[c][mask] = dp[nc][nmask] + 1;
//         go1[c][mask] = nc;
//         go2[c][mask] = nmask;
//       }
//     }
//   }
// 
//   sm = 0; c = mask = -1;
//   rep(i,M) rep(j,1<<N) if(sm < dp[i][j]) (c, mask, sm) = (i, j, dp[i][j]);
//   while(c >= 0){
//     res[ress++] = rev[c];
//     (c, mask) = (go1[c][mask], go2[c][mask]);
//   }
//   wt(ress);
//   wt(res);
// }