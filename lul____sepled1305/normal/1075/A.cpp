#include<stdio.h>
#include<iostream>
using namespace std;
unsigned long long int j,k,l,x,y,n;
int main(){
    cin>>n>>x>>y;
    if(x+y<=n+1){
        printf("WHITE");
    }
    else{
        printf("BLACK");
    }
    return 0;
}