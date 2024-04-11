#include<bits/stdc++.h>
using namespace std;
int t,ang,b[200];

int main(){
    scanf("%d",&t);
    for(int i=3;i<2e3+10;i++){
        for(int j=1;j<=i-2;j++){
            int x=360*j;
            if(x%i==0){
                x=x/i;
                if(x%2==0){
                    x=x/2;
                    if(b[x]==0)
                        b[x]=i;
                    }
            }
        }
    }
    while(t--){
        scanf("%d",&ang);
        if(b[ang])
            printf("%d\n",b[ang]);
        else
            printf("-1\n");
    }


}