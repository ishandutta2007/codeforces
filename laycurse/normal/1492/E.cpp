#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
}
template<class T> inline void walloc2d(T ***arr, int x1, int x2, int y1, int y2, void **mem = &wmem){
  int i;
  walloc1d(arr, x1, x2, mem);
  for(i=(x1);i<(x2);i++){
    walloc1d(&((*arr)[i]), y1, y2, mem);
  }
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
template<class S, class T> int HammingDistance(int N, S A[], T B[]){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i] != B[i]){
      res++;
    }
  }
  return res;
}
int N;
int M;
int**A;
int res[300000];
int ng[300000];
int main(){
  int i;
  wmem = memarr;
  int mx;
  int mxi;
  int ind[4];
  int chk;
  rd(N);
  rd(M);
  walloc2d(&A,N,M);
  {
    int Lj4PdHRW;
    int KL2GvlyY;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      for(KL2GvlyY=(0);KL2GvlyY<(M);KL2GvlyY++){
        rd(A[Lj4PdHRW][KL2GvlyY]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    ng[i] = HammingDistance(M, A[0], A[i]);
  }
  int WYIGIcGE;
  int t_ynMSdg;
  if(N==0){
    t_ynMSdg = 0;
  }
  else{
    t_ynMSdg = ng[0];
    for(WYIGIcGE=(1);WYIGIcGE<(N);WYIGIcGE++){
      t_ynMSdg = max_L(t_ynMSdg, ng[WYIGIcGE]);
    }
  }
  mx =t_ynMSdg;
  if(mx > 4){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  if(mx <= 2){
    wt_L("Yes");
    wt_L('\n');
    {
      int tU__gIr_;
      if(M==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(M-1);tU__gIr_++){
          wt_L(A[0][tU__gIr_]);
          wt_L(' ');
        }
        wt_L(A[0][tU__gIr_]);
        wt_L('\n');
      }
    }
    return 0;
  }
  int APIVbQlN;
  remove_reference<decltype(ng[APIVbQlN])>::type YREPHmFM;
  int jZyWAPpY = 0;
  int jbtyPBGc;
  if((0) > ((N)-1)){
    YREPHmFM = 0;
  }
  else{
    for(APIVbQlN = 0; APIVbQlN <= (N)-1; APIVbQlN++){
      if(jZyWAPpY == 0){
        YREPHmFM = ng[APIVbQlN];
        jbtyPBGc = APIVbQlN;
        jZyWAPpY = 1;
        continue;
      }
      const auto ZIeRIny5 = ng[APIVbQlN];
      if(YREPHmFM < ZIeRIny5){
        YREPHmFM = ZIeRIny5;
        jbtyPBGc = APIVbQlN;
      }
    }
  }
  {
    auto XJIcIBrW = (0);
    auto jPV_0s1p = (jbtyPBGc);
    mx = XJIcIBrW;
    mxi = jPV_0s1p;
  }
  for(i=(0);i<(M);i++){
    if(A[0][i] != A[mxi][i]){
      ind[mx++] = i;
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(mx);j++){
      if(A[0][ind[j]] != A[i][ind[j]]){
        ng[i]--;
      }
    }
  }
  for(i=(0);i<(M);i++){
    res[i] = A[0][i];
  }
  if(mx==3){
    int x;
    for(x=(0);x<(mx);x++){
      int y;
      for(y=(0);y<(mx);y++){
        if(x!=y){
          {
            auto H31bcJ8S = (A[0][ind[x]]);
            auto dtiCQK_a = ( A[mxi][ind[y]]);
            res[ind[x]] = H31bcJ8S;
            res[ind[y]] = dtiCQK_a;
          }
          for(i=(0);i<(N);i++){
            chk = ng[i];
            if(res[ind[x]] != A[i][ind[x]]){
              chk++;
            }
            if(res[ind[y]] != A[i][ind[y]]){
              chk++;
            }
            if(chk == 2){
              res[ind[3-x-y]] = A[i][ind[3-x-y]];
            }
          }
          int lQU550vz;
          remove_reference<decltype(HammingDistance(M,res,A[lQU550vz]))>::type qE8LMwYZ;
          int dKuENJNI = 0;
          if((0) > ((N)-1)){
            qE8LMwYZ = numeric_limits<remove_reference<decltype(HammingDistance(M,res,A[lQU550vz]))>::type>::lowest();
          }
          else{
            for(lQU550vz = 0; lQU550vz <= (N)-1; lQU550vz++){
              if(dKuENJNI == 0){
                qE8LMwYZ = HammingDistance(M,res,A[lQU550vz]);
                dKuENJNI = 1;
                continue;
              }
              const auto lGW8_MCT = HammingDistance(M,res,A[lQU550vz]);
              if(qE8LMwYZ < lGW8_MCT){
                qE8LMwYZ = lGW8_MCT;
              }
            }
          }
          if(qE8LMwYZ> 2){
            continue;
          }
          wt_L("Yes");
          wt_L('\n');
          {
            int YlLMHsfa;
            if(M==0){
              wt_L('\n');
            }
            else{
              for(YlLMHsfa=(0);YlLMHsfa<(M-1);YlLMHsfa++){
                wt_L(res[YlLMHsfa]);
                wt_L(' ');
              }
              wt_L(res[YlLMHsfa]);
              wt_L('\n');
            }
          }
          return 0;
        }
      }
    }
  }
  else{
    int x;
    for(x=(0);x<(mx);x++){
      int y;
      for(y=(x+1);y<(mx);y++){
        for(i=(0);i<(4);i++){
          res[ind[i]] = A[0][ind[i]];
        }
        {
          auto jO2HaRTX = (A[mxi][ind[x]]);
          auto IlgsnSAd = ( A[mxi][ind[y]]);
          res[ind[x]] = jO2HaRTX;
          res[ind[y]] = IlgsnSAd;
        }
        int jG1yfsum;
        remove_reference<decltype(HammingDistance(M,res,A[jG1yfsum]))>::type NLJcSLph;
        int Wu3kZ3t7 = 0;
        if((0) > ((N)-1)){
          NLJcSLph = numeric_limits<remove_reference<decltype(HammingDistance(M,res,A[jG1yfsum]))>::type>::lowest();
        }
        else{
          for(jG1yfsum = 0; jG1yfsum <= (N)-1; jG1yfsum++){
            if(Wu3kZ3t7 == 0){
              NLJcSLph = HammingDistance(M,res,A[jG1yfsum]);
              Wu3kZ3t7 = 1;
              continue;
            }
            const auto EE5PwD1R = HammingDistance(M,res,A[jG1yfsum]);
            if(NLJcSLph < EE5PwD1R){
              NLJcSLph = EE5PwD1R;
            }
          }
        }
        if(NLJcSLph> 2){
          continue;
        }
        wt_L("Yes");
        wt_L('\n');
        {
          int Wv3_QJ0O;
          if(M==0){
            wt_L('\n');
          }
          else{
            for(Wv3_QJ0O=(0);Wv3_QJ0O<(M-1);Wv3_QJ0O++){
              wt_L(res[Wv3_QJ0O]);
              wt_L(' ');
            }
            wt_L(res[Wv3_QJ0O]);
            wt_L('\n');
          }
        }
        return 0;
      }
    }
  }
  wt_L("No");
  wt_L('\n');
  return 0;
}
// cLay version 20210223-1

// --- original code ---
// //no-unlocked
// int N, M, **A;
// int res[3d5], ng[];
// {
//   int mx, mxi, ind[4], chk;
//   rd(N,M);
//   walloc2d(&A,N,M);
//   rd(A(N,M));
//   rep(i,N) ng[i] = HammingDistance(M, A[0], A[i]);
//   mx = max(ng(N));
//   if(mx > 4) wt("No"), return 0;
//   if(mx <= 2) wt("Yes"), wt(A[0](M)), return 0;
// 
//   (mx, mxi) = (0, argmax(ng(N)));
//   rep(i,M) if(A[0][i] != A[mxi][i]) ind[mx++] = i;
//   rep(i,N) rep(j,mx) if(A[0][ind[j]] != A[i][ind[j]]) ng[i]--;
//   rep(i,M) res[i] = A[0][i];
// 
//   if(mx==3){
//     rep(x,mx) rep(y,mx) if(x!=y){
//       (res[ind[x]], res[ind[y]]) = (A[0][ind[x]], A[mxi][ind[y]]);
//       rep(i,N){
//         chk = ng[i];
//         if(res[ind[x]] != A[i][ind[x]]) chk++;
//         if(res[ind[y]] != A[i][ind[y]]) chk++;
//         if(chk == 2) res[ind[3-x-y]] = A[i][ind[3-x-y]];
//       }
//       if(max[i,0,N](HammingDistance(M,res,A[i])) > 2) continue;
//       wt("Yes"), wt(res(M)), return 0;
//     }
//   } else {
//     rep(x,mx) rep(y,x+1,mx){
//       rep(i,4) res[ind[i]] = A[0][ind[i]];
//       (res[ind[x]], res[ind[y]]) = (A[mxi][ind[x]], A[mxi][ind[y]]);
//       if(max[i,0,N](HammingDistance(M,res,A[i])) > 2) continue;
//       wt("Yes"), wt(res(M)), return 0;
//     }
//   }
//   wt("No");
// }