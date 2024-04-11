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
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int A[100000+2];
int pr[100000+2];
int nx[100000+2];
int ress;
int res[100000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int st = 0;
    set<int> s;
    set<int>::iterator it;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      pr[i] =(moddw_L((i-1),N));
    }
    for(i=(0);i<(N);i++){
      nx[i] =(moddw_L((i+1),N));
    }
    st = nx[0];
    ress = 0;
    for(i=(0);i<(N);i++){
      if(GCD_L(A[pr[i]], A[i])== 1){
        s.insert(i);
      }
    }
    while(s.size()){
      it = s.lower_bound(st);
      if(it == s.end()){
        it = s.begin();
      }
      st = *it;
      s.erase(it);
      if(GCD_L(A[pr[st]], A[st])!= 1){
        continue;
      }
      res[ress++] = st;
      if(nx[st] == st){
        break;
      }
      nx[pr[st]] = nx[st];
      pr[nx[st]] = pr[st];
      st = nx[st];
      if(GCD_L(A[pr[st]], A[st])== 1){
        s.insert(st);
      }
      st = nx[st];
    }
    wt_L(ress);
    wt_L(' ');
    {
      int jZyWAPpY;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(jZyWAPpY=(0);jZyWAPpY<(ress-1);jZyWAPpY++){
          wt_L(res[jZyWAPpY]+ 1);
          wt_L(' ');
        }
        wt_L(res[jZyWAPpY]+ 1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[1d5+2], pr[], nx[];
// int ress, res[];
// {
//   REP(rd_int()){
//     int i, j, k, st = 0;
//     set<int> s;
//     set<int>::iterator it;
//     rd(N,A(N));
//     rep(i,N) pr[i] = (i-1)%%N;
//     rep(i,N) nx[i] = (i+1)%%N;
// 
//     st = nx[0];
//     ress = 0;
//     rep(i,N) if(gcd(A[pr[i]], A[i]) == 1) s.insert(i);
//     while(s.size()){
//       it = s.lower_bound(st);
//       if(it == s.end()) it = s.begin();
//       st = *it;
//       s.erase(it);
//       if(gcd(A[pr[st]], A[st]) != 1) continue;
// 
//       res[ress++] = st;
//       if(nx[st] == st) break;
//       nx[pr[st]] = nx[st];
//       pr[nx[st]] = pr[st];
// 
//       st = nx[st];
//       if(gcd(A[pr[st]], A[st]) == 1) s.insert(st);
//       st = nx[st];
//     }
// 
//     wt(ress, res(ress) + 1);
//   }
// }