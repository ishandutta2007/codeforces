#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
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
int X;
set<long long> s;
int ress;
long long res1[100000];
long long res2[100000];
char op[100000];
int main(){
  int i;
  long long mn_bt = 4611686016279904256LL;
  long long ta;
  long long tb;
  long long tc;
  long long bt;
  char top;
  rd(X);
  s.insert(X);
  for(;;){
    long long mx = 4611686016279904256LL;
    long long bc = 4611686016279904256LL;
    long long tmx;
    long long tbc;
    for(long long a : s){
      for(long long b : s){
        if(b > a){
          break;
        }
        if(a < 10000000000000LL && b < 10000000000000LL && s.find((a+b)%mn_bt) == s.end()){
          tmx = (a + b) % mn_bt;
          tbc =BIT_popcount_L(tmx);
          if(tmx > 0 && (bc > tbc || (bc==tbc && mx > tmx))){
            mx = tmx;
            bc = tbc;
            ta = a;
            tb = b;
            top = '+';
          }
        }
        if(a < 10000000000000LL && b < 10000000000000LL && s.find((a^b)%mn_bt) == s.end()){
          tmx = (a ^ b) % mn_bt;
          tbc =BIT_popcount_L(tmx);
          if(tmx > 0 && (bc > tbc || (bc==tbc && mx > tmx))){
            mx = tmx;
            bc = tbc;
            ta = a;
            tb = b;
            top = '^';
          }
        }
      }
    }
    arrInsert(ress, ress, res1, ta, res2, tb, op, top);
    if(top=='+'){
      tc = ta + tb;
    }
    if(top=='^'){
      tc = ta ^ tb;
    }
    for(bt = mn_bt; bt < 4611686016279904256LL; bt *= 2){
      if(tc & bt){
        arrInsert(ress, ress, res1, tc, res2, bt, op, '^');
        tc ^= bt;
      }
    }
    s.insert(mx);
    if(mx==1){
      break;
    }
    if(bc==1){
      mn_bt = mx;
      while(mx < 20000000000000LL){
        if(s.find(2*mx) != s.end()){
          break;
        }
        arrInsert(ress, ress, res1, mx, res2, mx, op, '+');
        mx *= 2;
      }
    }
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]);
    wt_L(' ');
    wt_L(op[i]);
    wt_L(' ');
    wt_L(res2[i]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int X;
// set<ll> s;
// int ress; ll res1[1d5], res2[1d5]; char op[1d5];
// 
// {
//   ll mn_bt = ll_inf;
//   ll ta, tb, tc, bt; char top;
//   rd(X);
//   s.insert(X);
//   for(;;){
//     ll mx = ll_inf, bc = ll_inf;
//     ll tmx, tbc;
//     for(ll a : s) for(ll b : s){
//       if(b > a) break;
//       if(a < 1d13 && b < 1d13 && s.find((a+b)%mn_bt) == s.end()){
//         tmx = (a + b) % mn_bt;
//         tbc = BIT_popcount(tmx);
//         if(tmx > 0 && (bc > tbc || (bc==tbc && mx > tmx))){
//           mx = tmx;
//           bc = tbc;
//           ta = a;
//           tb = b;
//           top = '+';
//         }
//       }
//       if(a < 1d13 && b < 1d13 && s.find((a^b)%mn_bt) == s.end()){
//         tmx = (a ^ b) % mn_bt;
//         tbc = BIT_popcount(tmx);
//         if(tmx > 0 && (bc > tbc || (bc==tbc && mx > tmx))){
//           mx = tmx;
//           bc = tbc;
//           ta = a;
//           tb = b;
//           top = '^';
//         }
//       }
//     }
// 
//     arrInsert(ress, ress, res1, ta, res2, tb, op, top);
//     if(top=='+') tc = ta + tb;
//     if(top=='^') tc = ta ^ tb;
//     for(bt = mn_bt; bt < ll_inf; bt *= 2) if(tc & bt){
//       arrInsert(ress, ress, res1, tc, res2, bt, op, '^');
//       tc ^= bt;
//     }
// 
//     s.insert(mx);
//     if(mx==1) break;
// //    printf("%lld %lld %lld %lld %d\n",mx,tc,bc,mn_bt,s.size());
// 
//     if(bc==1){
//       mn_bt = mx;
//       while(mx < 2d13){
//         if(s.find(2*mx) != s.end()) break;
//         arrInsert(ress, ress, res1, mx, res2, mx, op, '+');
//         mx *= 2;
//       }
//     }
//   }
// 
//   wt(ress);
//   rep(i,ress) wt(res1[i], op[i], res2[i]);
// }