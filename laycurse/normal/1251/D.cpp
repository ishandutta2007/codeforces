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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
    k = getchar();
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
    k = getchar();
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
int N;
long long S;
int L[200000];
int R[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  long long rem;
  int ok;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(L[cTE1_r3A]);
        rd(R[cTE1_r3A]);
      }
    }
    sortA_L(N,L,R);
    for(i=(0);i<(N);i++){
      S -= L[i];
    }
    int t_ynMSdg;
    int KrdatlYV;
    int ao_dF3pO;
    t_ynMSdg = 0;
    KrdatlYV = 1000000000;
    while(t_ynMSdg < KrdatlYV){
      if((t_ynMSdg + KrdatlYV)%2==0){
        ao_dF3pO = (t_ynMSdg + KrdatlYV) / 2;
      }
      else{
        ao_dF3pO = (t_ynMSdg + KrdatlYV + 1) / 2;
      }
      rem = S;
      ok = 0;
      for(i=(N)-1;i>=(0);i--){
        if(L[i] >= ao_dF3pO){
          ok++;
          continue;
        }
        if(R[i] < ao_dF3pO){
          continue;
        }
        if(rem >= ao_dF3pO - L[i]){
          ok++;
          rem -= ao_dF3pO - L[i];
        }
      }
      if(ok >= (N+1)/2){
        t_ynMSdg = ao_dF3pO;
      }
      else{
        KrdatlYV = ao_dF3pO - 1;
      }
    }
    res =KrdatlYV;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N; ll S; int L[2d5], R[2d5];
// {
//   ll rem;
//   int ok, res;
//   REP(rd_int()){
//     rd(N,S,(L,R)(N));
//     sortA(N,L,R);
//     rep(i,N) S -= L[i];
//     res = bsearch_max[int,x,0,1d9][
//       rem = S;
//       ok = 0;
//       rrep(i,N){
//         if(L[i] >= x) ok++, continue;
//         if(R[i] < x) continue;
//         if(rem >= x - L[i]) ok++, rem -= x - L[i];
//       }
//     ](ok >= (N+1)/2);
//     wt(res);
//   }
// }