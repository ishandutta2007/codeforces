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
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int n,m,q;
LL war[MAX];
LL wars[MAX];
LL dods[MAX];
LL il[MAX];
vector<int> dt[MAX],ds[MAX];
vector<PI> dd[MAX];
const int C = 2;
void lacz(int a,int b,int k){
  if(dd[a].size()+dt[a].size() < dd[b].size()+dt[b].size()){
    dd[a].PB(MP(b,k));
  }else{
    dd[b].PB(MP(a,k));
  }
}
main(){
  scanf("%d%d%d",&n,&m,&q);
  R(i,n)makel(war[i]);
  R(i,m){
    int _;make(_);
    while(_--){
      int pom;make(pom);pom--;
      ds[pom].PB(i);
    }
  }
  vector<PI> vpom;
  R(pom,n){
    if(ds[pom].size() > C){
      R(i,ds[pom].size())
        dt[ds[pom][i]].PB(pom);
    }else{
      R(i,ds[pom].size()){
        il[ds[pom][i]] ++;
        wars[ds[pom][i]] += war[pom];
        F(j,i+1,ds[pom].size()){
          vpom.PB(MP(ds[pom][i],ds[pom][j]));
        }
      }
    }
  }
  sort(vpom.begin(),vpom.end());
  R(i,vpom.size()){
    int k = 1;
    while(k+i < vpom.size() && vpom[i] == vpom[i+k])k++;
    lacz(vpom[i].FI,vpom[i].SE,k);
    i += k-1;
  }
  while(q--){
    char z;int k;
    scanf(" %c%d",&z,&k);k--;
    if(z == '?'){
      LL sum = wars[k];
      R(i,dt[k].size())
        sum += war[dt[k][i]];
      R(i,dd[k].size()){
        sum += dods[dd[k][i].FI] * dd[k][i].SE;
      }
      pll(sum);
    }else{
      LL x;makel(x);
      dods[k] += x;
      wars[k] += x * il[k];
      R(i,dt[k].size())
        war[dt[k][i]] += x;
      R(i,dd[k].size()){
        wars[dd[k][i].FI] += x * dd[k][i].SE;
      }
    }
  }
}