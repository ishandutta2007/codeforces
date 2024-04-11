#include <stdio.h>
#include <algorithm>

int max,k;
char s[400];

int type(int num){
 if(num<strlen(s))return (int)s[num];
 else if(num<strlen(s)+k) return 1;
 return 0;
}

//void chk(int a,int b){
bool chk(int cur,int len){
 int i,l,j;
 if(cur+2*len>strlen(s)+k)
  return false;
 i=cur;
 j=0;
// while(((s[i]==s[i+b])||((i+b>strlen(s)) && (i+b<=strlen(s)+k))) && i<=a+b){
 for(i=cur;i<cur+len;i++)if(type(i)==type(i+len)||type(i+len)==1){

 } else {
  return false;
 }
//  j++;
//  i++;
// }
 //if(j>=b) max=b;
 if(max<len)max=len;
 return true;
}

int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
 #endif
 int i,j;
 bool b;
 scanf("%s",&s);
 scanf("%d",&k);
 max=0;
#ifndef ONLINE_JUDGE
 printf("%d\n",strlen(s));
#endif
 for(i=0;i<strlen(s)+k/2+1;i++)
  for(j=0;j<(strlen(s)+k)/2+1;j++){
  b=chk(i,j);
  #ifndef ONLINE_JUDGE
  if(b)
   printf("%d %d YES\n",i,j);
  else 
   printf("%d %d NO\n",i,j);
  #endif
  }
 printf("%d",max*2);
}