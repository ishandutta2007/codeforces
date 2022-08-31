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
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int X, Y, XY, K, M;
char mp[1200][120];

int dist[1200][1200];

int used[1200], mn[1200], method[1200];
int res_cost;
int res1[1200], res2[1200], ress;

int main(){
  int i, j, k, m, ind;

  reader(&X,&Y);
  reader(&K,&M);
  XY = X*Y;
  rep(i,K) rep(j,X) reader(mp[i]+(j*Y));

  rep(i,K) dist[i][i] = 0;
  rep(i,K) REP(j,i+1,K){
    m = 0;
    rep(k,XY) if(mp[i][k]!=mp[j][k]) m++;
    dist[i][j] = dist[j][i] = m * M;
  }

  rep(i,K) used[i] = 0, mn[i] = XY, method[i] = -1;
  res_cost = 0;
  ress = 0;
  
  for(;;){
    k = XY + 1;
    rep(i,K) if(used[i]==0 && k > mn[i]) {
      k = mn[i];
      ind = i;
    }
    if(k==XY+1) break;

    res_cost += k;
    res1[ress] = ind+1;
    res2[ress++] = method[ind]+1;
    used[ind] = 1;

    rep(i,K) if(used[i]==0){
      if(mn[i] > dist[ind][i]){
        mn[i] = dist[ind][i];
        method[i] = ind;
      }
    }
  }

  writer(res_cost, '\n');
  rep(i,ress) writer(res1[i],' '), writer(res2[i],'\n');

  myed;
  return 0;
}