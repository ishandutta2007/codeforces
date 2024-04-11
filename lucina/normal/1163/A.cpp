#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,lft;

int main(){
    scanf("%d%d",&n,&m);
    if(m<2){
        printf("1");
        return 0;
    }
    lft=n-m;
    printf("%d\n",min(lft,m));

}