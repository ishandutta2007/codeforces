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
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, A[1000000];

int nx[1000000], bk[1000000], val[1000000];

int main(){
  int i, j, k;
  ll res;

  reader(&N);
  rep(i,N) reader(A+i);

  if(N<=2){ writer(0LL, '\n'); myed; return 0; }

  rep(i,N) nx[i] = i+1; nx[N-1] = -1;
  rep(i,N) bk[i] = i-1;

  res = 0;

  i = 0;
  for(;;){
    if(nx[i]==-1) break;
    if(bk[i]==-1){ i=nx[i]; continue; }

    if(A[bk[i]] >= A[i] && A[i] <= A[nx[i]]){
      res += min(A[bk[i]], A[nx[i]]);

      nx[bk[i]] = nx[i];
      bk[nx[i]] = bk[i];
      i = bk[i];
    } else {
      i = nx[i];
    }
  }

  rep(i,N) val[i] = -1;
  
  i = 0;
  for(;;){
    if(i==0 && nx[i]==N-1) break;
    if(i==N-1 && bk[i]==0) break;

    if(i==0){ i=nx[i]; continue; }
    if(i==N-1){ i=bk[i]; continue; }

    val[i] = min(A[bk[i]], A[nx[i]]);

    if(nx[i] != N-1 && (val[nx[i]] == -1 || val[i] < val[nx[i]])){ i = nx[i]; continue; }
    if(bk[i] != 0   && (val[bk[i]] == -1 || val[i] < val[bk[i]])){ i = bk[i]; continue; }

    res += min(A[bk[i]], A[nx[i]]);
    val[bk[i]] = val[nx[i]] = -1;
    
    nx[bk[i]] = nx[i];
    bk[nx[i]] = bk[i];
    i = bk[i];
  }

  writer(res, '\n');

  myed;
  return 0;
}