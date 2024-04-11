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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int N;
int K;
int M;
int T;
int A;
int B;
int as;
int a[200000];
int ia[200000];
int bs;
int b[200000];
int ib[200000];
int cs;
int c[200000];
int ic[200000];
int ds;
int d[200000];
int id[200000];
int ress;
int resarr[200000];
int main(){
  int i;
  wmem = memarr;
  long long res = 4611686016279904256LL;
  int r_a;
  int r_b;
  int r_c;
  int r_d;
  int ta = 0;
  int tb = 0;
  int tc = 0;
  int td = 0;
  long long tmp = 0;
  int va;
  int vb;
  int vd;
  int mv;
  rd(N);
  rd(M);
  rd(K);
  for(i=(0);i<(N);i++){
    rd(T);
    rd(A);
    rd(B);
    if(A==1 && B==0){
      arrInsert(as, as, a, T, ia, i);
    }
    if(A==0 && B==1){
      arrInsert(bs, bs, b, T, ib, i);
    }
    if(A==1 && B==1){
      arrInsert(cs, cs, c, T, ic, i);
    }
    if(A==0 && B==0){
      arrInsert(ds, ds, d, T, id, i);
    }
  }
  sortA_L(as, a, ia);
  sortA_L(bs, b, ib);
  sortA_L(cs, c, ic);
  sortA_L(ds, d, id);
  for(i=(0);i<(cs+1);i++){
    int cTE1_r3A;
    if(K-i > as){
      continue;
    }
    if(K-i > bs){
      continue;
    }
    if(i + K-i + K-i > M){
      continue;
    }
    if(i + as + bs + ds < M){
      continue;
    }
    for(cTE1_r3A=(0);cTE1_r3A<(3);cTE1_r3A++){
      if(ta > 0){
        tmp -= a[--ta];
      }
      if(tb > 0){
        tmp -= b[--tb];
      }
      if(td > 0){
        tmp -= d[--td];
      }
    }
    while(ta < as && ta < K-i){
      tmp += a[ta++];
    }
    while(tb < bs && tb < K-i){
      tmp += b[tb++];
    }
    while(tc < cs && tc < i){
      tmp += c[tc++];
    }
    while(ta+tb+tc+td < M){
      if(ta==as){
        va =1073709056;
      }
      else{
        va =a[ta];
      }
      if(tb==bs){
        vb =1073709056;
      }
      else{
        vb =b[tb];
      }
      if(td==ds){
        vd =1073709056;
      }
      else{
        vd =d[td];
      }
      mv =min_L(min_L(va, vb), vd);
      if(va == mv){
        tmp += a[ta++];
        continue;
      }
      if(vb == mv){
        tmp += b[tb++];
        continue;
      }
      if(vd == mv){
        tmp += d[td++];
        continue;
      }
    }
    if(res > tmp){
      res = tmp;
      r_a = ta;
      r_b = tb;
      r_c = tc;
      r_d = td;
    }
  }
  if(res==4611686016279904256LL){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(r_a);i++){
    resarr[ress++] = ia[i];
  }
  for(i=(0);i<(r_b);i++){
    resarr[ress++] = ib[i];
  }
  for(i=(0);i<(r_c);i++){
    resarr[ress++] = ic[i];
  }
  for(i=(0);i<(r_d);i++){
    resarr[ress++] = id[i];
  }
  wt_L(res);
  wt_L('\n');
  {
    int jPV_0s1p;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(jPV_0s1p=(0);jPV_0s1p<(ress-1);jPV_0s1p++){
        wt_L(resarr[jPV_0s1p]+1);
        wt_L(' ');
      }
      wt_L(resarr[jPV_0s1p]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, K, M;
// int T, A, B;
// int as, a[2d5], ia[2d5];
// int bs, b[2d5], ib[2d5];
// int cs, c[2d5], ic[2d5];
// int ds, d[2d5], id[2d5];
// int ress, resarr[2d5];
// 
// {
//   ll res = ll_inf;
//   int r_a, r_b, r_c, r_d;
//   int ta = 0, tb = 0, tc = 0, td = 0; ll tmp = 0;
//   int va, vb, vd, mv;
//   rd(N,M,K);
//   rep(i,N){
//     rd(T,A,B);
//     if(A==1 && B==0) arrInsert(as, as, a, T, ia, i);
//     if(A==0 && B==1) arrInsert(bs, bs, b, T, ib, i);
//     if(A==1 && B==1) arrInsert(cs, cs, c, T, ic, i);
//     if(A==0 && B==0) arrInsert(ds, ds, d, T, id, i);
//   }
//   sortA(as, a, ia);
//   sortA(bs, b, ib);
//   sortA(cs, c, ic);
//   sortA(ds, d, id);
// 
//   rep(i,cs+1){
//     if(K-i > as) continue;
//     if(K-i > bs) continue;
//     if(i + K-i + K-i > M) continue;
//     if(i + as + bs + ds < M) continue;
// 
//     rep(3){
//       if(ta > 0) tmp -= a[--ta];
//       if(tb > 0) tmp -= b[--tb];
//       if(td > 0) tmp -= d[--td];
//     }
//     while(ta < as && ta < K-i) tmp += a[ta++];
//     while(tb < bs && tb < K-i) tmp += b[tb++];
//     while(tc < cs && tc < i) tmp += c[tc++];
// 
//     while(ta+tb+tc+td < M){
//       va = if[ta==as, int_inf, a[ta]];
//       vb = if[tb==bs, int_inf, b[tb]];
//       vd = if[td==ds, int_inf, d[td]];
//       mv = min(va,vb,vd);
//       if(va == mv) tmp += a[ta++], continue;
//       if(vb == mv) tmp += b[tb++], continue;
//       if(vd == mv) tmp += d[td++], continue;
//     }
// 
//     if(res > tmp){
//       res = tmp;
//       r_a = ta;
//       r_b = tb;
//       r_c = tc;
//       r_d = td;
//     }
//   }
// 
//   if(res==ll_inf) wt(-1), return 0;
//   rep(i,r_a) resarr[ress++] = ia[i];
//   rep(i,r_b) resarr[ress++] = ib[i];
//   rep(i,r_c) resarr[ress++] = ic[i];
//   rep(i,r_d) resarr[ress++] = id[i];
//   wt(res);
//   wt(resarr(ress)+1);
// }