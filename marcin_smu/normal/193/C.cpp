#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 200005
char w[4][MAX];
int iw=0,t[4][4],a,b,c;
void ak(){
 for(int i=0;i<4;i++)
 for(int j=i+1;j<4;j++)
 if(w[i][iw]!=w[j][iw])
 t[i][j]--;
 iw++;
}
void abc(){
 a=t[0][1]-t[2][3];
 b=t[0][2]-t[1][3];
 c=t[0][3]-t[1][2];
}
void add1(int kt){
 for(int i=0;i<4;i++)
  w[i][iw]='a';
 w[kt][iw]='b';
 ak();
 abc();
}
void abc2(){
 a=t[0][1];
 b=t[0][2];
 c=t[0][3];
}
void add2(int kt){
 for(int i=1;i<4;i++)
  w[i][iw]='b';
 w[kt][iw]='a';
 w[0][iw]='a';
 ak();
 abc2();
}
main(){
 for(int i=0;i<4;i++)
 for(int j=i+1;j<4;j++)
 scanf("%d",&t[i][j]);
 abc();
 if(((a^b)&1)||((a^c)&1)){
  printf("-1\n");
  return 0;
 }
 while(a!=b||a!=c||a<0){
  if(a>b&&a>c)
   add1(1);
  else{
   if(b>c)
    add1(2);
   else
    add1(3);
  }
 }
 while(a!=0)add1(0);
 abc2();
 if(a+b+c<2*max(max(a,b),c)||((a+b+c)&1)||a<0||b<0||c<0){
  printf("-1\n");
  return 0;
 } 
 //printf("%d %d %d\n",a,b,c);
 while(a!=0||b!=0||c!=0){
  if(a<b&&a<c)
   add2(1);
  else{
   if(b<c)
    add2(2);
   else
    add2(3);
  }
 }
 printf("%d\n%s\n%s\n%s\n%s\n",iw,w[0],w[1],w[2],w[3]);
}