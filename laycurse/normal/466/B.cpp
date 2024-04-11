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

void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}

ll N, A, B;
ll area, resA, resB, tmpA, tmpB;

int main(){
  int i, j, k;

  reader(&N); N *= 6;
  reader(&A);
  reader(&B);

  area = 1000000000000000001LL;
  rep(i,100000){
    tmpA = A + i;
    tmpB = max(B, (N + tmpA-1) / tmpA);
    if(area > tmpA * tmpB){
      area = tmpA * tmpB;
      resA = tmpA;
      resB = tmpB;
    }

    tmpB = B + i;
    tmpA = max(A, (N + tmpB-1) / tmpB);
    if(area > tmpA * tmpB){
      area = tmpA * tmpB;
      resA = tmpA;
      resB = tmpB;
    }
  }

  writer(area, '\n');
  writer(resA, ' '); writer(resB, '\n');

  myed;
  return 0;
}