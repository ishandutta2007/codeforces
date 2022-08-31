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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int N, M, Q;
int mode;
int ind[500000], len[500000];
vector<int> edge[500000];

int dist[500000];
int reach[500000], reachsz;
int caled[500000];

void dfs(int now, int bef, int d){
  int i, j, k;

  reach[reachsz++] = now;
  dist[now] = d;

  rep(i,edge[now].size()){
    k = edge[now][i];
    if(k==bef) continue;
    dfs(k, now, d+1);
  }
}

int main(){
  int i, j, k;
  int mx, mx_ind;

  reader(&N,&M,&Q);

  rep(i,N) edge[i].clear();
  while(M--){
    reader(&i,&j); i--; j--;
    edge[i].push_back(j);
    edge[j].push_back(i);
  }

  unionInit(ind, N);

  rep(i,N) caled[i] = 0;
  rep(i,N) if(caled[i]==0){
    reachsz = 0;
    dfs(i, -1, 0);
    mx = -1;
    rep(j,reachsz){
      k = reach[j];
      if(mx < dist[k]) mx = dist[k], mx_ind = k;
    }

    reachsz = 0;
    dfs(mx_ind, -1, 0);
    mx = 0;
    rep(j,reachsz){
      k = reach[j];
      caled[k] = 1;
      mx = max(mx, dist[k]);
      unionConnect(ind, i, k);
    }
    len[unionGet(ind, i)] = mx;
  }

  while(Q--){
    reader(&mode);
    if(mode==1){
      reader(&i); i--;
      i = unionGet(ind, i);
      writer(len[i], '\n');
    } else {
      reader(&i,&j); i--; j--;
      i = unionGet(ind, i);
      j = unionGet(ind, j);
      if(i != j){
        mx = max(len[i], len[j]);
        mx = max(mx, (len[i]+1)/2 + 1 + (len[j]+1)/2);
        unionConnect(ind, i, j);
        i = unionGet(ind, i);
        len[i] = mx;
      }
    }
  }

  myed;
  return 0;
}