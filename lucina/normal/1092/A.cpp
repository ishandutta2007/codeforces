#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            printf("%c",'a'+(i%k));

        }
        printf("\n");

    }

}