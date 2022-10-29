#include <cstdio>

bool w[100005];

int main(){
    int n,k;
    scanf("%d",&n);
    while(--n){
        scanf("%d",&k);
        w[k]=true;
    }
    k=0;
    while(w[++k]);
    printf("%d\n",k);
    return 0;
}