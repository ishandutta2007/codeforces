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
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

typedef struct struct_intfenwick{
  int size, memory;
  int *data;
}intFenwickTree;

intFenwickTree intFenwickTreeNew(int memory){
  intFenwickTree res;
  res.memory=memory; res.data=(int*)malloc(memory*sizeof(int));
  return res;
}

void intFenwickTreeDelete(intFenwickTree *t){free(t->data);}
void intFenwickTreeInit(intFenwickTree *t, int size){int i; t->size=size; rep(i,size) t->data[i]=0;}
void intFenwickTreeAdd(intFenwickTree *t,int k,int add){while(k<t->size)t->data[k]+=add, k|=k+1;}
int intFenwickTreeGet(intFenwickTree *t,int k){int res=0; while(k>=0)res+=t->data[k],k=(k&(k+1))-1; return res;}
int intFenwickTreeRange(intFenwickTree *t,int a,int b){return intFenwickTreeGet(t,b)-intFenwickTreeGet(t,a-1);}
int intFenwickTreeNthElement(intFenwickTree *t,int n){
  int a=0,b=t->size-1,k,d;
  k=intFenwickTreeGet(t,b);
  if(k <= n) return -1;
  while(b>a){
    k=(a+b)/2;
    d=intFenwickTreeGet(t,k);
    if(d>n) b=k; else a=k+1;
  }
  return a;
}

int N;
int A[110000], B[110000];

int gain;
vector<int> in[110000], sum[110000];
int used[110000];

pair<int,int> sz[110000];

int main(){
  int i, j, k, ind;
  int res = 1000000000;
  int add, gg, rest, uu, val, cnt;

  intFenwickTree t_ele = intFenwickTreeNew(11000);
  intFenwickTree t_sum = intFenwickTreeNew(11000);

  intFenwickTreeInit(&t_ele, 11000);
  intFenwickTreeInit(&t_sum, 11000);

  reader(&N);
  rep(i,N) reader(A+i, B+i);

  gain = 0;
  rep(i,100000) in[i].clear();
  rep(i,N){
    if(A[i]==0) gain++;
    else        in[A[i]-1].push_back(B[i]);
  }

  rep(i,100000) sz[i] = make_pair(in[i].size(), i);
  sort(sz, sz+100000);
  reverse(sz, sz+100000);
  
  rep(i,100000) if(in[i].size()){
    sort(in[i].begin(), in[i].end());
    sum[i].clear();
    k = 0;
    rep(j,in[i].size()){
      k += in[i][j];
      sum[i].push_back(k);

      intFenwickTreeAdd(&t_ele, in[i][j], 1);
      intFenwickTreeAdd(&t_sum, in[i][j], in[i][j]);
    }
  }

  rep(i,110000) used[i] = 0;

  for(k=sz[0].first+1; k>=0; k--){
    gg = gain;
    add = 0;
    rep(i,100000){
      if(sz[i].first >= k){
        ind = sz[i].second;
        uu = sz[i].first - k + 1;
        add += sum[ind][uu-1];
        gg += uu;
        while(used[ind] < uu){
          intFenwickTreeAdd(&t_ele, in[ind][used[ind]], -1);
          intFenwickTreeAdd(&t_sum, in[ind][used[ind]], -in[ind][used[ind]]);
          used[ind]++;
        }
      } else {
        break;
      }
    }

    rest = k - gg;
    if(rest <= 0){
      res = min(res, add);
      break;
    }

    val = intFenwickTreeNthElement(&t_ele, rest-1);
    if(val == -1) continue;
    cnt = intFenwickTreeGet(&t_ele, val);
    add += intFenwickTreeGet(&t_sum, val) - val * (cnt - rest);

    res = min(res, add);
  }

  writer(res,'\n');

  myed;
  return 0;
}