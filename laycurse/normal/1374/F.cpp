#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int> *r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
int N;
int A[500];
int r[500];
int ress;
int res[1000000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int inv = 0;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      r[i] = 1000 * A[i] + i;
    }
    coordcomp_L(N, r);
    for(i=(0);i<(N);i++){
      for(j=(i+1);j<(N);j++){
        if(r[i] > r[j]){
          inv++;
        }
      }
    }
    if(inv % 2){
      int ok = 0;
      for(i=(0);i<(N);i++){
        for(j=(i+1);j<(N);j++){
          if(A[i]==A[j]){
            ok = 1;
            swap(r[i], r[j]);
            goto hCmBdyQB;
          }
        }
      }
      hCmBdyQB:;
      if(!ok){
        wt_L(-1);
        wt_L('\n');
        continue;
      }
    }
    for(i=(0);i<(N);i++){
      A[i] = r[i];
    }
    ress = 0;
    for(i=(0);i<(N);i++){
      for(j=(i);j<(N);j++){
        if(A[j]==i){
          break;
        }
      }
      while(j > i){
        k =max_L(i, j-2);
        res[ress++] = k;
        {
          auto Q5rsz4fz = (A[k+2]);
          auto GgkpftXM = ( A[k]);
          auto gEg5UqEA = ( A[k+1]);
          A[k] = Q5rsz4fz;
          A[k+1] = GgkpftXM;
          A[k+2] = gEg5UqEA;
        }
        j = k;
        while(A[j] != i){
          j++;
        }
      }
    }
    wt_L(ress);
    wt_L('\n');
    {
      int zT28qSmp;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(zT28qSmp=(0);zT28qSmp<(ress-1);zT28qSmp++){
          wt_L(res[zT28qSmp]+1);
          wt_L(' ');
        }
        wt_L(res[zT28qSmp]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[500];
// int r[500];
// int ress, res[1d6];
// {
//   REP(rd_int()){
//     int i, j, k, inv = 0;
//     rd(N,(A--)(N));
// 
//     rep(i,N) r[i] = 1000 * A[i] + i;
//     coordcomp(N, r);
// 
//     rep(i,N) rep(j,i+1,N) if(r[i] > r[j]) inv++;
//     if(inv % 2){
//       int ok = 0;
//       rep(i,N) rep(j,i+1,N) if(A[i]==A[j]){
//         ok = 1;
//         swap(r[i], r[j]);
//         break_break;
//       }
//       if(!ok) wt(-1), continue;
//     }
// 
//     rep(i,N) A[i] = r[i];
//     ress = 0;
//     rep(i,N){
//       rep(j,i,N) if(A[j]==i) break;
//       while(j > i){
//         k = max(i, j-2);
//         res[ress++] = k;
//         (A[k], A[k+1], A[k+2]) = (A[k+2], A[k], A[k+1]);
//         j = k;
//         while(A[j] != i) j++;
//       }
//     }
//     wt(ress);
//     wt(res(ress)+1);
//   }
// }