#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,n;
int main(){
    scanf("%d",&t);
    for(int j=1;j<=t;j++){
        scanf("%d",&n);
        for(int i=2;i<=7;i++){
            if(n%i==0){
                printf("%d\n",n/i);
                break;
            }
            else
            {
                if(n%i>=2){
                    printf("%d\n",n/i+1);
                    break;

                }
            }
        }
    }

}