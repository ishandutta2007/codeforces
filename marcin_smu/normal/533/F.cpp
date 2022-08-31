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
#define MAX 210010
const int alp = 'z'-'a'+1;
char s[MAX],t[MAX];
vector<int> wz[30],sl[30];
int ost[30];
int kmp[MAX*2];
int ile[MAX];
int q[MAX][alp];
vector<int> gd[alp];
void add(int nr,int i,int j){
  if(nr < 0 || nr >= MAX)return;
  if(q[nr][i]==0)q[nr][i] = j+1;
  if(q[nr][j]==0)q[nr][j] = i+1;
  if(q[nr][i] == j+1 && q[nr][j] == i+1)
    ile[nr]++;
}
void licz(vector<int> &z,int il,int zy,int d){
  int n = z.size();
  int t = 0;
  F(i,1,n){
    while(t && z[i] != z[t])t = kmp[t-1];
    if(z[i] == z[t])
      t++;
    kmp[i] = t;
    if(t == il){
      int poz = gd[d][i-il];
      add(poz-ost[zy],zy,d);
    }
  }
}
int n,m;
main(){
  make2(n,m);
  scanf("%s%s",s,t);
  R(i,n)s[i] -= 'a';
  R(i,m)t[i] -= 'a';
  R(i,alp)ost[i] = -1;
  R(i,n){
    if(ost[s[i]]!=-1)
      wz[s[i]].PB(i-ost[s[i]]);
    ost[s[i]] = i;
    gd[s[i]].PB(i);
  }
  R(i,alp)ost[i] = -1;
  R(i,m){
    if(ost[t[i]]!=-1)
      sl[t[i]].PB(i-ost[t[i]]);
    ost[t[i]] = i;
  }
  R(i,alp)sl[i].PB(-1);
  R(i,alp)R(j,alp){
    int pom = sl[i].size();
    if(ost[i] == -1 || gd[j].size() == 0)continue;
    if(pom == 1){
      R(k,gd[j].size())
        add(gd[j][k]-ost[i],i,j);
      continue;
    }
    R(k,wz[j].size())
      sl[i].PB(wz[j][k]);
    licz(sl[i],pom-1,i,j);
    sl[i].resize(pom);
  }
  int roz = 0;
  R(i,alp)if(ost[i]!=-1)roz++;
  vector<int> wyn;
  R(i,n)if(ile[i] == roz)wyn.PB(i+1);
  printf("%d\n",(int)wyn.size());
  R(i,wyn.size())
    printf("%d ",wyn[i]);
  puts("");
}