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
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

#define INF 1000000000

int N, M;
int T[110000], X[110000], Y[110000];

vector<int> edge[110000];
int up[110000], uptm[110000], depth[110000];

int up2[110000][20], mx2[110000][20];
int tmm[110000];

void get_depth(int node, int d){
  int i, k;

  depth[node] = d;

  rep(i,20){
    if(d - (1<<i) < 0){
      up2[node][i] = -1;
      mx2[node][i] = INF;
    } else {
      if(i==0){
        up2[node][i] = up[node];
        mx2[node][i] = uptm[node];
      } else {
        k = up2[node][i-1];
        up2[node][i] = up2[k][i-1];
        mx2[node][i] = max(mx2[node][i-1], mx2[k][i-1]);
      }
    }
  }

  rep(i,edge[node].size()) get_depth(edge[node][i], d+1);
}

int main(){
  int i, j, k, q;
  int t, st, ed;

  reader(&N,&M);
  rep(i,M){
    reader(T+i);
    if(T[i]==1) reader(X+i,Y+i), X[i]--, Y[i]--;
    if(T[i]==2) reader(X+i), X[i]--;
    if(T[i]==3) reader(X+i,Y+i), X[i]--, Y[i]--;
  }

  k = 0;
  rep(i,M) if(T[i]==2) tmm[k++] = i;

  rep(i,N) up[i] = -1;
  rep(i,M) if(T[i]==1){
    edge[Y[i]].push_back(X[i]);
    up[X[i]] = Y[i];
    uptm[X[i]] = i;
  }

  rep(i,N) if(up[i]==-1) get_depth(i, 0);

  rep(q,M) if(T[q]==3){
    t = tmm[Y[q]];
    st = X[t];
    ed = X[q];

    while(depth[st] > depth[ed]){
      k = depth[st] - depth[ed];
      for(i=0;;i++) if((1<<i) > k) break;
      i--;

      if(mx2[st][i] > t) break;
      st = up2[st][i];
    }

    if(st==ed) writer("YES\n");
    else       writer("NO\n");
  }

  myed;
  return 0;
}