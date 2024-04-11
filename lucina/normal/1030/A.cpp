#include<stdio.h>

int n,x;
int main(){
scanf("%d",&n);
while(n--){
scanf("%d",&x);
if(x==1){
printf("HARD");
return 0;
}
}
printf("EASY");
}