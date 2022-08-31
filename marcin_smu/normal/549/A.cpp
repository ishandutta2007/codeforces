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
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}
#define MAX 51
int n,m;
char t[MAX][MAX];
main(){
  make2(n,m);
  R(i,n){
    scanf("%s",t[i]);
  }
  int wyn = 0;
  R(i,n-1)R(j,m-1){
    vector<char> pom;
    R(ii,2)R(jj,2)
      pom.PB(t[i+ii][j+jj]);
    sort(ALL(pom));
    if(pom[0] == 'a' && pom[1] == 'c' && pom[2] == 'e' && pom[3] == 'f')
      wyn++;
  }
  printf("%d\n",wyn);
}