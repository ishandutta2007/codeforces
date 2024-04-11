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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int N;
int M;
vector<int> F[100000];
int res[100000];
int cnt[100000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int mx;
    rd(N);
    rd(M);
    mx =(divup_L(M,2));
    for(i=(0);i<(M);i++){
      int FmcKpFmN;
      rd(k);
      F[i].clear();
      for(FmcKpFmN=(0);FmcKpFmN<(k);FmcKpFmN++){
        F[i].push_back(rd_int()-1);
      }
    }
    for(i=(0);i<(M);i++){
      res[i] = F[i][0];
    }
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(M);i++){
      cnt[res[i]]++;
    }
    for(i=(0);i<(M);i++){
      if(cnt[res[i]] > mx && F[i].size() >= 2){
        cnt[res[i]]--;
        res[i] = F[i][1];
        cnt[res[i]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(cnt[i] > mx){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("YES");
    wt_L('\n');
    {
      int jbtyPBGc;
      if(M==0){
        wt_L('\n');
      }
      else{
        for(jbtyPBGc=(0);jbtyPBGc<(M-1);jbtyPBGc++){
          wt_L(res[jbtyPBGc]+1);
          wt_L(' ');
        }
        wt_L(res[jbtyPBGc]+1);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N, M;
// VI F[1d5];
// int res[1d5], cnt[1d5];
// {
//   REP(rd_int()){
//     int i, j, k, mx;
//     rd(N,M);
//     mx = M /+ 2;
//     rep(i,M){
//       rd(k);
//       F[i].clear();
//       rep(k) F[i].push_back(rd_int()-1);
//     }
//     rep(i,M) res[i] = F[i][0];
//     rep(i,N) cnt[i] = 0;
//     rep(i,M) cnt[res[i]]++;
//     rep(i,M){
//       if(cnt[res[i]] > mx && F[i].size() >= 2){
//         cnt[res[i]]--;
//         res[i] = F[i][1];
//         cnt[res[i]]++;
//       }
//     }
//     rep(i,N) if(cnt[i] > mx) wt("NO"), break_continue;
//     wt("YES");
//     wt(res(M)+1);
//   }
// }