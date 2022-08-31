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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int n,m,r,odl[MAX];
vector<int> d[MAX];
bool cz[MAX],nw[MAX];
bool dfs(int nr,int o=-1){
  R(i,d[nr].size()){
    if(d[nr][i] != o){
      if(dfs(d[nr][i],nr)){
        ma(odl[nr],odl[d[nr][i]]+1);
        cz[nr] = 1;
      }
    }
  }
  cz[nr]|=nw[nr];
  return cz[nr];
}
void dfs2(int nr,int og,int o){
  //printf("%d %d\n",nr+1,og);
  ma(odl[nr],og);
  vector<int> odly;
  odly.PB(og);
  if(nw[nr])odly.PB(0);
  R(i,d[nr].size()){
    if(d[nr][i] != o && cz[d[nr][i]]){
      odly.PB(odl[d[nr][i]]+1);
    }
  }
  sort(odly.begin(),odly.end(),greater<int>());
  R(i,d[nr].size()){
    if(d[nr][i] != o){
      int pom = odl[d[nr][i]]+1 == odly[0] && cz[d[nr][i]] ?odly[1]+1:odly[0]+1;
      dfs2(d[nr][i],pom,nr);
    }
  }
}
main(){
  scanf("%d%d%d",&n,&m,&r);
  R(i,m){
    int pom;
    make(pom);pom--;
    nw[pom] = 1;
  }
  R(i,n-1){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0);
  dfs2(0,-n*4,-1);
  int wyn=0;
  R(i,n){
    if(odl[i] <= r)wyn++;
 //   printf("%d\n",odl[i]);
  }
  printf("%d\n",wyn);
}