#pragma GCC optimize ("Ofast")
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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
int M;
int X[300000+2];
char D[300000+2];
int res[300000+2];
int s1;
int xx1[300000+2];
int ind1[300000+2];
int s2;
int xx2[300000+2];
int ind2[300000+2];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int o;
    int i;
    int j;
    int k;
    int x;
    int y;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(X[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(N);xr20shxY++){
        rd(D[xr20shxY]);
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(o=(0);o<(2);o++){
      s1 = s2 = 0;
      for(i=(0);i<(N);i++){
        if(X[i]%2==o){
          if(D[i] == 'R'){
            arrInsert(s1, s1, xx1, X[i], ind1, i);
          }
          if(D[i] == 'L'){
            arrInsert(s2, s2, xx2, X[i], ind2, i);
          }
        }
      }
      sortA_L(s1, xx1, ind1);
      sortA_L(s2, xx2, ind2);
      set<pair<int,int>> ss;
      set<pair<int,int>>::iterator it;
      for(i=(0);i<(s2);i++){
        ss.insert({xx2[i], ind2[i]});
      }
      for(i=(s1)-1;i>=(0);i--){
        it = ss.lower_bound({xx1[i], -1});
        if(it == ss.end()){
          continue;
        }
        res[ind1[i]] = res[it->second] = (it->first - xx1[i]) / 2;
        xx1[i] = -1;
        ss.erase(it);
      }
      k = s1;
      s1 = 0;
      for(i=(0);i<(k);i++){
        if(xx1[i] != -1){
          arrInsert(s1, s1, xx1, M - xx1[i], ind1, ind1[i]);
        }
      }
      s2 = 0;
      for(auto [a,b] : ss){
        arrInsert(s2, s2, xx2, a, ind2, b);
      }
      rsortA_L(s1, xx1, ind1);
      rsortA_L(s2, xx2, ind2);
      while(s1 >= 2){
        x = xx1[s1-1];
        y = xx1[s1-2];
        res[ind1[s1-1]] = res[ind1[s1-2]] = x + (y-x) / 2;
        s1 -= 2;
      }
      while(s2 >= 2){
        x = xx2[s2-1];
        y = xx2[s2-2];
        res[ind2[s2-1]] = res[ind2[s2-2]] = x + (y-x) / 2;
        s2 -= 2;
      }
      if(s1 && s2){
        res[ind1[0]] = res[ind2[0]] = (xx1[0] + xx2[0] + M) / 2;
      }
    }
    {
      int gEg5UqEA;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(gEg5UqEA=(0);gEg5UqEA<(N-1);gEg5UqEA++){
          wt_L(res[gEg5UqEA]);
          wt_L(' ');
        }
        wt_L(res[gEg5UqEA]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210508-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M, X[3d5+2];
// char D[];
// int res[];
// 
// int s1, xx1[], ind1[];
// int s2, xx2[], ind2[];
// 
// {
//   REP(rd_int()){
//     int i, j, k, x, y;
//     rd(N,M,X(N),D(N));
//     rep(i,N) res[i] = -1;
// 
//     rep(o,2){
//       s1 = s2 = 0;
//       rep(i,N) if(X[i]%2==o){
//         if(D[i] == 'R') arrInsert(s1, s1, xx1, X[i], ind1, i);
//         if(D[i] == 'L') arrInsert(s2, s2, xx2, X[i], ind2, i);
//       }
//       sortA(s1, xx1, ind1);
//       sortA(s2, xx2, ind2);
//       set<pair<int,int>> ss;
//       set<pair<int,int>>::iterator it;
//       rep(i,s2) ss.insert({xx2[i], ind2[i]});
//       rrep(i,s1){
//         it = ss.lower_bound({xx1[i], -1});
//         if(it == ss.end()) continue;
//         res[ind1[i]] = res[it->second] = (it->first - xx1[i]) / 2;
//         xx1[i] = -1;
//         ss.erase(it);
//       }
//       k = s1; s1 = 0;
//       rep(i,k) if(xx1[i] != -1) arrInsert(s1, s1, xx1, M - xx1[i], ind1, ind1[i]);
//       s2 = 0;
//       for(auto [a,b] : ss) arrInsert(s2, s2, xx2, a, ind2, b);
//       rsortA(s1, xx1, ind1);
//       rsortA(s2, xx2, ind2);
//       while(s1 >= 2){
//         x = xx1[s1-1];
//         y = xx1[s1-2];
//         res[ind1[s1-1]] = res[ind1[s1-2]] = x + (y-x) / 2;
//         s1 -= 2;
//       }
//       while(s2 >= 2){
//         x = xx2[s2-1];
//         y = xx2[s2-2];
//         res[ind2[s2-1]] = res[ind2[s2-2]] = x + (y-x) / 2;
//         s2 -= 2;
//       }
//       if(s1 && s2){
//         res[ind1[0]] = res[ind2[0]] = (xx1[0] + xx2[0] + M) / 2;
//       }
//     }
// 
//     wt(res(N));
//   }
// }