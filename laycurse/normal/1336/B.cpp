#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class T> inline T pow2_L(T a){
  return a*a;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int sz[3];
long long *arr[3];
inline long long ev(long long a, long long b, long long c){
  return (pow2_L((a-b)))+(pow2_L((b-c)))+(pow2_L((c-a)));
}
int main(){
  int Q5VJL1cS, i;
  wmem = memarr;
  for(i=(0);i<(3);i++){
    walloc1d(&arr[i], 100000);
  }
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    long long res = 4611686016279904256LL;
    long long cur;
    long long tmp;
    {
      int FmcKpFmN;
      for(FmcKpFmN=(0);FmcKpFmN<(3);FmcKpFmN++){
        rd(sz[FmcKpFmN]);
      }
    }
    for(i=(0);i<(3);i++){
      {
        int ao_dF3pO;
        for(ao_dF3pO=(0);ao_dF3pO<(sz[i]);ao_dF3pO++){
          rd(arr[i][ao_dF3pO]);
        }
      }
    }
    for(i=(0);i<(3);i++){
      sortA_L(sz[i], arr[i]);
    }
    while(sz[0] && sz[1] && sz[2]){
      if(arr[0][sz[0]-1] < arr[1][sz[1]-1]){
        swap(sz[0],sz[1]);
        swap(arr[0],arr[1]);
      }
      if(arr[1][sz[1]-1] < arr[2][sz[2]-1]){
        swap(sz[1],sz[2]);
        swap(arr[1],arr[2]);
      }
      if(arr[0][sz[0]-1] < arr[1][sz[1]-1]){
        swap(sz[0],sz[1]);
        swap(arr[0],arr[1]);
      }
      cur = ev(arr[0][sz[0]-1], arr[1][sz[1]-1], arr[2][sz[2]-1]);
      chmin(res, cur);
      if(sz[1] >= 2){
        tmp = ev(arr[0][sz[0]-1], arr[1][sz[1]-2], arr[2][sz[2]-1]);
        if(tmp <= cur){
          sz[1]--;
          continue;
        }
      }
      sz[0]--;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200418-1

// --- original code ---
// //no-unlocked
// int sz[3]; ll *arr[3];
// 
// inline ll ev(ll a, ll b, ll c){
//   return (a-b) ** 2 + (b-c) ** 2 + (c-a) ** 2;
// }
// 
// {
//   rep(i,3) walloc1d(&arr[i], 1d5);
//   REP(rd_int()){
//     ll res = ll_inf, cur, tmp;
//     rd(sz(3));
//     rep(i,3) rd(arr[i](sz[i]));
//     rep(i,3) sortA(sz[i], arr[i]);
// 
//     while(sz[0] && sz[1] && sz[2]){
//       if(arr[0][sz[0]-1] < arr[1][sz[1]-1]) swap(sz[0],sz[1]), swap(arr[0],arr[1]);
//       if(arr[1][sz[1]-1] < arr[2][sz[2]-1]) swap(sz[1],sz[2]), swap(arr[1],arr[2]);
//       if(arr[0][sz[0]-1] < arr[1][sz[1]-1]) swap(sz[0],sz[1]), swap(arr[0],arr[1]);
// 
//       cur = ev(arr[0][sz[0]-1], arr[1][sz[1]-1], arr[2][sz[2]-1]);
//       res <?= cur;
//       if(sz[1] >= 2){
//         tmp = ev(arr[0][sz[0]-1], arr[1][sz[1]-2], arr[2][sz[2]-1]);
//         if(tmp <= cur) sz[1]--, continue;
//       }
// 
//       sz[0]--;
//     }
//     wt(res);
//   }
// }