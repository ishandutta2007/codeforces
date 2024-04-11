#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define LL long long
#define PI pair<int,int>
#define D double
int x,y,x2,y2;
char z,z2;
main(){
 scanf("%c%d %c%d",&z,&x,&z2,&x2);
 y=z-'a'+1;
 y2=z2-'a'+1;
 int wyn=64;
 for(int i=1;i<=8;i++)
 for(int j=1;j<=8;j++){
  if(i==x||j==y||(abs(i-x)==1&&abs(j-y)==2)||(abs(i-x)==2&&abs(j-y)==1)
  ||(abs(i-x2)==1&&abs(j-y2)==2)||(abs(i-x2)==2&&abs(j-y2)==1)||(i==x2&&j==y2))
   wyn--;
 }
 printf("%d\n",wyn);
}