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

int S, N, M;
int rule[2][200][200];

char num[222];
char in[222];

int now[222];
int st[222], sts;

int is_ok(){
  int i, j, k;

  sts = 0;
  rep(i,N){
    now[i] = -1;
    if(in[i] != '?'){
      now[i] = num[in[i]-'a'];
      st[sts++] = i;
    }
  }

  while(sts){
    i = st[--sts];
    rep(j,N){
      k = rule[now[i]][i][j];
      if(k==3) continue;
      if(k==0) return 0;
      if(now[j]==-1){
        st[sts++] = j;
        if(k==1) now[j] = 0;
        if(k==2) now[j] = 1;
      }
      if(k==1 && now[j]!=0) return 0;
      if(k==2 && now[j]!=1) return 0;
    }
  }
  
  return 1;
}

int main(){
  int i, j, k, s, a, b;
  int cnv[333];

  cnv['V'] = 0;
  cnv['C'] = 1;

  S = reader(num);
  rep(i,S) num[i] = cnv[num[i]];
  reader(&N,&M);
  rep(i,2) rep(j,N) rep(k,N) rule[i][j][k] = 3;

  rep(i,2) rep(j,N) rule[i][j][j] = (1<<i);

  while(M--){
    reader(&i,in);
    reader(&j,in+1);
    rep(k,2) in[k] = cnv[in[k]];
    i--; j--;

    rule[in[0]][i][j] &= (1<<in[1]);
    rule[1-in[1]][j][i] &= (1<<(1-in[0]));
  }

  reader(in);
  if(is_ok()){ writerLn(in); return 0; }

  for(i=N-1;i>=0;i--){
    for(;;){
      in[i]++;
      if(in[i] > 'a'+S-1) break;
      if(is_ok()) break;
    }
    if(in[i] > 'a'+S-1) in[i] = '?'; else break;
  }
  if(in[0]=='?'){ writerLn(-1); return 0; }

  rep(i,N) if(in[i]=='?'){
    in[i] = 'a';
    while(!is_ok()){
      in[i]++;
      if(in[i] > 'a'+S-1){
        writerLn(-1);
        return 0;
      }
    }
  }
  writerLn(in);

  return 0;
}