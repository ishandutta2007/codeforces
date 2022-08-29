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
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

ll L, R, K;

ll opt, ress, res[1000];

int main(){
  int i, j;
  ll nx, mx;

  reader(&L);
  reader(&R);
  reader(&K);

  if(K==1){
    opt = L;
    ress = 1;
    res[0] = L;
  } else if(R-L==1){
    opt = L;
    ress = 1;
    res[0] = L;
    if((L^(L+1)) < opt){
      opt = L^(L+1);
      ress = 2;
      res[0] = L; res[1] = L+1;
    }
  } else {
    if(L%2==0){
      opt = L^(L+1);
      ress = 2;
      res[0] = L; res[1] = L+1;
    } else {
      opt = (L+1)^(L+2);
      ress = 2;
      res[0] = L+1; res[1] = L+2;
    }

    if(K >= 3){
      nx = 1;
      while(nx <= L) nx *= 2;
      if(nx/2 != L){
        if(nx+nx/2 <= R){
          opt = 0;
          ress = 3;
          res[0] = L; res[1] = nx+(L-nx/2); res[2] = nx+nx/2;
        }
      } else {
        if(L+nx <= R){
          opt = 0;
          ress = 3;
          res[0] = L; res[1] = nx; res[2] = L+nx;
        }
      }
    }

    if(K >= 4){
      rep(i,100){
        if(opt > ((L+i)^(L+i+1)^(L+i+2)^(L+i+3)) && L+i+3 <= R){
          opt = ((L+i)^(L+i+1)^(L+i+2)^(L+i+3));
          ress = 4;
          rep(j,4) res[j] = L+i+j;
        }
      }
    }
  }

  writer(opt, '\n');
  writer(ress, '\n');
  rep(i,ress) writer(res[i],i==ress-1?'\n':' ');

  myed;
  return 0;
}