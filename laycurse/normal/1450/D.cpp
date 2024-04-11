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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int A[300000];
vector<int> ind[300000];
char res[300000+2];
void solve(void){
  int i;
  int x;
  int y;
  int z;
  for(i=(0);i<(N);i++){
    res[i] = '0';
  }
  res[N] = '\0';
  for(i=(0);i<(N);i++){
    if(A[i] == 0){
      break;
    }
  }
  if(i==N){
    return;
  }
  for(i=(0);i<(N);i++){
    ind[i].clear();
  }
  for(i=(0);i<(N);i++){
    ind[A[i]].push_back(i);
  }
  for(i=(0);i<(N);i++){
    if(ind[i].size() == 0){
      break;
    }
  }
  if(i==N){
    res[0]++;
  }
  x = 0;
  y = N-1;
  z = 0;
  while(z < N-1){
    if(ind[z].size() == 0){
      break;
    }
    res[N-z-1]++;
    if(ind[z].size() > 1){
      break;
    }
    if(A[x] != z && A[y] != z){
      break;
    }
    if(A[x]==z){
      x++;
    }
    if(A[y]==z){
      y--;
    }
    z++;
  }
}
int main(){
  int tU__gIr_;
  int a2conNHc = rd_int();
  for(tU__gIr_=(0);tU__gIr_<(a2conNHc);tU__gIr_++){
    rd(N);
    {
      int APIVbQlN;
      for(APIVbQlN=(0);APIVbQlN<(N);APIVbQlN++){
        rd(A[APIVbQlN]);A[APIVbQlN] += (-1);
      }
    }
    solve();
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N, A[3d5];
// vector<int> ind[3d5];
// char res[3d5+2];
// 
// void solve(void){
//   int x, y, z;
// 
//   rep(i,N) res[i] = '0';
//   res[N] = '\0';
// 
//   rep(i,N) if(A[i] == 0) break;
//   if(i==N) return;
// 
//   rep(i,N) ind[i].clear();
//   rep(i,N) ind[A[i]].push_back(i);
//   rep(i,N) if(ind[i].size() == 0) break;
//   if(i==N) res[0]++;
// 
//   x = 0; y = N-1; z = 0;
//   while(z < N-1){
//     if(ind[z].size() == 0) break;
//     res[N-z-1]++;
//     if(ind[z].size() > 1) break;
//     if(A[x] != z && A[y] != z) break;
//     if(A[x]==z) x++;
//     if(A[y]==z) y--;
//     z++;
//   }
// }
// 
// {
//   REP(rd_int()){
//     rd(N,(A--)(N));
//     solve();
//     wt(res);
//   }
// }