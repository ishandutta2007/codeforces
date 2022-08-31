#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool*isprime;
  int*sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
int N;
int ps;
int p[100000];
int sz;
int arr[100000+1];
int cs;
int cand[100000];
void dodel(int k){
  int i;
  for(i=(k);i<(N+1);i+=(k)){
    sz -= arr[i];
    arr[i] = 0;
  }
}
int doget(int k){
  int i;
  int res = 0;
  for(i=(k);i<(N+1);i+=(k)){
    res += arr[i];
  }
  return res;
}
int queryA(int k){
  wt_L("A");
  wt_L(' ');
  wt_L(k);
  wt_L('\n');
  return rd_int();
}
int queryB(int k){
  dodel(k);
  wt_L("B");
  wt_L(' ');
  wt_L(k);
  wt_L('\n');
  return rd_int();
}
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int res = 1;
  int b = 100;
  int st;
  int ed;
  rd(N);
  if(N==1){
    wt_L("C");
    wt_L(' ');
    wt_L(1);
    wt_L('\n');
    return 0;
  }
  ps =Prime_L(N+1, p);
  for(i=(1);i<(N+1);i++){
    sz++;
    arr[i] = 1;
  }
  for(i=(0);i<(ps);i++){
    if((long long) p[i] * p[i] > N){
      break;
    }
    queryB(p[i]);
  }
  k = queryA(1);
  if(k == sz){
    for(i=(0);i<(ps);i++){
      if((long long) p[i] * p[i] <= N){
        continue;
      }
      cand[cs++] = p[i];
    }
    for(st=(0);st<(cs);st+=(b)){
      ed =min_L(st + b, cs);
      for(i=(st);i<(ed);i++){
        queryB(cand[i]);
      }
      k = queryA(1);
      if(k == sz){
        continue;
      }
      for(i=(st);i<(ed);i++){
        if(queryA(cand[i]) == 1){
          res = cand[i];
          goto ao_dF3pO;
        }
      }
    }
    ao_dF3pO:;
  }
  else{
    for(i=(0);i<(ps);i++){
      j = 1;
      while( (long long)j*p[i] <= N ){
        if(doget(j*p[i]) == queryA(j*p[i])){
          break;
        }
        j *= p[i];
      }
      res *= j;
    }
  }
  wt_L("C");
  wt_L(' ');
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200913-1

// --- original code ---
// //interactive
// int N;
// int ps, p[1d5];
// int sz, arr[1d5+1];
// int cs, cand[1d5];
// 
// void dodel(int k){
//   rep(i,k,N+1,k) sz -= arr[i], arr[i] = 0;
// }
// int doget(int k){
//   int res = 0;
//   rep(i,k,N+1,k) res += arr[i];
//   return res;
// }
// int queryA(int k){
//   wt("A", k);
//   return rd_int();
// }
// int queryB(int k){
//   dodel(k);
//   wt("B", k);
//   return rd_int();
// }
// 
// {
//   int i, j, k, res = 1, b = 100, st, ed;
//   rd(N);
//   if(N==1) wt("C", 1), return 0;
// 
//   ps = Prime(N+1, p);
//   rep(i,1,N+1) sz++, arr[i] = 1;
// 
//   rep(i,ps){
//     if((ll) p[i] * p[i] > N) break;
//     queryB(p[i]);
//   }
//   k = queryA(1);
// 
//   if(k == sz){
//     rep(i,ps){
//       if((ll) p[i] * p[i] <= N) continue;
//       cand[cs++] = p[i];
//     }
//     rep(st,0,cs,b){
//       ed = min(st + b, cs);
//       rep(i,st,ed) queryB(cand[i]);
//       k = queryA(1);
//       if(k == sz) continue;
//       rep(i,st,ed) if(queryA(cand[i]) == 1) res = cand[i], break_break;
//     }
//   } else {
//     rep(i,ps){
//       j = 1;
//       while( (ll)j*p[i] <= N ){
//         if(doget(j*p[i]) == queryA(j*p[i])) break;
//         j *= p[i];
//       }
//       res *= j;
//     }
//   }
// 
//   wt("C", res);
// }