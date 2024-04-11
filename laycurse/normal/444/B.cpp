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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, D; ll X;
int A[110000], B[110000], C[110000];

ll getNextX(void){
  X = (X*37+10007) % 1000000007;
  return X;
}

void initAB(void){
  int i;
  rep(i,N) A[i] = i+1;
  rep(i,N) swap(A[i], A[getNextX()%(i+1)]);
  rep(i,N) if(i<D) B[i]=1; else B[i] = 0;
  rep(i,N) swap(B[i], B[getNextX()%(i+1)]);
}


int main(){
  int i, j, k;
  map<int,int> mp;
  map<int,int>::iterator it;

  reader(&N);
  reader(&D);
  reader(&X);
  
  initAB();
  rep(i,N) C[i] = 0;

  if(D < 511){
    rep(i,N) if(B[i]){
      REP(j,i,N) C[j] = max(C[j], A[j-i]);
    }
  } else {
    rep(i,N){
      mp[-A[i]] = i;
      for(it = mp.begin(); it != mp.end(); it++){
        j = it->second;
        if(B[i-j]){
          C[i] = -(it->first);
          break;
        }
      }
    }
  }

  rep(i,N) writer(C[i], '\n');

  myed;
  return 0;
}