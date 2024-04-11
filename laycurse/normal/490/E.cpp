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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

#define MD 1000000007

int N;
int len[110000];
char S[110000][11];

int main(){
  int i, j, k, c;
  int dame = 0, ok;

  reader(&N);
  rep(i,N) len[i] = reader(S[i]);

  rep(i,N){
    if(i==0 || len[i]>len[i-1]){
      rep(j,len[i]) if(S[i][j]=='?') S[i][j] = (j==0?'1':'0');
    } else if(len[i] < len[i-1]){
      dame = 1;
    } else {
      ok = 0;
      rep(j,len[i]){
        if(ok==1 && S[i][j] != '?') continue;
        if(ok==0 && S[i][j] != '?' && S[i][j] < S[i-1][j]){ dame = 1; break; }
        if(ok==0 && S[i][j] != '?' && S[i][j] > S[i-1][j]){ ok = 1; continue; }
        if(ok==0 && S[i][j] != '?' && S[i][j] ==S[i-1][j]){ continue; }
        if(ok==1 && S[i][j] == '?'){ S[i][j] = '0'; continue; }

        c = 0;
        REP(k,j+1,len[i]){
          if(S[i][k] != '?' && S[i][k] < S[i-1][k]) break;
          if(S[i][k] != '?' && S[i][k] > S[i-1][k]){ c=1; break; }
          if(S[i][k] == '?' && S[i-1][k] != '9'){ c=1; break; }
        }
        if(c){ S[i][j] = S[i-1][j]; continue; }
        if(S[i-1][j]=='9'){ dame=1; break; }
        S[i][j] = S[i-1][j] + 1;
        ok = 1;
      }
      if(!ok) dame=1;
    }
    if(dame) break;
  }

  if(dame){
    writerLn("NO");
  }else{
    writerLn("YES");
    rep(i,N) writerLn(S[i]);
  }

  myed;
  return 0;
}