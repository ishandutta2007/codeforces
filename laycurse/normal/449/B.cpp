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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

template <class T>
struct DijkstraHeap {
  int *hp, *place, size; char *visited; T *val;

  void malloc(int N){hp=(int*)std::malloc(N*sizeof(int));place=(int*)std::malloc(N*sizeof(int));visited=(char*)std::malloc(N*sizeof(char));val=(T*)std::malloc(N*sizeof(T));}
  void free(){free(hp);free(place);free(visited);free(val);}
  void* malloc(int N, void *workMemory){hp=(int*)workMemory;place=(int*)(hp+N);visited=(char*)(place+N);val=(T*)(visited+N);workMemory=(void*)(val+N);return workMemory;}
  void init(int N){int i;size=0;rep(i,N)place[i]=-1,visited[i]=0;}
  void up(int n){int m;while(n){m=(n-1)/2;if(val[hp[m]]<=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void down(int n){int m;for(;;){m=2*n+1;if(m>=size)break;if(m+1<size&&val[hp[m]]>val[hp[m+1]])m++;if(val[hp[m]]>=val[hp[n]]) break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void change(int n, T v){if(visited[n]||(place[n]>=0&&val[n]<=v))return;val[n]=v;if(place[n]==-1)place[n]=size,hp[size++]=n,up(place[n]);else up(place[n]);}
  int pop(void){int res=hp[0];place[res]=-1;size--;if(size)hp[0]=hp[size],place[hp[0]]=0,down(0);visited[res]=1;return res;}
};

int N, M, K;
vector<int> edge[100001], cost[100001];
pair<int,int> train[100001];

int istrain[100001];

int main(){
  int i, j, k, c;
  int res = 0;
  DijkstraHeap<ll> heap;

  reader(&N,&M,&K);
  while(M--){
    reader(&i,&j,&c); i--; j--;
    edge[i].push_back(j); cost[i].push_back(c);
    edge[j].push_back(i); cost[j].push_back(c);
  }

  rep(i,K) reader(&train[i].first, &train[i].second), train[i].first--;
  sort(train, train+K);

  rep(i,N) istrain[i] = 0;

  heap.malloc(N);
  heap.init(N);
  heap.change(0, 0);
  while(heap.size){
    k = heap.pop();
    if(k==0){
      rep(j,K){
        i = train[j].first;
        if(heap.visited[i]) continue;
        if(heap.place[i]==-1 || heap.val[i] > heap.val[k] + train[j].second){
          heap.change(i, heap.val[k] + train[j].second);
          istrain[i] = 1;
        }
      }
    }
    rep(j,edge[k].size()){
      i = edge[k][j];
      if(heap.visited[i]) continue;
      if(heap.place[i]==-1 || heap.val[i] >= heap.val[k]+cost[k][j]){
        heap.change(i, heap.val[k]+cost[k][j]);
        istrain[i] = 0;
      }
    }
  }

  res = K;
  rep(i,N) res -= istrain[i];

  writer(res, '\n');

  myed;
  return 0;
}