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
inline void rd(long long &x){
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> inline T popLast(multiset<T> &a){
  T res;
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T popLast(set<T> &a){
  T res;
  typename set<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int N;
    rd(N);
    long long A[N];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);
      }
    }
    long long t;
    multiset<long long> s;
    int YGwFZBGH;
    cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type OA9NF42T;
    if(N==0){
      OA9NF42T = 0;
    }
    else{
      OA9NF42T = A[0];
      for(YGwFZBGH=(1);YGwFZBGH<(N);YGwFZBGH++){
        OA9NF42T += A[YGwFZBGH];
      }
    }
    s.insert(OA9NF42T);
    sortA_L(N,A);
    while(N){
      t = popLast(s);
      if(A[N-1] == t){
        N--;
        continue;
      }
      if(A[N-1] > t){
        wt_L("NO");
        wt_L('\n');
        goto WKqLrJHZ;
      }
      s.insert(t/2);
      s.insert((divup_L(t,2)));
    }
    wt_L("YES");
    wt_L('\n');
    WKqLrJHZ:;
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220312-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N; ll @A[N], t;
//   multiset<ll> s;
//   s.insert(sum(A(N)));
//   sortA(N,A);
//   while(N){
//     t = popLast(s);
//     if(A[N-1] == t) N--, continue;
//     if(A[N-1] > t) wt("NO"), break_continue;
//     s.insert(t/2);
//     s.insert(t/+2);
//   }
//   wt("YES");
// }