#include <cstdio>

int main(){
    int n,d,t,i,s=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;++i){
        scanf("%d",&t);
        s+=t;
    }

    if(s+10*(n-1)>d)puts("-1");
    else printf("%d\n", (d-s)/5);

    return 0;
}