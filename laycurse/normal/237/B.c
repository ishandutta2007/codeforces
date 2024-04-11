#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,s;
  int a, b, fin;
  int x, y[100];
  int in[100][100];
  int res[10000][4], res_size = 0;

  scanf("%d",&x);
  rep(i,x) scanf("%d",y+i);
  rep(i,x) rep(j,y[i]) scanf("%d",in[i]+j);

  s = 0;
  rep(i,x) s += y[i];

  m = 0;
  rep(i,x) rep(j,y[i]){
    fin = 0;
    m++;
    rep(a,x) if(!fin) rep(b,y[i]){
      if(in[a][b]==m){
        fin = 1;
        k = a;
        l = b;
        break;
      }
    }
    if(i==k && j==l) continue;
    res[res_size][0] = i;
    res[res_size][1] = j;
    res[res_size][2] = k;
    res[res_size][3] = l;
    res_size++;
    a = in[i][j];
    in[i][j] = in[k][l];
    in[k][l] = a;
  }

  printf("%d\n",res_size);
  rep(i,res_size) printf("%d %d %d %d\n",res[i][0]+1,res[i][1]+1,res[i][2]+1,res[i][3]+1);

  return 0;
}