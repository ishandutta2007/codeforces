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
char in[1111][1111];
int dist[3][1111][1111];

int q[4111111], q_st, q_ed;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void get_dist(int ind, char c){
  int i, j, k, d;
  int ni, nj;

  rep(i,X) rep(j,Y) dist[ind][i][j] = -1;

  q_st = q_ed = 2000110;
  rep(i,X) rep(j,Y) if(in[i][j]==c){
    dist[ind][i][j] = 0;
    q[q_ed++] = i*Y+j;
  }

  while(q_st < q_ed){
    k = q[q_st++];
    i = k / Y;
    j = k % Y;
    rep(k,4){
      ni = i + dx[k];
      nj = j + dy[k];
      if(i < 0 || j < 0 || i >= X || j >= Y) continue;
      if(in[ni][nj]=='#') continue;
      
      if(in[ni][nj]=='.') d = dist[ind][i][j] + 1;
      else                d = dist[ind][i][j];

      if(dist[ind][ni][nj]==-1 || dist[ind][ni][nj] > d){
        dist[ind][ni][nj] = d;
        if(d == dist[ind][i][j]) q[--q_st] = ni * Y + nj;
        else                     q[q_ed++] = ni * Y + nj;
      }
    }
  }

}

int main(){
  int i, j, k;
  int res;

  reader(&X,&Y);
  rep(i,X) reader(in[i]);
  get_dist(0,'1');
  get_dist(1,'2');
  get_dist(2,'3');

//  rep(i,X) writerArr(dist[0][i], Y); puts("");
//  rep(i,X) writerArr(dist[1][i], Y); puts("");
//  rep(i,X) writerArr(dist[2][i], Y); puts("");

  res = MD;
  rep(i,X) rep(j,Y){
    if(dist[0][i][j]==-1) continue;
    if(dist[1][i][j]==-1) continue;
    if(dist[2][i][j]==-1) continue;
    k = dist[0][i][j]+dist[1][i][j]+dist[2][i][j];
    if(in[i][j]=='.') k-=2;
    res = min(res, k);
  }

  if(res==MD) res = -1;
  writerLn(res);

  return 0;
}