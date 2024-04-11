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

int N; char S[210];
int dp[210][210][210];

int edge[3][3];

int solve(int a, int b, int c){
  int i, j, k, x, y;
  int res = 0;

  if(dp[a][b][c] > 0) return dp[a][b][c];

  if(a+b+c==1){
    if(a) res |= (1<<0);
    if(b) res |= (1<<1);
    if(c) res |= (1<<2);
    return dp[a][b][c] = res;
  }
  
  if(a >= 2) res |= solve(a-1, b, c);
  if(b >= 2) res |= solve(a, b-1, c);
  if(c >= 2) res |= solve(a, b, c-1);
  if(a && b) res |= solve(a-1, b-1, c+1);
  if(a && c) res |= solve(a-1, b+1, c-1);
  if(b && c) res |= solve(a+1, b-1, c-1);

  return dp[a][b][c] = res;
}

int main(){
  int i, j, k;
  int a=0, b=0, c=0;

  rep(i,3) edge[i][i] = i;
  edge[0][1] = edge[1][0] = 2;
  edge[0][2] = edge[2][0] = 1;
  edge[1][2] = edge[2][1] = 0;

  reader(&N,S);
  rep(i,N){
    if(S[i]=='B') a++;
    else if(S[i]=='G') b++;
    else if(S[i]=='R') c++;
  }

  k = solve(a,b,c);
  if(k&1<<0) mypc('B');
  if(k&1<<1) mypc('G');
  if(k&1<<2) mypc('R');
  mypc('\n');
  
  return 0;
}