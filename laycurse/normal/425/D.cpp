#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cassert>
#include<cstring>
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
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, X[100001], Y[100001];
vector<int> xlist[100001], ylist[100001];

int main(){
  int i,j,k,l,m,d,geta, mode;
  int res = 0;
  vector<int> *lis;

  reader(&N);
  rep(i,N) reader(X+i), reader(Y+i);

  rep(i,N){
    xlist[X[i]].push_back( Y[i] );
    ylist[Y[i]].push_back( X[i] );
  }
  rep(i,100001){
    sort(xlist[i].begin(), xlist[i].end());
    sort(ylist[i].begin(), ylist[i].end());
  }

  rep(i,N){
    if(xlist[X[i]].size() < ylist[Y[i]].size()) lis = &xlist[X[i]], geta = Y[i], mode = 0;
    else                                        lis = &ylist[Y[i]], geta = X[i], mode = 1;

    rep(k,lis->size()){
      d = (*lis)[k] - geta;
      if(d<=0) continue;

      if(mode!=0 && !binary_search( xlist[X[i]].begin(), xlist[X[i]].end(), Y[i]+d)) continue;
      if(mode!=1 && !binary_search( xlist[X[i]+d].begin(), xlist[X[i]+d].end(), Y[i])) continue;
      if(!binary_search( xlist[X[i]+d].begin(), xlist[X[i]+d].end(), Y[i]+d)) continue;
      res++;
    }
  }

  writer(res, '\n');
  myed;
  return 0;
}