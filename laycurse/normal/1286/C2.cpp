#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int N;
char res[102];
vector<string> g[102];
int cnt[102][26];
int r[26];
int tmp[26];
int q[51][2];
int m;
int a[100000];
int b[100000];
int v1[100000];
int v2[100000];
int f[51][2];
int lf[51][2];
int rg[51][2];
void query(int a, int b){
  int i, k;
  int len;
  int n;
  int m;
  char buf[102];
  printf("? %d %d\n", a+1, b+1);
  fflush(stdout);
  n = (b-a+1) * (b-a+2) / 2;
  for(i=(0);i<(N+1);i++){
    g[i].clear();
  }
  for(i=(0);i<(N+1);i++){
    int j;
    for(j=(0);j<(26);j++){
      cnt[i][j] = 0;
    }
  }
  for(i=(0);i<(n);i++){
    int j;
    scanf("%s",buf);
    len = strlen(buf);
    g[len].push_back((string)buf);
    for(j=(0);j<(len);j++){
      cnt[len][buf[j]-'a']++;
    }
  }
  n = b - a + 1;
  for(k=(0);k<(26);k++){
    r[k] = cnt[0][k];
  }
  for(i=(0);i<((n+1)/2);i++){
    q[i][0] = q[i][1] = -1;
    if(i==(n+1)/2-1){
      for(k=(0);k<(26);k++){
        r[k] = cnt[1][k];
      }
    }
    else{
      for(k=(0);k<(26);k++){
        r[k] = cnt[1][k] - (cnt[i+2][k] - cnt[i+1][k]);
      }
    }
    for(k=(0);k<(i);k++){
      for(m=(0);m<(2);m++){
        if(q[k][m] >= 0){
          r[q[k][m]]--;
        }
      }
    }
    m = 0;
    for(k=(0);k<(26);k++){
      while(r[k]){
        q[i][m++] = k;
        r[k]--;
      }
    }
  }
}
void answer(void){
  printf("! %s\n", res);
  fflush(stdout);
  exit(0);
}
int main(){
  int i;
  int v;
  int sz;
  scanf("%d",&N);
  if(N <= 3){
    int i;
    for(i=(0);i<(N);i++){
      query(i, i);
      res[i] = g[1][0][0];
    }
    answer();
  }
  for(i=(0);i<(N);i++){
    res[i] = 127;
  }
  sz = N / 2;
  query(0, N-1);
  for(i=(0);i<((N+1)/2);i++){
    if(q[i][1] == -1){
      res[i] = q[i][0];
      continue;
    }
    a[m] = i;
    b[m] = N-1-i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  query(0, sz-1);
  for(i=(0);i<((sz+1)/2);i++){
    if(q[i][1] == -1){
      res[i] = q[i][0];
      continue;
    }
    a[m] = i;
    b[m] = sz-1-i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  query(0, sz-2);
  for(i=(0);i<(sz/2);i++){
    if(q[i][1] == -1){
      res[i] = q[i][0];
      continue;
    }
    a[m] = i;
    b[m] = sz-2-i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  for(;;){
    int fg = 0;
    for(i=(0);i<(m);i++){
      if(res[a[i]]!=127 && res[b[i]]==127){
        res[b[i]] = ((int)res[a[i]]) ^ v1[i] ^ v2[i];
        fg++;
      }
      if(res[a[i]]==127 && res[b[i]]!=127){
        res[a[i]] = ((int)res[b[i]]) ^ v1[i] ^ v2[i];
        fg++;
      }
    }
    if(!fg){
      break;
    }
  }
  for(i=(0);i<(N);i++){
    res[i] += 'a';
  }
  answer();
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char res[102];
// 
// vector<string> g[102];
// int cnt[102][26];
// 
// int r[26], tmp[26];
// int q[51][2];
// 
// int m, a[1d5], b[1d5], v1[1d5], v2[1d5];
// int f[51][2];
// int lf[51][2];
// int rg[51][2];
// 
// void query(int a, int b){
//   int len, n, m;
//   char buf[102];
//   printf("? %d %d\n", a+1, b+1);
//   fflush(stdout);
//   n = (b-a+1) * (b-a+2) / 2;
//   rep(i,N+1) g[i].clear();
//   rep(i,N+1) rep(j,26) cnt[i][j] = 0;
//   rep(i,n){
//     scanf("%s",buf);
//     len = strlen(buf);
//     g[len].push_back((string)buf);
//     rep(j,len) cnt[len][buf[j]-'a']++;
//   }
// 
//   n = b - a + 1;
//   rep(k,26) r[k] = cnt[0][k];
// //  printf("n %d\n",n);
//   rep(i,(n+1)/2){
//     q[i][0] = q[i][1] = -1;
//     if(i==(n+1)/2-1){
//       rep(k,26) r[k] = cnt[1][k];
//     } else {
//       rep(k,26) r[k] = cnt[1][k] - (cnt[i+2][k] - cnt[i+1][k]);
//     }
//     rep(k,i) rep(m,2) if(q[k][m] >= 0) r[q[k][m]]--;
//     m = 0;
//     rep(k,26) while(r[k]){
//       q[i][m++] = k;
//       r[k]--;
//     }
//     //wt(i,q[i][0],q[i][1]);
//   }
// }
// 
// void answer(void){
//   printf("! %s\n", res);
//   fflush(stdout);
//   exit(0);
// }
// 
// {
//   int v, sz;
//   scanf("%d",&N);
// 
//   if(N <= 3){
//     rep(i,N){
//       query(i, i);
//       res[i] = g[1][0][0];
//     }
//     answer();
//   }
// 
//   rep(i,N) res[i] = 127;
//   sz = N / 2;
// 
//   query(0, N-1);
//   rep(i,(N+1)/2){
//     if(q[i][1] == -1) res[i] = q[i][0], continue;
//     a[m] = i;
//     b[m] = N-1-i;
//     v1[m] = q[i][0];
//     v2[m] = q[i][1];
//     m++;
//   }
// //  rep(i,N) printf("res[%d] = %d\n",i,res[i]);
//   query(0, sz-1);
//   rep(i,(sz+1)/2){
// //    printf("++++ %d %d %d\n",i,q[i][0],q[i][1]);
//     if(q[i][1] == -1) res[i] = q[i][0], continue;
//     a[m] = i;
//     b[m] = sz-1-i;
//     v1[m] = q[i][0];
//     v2[m] = q[i][1];
//     m++;
//   }
// //  rep(i,N) printf("res[%d] = %d\n",i,res[i]);
//   query(0, sz-2);
//   rep(i,sz/2){
// //    printf("++++++ %d %d %d\n",i,q[i][0],q[i][1]);
//     if(q[i][1] == -1) res[i] = q[i][0], continue;
//     a[m] = i;
//     b[m] = sz-2-i;
//     v1[m] = q[i][0];
//     v2[m] = q[i][1];
//     m++;
//   }
// 
// //  rep(i,N) printf("res[%d] = %d\n",i,res[i]);
// //  rep(i,m) wt("edge", a[i],b[i],v1[i],v2[i]);
// 
//   for(;;){
//     int fg = 0;
//     rep(i,m){
//       if(res[a[i]]!=127 && res[b[i]]==127){
//         res[b[i]] = ((int)res[a[i]]) ^ v1[i] ^ v2[i];
//         fg++;
//       }
//       if(res[a[i]]==127 && res[b[i]]!=127){
//         res[a[i]] = ((int)res[b[i]]) ^ v1[i] ^ v2[i];
//         fg++;
//       }
//     }
//     if(!fg) break;
//   }
// 
// //  rep(i,N) printf("%d-",res[i]);puts("");
//   rep(i,N) res[i] += 'a';
//   answer();
// }