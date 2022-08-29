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
char A[1100000], B[1100000];

int main(){
  int i, j, k, loop, ok;
  int x, y, bx, by;
  int cnv[333];

  cnv['N'] = 0;
  cnv['E'] = 1;
  cnv['S'] = 2;
  cnv['W'] = 3;

  reader(&N,A,B);
  N--;
  rep(i,N) A[i] = cnv[A[i]];
  rep(i,N) B[i] = cnv[B[i]];

  x = y = 0;

  for(;;){
    if(x==N && y==N){ writerLn("YES"); return 0; }
    if(x==N){
      if(x==0 || B[y]!=(A[x-1]+2)%4){ y++; continue; }
    } else if(y==N){
      if(y==0 || A[x]!=(B[y-1]+2)%4){ x++; continue; }
    } else {
      if(A[x]==B[y]){ x++; y++; continue; }
      if(y==0 || A[x]!=(B[y-1]+2)%4){ x++; continue; }
      if(x==0 || B[y]!=(A[x-1]+2)%4){ y++; continue; }
    }

    ok = 0;
    bx = x;
    by = y;
    while(x>0 && y<N){
      x--; y++;
      if(x<N && (y==0 || A[x]!=(B[y-1]+2)%4)){ x++; ok = 1; break; }
      if(y<N && (x==0 || B[y]!=(A[x-1]+2)%4)){ y++; ok = 1; break; }
    }
    if(ok) continue;

    ok = 0;
    x = bx;
    y = by;
    while(y>0 && x<N){
      y--; x++;
      if(x<N && (y==0 || A[x]!=(B[y-1]+2)%4)){ x++; ok = 1; break; }
      if(y<N && (x==0 || B[y]!=(A[x-1]+2)%4)){ y++; ok = 1; break; }
    }
    if(ok) continue;

    break;
  }

  writerLn("NO");

  return 0;
}