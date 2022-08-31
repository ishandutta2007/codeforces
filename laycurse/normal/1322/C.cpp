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
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class T, class U> inline T GCD_L(T a, U b){
  T r;
  while(b){
    r=a;
    a=b;
    b=r%a;
  }
  return a;
}
int N;
int M;
long long C[500000];
pair<vector<int>,int> e[500000];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  long long res;
  long long stupid;
  long long tmp;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int ao_dF3pO;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(C[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      e[i].first.clear();
    }
    for(i=(0);i<(N);i++){
      e[i].second = i;
    }
    for(ao_dF3pO=(0);ao_dF3pO<(M);ao_dF3pO++){
      rd(i);i += (-1);
      rd(j);j += (-1);
      e[j].first.push_back(i);
    }
    for(i=(0);i<(N);i++){
      sort(e[i].first.begin(), e[i].first.end());
    }
    sort(e, e+N);
    for(i=(0);i<(N);i++){
      if(e[i].first.size()==0){
        C[e[i].second] = 0;
      }
    }
    for(i=(1);i<(N);i++){
      if(e[i].first == e[i-1].first){
        C[e[i].second] += C[e[i-1].second];
        C[e[i-1].second] = 0;
      }
    }
    {
      int ZIeRIny5;
      long long iMWUTgY_;
      if(N==0){
        iMWUTgY_ = 0;
      }
      else{
        iMWUTgY_ = C[0];
        for(ZIeRIny5=(1);ZIeRIny5<(N);ZIeRIny5++){
          iMWUTgY_ = GCD_L(iMWUTgY_, C[ZIeRIny5]);
        }
      }
      res =iMWUTgY_;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200303-1 [beta]

// --- original code ---
// //no-unlocked
// //no-fwrite
// int N, M;
// ll C[5d5];
// 
// pair<vector<int>,int> e[5d5];
// 
// {
//   int i, j;
//   ll res, stupid, tmp;
// 
//   REP(rd_int()){
//     rd(N,M,C(N));
//     rep(i,N) e[i].first.clear();
//     rep(i,N) e[i].second = i;
//     rep(M){
//       rd(i--, j--);
//       e[j].first.push_back(i);
//     }
// 
// /*    stupid = 0;
//     rep(mask,1<<N){
//       tmp = 0;
//       rep(i,N) for(int j : e[i].first) if(BIT_ith(mask,j)) tmp += C[i], break;
//       stupid = gcd(stupid, tmp);
//     }*/
// 
//     rep(i,N) sort(e[i].first.begin(), e[i].first.end());
//     sort(e, e+N);
//     rep(i,N) if(e[i].first.size()==0) C[e[i].second] = 0;
//     rep(i,1,N) if(e[i].first == e[i-1].first){
//       C[e[i].second] += C[e[i-1].second];
//       C[e[i-1].second] = 0;
//     }
//     res = gcd(C(N));
//     wt(res);
// //    assert(res==stupid);
//   }
// }