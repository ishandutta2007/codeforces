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

int X, Y;
char in[2020][2020];
int deg[5000000];
int st[5000000], st_size;

int dx[4] = {-1,1,0,0}, dy[4]={0,0,-1,1};
int get_deg(int a, int b){
  int i, j, k, res = 0;
  if(in[a][b]!='.') return 0;
  rep(k,4){
    i = a+dx[k];
    j = b+dy[k];
    if(i < 0 || j < 0 || i >= X || j >= Y) continue;
    if(in[i][j]=='.') res++;
  }
  return res;
}

int main(){
  int i, j, k, d, ni, nj, dd, nni, nnj;

  reader(&X,&Y);
  rep(i,X) reader(in[i]);

  rep(i,X) rep(j,Y){
    deg[i*Y+j] = get_deg(i,j);
    if(deg[i*Y+j]==1) st[st_size++] = i*Y+j;
  }

//  rep(i,X) writerArr(deg+i*Y, X);

  while(st_size){
    k = st[--st_size];
    if(deg[k]!=1) continue;

    i = k/Y; j = k%Y;
    rep(d,4){
      ni = i + dx[d];
      nj = j + dy[d];
      if(ni < 0 || nj < 0 || ni >= X || nj >= Y) continue;
      if(in[ni][nj] != '.') continue;

      if(d==0) in[i][j] = 'v', in[ni][nj] = '^';
      if(d==1) in[i][j] = '^', in[ni][nj] = 'v';
      if(d==2) in[i][j] = '>', in[ni][nj] = '<';
      if(d==3) in[i][j] = '<', in[ni][nj] = '>';

      rep(d,4){
        nni = i + dx[d];
        nnj = j + dy[d];
        if(nni<0||nnj<0||nni>=X||nnj>=Y) continue;
        deg[nni*Y+nnj] = get_deg(nni,nnj);
        if(deg[nni*Y+nnj]==1) st[st_size++] = nni*Y+nnj;
      }
      rep(d,4){
        nni = ni + dx[d];
        nnj = nj + dy[d];
        if(nni<0||nnj<0||nni>=X||nnj>=Y) continue;
        deg[nni*Y+nnj] = get_deg(nni,nnj);
        if(deg[nni*Y+nnj]==1) st[st_size++] = nni*Y+nnj;
      }
    }
  }

  k = 0;
  rep(i,X) rep(j,Y) if(in[i][j]=='.') k++;
  if(k){
    writerLn("Not unique");
  } else {
    rep(i,X) writerLn(in[i]);
  }

  return 0;
}