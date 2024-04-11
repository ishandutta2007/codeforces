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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int As, Bs;
ll A[200000], B[200000];
ll sumA[200000], sumB[200000];

int main(){
  int i, j, k;
  ll res, tmp;

  reader(&As,&Bs);
  rep(i,As) reader(A+i);
  rep(i,Bs) reader(B+i);

  sort(A, A+As); reverse(A, A+As);
  sort(B, B+Bs); reverse(B, B+Bs);

  sumA[0] = sumB[0] = 0;
  rep(i,As) sumA[i+1] = sumA[i] + A[i];
  rep(i,Bs) sumB[i+1] = sumB[i] + B[i];

  res = sumA[As] + sumB[Bs];

  REP(i,1,As+1){
    if(sumB[Bs] * i >= res) break;
    tmp = (sumA[As] - sumA[i]) + sumB[Bs] * i;
    res = min(res, tmp);
  }
  REP(i,1,Bs+1){
    if(sumA[As] * i >= res) break;
    tmp = (sumB[Bs] - sumB[i]) + sumA[As] * i;
    res = min(res, tmp);
  }

  writer(res, '\n');

  myed;
  return 0;
}