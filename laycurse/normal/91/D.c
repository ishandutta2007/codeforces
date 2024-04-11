#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int in[120000], used[120000];
int cyc2[120000][7], cyc2_size;
int cyc3[120000][7], cyc3_size;

int now[120000], now_len;

int resA[120000][7], resB[120000][7], res_len[120000], res_size;

void proc(int now[], int now_len){
  int i,j,k;

  if(now_len==1) return;

  if(now_len==2){
    rep(i,2) cyc2[cyc2_size][i] = now[i];
    cyc2_size++;
    return;
  }
  
  if(now_len==3){
    rep(i,3) cyc3[cyc3_size][i] = now[i];
    cyc3_size++;
    return;
  }
  
  if(now_len==4 || now_len==5){
    res_len[res_size] = now_len;
    rep(i,now_len) resA[res_size][i] = now[i];
    rep(i,now_len) resB[res_size][i] = now[(i+1)%now_len];
    res_size++;
    return;
  }

  res_len[res_size] = 5;
  rep(i,5) resA[res_size][i] = now[i];
  rep(i,5) resB[res_size][(i+4)%5] = now[i];
  now[4]=now[0];
  res_size++;

  proc(now+4, now_len-4);
}

int main(){
  int i,j,k,l,m,n;
  int start;

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);
    rep(i,n) used[i] = 0;
    rep(i,n) in[i]--;

    cyc2_size = cyc3_size = res_size = 0;

    rep(start,n) if(!used[start]){
      now_len = 0;
      k = start;
      while(!used[k]){
        now[now_len++] = k;
        used[k] = 1;
        k = in[k];
      }

      proc(now,now_len);
    }

    while(cyc2_size && cyc3_size){
      res_len[res_size] = 5;
      rep(i,2) resA[res_size][i  ] = cyc2[cyc2_size-1][ i     ];
      rep(i,2) resB[res_size][i  ] = cyc2[cyc2_size-1][(i+1)%2];
      rep(i,3) resA[res_size][i+2] = cyc3[cyc3_size-1][ i     ];
      rep(i,3) resB[res_size][i+2] = cyc3[cyc3_size-1][(i+1)%3];
      res_size++;
      cyc2_size--; cyc3_size--;
    }

    while(cyc3_size>=3){
      res_len[res_size  ] = 5;
      rep(i,3) resA[res_size  ][i  ] = cyc3[cyc3_size-1][ i     ];
      rep(i,3) resB[res_size  ][i  ] = cyc3[cyc3_size-1][(i+1)%3];
      cyc3_size--;

      res_len[res_size+1] = 5;
      rep(i,3) resA[res_size+1][i  ] = cyc3[cyc3_size-1][ i     ];
      rep(i,3) resB[res_size+1][i  ] = cyc3[cyc3_size-1][(i+1)%3];
      cyc3_size--;

      resA[res_size  ][3] = cyc3[cyc3_size-1][0]; resA[res_size  ][4] = cyc3[cyc3_size-1][1];
      resB[res_size  ][3] = cyc3[cyc3_size-1][1]; resB[res_size  ][4] = cyc3[cyc3_size-1][0];
      resA[res_size+1][3] = cyc3[cyc3_size-1][0]; resA[res_size+1][4] = cyc3[cyc3_size-1][2];
      resB[res_size+1][3] = cyc3[cyc3_size-1][2]; resB[res_size+1][4] = cyc3[cyc3_size-1][0];
      cyc3_size--;

      res_size+=2;
    }

    while(cyc2_size>=2){
      res_len[res_size] = 4;
      rep(i,2) resA[res_size][i  ] = cyc2[cyc2_size-1][ i     ];
      rep(i,2) resB[res_size][i  ] = cyc2[cyc2_size-1][(i+1)%2];
      cyc2_size--;
      rep(i,2) resA[res_size][i+2] = cyc2[cyc2_size-1][ i     ];
      rep(i,2) resB[res_size][i+2] = cyc2[cyc2_size-1][(i+1)%2];
      cyc2_size--;
      res_size++;
    }

    while(cyc2_size){
      res_len[res_size] = 2;
      rep(i,2) resA[res_size][i  ] = cyc2[cyc2_size-1][ i     ];
      rep(i,2) resB[res_size][i  ] = cyc2[cyc2_size-1][(i+1)%2];
      res_size++;
      cyc2_size--;
    }

    while(cyc3_size){
      res_len[res_size] = 3;
      rep(i,3) resA[res_size][i  ] = cyc3[cyc3_size-1][ i     ];
      rep(i,3) resB[res_size][i  ] = cyc3[cyc3_size-1][(i+1)%3];
      res_size++;
      cyc3_size--;
    }

    printf("%d\n",res_size);
    rep(i,res_size){
      printf("%d\n",res_len[i]);
      rep(k,res_len[i]){
        if(k) putchar(' ');
        printf("%d",resA[i][k]+1);
      }
      puts("");
      rep(k,res_len[i]){
        if(k) putchar(' ');
        printf("%d",resB[i][k]+1);
      }
      puts("");
    }
  }


  return 0;
}