#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,l,r;
int main(){
        scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        if(r%2){
            printf("%d %d\n",r/2,r-1);
        }
        else{
            printf("%d %d\n",r/2,r);
        }
    }



}