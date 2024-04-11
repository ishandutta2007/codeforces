#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, in[200];

int mp[10][10], arr[10][10];
char buf[100];

int main(){
  int i, j, k, x, y, xx, yy;
  int res, tmp;

  rep(i,10) rep(j,10) mp[i][j] = 0;
  reader(&N);
  rep(i,N){
    reader(buf);
    in[i] = buf[1] - '1';
    if(buf[0]=='G') in[i] += 5;
    if(buf[0]=='B') in[i] += 10;
    if(buf[0]=='Y') in[i] += 15;
    if(buf[0]=='W') in[i] += 20;

    mp[in[i]/5][in[i]%5] = 1;
  }

  res = 1000000;
  rep(i,1<<5) rep(j,1<<5){
    k = 0;
    rep(x,6) rep(y,6) arr[x][y] = 0;
    rep(x,5) rep(y,5) if(mp[x][y]){
      if(i & 1<<x) xx = x; else xx = 5;
      if(j & 1<<y) yy = y; else yy = 5;
      arr[xx][yy]++;
      if(arr[xx][yy] > 1) k = 1;
    }

    if(k) continue;

    tmp = 0;
    rep(k,5) if(i & 1<<k) tmp++;
    rep(k,5) if(j & 1<<k) tmp++;
    res = min(res, tmp);
  }

  writer(res, '\n');

  myed;
  return 0;
}