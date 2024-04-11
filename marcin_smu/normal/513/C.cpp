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
#define MAX 11
int p[MAX],k[MAX];
vector<int> a;
int n;
D wyn = 0;
int il[MAX];
D dp[MAX][5][2];
void licz(int kt,D pr){
  if(kt == n){
    int pom = 0;
    FD(i,a.size()-1){
      if(pom + il[i] > 1){
        dp[i][il[i]][pom] += pr;
        return;
      }
      pom += il[i];
    }
    return;
  }
  R(i,a.size()-1){
    if(a[i] >= p[kt] && a[i+1] <= k[kt] && a[i] != a[i+1]){
      il[i]++;
      licz(kt+1,pr *  (a[i+1] - a[i]) / (k[kt]- p[kt]));
      il[i]--;
    }
  }
}
main(){
  make(n);
  R(i,n){
    make2(p[i],k[i]);k[i]++;
    a.PB(p[i]);
    a.PB(k[i]);
  }
  sort(a.begin(),a.end());
 // R(i,a.size())printf("%d\n",a[i]);
  licz(0,1.);
  R(i,a.size()-1)F(j,1,n+1){
    wyn += (dp[i][j][0] + dp[i][j][1]) * a[i];
    int dl = a[i+1] - a[i];
   // printf("%d %d %d %lf %lf\n",a[i],dl,j,dp[i][j][0],dp[i][j][1]);
    F(k,1,dl+1){
      //printf("(%d %lf %lf)",(k-1),pow((D)k/dl,j),pow((D)(k-1)/dl,j));
      wyn += (k-1) * (pow((D)k/dl,j) - pow((D)(k-1)/dl,j)) * dp[i][j][1];
      
      wyn += (k-1) * (
        j * (D)(dl-k) / dl * (pow((D)k/dl,j-1) - pow((D)(k-1)/dl,j-1)) +
        (pow((D)k/dl,j) - pow((D)(k-1)/dl,j) - j*pow((D)(k-1)/dl,j-1)/dl)
      ) * dp[i][j][0];
      
    }
  //  printf("%lf\n",wyn);
  }
  printf("%.10f\n",wyn);
}