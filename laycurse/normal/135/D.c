#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x, y;
char in[1100][1100];

int st[1100000], st_size;

int nutta[1100000], nutta_size;

int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

int main(){
  int i,j,k,l,m,n,tonari;
  int reach_out_side, more_than_two, step;
  int a, b, na, nb, ii, jj;
  int res = 0;

  scanf("%d%d",&x,&y);
  rep(i,x) scanf("%s",in[i]);

  REP(i,1,x) REP(j,1,y){
    if(in[i-1][j-1]=='1' && in[i-1][j]=='1' && in[i][j-1]=='1' && in[i][j]=='1') res = 4;
  }

  rep(i,x) rep(j,y) if(in[i][j]=='0'){
    nutta_size = 0;
    reach_out_side = more_than_two = 0;

/*    printf("%d %d\n",i,j);
    rep(k,x) puts(in[k]); puts("");*/

    st_size = 0;
    a = i; b = j;
    st[st_size++] = a*y + b;
    in[a][b] = '@';
    while(st_size){
      st_size--;
      a = st[st_size]/y; b = st[st_size]%y;

      REP(ii,-1,2) REP(jj,-1,2){
        na = a+ii; nb = b+jj;
        if(na < 0 || nb < 0 || na >= x || nb >= y){
          reach_out_side = 1;
          continue;
        }
        if(in[na][nb]=='0'){
          in[na][nb] = '@';
          st[st_size++] = na*y + nb;
        }
        if(in[na][nb]=='1'){
          in[na][nb] = '2';
          nutta[nutta_size++] = na*y + nb;
        }
      }
    }

    if(nutta_size==0) continue;
    
    step = 0;
    st_size = 0;
    st[st_size++] = nutta[0];
    in[nutta[0]/y][nutta[0]%y] = '3';
    while(st_size){
      st_size--; step++;
      a = st[st_size]/y, b = st[st_size]%y;
      tonari = 0;
      rep(k,4){
        na = a + dx[k];
        nb = b + dy[k];
        if(na < 0 || nb < 0 || na >= x || nb >= y) continue;
        if(in[na][nb] == '2' || in[na][nb] == '3') tonari++;
        if(in[na][nb] == '2'){
          in[na][nb] = '3';
          st[st_size++] = na * y + nb;
        }
      }
      if(tonari != 2) more_than_two = 1;
    }

    if(step == nutta_size && reach_out_side==0 && more_than_two==0 ){
/*      printf("ok length = %d\n",step);*/
      if(res < step) res = step;
    }

    rep(k,nutta_size){
      a = nutta[k]/y; b = nutta[k]%y;
      in[a][b] = '1';
    }

  }

/*  rep(i,x) puts(in[i]); puts("");*/
  printf("%d\n",res);

  return 0;
}