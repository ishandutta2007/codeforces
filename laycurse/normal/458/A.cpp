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

int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int NS, NT;
char S[200000], T[200000];

int main(){
  int i, j, k;
  int N;
  ll m;

  NS = reader(S);
  NT = reader(T);

  N = max(NS, NT) + 10;

  k = NS-1;
  for(i=N-1;i>=0;i--){
    if(k >= 0) S[i] = S[k]; else S[i] = '0';
    k--;
  }
  k = NT-1;
  for(i=N-1;i>=0;i--){
    if(k >= 0) T[i] = T[k]; else T[i] = '0';
    k--;
  }

  rep(i,N) S[i] -= '0';
  rep(i,N) T[i] -= '0';

  REP(i,2,N){
    m = min(S[i], S[i-1]);
    S[i] -= m; S[i-1] -= m; S[i-2] += m;
    if(m) i = max(2, i-4);
  }
  REP(i,2,N){
    m = min(T[i], T[i-1]);
    T[i] -= m; T[i-1] -= m; T[i-2] += m;
    if(m) i = max(2, i-4);
  }

//  rep(i,N) printf("%d",S[i]); puts("");
//  rep(i,N) printf("%d",T[i]); puts("");

//  double a, b, q = (sqrt(5)+1) / 2;
//  a = b = 0;
//  rep(i,N) a = a*q + S[i];
//  rep(i,N) b = b*q + T[i];
//  printf("%f %f\n",a,b);

  rep(i,N){
    if(S[i]==T[i]) continue;
    if(S[i] > T[i]){ puts(">"); break; }
    if(S[i] < T[i]){ puts("<"); break; }
  }
  if(i==N) puts("=");

  myed;
  return 0;
}