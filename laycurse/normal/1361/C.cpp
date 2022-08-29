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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[1000000];
int res[1000000];
int sz;
int use[1000000];
vector<int> ind[2000000];
int dfs(int k, int s){
  int i = -1;
  int j;
  while(ind[k].size()){
    i = ind[k].back();
    ind[k].pop_back();
    if(use[i]){
      i = -1;
      continue;
    }
    break;
  }
  if(i==-1){
    if(s!=k){
      return 0;
    }
    return 1;
  }
  j = i^1;
  use[i] = use[j] = 1;
  if(!dfs(A[j],s)){
    return 0;
  }
  if(!dfs(A[j],A[j])){
    return 0;
  }
  res[sz++] = j;
  res[sz++] = i;
  return 1;
}
int solve(void){
  int i;
  int k;
  int mx = 0;
  sz = 0;
  for(i=(0);i<(2*N);i++){
    chmax(mx, A[i]);
  }
  mx++;
  for(i=(0);i<(mx);i++){
    ind[i].clear();
  }
  for(i=(0);i<(2*N);i++){
    ind[A[i]].push_back(i);
  }
  for(i=(0);i<(2*N);i++){
    use[i] = 0;
  }
  for(k=(0);k<(mx);k++){
    if(ind[k].size()){
      break;
    }
  }
  if(!dfs(k,k)){
    return 0;
  }
  if(sz!=2*N){
    return 0;
  }
  return 1;
}
int main(){
  int k;
  rd(N);
  {
    int tU__gIr_;
    for(tU__gIr_=(0);tU__gIr_<(2*N);tU__gIr_++){
      rd(A[tU__gIr_]);
    }
  }
  for(k=(21)-1;k>=(0);k--){
    int i;
    for(i=(0);i<(2*N);i++){
      if(((A[i]) &(1<<(k)))){
        A[i] ^=(1<<(k));
      }
    }
    if(solve()){
      wt_L(k);
      wt_L('\n');
      {
        int jbtyPBGc;
        if(2*N==0){
          wt_L('\n');
        }
        else{
          for(jbtyPBGc=(0);jbtyPBGc<(2*N-1);jbtyPBGc++){
            wt_L(res[jbtyPBGc]+1);
            wt_L(' ');
          }
          wt_L(res[jbtyPBGc]+1);
          wt_L('\n');
        }
      }
      break;
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[1d6];
// int res[1d6];
// 
// int sz, use[1d6];
// vector<int> ind[2d6];
// 
// int dfs(int k, int s){
//   int i = -1, j;
// 
//   while(ind[k].size()){
//     i = ind[k].back();
//     ind[k].pop_back();
//     if(use[i]) i = -1, continue;
//     break;
//   }
// 
//   if(i==-1){
//     if(s!=k) return 0;
//     return 1;
//   }
// 
//   j = i^1;
//   use[i] = use[j] = 1;
//   if(!dfs(A[j],s)) return 0;
//   if(!dfs(A[j],A[j])) return 0;
//   res[sz++] = j;
//   res[sz++] = i;
//   return 1;
// }
// 
// int solve(void){
//   int i, k, mx = 0;
//   sz = 0;
// 
//   rep(i,2N) mx >?= A[i];
//   mx++;
//   rep(i,mx) ind[i].clear();
// 
//   rep(i,2N) ind[A[i]].push_back(i);
//   rep(i,2N) use[i] = 0;
// 
//   rep(k,mx) if(ind[k].size()) break;
//   if(!dfs(k,k)) return 0;
//   if(sz!=2N) return 0;
//   return 1;
// }
// 
// {
//   rd(N,A(2N));
//   rrep(k,21){
//     rep(i,2N) if(BIT_ith(A[i],k)) A[i] ^= BIT_ith(k);
//     if(solve()){
//       wt(k);
//       wt(res(2N)+1);
//       break;
//     }
//   }
// }