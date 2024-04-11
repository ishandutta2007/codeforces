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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
}
;
int N;
int A[200000];
int B[200000];
graph g;
int cur[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k;
    int m1;
    int m2;
    int mn;
    int res;
    int ok;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N-1);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    g.setEdgeRootedTree(N,N-1,A,B,0,1);
    int xr20shxY;
    int WYIGIcGE;
    int t_ynMSdg;
    xr20shxY = 1;
    WYIGIcGE = N-1;
    while(xr20shxY < WYIGIcGE){
      if((xr20shxY + WYIGIcGE)%2==0){
        t_ynMSdg = (xr20shxY + WYIGIcGE) / 2;
      }
      else{
        t_ynMSdg = (xr20shxY + WYIGIcGE - 1) / 2;
      }
      ok = 1;
      for(i=(N)-1;i>=(0);i--){
        int hCmBdyQB;
        if(g.es[i]==0){
          cur[i] = 0;
          continue;
        }
        if(g.es[i]==1){
          cur[i] = cur[g.edge[i][0]] + 1;
          if(cur[i] > t_ynMSdg){
            ok = 0;
            break;
          }
          continue;
        }
        m1 = m2 = 0;
        mn = 1073709056;
        for(hCmBdyQB=(0);hCmBdyQB<(g.es[i]);hCmBdyQB++){
          auto &k = g.edge[i][hCmBdyQB];
          chmin(mn, cur[k]);
          chmax(m2, cur[k]);
          if(m1 < m2){
            swap(m1, m2);
          }
        }
        if(m1 + 1 >= t_ynMSdg){
          cur[i] =max_L(m1 + 1, m2 + 2);
        }
        else{
          cur[i] = mn + 1;
        }
        if(cur[i] > t_ynMSdg){
          ok = 0;
          break;
        }
      }
      if(ok){
        WYIGIcGE = t_ynMSdg;
      }
      else{
        xr20shxY = t_ynMSdg + 1;
      }
    }
    res =WYIGIcGE;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], B[2d5];
// graph g;
// int cur[2d5];
// {
//   REP(rd_int()){
//     int i, k, m1, m2, mn, res, ok;
//     rd(N,(A--,B--)(N-1));
//     g.setEdgeRootedTree(N,N-1,A,B,0,1);
//     res = bsearch_min[int,x,1,N-1][
//       ok = 1;
//       rrep(i,N){
//         if(g.es[i]==0) cur[i] = 0, continue;
//         if(g.es[i]==1){
//           cur[i] = cur[g.edge[i][0]] + 1;
//           if(cur[i] > x) ok = 0, break;
//           continue;
//         }
//         m1 = m2 = 0;
//         mn = int_inf;
//         rep[g.edge[i]](k,g.es[i]){
//           mn <?= cur[k];
//           m2 >?= cur[k];
//           if(m1 < m2) swap(m1, m2);
//         }
//         if(m1 + 1 >= x) cur[i] = max(m1 + 1, m2 + 2);
//         else            cur[i] = mn + 1;
//         if(cur[i] > x) ok = 0, break;
//       }
//     ](ok);
//     wt(res);
//   }
// }