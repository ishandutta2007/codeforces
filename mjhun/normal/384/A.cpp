#include <cstdio>

int main(){
    int n,i,j;
    scanf("%d",&n);
    if(n%2)printf("%d\n",(n*n+1)/2);
    else printf("%d\n",n*n/2);

    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if((i+j)%2)putchar('.');
            else putchar('C');
        }
        putchar('\n');
    }
    return 0;
}