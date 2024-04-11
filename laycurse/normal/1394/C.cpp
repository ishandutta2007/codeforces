#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[300000];
int B[300000];
char tmp[500000+2];
long long dist(int a, int b){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i] >= a && B[i] >= b){
      chmax(res, max_L(A[i]-a, B[i]-b));
      continue;
    }
    if(A[i] <= a && B[i] <= b){
      chmax(res, max_L(a-A[i], b-B[i]));
      continue;
    }
    chmax(res, abs(A[i]-a) + abs(B[i]-b));
  }
  return res;
}
int main(){
  int i;
  int j;
  int k;
  int len;
  int step;
  int ca = 0;
  int cb = 0;
  int ta;
  int tb;
  int cc;
  int tc;
  Rand rnd;
  rd(N);
  for(i=(0);i<(N);i++){
    len = rd(tmp);
    for(j=(0);j<(len);j++){
      if(tmp[j]=='B'){
        A[i]++;
      }
      else{
        B[i]++;
      }
    }
  }
  ca++;
  cc = dist(ca, cb);
  for(step=1<<20;step;step/=2){
    int KrdatlYV;
    for(KrdatlYV=(0);KrdatlYV<(6);KrdatlYV++){
      int da;
      for(da=(-1);da<(2);da++){
        int db;
        for(db=(-1);db<(2);db++){
          ta =max_L(0, ca + da * step);
          tb =max_L(0, cb + db * step);
          if(ta==0 && tb==0){
            continue;
          }
          if(ta==ca && tb==cb){
            continue;
          }
          tc = dist(ta, tb);
          if(tc < cc){
            {
              auto jbtyPBGc = (ta);
              auto ZIeRIny5 = ( tb);
              auto iMWUTgY_ = ( tc);
              ca = jbtyPBGc;
              cb = ZIeRIny5;
              cc = iMWUTgY_;
            }
            continue;
          }
          if(tc == cc && rnd.get(10000) < 5000){
            {
              auto AlM5nNnR = (ta);
              auto XJIcIBrW = ( tb);
              auto jPV_0s1p = ( tc);
              ca = AlM5nNnR;
              cb = XJIcIBrW;
              cc = jPV_0s1p;
            }
            continue;
          }
        }
      }
    }
  }
  wt_L(cc);
  wt_L('\n');
  for(i=(0);i<(ca);i++){
    wt_L('B');
  }
  for(i=(0);i<(cb);i++){
    wt_L('N');
  }
  wt_L("");
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[3d5], B[3d5];
// char tmp[5d5+2];
// 
// ll dist(int a, int b){
//   int res = 0;
//   rep(i,N){
//     if(A[i] >= a && B[i] >= b) res >?= max(A[i]-a, B[i]-b), continue;
//     if(A[i] <= a && B[i] <= b) res >?= max(a-A[i], b-B[i]), continue;
//     res >?= abs(A[i]-a) + abs(B[i]-b);
//   }
//   return res;
// }
// 
// {
//   int i, j, k, len, step;
//   int ca = 0, cb = 0, ta, tb;
//   int cc, tc;
//   Rand rnd;
// 
//   rd(N);
//   rep(i,N){
//     rd(tmp@len);
//     rep(j,len) if[tmp[j]=='B', A[i], B[i]]++;
//   }
// 
//   ca++;
//   cc = dist(ca, cb);
//   for(step=1<<20;step;step/=2) rep(6){
//     rep(da,-1,2) rep(db,-1,2){
//       ta = max(0, ca + da * step);
//       tb = max(0, cb + db * step);
//       if(ta==0 && tb==0) continue;
//       if(ta==ca && tb==cb) continue;
//       tc = dist(ta, tb);
//       if(tc < cc) (ca, cb, cc) = (ta, tb, tc), continue;
//       if(tc == cc && rnd.get(10000) < 5000) (ca, cb, cc) = (ta, tb, tc), continue;
//     }
//   }
//   wt(cc);
//   rep(i,ca) wtN('B');
//   rep(i,cb) wtN('N');
//   wt("");
// }