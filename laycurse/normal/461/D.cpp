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
#define MD 1000000007

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int N, K;
int even[200000], odd[200000];

int main(){
  int i, j, k;
  int N1, N2;
  int x, y; char c[10];
  int mn, mx;
  int res = 1, freedom;

  reader(&N, &K);

  N1 = (N+1) / 2 + 10;
  N2 = N / 2 + 10;
  unionInit(even, N1*2);
  unionInit(odd,  N2*2);
  freedom = N;
  
  while(K--){
    reader(&x,&y); reader(c);
    x--; y--;

    mn = max(y - x, x - y);
    mx = min(y + x, 2*N - x - y - 2);

    if( (x+y)%2==0 ){
      if(mn <  0) mn = 0;
      if(mx >= N){
        mx = N-1;
        if(mx%2==1) mx--;
      }
      mn /= 2;
      mx /= 2;
      mx++;
      if(c[0]=='x'){
        k = unionConnect(even, mn, mx);
        k = unionConnect(even, mn+N1, mx+N1);
      } else {
        k = unionConnect(even, mn, mx+N1);
        k = unionConnect(even, mn+N1, mx);
      }
      freedom -= k;
    } else {
      if(mn <  1) mn = 1;
      if(mx >= N){
        mx = N-1;
        if(mx%2==0) mx--;
      }
      mn /= 2;
      mx /= 2;
      mx++;
      if(c[0]=='x'){
        k = unionConnect(odd, mn, mx);
        k = unionConnect(odd, mn+N2, mx+N2);
      } else {
        k = unionConnect(odd, mn, mx+N2);
        k = unionConnect(odd, mn+N2, mx);
      }
      freedom -= k;
    }
  }

  rep(i,freedom) res = res * 2 % MD;
  rep(i,N1) if(unionGet(even,i)==unionGet(even,i+N1)) res = 0;
  rep(i,N2) if(unionGet(odd, i)==unionGet(odd, i+N2)) res = 0;
  writer(res,'\n');

  myed;
  return 0;
}