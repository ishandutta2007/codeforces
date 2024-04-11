#include<stdio.h>
int x,y,z,a,b,c,stair,elevator;
int main(){
    scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);
    if(x>z & x>y){
        elevator=((x-z)*b)+ 3*c + ((x-y)*b);
        stair= (x-y)*a;
    }
    if(x<=z & x>y){
        elevator=((z-x)*b)+ 3*c + ((x-y)*b);
        stair= (x-y)*a;
    }
    if(x>z & x<=y){
        elevator=((x-z)*b)+ 3*c + ((y-x)*b);
        stair= (y-x)*a;
    }
    if(x<=z & x<=y){
        elevator=((z-x)*b)+ 3*c + ((y-x)*b);
        stair= (y-x)*a;
    }
    if(elevator<=stair){
        printf("YES");
    }
    else{
        printf("NO");
    }
}