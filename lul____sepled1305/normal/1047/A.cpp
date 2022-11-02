#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(n%3==2){
        n=n-4;
        printf("2 2 %d",n);
    }
    else{
        n=n-2;
        printf("1 1 %d",n);
    }
    return 0;
}