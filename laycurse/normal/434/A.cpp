#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

vector<int> ni[100001];
int N, A[100001];

int main(){
  int i, j, k;
  ll res = 0, sa = 0;
  ll tmp, opt;

  reader(&N);
  reader(&N);
  rep(i,N) reader(A+i);
  REP(i,1,N) res += abs(A[i]-A[i-1]);

  REP(i,1,N) if(A[i-1]!=A[i]){
    ni[A[i-1]].push_back(A[i]);
    ni[A[i]].push_back(A[i-1]);
  }

 
  rep(i,100001) if(ni[i].size()){
    tmp = opt = 0;
    sort(ni[i].begin(), ni[i].end());
    
    rep(j,ni[i].size()) tmp += abs(i-ni[i][j]);

    k = ni[i][ni[i].size() / 2];
    rep(j,ni[i].size()) opt += abs(k-ni[i][j]);

    sa = max(sa, tmp-opt);
  }

  res -= sa;
  writer(res, '\n');

  myed;
  return 0;
}