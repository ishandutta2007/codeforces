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
template<class S, class T> inline int arrcmp(int As, S A[], int Bs, T B[]){
  int i;
  for(i=0;;i++){
    if(i==As && As==Bs){
      break;
    }
    if(i==As){
      return -1;
    }
    if(i==Bs){
      return 1;
    }
    if(A[i] < B[i]){
      return -1;
    }
    if(A[i] > B[i]){
      return 1;
    }
  }
  return 0;
}
int N;
int len;
int ss;
int sc;
char S[500000+2];
char T[500000+2];
char res[500000+2];
char chk[500000+2];
int cnt[26];
int ress;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    N = rd(T);
    ress = 0;
    for(i=(0);i<(26);i++){
      cnt[i] = 0;
    }
    for(i=(N)-1;i>=(0);i--){
      if(cnt[T[i]-'a']++ == 0){
        res[ress++] = T[i];
      }
    }
    reverse(res, res+ress);
    res[ress] = '\0';
    for(i=(0);i<(ress);i++){
      if(cnt[res[i]-'a'] % (i+1)){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      cnt[res[i]-'a'] /= (i+1);
    }
    sc = 0;
    int KrdatlYV;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type ao_dF3pO;
    if(26==0){
      ao_dF3pO = 0;
    }
    else{
      ao_dF3pO = cnt[0];
      for(KrdatlYV=(1);KrdatlYV<(26);KrdatlYV++){
        ao_dF3pO += cnt[KrdatlYV];
      }
    }
    len =ao_dF3pO;
    for(i=(0);i<(len);i++){
      S[i] = T[i];
    }
    for(i=(0);i<(ress);i++){
      int k;
      ss = 0;
      for(k=(0);k<(len);k++){
        chk[sc++] = S[k];
        if(S[k] != res[i]){
          S[ss++] = S[k];
        }
        if(sc > N){
          goto YREPHmFM;
        }
      }
      len = ss;
    }
    YREPHmFM:;
    if(arrcmp(N,T,sc,chk)!=0){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    int ZIeRIny5;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type iMWUTgY_;
    if(26==0){
      iMWUTgY_ = 0;
    }
    else{
      iMWUTgY_ = cnt[0];
      for(ZIeRIny5=(1);ZIeRIny5<(26);ZIeRIny5++){
        iMWUTgY_ += cnt[ZIeRIny5];
      }
    }
    T[iMWUTgY_] = '\0';
    wt_L(T);
    wt_L(' ');
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210816-1

// --- original code ---
// //no-unlocked
// int N, len, ss, sc;
// char S[5d5+2], T[], res[], chk[];
// int cnt[26], ress;
// {
//   REP(rd_int()){
//     rd(T@N);
//     ress = 0;
//     rep(i,26) cnt[i] = 0;
//     rrep(i,N) if(cnt[T[i]-'a']++ == 0) res[ress++] = T[i];
//     reverse(res, res+ress);
//     res[ress] = '\0';
// 
//     rep(i,ress){
//       if(cnt[res[i]-'a'] % (i+1)) wt(-1), break_continue;
//       cnt[res[i]-'a'] /= (i+1);
//     }
// 
//     sc = 0;
//     len = sum(cnt(26));
//     rep(i,len) S[i] = T[i];
//     rep(i,ress){
//       ss = 0;
//       rep(k,len){
//         chk[sc++] = S[k];
//         if(S[k] != res[i]) S[ss++] = S[k];
//         if(sc > N) break_break;
//       }
//       len = ss;
//     }
// 
//     if(arrcmp(N,T,sc,chk)!=0) wt(-1), continue;
//     T[sum(cnt(26))] = '\0';
//     wt(T,res);
//   }
// }