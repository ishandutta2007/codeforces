#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

int N;
char in[200][200];
char chk[200][200];

int NN;
char res[200][200];

int main(){
  int i, j, k;
  int di, dj, ni, nj;

  reader(&N);
  rep(i,N) reader(in[i]);

  NN = 2*N-1;
  rep(i,NN) rep(j,NN) res[i][j] = '.';
  res[N-1][N-1] = 'o';

  REP(di,-N+1,N) REP(dj,-N+1,N){
    if(di==0 && dj==0) continue;
    k = 0;
    rep(i,N) rep(j,N) if(in[i][j]=='o'){
      ni = i + di;
      nj = j + dj;
      if(ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
      if(in[ni][nj]=='.') k++;
    }
    if(k==0) res[N-1+di][N-1+dj] = 'x';
  }

  rep(i,N) rep(j,N) chk[i][j] = '.';
  rep(i,N) rep(j,N){
    if(in[i][j]=='o'){
      chk[i][j] = 'o';
      REP(di,-N+1,N) REP(dj,-N+1,N) if(res[N-1+di][N-1+dj]=='x'){
        ni = i + di;
        nj = j + dj;
        if(ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
        if(chk[ni][nj]=='.') chk[ni][nj] = 'x';
      }
    }
  }

  k = 0;
  rep(i,N) rep(j,N) if(chk[i][j]!=in[i][j]) k++;

//  rep(i,N) chk[i][N] = '\0';
//  rep(i,N) writerLn(chk[i]);
  
  if(k){ writerLn("NO"); }
  else {
    writerLn("YES");
    rep(i,NN) res[i][NN] = '\0';
    rep(i,NN) writerLn(res[i]);
  }

  return 0;
}