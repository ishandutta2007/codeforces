#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int x,y,z;

int main(){
    scanf("%d%d%d",&x,&y,&z);
    x-=y;
    int ma=x+z,mi=x-z;
    if(ma==mi&&ma==0)
        return !printf("0");
    if(ma<0)return !printf("-");
    if(mi>0)return !printf("+");
    printf("?");
}