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

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

void intIntIntSort(int d[],int m1[],int m2[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m1[i];m1[i]=m1[j];m1[j]=t;t=m2[i];m2[i]=m2[j];m2[j]=t;}intIntIntSort(d,m1,m2,i);intIntIntSort(d+j+1,m1+j+1,m2+j+1,s-j-1);}

int N, M, A[200000];
int x[200000], y[200000], c[200000];

int ind[200000], sz[200000];

int main(){
  int i, j, k, l;
  double res = 0;

  reader(&N,&M);
  rep(i,N) reader(A+i);
  rep(i,M) reader(x+i, y+i), x[i]--, y[i]--;

  rep(i,M) c[i] = min(A[x[i]], A[y[i]]);
  intIntIntSort(c,x,y,M);

  unionInit(ind, N);
  rep(i,N) sz[i] = 1;

  for(k=M-1;k>=0;k--){
    i = unionGet(ind, x[k]);
    j = unionGet(ind, y[k]);
    if(i==j) continue;
    res += 2.0 * c[k] * sz[i] * sz[j];
    unionConnect(ind, i, j);
    l = unionGet(ind, i);
    sz[l] = sz[i] + sz[j];
  }

  res /= N;
  res /= N-1;
  printf("%.10f\n",res);

  myed;
  return 0;
}