#include<cstdio>
#include<set>
#include<vector>
using namespace std;
#define MAX 100005
#define PB push_back
int n,rp[MAX],wynik[MAX];
struct cos{
 int il;
 bool jak;//1 ros // 0 mal
};
struct licz{
 int ile;
 multiset<int> q;
}a,b;
vector<cos> d[MAX],u[MAX];
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  int pom;
  scanf("%d",&pom);
  rp[pom]=i;
 }
 for(int i=0;i<n;i++){
  int pom;
  scanf("%d",&pom);
  int j=rp[pom];
  if(j<=i){
   
   cos x;
   x.il=i-j;
   x.jak=1;
   d[0].PB(x);
   x.il=n-1-j;
   u[n-1-i].PB(x);
   
   x.il=j;
   x.jak=0;
   d[n-i].PB(x);
   x.il=0;
   u[n-i+j].PB(x);
   x.jak=1;
   d[n-i+j].PB(x);
  }else{
   cos x;
   x.il=j-i;
   x.jak=0;
   d[0].PB(x);
   x.il=0;
   u[j-i].PB(x);
   x.jak=1;
   d[j-i].PB(x);
   x.il=n-1-j;
   u[n-1-i].PB(x);
   x.il=j;
   x.jak=0;
   d[n-i].PB(x);
  }
 }
 a.ile=0;b.ile=0;
 for(int i=0;i<n;i++){
 // printf("       %d\n",i);
 // printf("dod\n");
  for(int j=0;j<d[i].size();j++){
 //  printf("%d %d\n",d[i][j].il,d[i][j].jak);
   if(d[i][j].jak){
    a.q.insert(d[i][j].il-a.ile);
   }else{
    b.q.insert(d[i][j].il-b.ile);
   }
  }
  int wyn=MAX;
  if(a.q.empty()==0){
   int pom=(*a.q.begin())+a.ile;
   wyn=min(pom,wyn);
  }
  if(b.q.empty()==0){
   int pom=(*b.q.begin())+b.ile;
   wyn=min(pom,wyn);
  }
 // printf("wyn:");
 wynik[i]=wyn;
 // printf("us:\n");
  for(int j=0;j<u[i].size();j++){
//   printf("%d %d\n",u[i][j].il,u[i][j].jak);
   if(u[i][j].jak){
   
  // printf("x %d\n",*a.q.lower_bound(u[i][j].il-a.ile))'
    a.q.erase(a.q.lower_bound(u[i][j].il-a.ile));
  // printf("x %d\n",*a.q.lower_bound(u[i][j].il-a.ile));
   }else{
   
  // printf("x %d\n",*b.q.lower_bound(u[i][j].il-b.ile));
    b.q.erase(b.q.lower_bound(u[i][j].il-b.ile));
  // printf("x %d\n",*b.q.lower_bound(u[i][j].il-b.ile));
   }
  }
  a.ile++;
  b.ile--;
 }
 printf("%d\n",wynik[0]);
 for(int i=n-1;i>0;i--)
 printf("%d\n",wynik[i]);
}