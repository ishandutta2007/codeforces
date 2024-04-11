#include<cstdio>
#define LL long long
#define INF 1000000010
int a,b,n;
bool licz(LL c,int d){
 LL wyn=1;
 for(int i=0;i<d;i++){
  wyn*=c;
  if(wyn>=(LL)(n))
  return 0;
 }
 return 1;
}
main(){
 scanf("%d%d%d",&a,&b,&n);
 bool zm=0;
 while(licz(a+1,b+1)){a++;b++;}
 int i=1;
 if(a!=1)
  while(licz(a,b+i))i++;
 int p=1,k=INF;
 while(p+1!=k){
  if(licz((p+k)/2,b))
  p=(p+k)/2;
  else
  k=(p+k)/2;
 }
 if(a==1&&(k-a)%2==1)
 printf("Missing\n");
 else
 printf("%s\n",((k-a)%2==1&&(i%2)==1)?"Stas":"Masha");
}