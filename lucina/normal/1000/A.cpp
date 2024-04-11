#include<stdio.h>
#include<string.h>
int a[9];
char b[5];
int main(){
int n,l,k;
scanf("%d",&n);
for(int i=0;i<n;i++){
   scanf("%s",b);
   l=strlen(b);
   if(b[l-1]=='M')k=0;
   else if(b[l-1]=='S')k=(1+(2*(l-1)));
   else if(b[l-1]=='L') k=(2+(2*(l-1)));
   a[k]++;
}
for(int j=0;j<n;j++){
scanf("%s",b);
   l=strlen(b);
   if(b[l-1]=='M')k=0;
   else if(b[l-1]=='S')k=(1+(2*(l-1)));
   else if(b[l-1]=='L') k=(2+(2*(l-1)));
   a[k]--;
}
int y=0;
for(int x=0;x<9;x++){
if(a[x]<0){
y=y-a[x];
}
}
printf("%d",y);
}