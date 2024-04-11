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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int mode = 0;
int X1;
int Y1;
int X2;
int Y2;
int ttm;
int qs;
int qx[100000];
int qy[100000];
int query(void){
  int res;
  ttm++;
  if(mode == 0){
    int i;
    wt_L("?");
    wt_L(' ');
    wt_L(qs);
    wt_L('\n');
    for(i=(0);i<(qs);i++){
      if(i){
        wt_L(" ");
      }
      wt_L(qx[i]+1);
      wt_L(" ");
      wt_L(qy[i]+1);
    }
    wt_L("");
    wt_L('\n');
    rd(res);
  }
  if(mode == 1){
    int i;
    res = 0;
    for(i=(0);i<(qs);i++){
      if(X1 <= qx[i]  &&  qx[i] <= X2 && Y1 <= qy[i]  &&  qy[i] <= Y2){
        res++;
      }
    }
  }
  return res;
}
void ans(int res){
  if(mode == 0){
    wt_L("!");
    wt_L(' ');
    wt_L(res);
    wt_L('\n');
  }
  else{
    int t;
    t = 2 * (X2 - X1 + Y2 - Y1);
    wt_L(res);
    wt_L(' ');
    wt_L(t);
    wt_L(' ');
    wt_L(ttm);
    wt_L('\n');
    ttm = 0;
    assert(res==t && ttm <= 4);
  }
}
int cnt[40001];
int ls[40001];
void solve(){
  int i;
  int j;
  int k;
  int s;
  int sz;
  int dx[1000];
  int dy[1000];
  int mx;
  int d;
  int xx;
  int opt_d;
  int opt_xx;
  int tmp;
  int x1;
  int x2;
  int y;
  qs = 0;
  for(i=(0);i<(200);i++){
    for(j=(0);j<(200);j++){
      arrInsert(qs, qs, qx, i, qy, j);
    }
  }
  s = query();
  sz = 0;
  for(i=(2);i<(201);i++){
    if(s%i==0 && s/i <= 200){
      arrInsert(sz, sz, dx, i, dy, s/i);
    }
  }
  while(sz > 1){
    mx = 1073709056;
    for(d=(0);d<(2);d++){
      for(xx=(2);xx<(201);xx++){
        for(i=(0);i<(40001);i++){
          cnt[i] = 0;
        }
        for(i=(0);i<(sz);i++){
          if(d==0){
            x1 = dx[i] / xx;
            x2 =(divup_L(dx[i],xx));
            y = dy[i];
          }
          if(d==1){
            x1 = dy[i] / xx;
            x2 =(divup_L(dy[i],xx));
            y = dx[i];
          }
          cnt[x1*y]++;
          if(x2!=x1){
            cnt[x2*y]++;
          }
        }
        int ZIeRIny5;
        cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type iMWUTgY_;
        if(40001==0){
          iMWUTgY_ = 0;
        }
        else{
          iMWUTgY_ = cnt[0];
          for(ZIeRIny5=(1);ZIeRIny5<(40001);ZIeRIny5++){
            iMWUTgY_ = max_L(iMWUTgY_, cnt[ZIeRIny5]);
          }
        }
        tmp =iMWUTgY_;
        if(mx > tmp){
          mx = tmp;
          opt_d = d;
          opt_xx = xx;
        }
      }
    }
    d = opt_d;
    xx = opt_xx;
    qs = 0;
    for(i=(0);i<(200);i++){
      for(j=(0);j<(200);j++){
        if(d==0 && i%xx){
          continue;
        }
        if(d==1 && j%xx){
          continue;
        }
        arrInsert(qs, qs, qx, i, qy, j);
      }
    }
    s = query();
    k = 0;
    for(i=(0);i<(sz);i++){
      if(d==0){
        x1 = dx[i] / xx;
        x2 =(divup_L(dx[i],xx));
        y = dy[i];
      }
      if(d==1){
        x1 = dy[i] / xx;
        x2 =(divup_L(dy[i],xx));
        y = dx[i];
      }
      if(x1*y==s || x2*y==s){
        arrInsert(k, k, dx, dx[i], dy, dy[i]);
      }
    }
    sz = k;
  }
  ans(2*(dx[0]-1+dy[0]-1));
}
int main(){
  int Hjfu7Vx7;
  solve();
  return 0;
  for(Hjfu7Vx7=(0);Hjfu7Vx7<(10000);Hjfu7Vx7++){
    X1 = rand()%199;
    X2 = rand()%199;
    Y1 = rand()%199;
    Y2 = rand()%199;
    if(X1 > X2){
      swap(X1, X2);
    }
    ;
    if(Y1 > Y2){
      swap(Y1, Y2);
    }
    ;
    X2++;
    Y2++;
    solve();
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //interactive
// int mode = 0;
// 
// int X1, Y1, X2, Y2, ttm;
// 
// int qs, qx[1d5], qy[1d5];
// int query(void){
//   int res;
//   ttm++;
//   if(mode == 0){
//     wt("?", qs);
//     rep(i,qs){
//       if(i) wtN(" ");
//       wtN(qx[i]+1, " ", qy[i]+1);
//     }
//     wt("");
//     rd(res);
//   }
//   if(mode == 1){
//     res = 0;
//     rep(i,qs) if(X1 <= qx[i] <= X2 && Y1 <= qy[i] <= Y2) res++;
//   }
//   return res;
// }
// 
// void ans(int res){
//   if(mode == 0){
//     wt("!",res);
//   } else {
//     int t;
//     t = 2 * (X2 - X1 + Y2 - Y1);
//     wt(res, t, ttm);
//     ttm = 0;
//     assert(res==t && ttm <= 4);
//   }
// }
// 
// 
// int cnt[40001], ls[40001];
// void solve(){
//   int i, j, k, s;
//   int sz, dx[1000], dy[1000];
//   int mx, d, xx, opt_d, opt_xx, tmp, x1, x2, y;
// 
//   qs = 0;
//   rep(i,200) rep(j,200) arrInsert(qs, qs, qx, i, qy, j);
//   s = query();
// 
//   sz = 0;
//   rep(i,2,201) if(s%i==0 && s/i <= 200) arrInsert(sz, sz, dx, i, dy, s/i);
// 
//   while(sz > 1){
//     // rep(i,sz) wt(i,":",dx[i],dy[i]);
//     mx = int_inf;
//     rep(d,2) rep(xx,2,201){
//       rep(i,40001) cnt[i] = 0;
//       rep(i,sz){
//         if(d==0) x1 = dx[i] / xx, x2 = dx[i] /+ xx, y = dy[i];
//         if(d==1) x1 = dy[i] / xx, x2 = dy[i] /+ xx, y = dx[i];
//         cnt[x1*y]++;
//         if(x2!=x1) cnt[x2*y]++;
//       }
//       tmp = max(cnt(40001));
//       if(mx > tmp){
//         mx = tmp;
//         opt_d = d;
//         opt_xx = xx;
//       }
//     }
//     d = opt_d;
//     xx = opt_xx;
// 
//     qs = 0;
//     rep(i,200) rep(j,200){
//       if(d==0 && i%xx) continue;
//       if(d==1 && j%xx) continue;
//       arrInsert(qs, qs, qx, i, qy, j);
//     }
//     s = query();
// 
//     k = 0;
//     rep(i,sz){
//       if(d==0) x1 = dx[i] / xx, x2 = dx[i] /+ xx, y = dy[i];
//       if(d==1) x1 = dy[i] / xx, x2 = dy[i] /+ xx, y = dx[i];
//       if(x1*y==s || x2*y==s) arrInsert(k, k, dx, dx[i], dy, dy[i]);
//     }
//     sz = k;
//   }
// 
//   ans(2*(dx[0]-1+dy[0]-1));
// }
// 
// {
//   solve();
//   return 0;
//   rep(10000){
//     X1 = rand()%199;
//     X2 = rand()%199;
//     Y1 = rand()%199;
//     Y2 = rand()%199;
//     sortE(X1,X2);
//     sortE(Y1,Y2);
//     X2++;
//     Y2++;
//     solve();
//   }
// }