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

int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> int KMP(T A[], int As, T B[], int Bs, S res[], void *mem){int i,k,c=0,*f=(int*)mem;k=f[0]=-1;rep(i,Bs){while(k>=0&&B[k]!=B[i])k=f[k];f[i+1]=++k;}if(res!=NULL)rep(i,As-Bs+1)res[i]=0;k=0;rep(i,As){while(k>=0&&B[k]!=A[i])k=f[k];if(++k==Bs){c++;if(res!=NULL)res[i-Bs+1]=1;k=f[k];}}return c;}

#define MD 1000000007

int Slen, Tlen;
char S[200000], T[200000];

ll dp[200000];
int ok[200000], nx[200000];

int main(){
  int i, j, k;
  ll res;
  void *mem = malloc(10000000);

  Slen = reader(S);
  Tlen = reader(T);

  KMP(S, Slen, T, Tlen, ok+Tlen, mem);

  nx[Slen+1] = Slen+1;
  for(i=Slen;i>=0;i--){
    nx[i] = nx[i+1];
    if(ok[i]) nx[i] = i;
  }

  res = 0;
  rep(i,Slen+1){
    if(i) (dp[i] += dp[i-1]) %= MD;
    (res += dp[i]) %= MD;
    if(i+Tlen <= Slen) k = nx[i+Tlen]; else k = Slen+1;
    if(k>Slen) continue;
    (dp[k] += res + 1) %= MD;
  }

  if(res < 0) res += MD;
  writerLn((int)res);

  myed;
  return 0;
}