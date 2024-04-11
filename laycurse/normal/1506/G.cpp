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
int N;
char S[200000+2];
vector<int> ind[26];
int ress;
char res[28];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    N = rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    for(i=(0);i<(26);i++){
      ind[i].clear();
    }
    for(i=(N)-1;i>=(0);i--){
      ind[S[i]].push_back(i);
    }
    ress = 0;
    for(;;){
      int j;
      for(i=(26)-1;i>=(0);i--){
        if(ind[i].size()){
          int j;
          for(j=(0);j<(26);j++){
            if(ind[j].size() && ind[j].front() < ind[i].back()){
              goto tU__gIr_;
            }
          }
          break;
        }
        tU__gIr_:;
      }
      if(i < 0){
        break;
      }
      res[ress++] = i;
      for(j=(0);j<(26);j++){
        while(ind[j].size() && ind[j].back() < ind[i].back()){
          ind[j].pop_back();
        }
      }
      ind[i].clear();
    }
    for(i=(0);i<(ress);i++){
      res[i] = res[i] + 'a';
    }
    res[ress] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[2d5+2];
// VI ind[26];
// int ress; char res[28];
// {
//   REP(rd_int()){
//     rd(S@N);
//     rep(i,N) S[i] -= 'a';
// 
//     rep(i,26) ind[i].clear();
//     rrep(i,N) ind[S[i]].push_back(i);
//     ress = 0;
// 
//     for(;;){
//       rrep(i,26) if(ind[i].size()){
//         rep(j,26) if(ind[j].size() && ind[j].front() < ind[i].back()) break_continue;
//         break;
//       }
//       if(i < 0) break;
//       res[ress++] = i;
//       rep(j,26) while(ind[j].size() && ind[j].back() < ind[i].back()) ind[j].pop_back();
//       ind[i].clear();
//     }
// 
//     rep(i,ress) res[i] = res[i] + 'a';
//     res[ress] = '\0';
//     wt(res);
//   }
// }