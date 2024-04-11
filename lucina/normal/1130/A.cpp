#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,cp,cm,x;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x<0)cm++;
        if(x>0)cp++;
    }
    int r=n/2+n%2;
    if(cm>=r){
        printf("-1");
        return 0;
    }
    if(cp>=r){
        printf("1");
        return 0;
    }

        printf("0");
        return 0;
}