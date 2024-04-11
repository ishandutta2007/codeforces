#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define makel(A) scanf("%I64d",&A)
#define pl(A) printf("%I64d ",A)
#define MAX 1000001
vector<int> t[MAX],j;
int n,wyn=0;
main(){
 make(n);
 R(i,n){
  int pom=0;
  make(pom);
  if(t[pom].size()==0){
   j.PB(pom);
  }
  t[pom].PB(i);
  if(wyn<t[pom].size())
  wyn=t[pom].size();
 }
 R(i,j.size()){
  R(k,j.size()){
   if(i==k)continue;
   int a=0,b=0,ak=1;
   while(1){
    while(b<t[j[k]].size()&&t[j[k]][b]<t[j[i]][a])b++;
    if(b==t[j[k]].size())break;
    ak++;
    while(a<t[j[i]].size()&&t[j[i]][a]<t[j[k]][b])a++;
    if(a==t[j[i]].size())break;
    ak++;
   }
   if(ak>wyn)wyn=ak;
  }
 }
 printf("%d\n",wyn);
}