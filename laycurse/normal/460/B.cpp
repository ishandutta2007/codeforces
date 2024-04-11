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

void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

ll pw(ll a, ll b){
  ll res = 1;
  while(b--) res *= a;
  return res;
}

ll sod(ll x){
  ll res = 0;
  while(x) res += x%10, x/=10;
  return res;
}

ll A, B, C;
int res[10000], ress;

int main(){
  int i, j, k;
  ll x, sx;

  ress = 0;
  reader(&A); reader(&B); reader(&C);

  REP(sx,1,100){
    x = B * pw(sx, A) + C;
    if(x >= 1000000000) continue;
    if(sod(x) != sx) continue;
    res[ress++] = x;
  }
  
  sort(res,res+ress);
  writer(ress,'\n');
  rep(i,ress) writer(res[i],i==ress-1?'\n':' ');

  myed;
  return 0;
}