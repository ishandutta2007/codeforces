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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
template<class T> inline int isPalindrome(const int N, const T A[]){
  int i = 0;
  int j = N-1;
  while(i < j){
    if(A[i] != A[j]){
      return 0;
    }
    ;
    i++;
    j--;
  }
  return 1;
}
int N;
char S[1002];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cnt;
    int cen;
    rd(N);
    rd(S);
    cnt = arrCountVal(N,S,'0');
    if(N%2==1 && S[N/2]=='0'){
      cen =1;
    }
    else{
      cen =0;
    }
    if(cnt==0){
      wt_L("DRAW");
      wt_L('\n');
      continue;
    }
    if(!isPalindrome(N,S)){
      if(cen && cnt==2){
        wt_L("DRAW");
        wt_L('\n');
      }
      else{
        wt_L("ALICE");
        wt_L('\n');
      }
      continue;
    }
    if(cen){
      if(cnt==1){
        wt_L("BOB");
        wt_L('\n');
      }
      else if(cnt==2){
        wt_L("DRAW");
        wt_L('\n');
      }
      else{
        wt_L("ALICE");
        wt_L('\n');
      }
      continue;
    }
    wt_L("BOB");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N; char S[1002];
// {
//   REP(rd_int()){
//     int cnt, cen;
//     rd(N,S);
//     cnt = arrCountVal(N,S,'0');
//     cen = if[N%2==1 && S[N/2]=='0', 1, 0];
// 
//     if(cnt==0) wt("DRAW"), continue;
//     if(!isPalindrome(N,S)) wt(if[cen && cnt==2, "DRAW", "ALICE"]), continue;
//     if(cen) wt(if[cnt==1, "BOB", cnt==2, "DRAW", "ALICE"]), continue;
//     wt("BOB");
//   }
// }