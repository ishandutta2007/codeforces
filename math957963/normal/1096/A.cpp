#include<cstdio>
int main(void){
int n;
int x,y;
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d %d",&x,&y);
printf("%d %d\n",x,2*x);
}
return 0;
}