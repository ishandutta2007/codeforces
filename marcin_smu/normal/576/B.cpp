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
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int p[MAX];
int wyn[MAX];
int n;
void nie(){
  puts("NO");
  exit(0);
}
main(){
  make(n);
  R(i,n){
    make(p[i]);
    p[i]--;
  }
  R(i,n){
    if(p[i] == i){
      puts("YES");
      R(j,n){
        if(i!=j)
          printf("%d %d\n",i+1,j+1);
      }
      return 0;
    }
  }
  R(i,n)wyn[i] = -1;
  R(i,n){
    if(p[p[i]] == i){   
      int k = p[i];
      R(j,n){
        if(wyn[j] == -1 && j != i && j!=k){
          int ak = j;
          int w = i;
          while(wyn[ak] == -1){
            wyn[ak] = w;
            ak = p[ak];
            w = i+k - w;
          }
          if(w != i)nie();
        }
      }
      puts("YES");
      printf("%d %d\n",i+1,k+1);
      R(j,n){
        if(i!=j && j!=k)
          printf("%d %d\n",wyn[j]+1,j+1);
      }
      return 0;
    }
  }
  nie();
}