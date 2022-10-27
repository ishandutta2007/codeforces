#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a,b,c,T;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        if(c%3==0){
            printf("%d\n",a);
        }
        else if(c%3==1){
            printf("%d\n",b);
        }
        else{
            printf("%d\n",a^b);
        }
    }
}
/*
    Good Luck
        -Lucina
*/