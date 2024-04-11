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
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int getPrime(int N, int res[]){int i,a,b,s=1,f[4780],S=1;const int r=23000;bool B[r],*p=B;N/=2;res[0]=2;b=min(r,N);REP(i,1,b)p[i]=1;REP(i,1,b)if(p[i]){res[s++]=2*i+1;f[S]=2*i*(i+1);if(f[S]<N){for(;f[S]<r;f[S]+=res[S])p[f[S]]=0;S++;}}for(a=r;a<N;a+=r){b=min(a+r,N);p-=r;REP(i,a,b)p[i]=1;REP(i,1,S)for(;f[i]<b;f[i]+=res[i])p[f[i]]=0;REP(i,a,b)if(p[i])res[s++]=2*i+1;}return s;}
int ps, p[110000], isp[110000];

template<class T> T GCD(T a,T b){T r; while(a){r=b; b=a; a=r%a;} return b;}

int N, used[100010];
int res, res1[100000], res2[100000];

int main(){
  int i, j, k;

  reader(&N);
  rep(i,N+1) used[i] = 0;

  ps = getPrime(N+1, p);
  rep(i,N+1) isp[i] = 0;
  rep(i,ps) isp[p[i]] = 1;

  res = 0;
  for(i=N;i>=1;i--){
    if(used[i]) continue;
    for(j=2;j<=i/2;j++){
      while(i/(j+100) == i/j) j += 100;
      while(i/(j+10) == i/j) j += 10;
      if(i%j==0){
        if(used[i/j]) continue;
        used[i] = used[i/j] = 1;
        res1[res] = i;
        res2[res] = i/j;
        res++;
        break;
      }
    }
  }

  for(i=N;i>=1;i--) if(!isp[i] && !used[i]) for(j=i-1;j>=1;j--) if(!used[j]){
    if(GCD(i,j) > 1){
      used[i] = used[j] = 1;
      res1[res] = i;
      res2[res] = j;
      res++;
      break;
    }
  }

  writer(res,'\n');
  rep(i,res) writer(res1[i], ' '), writer(res2[i], '\n');

  myed;
  return 0;
}