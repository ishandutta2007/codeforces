#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

#define LIM 100000

ll X, K;

ll yaku[10000];
int yakus;
vector<int> edge[10000];
int rest;

void dfs(int depth, int node){
  int i;

  if(rest==0) return;

  if(node==0){
    rest--;
    writer(yaku[node], ' ');
    return;
  }

  if(node==1){
    rep(i,K-depth){
      rest--;
      writer(yaku[0], ' ');
      if(rest==0) return;
    }
    rest--;
    writer(yaku[node], ' ');
    return;
  }

  if(depth==K){
    rest--;
    writer(yaku[node], ' ');
    return;
  }

  rep(i,edge[node].size()){
    dfs(depth+1, edge[node][i]);
    if(rest==0) return;
  }
}

void solve(){
  ll i, j, k;
  
  rest = LIM;
  if(X==1 || K==0){
    writer(X, ' ');
    return;
  }

  if(K>=LIM){
    rep(i,LIM) writer(1LL, ' ');
    return;
  }

  yakus = 0;
  for(i=1;i*i<=X;i++) if(X%i==0){
    yaku[yakus++] = i;
    if(X/i!=i) yaku[yakus++] = X/i;
  }
  sort(yaku, yaku+yakus);

  rep(i,yakus) edge[i].clear();
  rep(i,yakus) rep(j,i+1) if(yaku[i]%yaku[j]==0) edge[i].push_back(j);

  dfs(0, yakus-1);
}

int main(){
  reader(&X);
  reader(&K);
  solve();

  myed;
  return 0;
}