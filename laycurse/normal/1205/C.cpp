#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int N;
int res[50][50];
int query(int x1, int y1, int x2, int y2){
  int r;
  if(x1 > x2){
    swap(x1, x2);
  }
  ;
  if(y1 > y2){
    swap(y1, y2);
  }
  ;
  printf("? %d %d %d %d\n",x1+1,y1+1,x2+1,y2+1);
  fflush(stdout);
  scanf("%d",&r);
  return r;
}
int match(int a, int b, int m){
  if(a > b){
    swap(a, b);
  }
  ;
  if(a==b){
    return 1;
  }
  if(m==0){
    if(a==0 && b==2){
      return 1;
    }
    if(a==1 && b==3){
      return 1;
    }
  }
  else{
    if(a==1 && b==2){
      return 1;
    }
    if(a==0 && b==3){
      return 1;
    }
  }
  return 0;
}
pair<int,int> pre_query(int x1, int y1, int x2, int y2){
  int i, j, k, s, val[4];
  pair<int,int> r=make_pair(0,0);
  if(x1 > x2){
    swap(x1, x2);
  }
  ;
  if(y1 > y2){
    swap(y1, y2);
  }
  ;
  for(k=0;k<(1<<3);k++){
    i = x1;
    j = y1;
    val[0] = res[i][j];
    for(s=0;s<(3);s++){
      if(k&1<<s){
        i++;
      }
      else{
        j++;
      }
      if(i >= N || j >= N){
        break;
      }
      val[s+1] = res[i][j];
    }
    if(i==x2 && j==y2){
      if(match(val[0],val[3],0) && match(val[1],val[2],0)){
        r.first = 1;
      }
      if(match(val[0],val[3],1) && match(val[1],val[2],1)){
        r.second = 1;
      }
    }
  }
  return r;
}
void answer(void){
  int i, j;
  puts("!");
  for(i=0;i<(N);i++){
    for(j=0;j<(N);j++){
      printf("%d",res[i][j]);
    }
    puts("");
  }
  fflush(stdout);
}
int main(){
  int d, di[4]={1,-1,2,0}, dj[4]={1,-1,0,2}, i, j, k, ni, nj, si, sj, st[10000], sts;
  pair<int,int> p;
  scanf("%d", &N);
  for(i=0;i<(N);i++){
    for(j=0;j<(N);j++){
      res[i][j] = -1;
    }
  }
  res[0][0] = 1;
  res[N-1][N-1] = 0;
  for(i=2;i<N;i+=2){
    k = query(0, i-2, 0, i);
    res[0][i] = (res[0][i-2] ^ k ^ 1);
    k = query(i-2, 0, i, 0);
    res[i][0] = (res[i-2][0] ^ k ^ 1);
  }
  for(i=(1);i<(N);i++){
    for(j=(1);j<(N);j++){
      if( (i+j)%2==0 && i+j != 2*N-2 ){
        k = query(i-1, j-1, i, j);
        res[i][j] = (res[i-1][j-1] ^ k ^ 1);
      }
    }
  }
  res[0][1] = 2;
  sts = 0;
  st[sts++] = 1;
  while(sts){
    k = st[--sts];
    si = k / N;
    sj = k % N;
    for(d=0;d<(4);d++){
      ni = si + di[d];
      nj = sj + dj[d];
      if(ni < 0 || nj < 0 || ni >= N || nj >= N || res[ni][nj] != -1){
        continue;
      }
      i = query(si, sj, ni, nj);
      res[ni][nj] = (res[si][sj] ^ i ^ 1);
      st[sts++] = ni * N + nj;
    }
  }
  for(si=0;si<(N);si++){
    for(sj=0;sj<(N);sj++){
      for(k=0;k<(4);k++){
        ni = si + k;
        nj = sj + (3 - k);
        if(ni >= N || nj >= N){
          continue;
        }
        p = pre_query(si, sj, ni, nj);
        if(p.first != p.second){
          d = query(si, sj, ni, nj);
          if(p.first == d){
            for(i=0;i<(N);i++){
              for(j=0;j<(N);j++){
                if(res[i][j] == 2){
                  res[i][j] = 0;
                }
                if(res[i][j] == 3){
                  res[i][j] = 1;
                }
              }
            }
          }
          else{
            for(i=0;i<(N);i++){
              for(j=0;j<(N);j++){
                if(res[i][j] == 2){
                  res[i][j] = 1;
                }
                if(res[i][j] == 3){
                  res[i][j] = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  answer();
  return 0;
}
// cLay varsion 20190818-1

// --- original code ---
// //no-unlocked
// int N;
// int res[50][50];
// 
// int query(int x1, int y1, int x2, int y2){
//   int r;
//   sortE(x1, x2);
//   sortE(y1, y2);
//   printf("? %d %d %d %d\n",x1+1,y1+1,x2+1,y2+1);
//   fflush(stdout);
//   scanf("%d",&r);
//   return r;
// }
// 
// int match(int a, int b, int m){
//   sortE(a,b);
//   if(a==b) return 1;
//   if(m==0){
//     if(a==0 && b==2) return 1;
//     if(a==1 && b==3) return 1;
//   } else {
//     if(a==1 && b==2) return 1;
//     if(a==0 && b==3) return 1;
//   }
//   return 0;
// }
// 
// pair<int,int> pre_query(int x1, int y1, int x2, int y2){
//   int i, j, k, s;
//   int val[4];
//   pair<int,int> r = make_pair(0,0);
//   
//   sortE(x1, x2);
//   sortE(y1, y2);
// 
//   rep(k,1<<3){
//     i = x1;
//     j = y1;
//     val[0] = res[i][j];
//     rep(s,3){
//       if(k&1<<s) i++;
//       else       j++;
//       if(i >= N || j >= N) break;
//       val[s+1] = res[i][j];
//     }
//     if(i==x2 && j==y2){
//       if(match(val[0],val[3],0) && match(val[1],val[2],0)) r.first = 1;
//       if(match(val[0],val[3],1) && match(val[1],val[2],1)) r.second = 1;
//     }
//   }
// 
//   return r;
// }
// 
// void answer(void){
//   int i, j;
//   puts("!");
//   rep(i,N){
//     rep(j,N) printf("%d",res[i][j]);
//     puts("");
//   }
//   fflush(stdout);
// }
// 
// {
//   int i, j, k;
//   int si, sj, ni, nj;
//   int di[4] = {1,-1,2,0}, dj[4] = {1,-1,0,2}, d;
//   int st[10000], sts;
//   pair<int,int> p;
//   scanf("%d", &N);
// 
//   rep(i,N) rep(j,N) res[i][j] = -1;
//   res[0][0] = 1;
//   res[N-1][N-1] = 0;
// 
//   for(i=2;i<N;i+=2){
//     k = query(0, i-2, 0, i);
//     res[0][i] = (res[0][i-2] ^ k ^ 1);
//     k = query(i-2, 0, i, 0);
//     res[i][0] = (res[i-2][0] ^ k ^ 1);
//   }
//   rep(i,1,N) rep(j,1,N) if( (i+j)%2==0 && i+j != 2N-2 ){
//     k = query(i-1, j-1, i, j);
//     res[i][j] = (res[i-1][j-1] ^ k ^ 1);
//   }
// 
//   res[0][1] = 2;
//   sts = 0;
//   st[sts++] = 1;
//   while(sts){
//     k = st[--sts];
//     si = k / N;
//     sj = k % N;
//     rep(d,4){
//       ni = si + di[d];
//       nj = sj + dj[d];
//       if(ni < 0 || nj < 0 || ni >= N || nj >= N || res[ni][nj] != -1) continue;
//       i = query(si, sj, ni, nj);
//       res[ni][nj] = (res[si][sj] ^ i ^ 1);
//       st[sts++] = ni * N + nj;
//     }
//   }
// 
//   rep(si,N) rep(sj,N) rep(k,4){
//     ni = si + k;
//     nj = sj + (3 - k);
//     if(ni >= N || nj >= N) continue;
//     p = pre_query(si, sj, ni, nj);
//     if(p.first != p.second){
//       d = query(si, sj, ni, nj);
//       if(p.first == d){
//         rep(i,N) rep(j,N){
//           if(res[i][j] == 2) res[i][j] = 0;
//           if(res[i][j] == 3) res[i][j] = 1;
//         }
//       } else {
//         rep(i,N) rep(j,N){
//           if(res[i][j] == 2) res[i][j] = 1;
//           if(res[i][j] == 3) res[i][j] = 0;
//         }
//       }
//     }
//   }
// 
//   answer();
// }