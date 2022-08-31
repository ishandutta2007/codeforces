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
int P[200];
int K[200];
int S[200][200];
int ss[200];
int cnv[200];
int chker(void){
  int i;
  for(i=(0);i<(N);i++){
    cnv[P[i]] = i;
  }
  for(i=(0);i<(N-1);i++){
    int j;
    for(j=(0);j<(K[i]);j++){
      ss[j] = cnv[S[i][j]];
    }
    sortA_L(K[i], ss);
    if(ss[0]+K[i]-1 != ss[K[i]-1]){
      return 0;
    }
  }
  return 1;
}
int ok[200];
int use_num[200];
int use_seq[200];
int cnt[200];
int ls[200];
int solve(int rem){
  int i;
  int x = -1;
  int y = -1;
  int lx;
  int ly;
  if(rem==1){
    int i;
    for(i=(0);i<(N);i++){
      if(!use_num[i]){
        P[0] = i;
      }
    }
    return chker();
  }
  for(i=(0);i<(N);i++){
    cnt[i] = 0;
  }
  for(i=(0);i<(N-1);i++){
    if(!use_seq[i]){
      int j;
      for(j=(0);j<(K[i]);j++){
        cnt[S[i][j]]++;
        ls[S[i][j]] = i;
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(use_num[i] == 0 && cnt[i] == 1 && ok[i]){
      if(x==-1){
        x= i;
      }
      else{
        y= i;
      }
    }
  }
  if(x >= 0){
    lx = ls[x];
  }
  if(y >= 0){
    ly = ls[y];
  }
  if(x >= 0){
    use_num[x] = use_seq[ls[x]] = 1;
    for(i=(0);i<(N);i++){
      ok[i] = 0;
    }
    for(i=(0);i<(K[ls[x]]);i++){
      ok[S[ls[x]][i]] = 1;
    }
    P[rem-1] = x;
    if(solve(rem-1)){
      return 1;
    }
    use_num[x] = use_seq[ls[x]] = 0;
  }
  if(y >= 0){
    use_num[y] = use_seq[ls[y]] = 1;
    for(i=(0);i<(N);i++){
      ok[i] = 0;
    }
    for(i=(0);i<(K[ls[y]]);i++){
      ok[S[ls[y]][i]] = 1;
    }
    P[rem-1] = y;
    if(solve(rem-1)){
      return 1;
    }
    use_num[y] = use_seq[ls[y]] = 0;
  }
  return 0;
}
int main(){
  int jPV_0s1p;
  wmem = memarr;
  int BUotOFBp = rd_int();
  for(jPV_0s1p=(0);jPV_0s1p<(BUotOFBp);jPV_0s1p++){
    int i;
    rd(N);
    for(i=(0);i<(N-1);i++){
      rd(K[i]);
      {
        int Hjfu7Vx7;
        for(Hjfu7Vx7=(0);Hjfu7Vx7<(K[i]);Hjfu7Vx7++){
          rd(S[i][Hjfu7Vx7]);S[i][Hjfu7Vx7] += (-1);
        }
      }
    }
    for(i=(0);i<(N);i++){
      ok[i] = 1;
      use_num[i] = use_seq[i] = 0;
    }
    solve(N);
    {
      int ytthggxT;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(ytthggxT=(0);ytthggxT<(N-1);ytthggxT++){
          wt_L(P[ytthggxT]+1);
          wt_L(' ');
        }
        wt_L(P[ytthggxT]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, P[200];
// int K[200], S[200][200];
// 
// 
// int ss[200], cnv[200];
// int chker(void){
//   rep(i,N) cnv[P[i]] = i;
//   rep(i,N-1){
//     rep(j,K[i]) ss[j] = cnv[S[i][j]];
//     sortA(K[i], ss);
//     if(ss[0]+K[i]-1 != ss[K[i]-1]) return 0;
//   }
//   return 1;
// }
// 
// 
// int ok[200], use_num[200], use_seq[200];
// int cnt[200], ls[200];
// int solve(int rem){
//   int x = -1, y = -1, lx, ly;
// 
//   if(rem==1){
//     rep(i,N) if(!use_num[i]) P[0] = i;
//     return chker();
//   }
// 
//   rep(i,N) cnt[i] = 0;
//   rep(i,N-1) if(!use_seq[i]) rep(j,K[i]){
//     cnt[S[i][j]]++;
//     ls[S[i][j]] = i;
//   }
// 
//   rep(i,N) if(use_num[i] == 0 && cnt[i] == 1 && ok[i]) if[x==-1, x, y] = i;
// 
//   if(x >= 0) lx = ls[x];
//   if(y >= 0) ly = ls[y];
// 
//   if(x >= 0){
//     use_num[x] = use_seq[ls[x]] = 1;
//     rep(i,N) ok[i] = 0;
//     rep(i,K[ls[x]]) ok[S[ls[x]][i]] = 1;
//     P[rem-1] = x;
//     if(solve(rem-1)) return 1;
//     use_num[x] = use_seq[ls[x]] = 0;
//   }
//   if(y >= 0){
//     use_num[y] = use_seq[ls[y]] = 1;
//     rep(i,N) ok[i] = 0;
//     rep(i,K[ls[y]]) ok[S[ls[y]][i]] = 1;
//     P[rem-1] = y;
//     if(solve(rem-1)) return 1;
//     use_num[y] = use_seq[ls[y]] = 0;
//   }
// 
//   return 0;
// }
// 
// {
//   REP(rd_int()){
//     rd(N);
//     rep(i,N-1) rd(K[i], (S[i]--)(K[i]));
//     rep(i,N) ok[i] = 1, use_num[i] = use_seq[i] = 0;
//     solve(N);
//     wt(P(N)+1);
//   }
// }