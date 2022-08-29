#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAXn 500001
const int INF = 1000 * 1000 * 1000 + 3;
vector<int> e;
vector<PI> d[MAXn],d2[MAXn];
int N,P,K,odl[MAXn],gd[MAXn];
void init(int n,int p,int k){
      N = n;
      P = p;
      K = k;
      e.clear();
      R(i,n)d[i].clear();
}
void add_edge(int a,int b,int p){
      d[a].PB(MP(b,int(e.size())));
      e.PB(p);
      d[b].PB(MP(a,int(e.size())));
      e.PB(0);
}
bool bfs(){
      R(i,N){
              d2[i].clear();
              gd[i]=0;
              odl[i]=-1;
      }
      queue<int> kol;
      kol.push(P);odl[P]=0;
      while(!kol.empty()){
              int ak = kol.front();kol.pop();
              R(i,d[ak].size()){
                      if(e[d[ak][i].SE]==0)continue;
                      int pom = d[ak][i].FI;
                      if(odl[pom] == -1){
                              odl[pom] = odl[ak]+1;
                              kol.push(pom);
                      }
                      if(odl[pom] == odl[ak]+1)
                              d2[ak].PB(d[ak][i]);
              }
      }
      return odl[K]!=-1;
}
int dfs(int nr,int flow){
      if(nr == K || flow == 0)return flow;
      int wyn = 0;
      F(i,gd[nr],d2[nr].size()){
              PI pom = d2[nr][i];
              int il = dfs(pom.FI,min(flow,e[pom.SE]));
              wyn += il;
              flow -= il;
              e[pom.SE] -= il;
              e[pom.SE^1] += il;
              if(flow == 0){
                      gd[nr] = i;
                      return wyn;
              }
      }
      gd[nr] = d2[nr].size();
      return wyn;
}
int flow(){
      int wyn=0;
      while(bfs()){
         wyn+=dfs(P,INF);
      }
      return wyn;
}

void nie(){
  puts("Impossible");
  exit(0);
}

vector<int> p,np;
int n;
#define MAX_p 20001
#define MAX 201
bool pie[MAX_p];
bool cz[MAX];
vector<int> wyn[MAX];
vector<vector<int> > res;
void add(int i,int j){
  if(i < n*2 && j < n*2){
    wyn[i].PB(j);
    wyn[j].PB(i);
  }
}
int t[MAX];
main(){
  F(i,2,MAX_p){
    pie[i] = 1;
    for(int j = 2;j*j <= i ;j++){
      if(i%j == 0)pie[i] = 0;
    }
  }
  make(n);
  R(i,n){
    make(t[i]);
    if(t[i]&1)np.PB(i);
    else p.PB(i);
  }
  if(np.size() != p.size())nie();
  n/=2;
  init(n*2+2,n*2,n*2+1);
  R(i,n){
    add_edge(n*2,i,2);
    add_edge(i+n,n*2+1,2);
  }
  R(i,n)R(j,n){
    if(pie[t[p[i]]+t[np[j]]]){
      add_edge(i,j+n,1);
    }
  }
  if(flow() != n*2)nie();
  R(i,n*2)R(j,d[i].size()){
    PI ak = d[i][j];
    if((ak.SE&1) && e[ak.SE] == 1){
      add(i,ak.FI);
    }
  }
  R(i,n*2){
    if(cz[i] == 0){
      vector<int> pom;
      int ak = i;
      int pop = -1;
      do{
        cz[ak] = 1;
        pom.PB(ak);
        R(i,2){
          if(wyn[ak][i]!= pop){
            pop = ak;
            ak = wyn[ak][i];
            break;
          }
        }
      }while(ak!=i);
      res.PB(pom);
    }
  }
  printf("%d\n",(int)res.size());
  R(i,res.size()){
    printf("%d",(int)res[i].size());
    R(j,res[i].size()){
      int pom = res[i][j];
      if(pom < n)
        printf(" %d",p[pom]+1);
      else
        printf(" %d",np[pom-n]+1);
    }
    puts("");
  }
}