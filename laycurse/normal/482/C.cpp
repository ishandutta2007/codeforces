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
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int N, L;
char in[66][33];

int mask[66][66], mask2[66];

int dp[1200000];
int bc[1200000];
double comb[100][100];

ll memo[1200000];

int main(){
  int i, j, k, mas;
  int st, m;
  double res, tmp;

  rep(i,100) comb[0][i] = 0;
  rep(i,100) comb[i][0] = 1;
  REP(i,1,100) REP(j,1,100) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];

  reader(&N);
  if(N==1){puts("0"); return 0;}
  rep(i,N) L = reader(in[i]);

  rep(i,N) rep(j,N){
    mask[i][j] = 0;
    rep(k,L) if(in[i][k]==in[j][k]) mask[i][j] |= (1<<k);
  }

  bc[0] = 0;
  REP(i,1,1<<L) bc[i] = bc[i&(i-1)]+1;

  rep(i,N) rep(j,N) if(i!=j) memo[mask[i][j]] |= (1LL<<i);
  for(j=(1<<L)-1;j>=0;j--){
    rep(k,L) if(!(j & 1<<k)) memo[j] |= memo[j^(1<<k)];
  }

  res = 0;
  rep(mas,1<<L){
    dp[mas] = 0;
    if(mas==0) continue;

    rep(i,N) if((memo[mas]&(1LL<<i))==0) dp[mas]++;

    tmp = 1.0 / comb[L][bc[mas]-1];
    tmp /= (L-bc[mas]+1);
    rep(i,L) if(mas & 1<<i){
      res += (dp[mas] - dp[mas - (1<<i)]) * tmp * bc[mas];
    }
  }

  printf("%.10f\n",res / N);

  myed;
  return 0;
}