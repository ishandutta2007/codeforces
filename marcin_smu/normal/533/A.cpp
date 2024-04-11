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
#define MAX 500100
int n;
set<int> skal;
map<int,int> m;
int h[MAX];
vector<int> d[MAX];
int k;
int s[MAX];
vector<int> prze;
const int MAXX = 1<<20;
struct node{
  int sum,suf;
  void licz(node a,node b){
    sum = a.sum + b.sum;
    suf = min(b.suf,a.suf + b.sum);
  }
  void add(int il){
    sum += il;
    suf = min(0,sum);
  }
}dp[MAXX*2 + 5];
int add(int a,int il){
  a += MAXX;
  dp[a].add(il);
  while(1){
    a/=2;
    dp[a].licz(dp[a*2],dp[a*2+1]);
    if(a == 1)break;
  }
}
void dfs(int nr,int oj,int war){
  MI(war,h[nr]);
  prze.PB(war);
  R(i,(int)d[nr].size())
    if(d[nr][i]!=oj)
      dfs(d[nr][i],nr,war);
}
int wyn = -1;
int nowa;
int stara;
vector<int> wart;
void dfsw(int nr,int oj,int war){
  MI(war,h[nr]);
  if(war <= stara)return;
  wart.PB(war);
  R(i,(int)d[nr].size())
    if(d[nr][i]!=oj)
      dfsw(d[nr][i],nr,war);
}
void dfsn(int nr,int oj,int war){
  MI(war,h[nr]);
  if(war < nowa){
    stara = h[nr];
    h[nr] = nowa;
    wart.clear();
    dfsw(nr,oj,nowa);
    R(i,wart.size())
      add(wart[i],1);
    add(stara,(int)wart.size() * -1);
    if(dp[1].suf == 0){
      MA(wyn,stara);
    }
    R(i,wart.size())
      add(wart[i],-1);
    add(stara,(int)wart.size());
    h[nr] = stara;
  }else{
    R(i,(int)d[nr].size())
      if(d[nr][i]!=oj)
        dfsn(d[nr][i],nr,war);
  }
}
void licz(){
  dfsn(0,-1,1e9);
}
int wyc(int szu){
  int nr=0;
  for(int a:skal){
    if(nr == szu)return a;
    nr++;
  }
}
main(){
  make(n);
  R(i,n){
    make(h[i]);
    skal.insert(h[i]);
  }
  R(i,n-1){
    int a,b;
    make2(a,b);
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  make(k);
  R(i,k){
    make(s[i]);
    skal.insert(s[i]);
  }
  int nr=0;
  for(int a:skal){
    m[a] = nr;
    nr++;
  }
  R(i,n)h[i] = m[h[i]];
  R(i,k)s[i] = m[s[i]];
  dfs(0,-1,nr);
  R(i,prze.size())add(prze[i],1);
  R(i,k)add(s[i],-1);
  if(dp[1].suf == 0){
    puts("0");
    return 0;
  }
  sort(s,s+k,greater<int>());
  sort(ALL(prze),greater<int>());
  R(i,k){
    if(prze[i] < s[i]){
      nowa = s[i];
      licz();
      if(wyn == -1){
        puts("-1");
        return 0;
      }
      printf("%d\n",wyc(nowa) - wyc(wyn));
      return 0;
    }
  }
  assert(0);
}