#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005];

int main(){
    int n,i,j,k;int r0,r1,r2;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    i=1;
    while(i<=n){
        r0=r1=r2=0;
        j=i;
        while(j<=n&&a[j]){
            if(a[j]>a[r0]){
                r2=r1;
                r1=r0;
                r0=j;
            }
            else if(a[j]>a[r1]){
                r2=r1;
                r1=j;
            }
            else if(a[j]>a[r2])r2=j;
            j++;
        }
        for(k=i;k<j;++k){
            if(k==r0)puts("pushStack");
            else if(k==r1)puts("pushFront");
            else if(k==r2)puts("pushQueue");
            else puts("pushBack");
        }
        if(j<=n){
        k=(r0!=0)+(r1!=0)+(r2!=0);
        printf("%d",k);
        if(r0)printf(" popStack");
        if(r1)printf(" popFront");
        if(r2)printf(" popQueue");
        putchar('\n');
        }
        i=j+1;
    }
    return 0;
}