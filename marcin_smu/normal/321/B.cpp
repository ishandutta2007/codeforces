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
#define MAX 101
int n,m;
int b[MAX];
vector<int> a,d;
int wyn;
int dp[MAX][MAX][MAX];
main(){
  scanf("%d%d",&n,&m);
  R(i,n){
    char z[5];int pom;
    scanf("%s%d",z,&pom);
    if(z[0] == 'A')a.PB(pom);
    else d.PB(pom);
  }
  R(i,m)make(b[i]);
  sort(a.begin(),a.end());
  sort(d.begin(),d.end());
  sort(b,b+m);
  R(i,min((int)a.size(),m)){
    bool cz = 1;
    int res = 0;
    R(j,i+1){
      if(a[j] <= b[m-i-1+j]){
        res += b[m-i-1+j] - a[j];
      }else
        cz = 0;
    }
    if(cz)ma(wyn,res);
  }
  dp[0][0][0] = 1;
  R(i,m)R(j,a.size()+1)R(k,d.size()+1){
    if(dp[i][j][k] == 0)continue;
    if(j < a.size() && b[i] >= a[j])
      ma(dp[i+1][j+1][k],dp[i][j][k] + b[i] - a[j]);
    if(k < d.size() && b[i] > d[k])
      ma(dp[i+1][j][k+1],dp[i][j][k]);
    ma(dp[i+1][j][k],dp[i][j][k] + b[i]);
  }
  printf("%d\n",max(wyn,dp[m][a.size()][d.size()]-1));
}