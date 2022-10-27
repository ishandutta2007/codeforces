#include<stdio.h>
const int maxn=3e5+10;
int t,b[maxn],n,c;
int main(){
    int id=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        b[t]=i;
        }
    for(int i=1;i<=n;i++){
        scanf("%d",&c);
        if(b[c]>=id){
            printf("%d ",b[c]-id);
            id=b[c];
        }
        else
            printf("%d ",0);
    }
}