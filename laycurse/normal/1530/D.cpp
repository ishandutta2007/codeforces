#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
int N;
int A[200000];
int ms;
int ss;
int m[200000];
int s[200000];
vector<int> ind[200000];
int res[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      ind[i].clear();
    }
    for(i=(0);i<(N);i++){
      ind[A[i]].push_back(i);
    }
    ms = ss = 0;
    for(i=(0);i<(N);i++){
      if(ind[i].size() > 1){
        m[ms++] = i;
      }
    }
    for(i=(0);i<(N);i++){
      if(ind[i].size()==0){
        s[ss++] = i;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = A[i];
    }
    while(ms || ss){
      j = m[ms-1];
      k = s[--ss];
      for(i=(ind[j].size())-1;i>=(0);i--){
        if(ind[j][i] != k){
          res[ind[j][i]] = k;
          ind[j].erase(ind[j].begin()+i);
          if(ind[j].size()==1){
            ms--;
          }
          break;
        }
      }
    }
    k = 0;
    for(i=(0);i<(N);i++){
      if(A[i]==res[i]){
        k++;
      }
    }
    wt_L(k);
    wt_L('\n');
    {
      int XJIcIBrW;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(XJIcIBrW=(0);XJIcIBrW<(N-1);XJIcIBrW++){
          wt_L(res[XJIcIBrW]+1);
          wt_L(' ');
        }
        wt_L(res[XJIcIBrW]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// int ms, ss, m[], s[];
// VI ind[];
// int res[];
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N,(A--)(N));
// 
//     rep(i,N) ind[i].clear();
//     rep(i,N) ind[A[i]].push_back(i);
//     ms = ss = 0;
//     rep(i,N) if(ind[i].size() > 1) m[ms++] = i;
//     rep(i,N) if(ind[i].size()==0) s[ss++] = i;
// 
//     rep(i,N) res[i] = A[i];
//     while(ms || ss){
//       j = m[ms-1];
//       k = s[--ss];
//       rrep(i,ind[j].size()) if(ind[j][i] != k){
//         res[ind[j][i]] = k;
//         ind[j].erase(ind[j].begin()+i);
//         if(ind[j].size()==1) ms--;
//         break;
//       }
//     }
// 
//     k = 0;
//     rep(i,N) if(A[i]==res[i]) k++;
//     wt(k);
//     wt(res(N)+1);
//   }
// }