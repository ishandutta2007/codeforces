#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> PI;
#define FI first
#define SE second
#define MP make_pair
#define MAX 100001
int n,k;
char z[2][MAX];
int odl[2][MAX],gl;
queue<PI> pom;
void add(int a,int b){
 if(b>=n){
  printf("YES\n");
  exit(0);
 }
 if(z[a][b]=='X'||gl>b)return;
 if(odl[a][b]==0){
  pom.push(MP(a,b));
  odl[a][b]=gl+1;
 }
}
main(){
 scanf("%d%d %s %s",&n,&k,z[0],z[1]);
 pom.push(MP(0,0));
 odl[0][0]=1;
 while(pom.empty()==0){
  PI ak=pom.front();
  pom.pop();
  gl=odl[ak.FI][ak.SE];
  add(ak.FI,ak.SE-1);
  add(ak.FI,ak.SE+1);
  add(1-ak.FI,ak.SE+k);
 }
 printf("NO\n");
}