#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<ctime>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}
int ps, p[10000];
ull rnd[1000100], sums[1000101];

ull node1[1000100], node2[1000100];

int main(){
  int i,j,k,l,m,n;
  ll st, ed;
  ll res;

  srand(time(NULL));

  ps = getPrime(10000, p);
  rep(i,1000100){
    rnd[i] = 1;
    rep(k,20) rnd[i] *= p[rand()%(ps-10)+5];
  }
  sums[0] = 0;
  rep(i,1000100) sums[i+1] = sums[i] + rnd[i];

  while(scanf("%d%d",&n,&m)==2){
    rep(i,n) node1[i] = 0;
    while(m--){
      scanf("%d%d",&i,&j); i--; j--;
      node1[i] += rnd[j];
      node1[j] += rnd[i];
    }
    rep(i,n) node2[i] = sums[n] - node1[i] - rnd[i];
    
    sort(node1, node1+n);
    sort(node2, node2+n);
    
    res = 0;
    
    st = 0;
    while(st < n){
      ed = st;
      while(ed < n && node1[st]==node1[ed]) ed++;
      res += (ed-st) * (ed-st-1) / 2;
      st = ed;
    }
    
    st = 0;
    while(st < n){
      ed = st;
      while(ed < n && node2[st]==node2[ed]) ed++;
      res += (ed-st) * (ed-st-1) / 2;
      st = ed;
    }
    
    printf("%I64d\n",res);

  }
  return 0;
}