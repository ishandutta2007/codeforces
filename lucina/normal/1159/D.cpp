#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    if(k==1){
        printf("1");
        for(int i=1;i<n;i++)
            printf("0");
        return 0;
    }
    int c=(n-k)>>1;
    int r=0;
    for(int i=1;i<=n;i++){
        if(r==c){
            printf("0");
            r=0;
        }
        else{
            printf("1");
            r++;
        }
    }
}