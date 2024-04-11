#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;

int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(c){
        if(a>0&&d>0){
        a--;
        d--;
        }
        else{
            printf("0");
            return 0;
        }
        printf("%d",a==d?1:0);
    }
    else{
        printf("%d",a==d?1:0);
    }
}