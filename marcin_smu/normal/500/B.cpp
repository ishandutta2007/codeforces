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
#define db if(1)printf
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 301
int n,t[MAX],f[MAX];
char z[MAX];
bool cz[MAX];
int find(int a){
  return f[a]==a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  f[find(a)] = find(b);
}
main(){
  make(n);
  R(i,n)make(t[i]),f[i]=i;
  R(i,n){
    scanf("%s",z);
    R(j,n)if(z[j]=='1')uni(i,j);
  }
  R(i,n){
    if(cz[i] == 0){
      vector<int> war;
      R(j,n){
        if(find(i) == find(j)){
          war.PB(t[j]);
          cz[j] = 1;
        }
      }
      sort(war.begin(),war.end());
      int it = 0;
      R(j,n){
        if(find(i) == find(j)){
          t[j] = war[it++];
        }
      }
    }
  }
  R(i,n)printf("%d ",t[i]);
  puts("");
}