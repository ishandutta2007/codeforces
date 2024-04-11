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

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int X, Y;
char mp[1111][1111];
int sum[1111][1111];

int getn(int x1, int y1, int x2, int y2){
  return sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1];
}

int main(){
  int i, j, k, si, sj, di, dj;
  int fg1, fg2;
  int all, cnt;
  int res = 1000000000;

  reader(&X,&Y);
  rep(i,X) reader(mp[i]);

  rep(i,X+1) rep(j,Y+1) sum[i][j] = 0;
  rep(i,X) rep(j,Y){
    sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j];
    if(mp[i][j]=='X') sum[i+1][j+1]++;
  }

  all = getn(0, 0, X-1, Y-1);

  k = 0;
  rep(i,X) if(!k) rep(j,Y) if(!k) if(mp[i][j]=='X'){
    k++;
    si = i;
    sj = j;
  }

  REP(di,1,X+1) REP(dj,1,Y+1){
    i = si; j = sj;
    
    if(di*dj >= res) continue;
    if(i+di-1 >= X) continue;
    if(j+dj-1 >= Y) continue;
    if(getn(i,j,i+di-1,j+dj-1) != di*dj) continue;

    cnt = di * dj;
    for(;;){
      fg1 = fg2 = 0;
      if(i+di < X && getn(i+1,j,i+di,j+dj-1) == di*dj) fg1 = 1;
      if(j+dj < Y && getn(i,j+1,i+di-1,j+dj) == di*dj) fg2 = 1;
      if(fg1 == fg2) break;

      if(fg1) i++, cnt += dj;
      else    j++, cnt += di;
    }

    if(cnt==all) res = di*dj;
  }

  if(res==1000000000) res = -1;
  writer(res,'\n');

  myed;
  return 0;
}