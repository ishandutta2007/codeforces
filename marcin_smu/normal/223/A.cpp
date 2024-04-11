#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define F(I,N) for(int I=0;I<N;I++)
#define R(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A);
#define MAX 100010
char t[MAX];
bool cz[MAX];
stack<PI> p;
int wyn=0,po=0,k=0;
char z[300];
main(){
 z['(']=')';
 z['[']=']';
 scanf("%s",t);
 int i=0,il=0;
 int pocz=0;
 while(t[i]){
  if(t[i]=='['){
   il++;
   p.push(MP(i,il));
  }
  if(t[i]=='(')p.push(MP(i,il));
  if(t[i]==']'||t[i]==')'){
   if(p.empty()==0&&z[t[p.top().FI]]==t[i]){
    p.pop();
    int pom,ak;
    if(p.empty()==0){
     pom=il-p.top().SE;
     ak=p.top().FI+1;
    }
    else{
     ak=pocz;
     pom=il;
    }
    if(pom>wyn){
     wyn=pom;
     po=ak;
     k=i+1;
    }
   }else{
    while(p.empty()==0)p.pop();
    il=0;
    pocz=i+1;
   }
  }
  i++;
 }
 t[k]=0;
 printf("%d\n%s\n",wyn,t+po);
}