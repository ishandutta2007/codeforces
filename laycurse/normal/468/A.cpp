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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

int N;
int dp[100][1000];
int sign[100];

int main(){
  int i, j, k;
  int cnt;

  reader(&N);

  if(N<=3){
    puts("NO");
    return 0;
  }
  puts("YES");

  if(N==5){
    puts("4 * 5 = 20");
    puts("20 + 3 = 23");
    puts("23 + 2 = 25");
    puts("25 - 1 = 24");
    return 0;
  }

  if(N >= 48){
    cnt = 0;
    for(i=N;i>=2;i-=2){
      printf("%d - %d = 1\n",i,i-1);
      cnt++;
    }
    if(i==1) cnt++;

    REP(i,1,24) printf("%d + 1 = %d\n",i,i+1);
    REP(i,24,cnt) puts("24 * 1 = 24");
    return 0;
  }

  dp[1][1] = 1;
  REP(i,1,N+1) rep(j,1000) if(dp[i-1][j]){
    if(j*i < 1000) dp[i][j*i] = 1;
    if(j+i < 1000) dp[i][j+i] = 1;
    if(j-i >= 0)   dp[i][j-i] = 1;
  }

  k = 24;
  for(i=N;i;i--){
    if(k%i==0) if(dp[i-1][k/i]){ sign[i] = -2; k /= i; continue; }
    
    if(dp[i-1][k+i]){ sign[i] = -1; k += i; }
    else            { sign[i] =  1; k -= i; }
  }

  k = 1;
  REP(i,2,N+1){
    if(sign[i]==-2)     printf("%d * %d = %d\n",k,i,k*i), k*=i;
    else if(sign[i]==1) printf("%d + %d = %d\n",k,i,k+i), k+=i;
    else                printf("%d - %d = %d\n",k,i,k-i), k-=i;
  }

  myed;
  return 0;
}