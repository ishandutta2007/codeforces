#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T> struct segtree_Point_Minval{
  int N;
  int logN;
  T*mn;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
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
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
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
      for(i=(0);i<(N);i++){
        mn[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mn[i] =min_L(mn[2*i], mn[2*i+1]);
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mn[a] =min_L(mn[2*a], mn[2*a+1]);
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
template<class T> struct segtree_Point_Maxval{
  int N;
  int logN;
  T*mx;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mx = new T[2*i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mx, 2*i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mx;
  }
  T& operator[](int i){
    return mx[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        mx[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mx[i] =max_L(mx[2*i], mx[2*i+1]);
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mx[a] =max_L(mx[2*a], mx[2*a+1]);
    }
  }
  inline void change(int a, T val){
    mx[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mx[a+N] += val;
    build(a+N);
  }
  inline T getMaxVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    while(a < b){
      if(a%2){
        if(fga){
          res =max_L(res, mx[a]);
        }
        else{
          res = mx[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =max_L(mx[b], tmp);
        }
        else{
          tmp = mx[b];
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
      res =max_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
int M;
int K[100000];
int A1[100000];
int B1[100000];
int A2[100000];
int B2[100000];
int ok[2][100000];
int res[100000];
segtree_Point_Maxval<int> aa1;
segtree_Point_Maxval<int> aa2;
segtree_Point_Minval<int> bb1;
segtree_Point_Minval<int> bb2;
int is_better(int &x, int &y, int nx, int ny, int i){
  int s;
  int t;
  if(nx < A1[i] || nx > B1[i]){
    return 0;
  }
  if(ny < A2[i] || ny > B2[i]){
    return 0;
  }
  if(x == -1){
    x = nx;
    y = ny;
    return 1;
  }
  if(x == nx  &&  nx == K[i]){
    int Lj4PdHRW;
    int KL2GvlyY;
    int Q5VJL1cS;
    Lj4PdHRW = i+1;
    KL2GvlyY = N;
    while(Lj4PdHRW < KL2GvlyY){
      if((Lj4PdHRW + KL2GvlyY)%2==0){
        Q5VJL1cS = (Lj4PdHRW + KL2GvlyY) / 2;
      }
      else{
        Q5VJL1cS = (Lj4PdHRW + KL2GvlyY - 1) / 2;
      }
      if(aa2.getMaxVal(i+1,Q5VJL1cS+1) > ny){
        KL2GvlyY = Q5VJL1cS;
      }
      else{
        Lj4PdHRW = Q5VJL1cS + 1;
      }
    }
    s =KL2GvlyY;
    int RZTsC2BF;
    int FmcKpFmN;
    int xr20shxY;
    RZTsC2BF = i+1;
    FmcKpFmN = N;
    while(RZTsC2BF < FmcKpFmN){
      if((RZTsC2BF + FmcKpFmN)%2==0){
        xr20shxY = (RZTsC2BF + FmcKpFmN) / 2;
      }
      else{
        xr20shxY = (RZTsC2BF + FmcKpFmN - 1) / 2;
      }
      if(bb2.getMinVal(i+1,xr20shxY+1) < ny){
        FmcKpFmN = xr20shxY;
      }
      else{
        RZTsC2BF = xr20shxY + 1;
      }
    }
    chmin(s, FmcKpFmN);
    int KrdatlYV;
    int ao_dF3pO;
    int tU__gIr_;
    KrdatlYV = i+1;
    ao_dF3pO = N;
    while(KrdatlYV < ao_dF3pO){
      if((KrdatlYV + ao_dF3pO)%2==0){
        tU__gIr_ = (KrdatlYV + ao_dF3pO) / 2;
      }
      else{
        tU__gIr_ = (KrdatlYV + ao_dF3pO - 1) / 2;
      }
      if(aa2.getMaxVal(i+1,tU__gIr_+1) > y){
        ao_dF3pO = tU__gIr_;
      }
      else{
        KrdatlYV = tU__gIr_ + 1;
      }
    }
    t =ao_dF3pO;
    int V9aVTaxx;
    int APIVbQlN;
    int YREPHmFM;
    V9aVTaxx = i+1;
    APIVbQlN = N;
    while(V9aVTaxx < APIVbQlN){
      if((V9aVTaxx + APIVbQlN)%2==0){
        YREPHmFM = (V9aVTaxx + APIVbQlN) / 2;
      }
      else{
        YREPHmFM = (V9aVTaxx + APIVbQlN - 1) / 2;
      }
      if(bb2.getMinVal(i+1,YREPHmFM+1) < y){
        APIVbQlN = YREPHmFM;
      }
      else{
        V9aVTaxx = YREPHmFM + 1;
      }
    }
    chmin(t, APIVbQlN);
    if(s > t){
      x = nx;
      y = ny;
      return 1;
    }
    return 0;
  }
  if(y == ny  &&  ny == K[i]){
    int ZIeRIny5;
    int iMWUTgY_;
    int AlM5nNnR;
    ZIeRIny5 = i+1;
    iMWUTgY_ = N;
    while(ZIeRIny5 < iMWUTgY_){
      if((ZIeRIny5 + iMWUTgY_)%2==0){
        AlM5nNnR = (ZIeRIny5 + iMWUTgY_) / 2;
      }
      else{
        AlM5nNnR = (ZIeRIny5 + iMWUTgY_ - 1) / 2;
      }
      if(aa1.getMaxVal(i+1,AlM5nNnR+1) > nx){
        iMWUTgY_ = AlM5nNnR;
      }
      else{
        ZIeRIny5 = AlM5nNnR + 1;
      }
    }
    s =iMWUTgY_;
    int BUotOFBp;
    int Q5rsz4fz;
    int GgkpftXM;
    BUotOFBp = i+1;
    Q5rsz4fz = N;
    while(BUotOFBp < Q5rsz4fz){
      if((BUotOFBp + Q5rsz4fz)%2==0){
        GgkpftXM = (BUotOFBp + Q5rsz4fz) / 2;
      }
      else{
        GgkpftXM = (BUotOFBp + Q5rsz4fz - 1) / 2;
      }
      if(bb1.getMinVal(i+1,GgkpftXM+1) < nx){
        Q5rsz4fz = GgkpftXM;
      }
      else{
        BUotOFBp = GgkpftXM + 1;
      }
    }
    chmin(s, Q5rsz4fz);
    int Hjfu7Vx7;
    int zT28qSmp;
    int aTqQ6rt8;
    Hjfu7Vx7 = i+1;
    zT28qSmp = N;
    while(Hjfu7Vx7 < zT28qSmp){
      if((Hjfu7Vx7 + zT28qSmp)%2==0){
        aTqQ6rt8 = (Hjfu7Vx7 + zT28qSmp) / 2;
      }
      else{
        aTqQ6rt8 = (Hjfu7Vx7 + zT28qSmp - 1) / 2;
      }
      if(aa1.getMaxVal(i+1,aTqQ6rt8+1) > x){
        zT28qSmp = aTqQ6rt8;
      }
      else{
        Hjfu7Vx7 = aTqQ6rt8 + 1;
      }
    }
    t =zT28qSmp;
    int ytthggxT;
    int O3U4gd88;
    int H31bcJ8S;
    ytthggxT = i+1;
    O3U4gd88 = N;
    while(ytthggxT < O3U4gd88){
      if((ytthggxT + O3U4gd88)%2==0){
        H31bcJ8S = (ytthggxT + O3U4gd88) / 2;
      }
      else{
        H31bcJ8S = (ytthggxT + O3U4gd88 - 1) / 2;
      }
      if(bb1.getMinVal(i+1,H31bcJ8S+1) < x){
        O3U4gd88 = H31bcJ8S;
      }
      else{
        ytthggxT = H31bcJ8S + 1;
      }
    }
    chmin(t, O3U4gd88);
    if(s > t){
      x = nx;
      y = ny;
      return 1;
    }
    return 0;
  }
  assert(0);
  return 0;
}
int main(){
  int i;
  wmem = memarr;
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;
  int nx1;
  int ny1;
  int nx2;
  int ny2;
  int tx;
  int ty;
  int k;
  rd(N);
  rd(M);
  {
    int o3WxPXbE;
    for(o3WxPXbE=(0);o3WxPXbE<(N);o3WxPXbE++){
      rd(K[o3WxPXbE]);
      rd(A1[o3WxPXbE]);
      rd(B1[o3WxPXbE]);
      rd(A2[o3WxPXbE]);
      rd(B2[o3WxPXbE]);
    }
  }
  aa1.walloc(N,1);
  for(i=(0);i<(N);i++){
    aa1.change(i,A1[i]);
  }
  aa2.walloc(N,1);
  for(i=(0);i<(N);i++){
    aa2.change(i,A2[i]);
  }
  bb1.walloc(N,1);
  for(i=(0);i<(N);i++){
    bb1.change(i,B1[i]);
  }
  bb2.walloc(N,1);
  for(i=(0);i<(N);i++){
    bb2.change(i,B2[i]);
  }
  for(i=(0);i<(N);i++){
    auto AAsEZMFe = ((-1));
    auto xtzQOlbs = (( -1));
    auto aFgbOQYS = (( -1));
    auto Oq6TK1Zh = (( -1));
    nx1=AAsEZMFe;
    ny1=xtzQOlbs;
    nx2=aFgbOQYS;
    ny2=Oq6TK1Zh;
    ok[0][i] = ok[1][i] = -1;
    if(x1 >= 0){
      tx = K[i];
      ty = y1;
      if(is_better(nx1,ny1,tx,ty,i)){
        ok[0][i] = 0;
      }
      tx = x1;
      ty = K[i];
      if(is_better(nx2,ny2,tx,ty,i)){
        ok[1][i] = 0;
      }
    }
    if(x2 >= 0){
      tx = K[i];
      ty = y2;
      if(is_better(nx1,ny1,tx,ty,i)){
        ok[0][i] = 1;
      }
      tx = x2;
      ty = K[i];
      if(is_better(nx2,ny2,tx,ty,i)){
        ok[1][i] = 1;
      }
    }
    auto jO2HaRTX = ((nx1));
    auto IlgsnSAd = (( ny1));
    auto jG1yfsum = (( nx2));
    auto NLJcSLph = (( ny2));
    x1=jO2HaRTX;
    y1=IlgsnSAd;
    x2=jG1yfsum;
    y2=NLJcSLph;
  }
  if(ok[0][N-1] == ok[1][N-1]  &&  ok[1][N-1] == -1){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  wt_L("Yes");
  wt_L('\n');
  if(ok[0][N-1] >= 0){
    k =0;
  }
  else{
    k =1;
  }
  for(i=(N)-1;i>=(0);i--){
    res[i] = k;
    k = ok[k][i];
  }
  {
    int EE5PwD1R;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(EE5PwD1R=(0);EE5PwD1R<(N-1);EE5PwD1R++){
        wt_L(res[EE5PwD1R]);
        wt_L(' ');
      }
      wt_L(res[EE5PwD1R]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210619-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M;
// int K[1d5], A1[1d5], B1[1d5], A2[1d5], B2[1d5];
// int ok[2][1d5], res[1d5];
// 
// segtree_Point_Maxval<int> aa1, aa2;
// segtree_Point_Minval<int> bb1, bb2;
// 
// int is_better(int &x, int &y, int nx, int ny, int i){
//   int s, t;
//   if(nx < A1[i] || nx > B1[i]) return 0;
//   if(ny < A2[i] || ny > B2[i]) return 0;
// 
//   if(x == -1){
//     x = nx;
//     y = ny;
//     return 1;
//   }
// 
//   if(x == nx == K[i]){
//     s = bsearch_min[int,k,i+1,N](aa2.getMaxVal(i+1,k+1) > ny);
//     s <?= bsearch_min[int,k,i+1,N](bb2.getMinVal(i+1,k+1) < ny);
//     t = bsearch_min[int,k,i+1,N](aa2.getMaxVal(i+1,k+1) > y);
//     t <?= bsearch_min[int,k,i+1,N](bb2.getMinVal(i+1,k+1) < y);
//     if(s > t){
//       x = nx;
//       y = ny;
//       return 1;
//     }
//     return 0;
//   }
// 
//   if(y == ny == K[i]){
//     s = bsearch_min[int,k,i+1,N](aa1.getMaxVal(i+1,k+1) > nx);
//     s <?= bsearch_min[int,k,i+1,N](bb1.getMinVal(i+1,k+1) < nx);
//     t = bsearch_min[int,k,i+1,N](aa1.getMaxVal(i+1,k+1) > x);
//     t <?= bsearch_min[int,k,i+1,N](bb1.getMinVal(i+1,k+1) < x);
//     if(s > t){
//       x = nx;
//       y = ny;
//       return 1;
//     }
//     return 0;
//   }
// 
//   assert(0);
//   return 0;
// }
// 
// {
//   int x1 = 0, y1 = 0, x2 = 0, y2 = 0, nx1, ny1, nx2, ny2, tx, ty, k;
//   rd(N,M,(K,A1,B1,A2,B2)(N));
//   aa1.walloc(N,1); rep(i,N) aa1.change(i,A1[i]);
//   aa2.walloc(N,1); rep(i,N) aa2.change(i,A2[i]);
//   bb1.walloc(N,1); rep(i,N) bb1.change(i,B1[i]);
//   bb2.walloc(N,1); rep(i,N) bb2.change(i,B2[i]);
//   rep(i,N){
//     // wt(i,":",x1,y1,":",x2,y2);
//     (nx1, ny1, nx2, ny2) = (-1, -1, -1, -1);
//     ok[0][i] = ok[1][i] = -1;
//     if(x1 >= 0){
//       tx = K[i]; ty = y1;
//       if(is_better(nx1,ny1,tx,ty,i)) ok[0][i] = 0;
//       tx = x1; ty = K[i];
//       if(is_better(nx2,ny2,tx,ty,i)) ok[1][i] = 0;
//     }
//     if(x2 >= 0){
//       tx = K[i]; ty = y2;
//       if(is_better(nx1,ny1,tx,ty,i)) ok[0][i] = 1;
//       tx = x2; ty = K[i];
//       if(is_better(nx2,ny2,tx,ty,i)) ok[1][i] = 1;
//     }
//     (x1, y1, x2, y2) = (nx1, ny1, nx2, ny2);
//   }
//   // wt(i,":",x1,y1,":",x2,y2);
//   if(ok[0][N-1] == ok[1][N-1] == -1) wt("No"), return 0;
// 
//   wt("Yes");
//   k = if[ok[0][N-1] >= 0, 0, 1];
//   rrep(i,N){
//     res[i] = k;
//     k = ok[k][i];
//   }
//   wt(res(N));
// }