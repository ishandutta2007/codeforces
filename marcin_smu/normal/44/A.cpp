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
#define MAX 
int n,wyn;
struct lisc{
 char a[11],b[11];
}t[101];
int cz(int nr,int i){
 for(int j=0;t[i].a[j]||t[nr].a[j];j++)
 if(t[i].a[j]!=t[nr].a[j])return 0;
 for(int j=0;t[i].b[j]||t[nr].b[j];j++)
 if(t[i].b[j]!=t[nr].b[j])return 0;
 return 1;
}
int te(int nr){
 for(int i=0;i<nr;i++){
  if(cz(nr,i))return 0;
 }
 return 1;
}
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf(" %s %s",t[i].a,t[i].b);
  if(te(i))wyn++;
 }
 printf("%d\n",wyn);
}