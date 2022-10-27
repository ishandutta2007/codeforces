#include<stdio.h>
int a;
int main(){
    scanf("%d",&a);
    printf("%d",a/100+(a%100)/20+(a%20)/10+(a%10)/5+(a%5));
}