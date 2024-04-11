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
int TP;
int D;
int ls;
multiset<long long> m1up;
multiset<long long> m2up;
multiset<long long> m1dw;
multiset<long long> m2dw;
long long res;
void add(long long x, int tp){
  res += x;
  if(tp==0){
    m1dw.insert(x);
  }
  if(tp==1){
    m2dw.insert(x);
  }
}
void del(long long x, int tp){
  multiset<long long>::iterator it;
  if(tp==0){
    it = m1up.find(x);
    if(it!=m1up.end()){
      res -= 2 * x;
      m1up.erase(it);
      return;
    }
    it = m1dw.find(x);
    res -= x;
    m1dw.erase(it);
  }
  else{
    it = m2up.find(x);
    if(it!=m2up.end()){
      res -= 2 * x;
      m2up.erase(it);
      return;
    }
    it = m2dw.find(x);
    res -= x;
    m2dw.erase(it);
  }
}
void ord(void){
  long long v1;
  long long v2;
  if(m1up.size()){
    v1 = *m1up.begin();
    m1up.erase(m1up.find(v1));
    m1dw.insert(v1);
    res -= v1;
  }
  if(m2up.size()){
    v2 = *m2up.begin();
    m2up.erase(m2up.find(v2));
    m2dw.insert(v2);
    res -= v2;
  }
  while(m2up.size() + m2dw.size() > m1up.size() + m2up.size()){
    if(m1dw.size()){
      v1 =*m1dw.rbegin();
    }
    else{
      v1 =-4611686016279904256LL;
    }
    if(m2dw.size() > 1){
      v2 =*m2dw.rbegin();
    }
    else{
      v2 =-4611686016279904256LL;
    }
    if(v1==v2 && v2==-4611686016279904256LL){
      break;
    }
    if(v1 > v2){
      m1up.insert(v1);
      m1dw.erase(m1dw.find(v1));
      res += v1;
    }
    else{
      m2up.insert(v2);
      m2dw.erase(m2dw.find(v2));
      res += v2;
    }
  }
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    rd(TP);
    rd(D);
    if(D < 0){
      del(-D, TP);
    }
    if(D > 0){
      add(D, TP);
    }
    ord();
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int TP, D;
// 
// int ls;
// multiset<ll> m1up, m2up, m1dw, m2dw;
// ll res;
// 
// void add(ll x, int tp){
//   res += x;
//   if(tp==0) m1dw.insert(x);
//   if(tp==1) m2dw.insert(x);
// }
// 
// void del(ll x, int tp){
//   multiset<ll>::iterator it;
//   if(tp==0){
//     it = m1up.find(x);
//     if(it!=m1up.end()){
//       res -= 2 * x;
//       m1up.erase(it);
//       return;
//     }
//     it = m1dw.find(x);
//     res -= x;
//     m1dw.erase(it);
//   } else {
//     it = m2up.find(x);
//     if(it!=m2up.end()){
//       res -= 2 * x;
//       m2up.erase(it);
//       return;
//     }
//     it = m2dw.find(x);
//     res -= x;
//     m2dw.erase(it);
//   }
// }
// 
// void ord(void){
//   ll v1, v2;
// 
//   if(m1up.size()){
//     v1 = *m1up.begin();
//     m1up.erase(m1up.find(v1));
//     m1dw.insert(v1);
//     res -= v1;
//   }
// 
//   if(m2up.size()){
//     v2 = *m2up.begin();
//     m2up.erase(m2up.find(v2));
//     m2dw.insert(v2);
//     res -= v2;
//   }
// 
//   while(m2up.size() + m2dw.size() > m1up.size() + m2up.size()){
//     v1 = if[m1dw.size(), *m1dw.rbegin(), -ll_inf];
//     v2 = if[m2dw.size() > 1, *m2dw.rbegin(), -ll_inf];
//     if(v1==v2==-ll_inf) break;
//     if(v1 > v2){
//       m1up.insert(v1);
//       m1dw.erase(m1dw.find(v1));
//       res += v1;
//     } else {
//       m2up.insert(v2);
//       m2dw.erase(m2dw.find(v2));
//       res += v2;
//     }
//   }
// }
// 
// {
// 
//   REP(rd_int()){
//     rd(TP,D);
//     if(D < 0) del(-D, TP);
//     if(D > 0) add(D, TP);
//     ord();
//     wt(res);
//   }
// }