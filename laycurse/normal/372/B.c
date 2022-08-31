#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define READER_BUF_SIZE 65536
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}

int reader_string(char res[]){
  int len = 0;
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(!myIsSpace(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(myIsSpace(reader_buf[reader_pt])){
      reader_pt++;
      break;
    }
    res[len++] = reader_buf[reader_pt++];
  }
  res[len] = '\0';
  return len;
}


int main(){
  int i,j,k,l,m,n;
  int x, y, q;
  char mp[50][50];
  int sum[50][50];
  static int res[41][41][41][41];
  int x1, y1, x2, y2;

  x = reader_nonneg_int();
  y = reader_nonneg_int();
  q = reader_nonneg_int();
  rep(i,x) reader_string(mp[i]);

  rep(x1,x) rep(y1,y) rep(x2,x) rep(y2,y) res[x1][y1][x2][y2] = 0;

  rep(x1,x) rep(y1,y){
    REP(i,x1,x) REP(j,y1,y) sum[i][j] = 0;
    REP(i,x1,x){
      REP(j,y1,y){
        if(mp[i][j]=='1') break;
        if(i>x1 && sum[i-1][j]==0) break;
        sum[i][j] = 1;
      }
    }
    REP(i,x1,x) REP(j,y1+1,y) sum[i][j] += sum[i][j-1];
    REP(j,y1,y) REP(i,x1+1,x) sum[i][j] += sum[i-1][j];

    rep(i,x1+1) rep(j,y1+1) REP(x2,x1,x) REP(y2,y1,y) res[i][j][x2][y2] += sum[x2][y2];
  }

  while(q--){
    x1 = reader_nonneg_int() - 1;
    y1 = reader_nonneg_int() - 1;
    x2 = reader_nonneg_int() - 1;
    y2 = reader_nonneg_int() - 1;
    printf("%d\n",res[x1][y1][x2][y2]);
  }

  return 0;
}