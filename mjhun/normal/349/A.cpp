#include <cstdio>


int a[256];

int main(){
    int n,k,i;bool r=true;
    scanf("%d",&n);a[50]=0;a[25]=0;a[100]=0;
    for(i=0;r&&i<n;++i){
        scanf("%d",&k);
        if(k==50){
            if(a[25]<=0)r=false;
            else a[25]--;
        }
        else if(k==100){
            if(a[25]<=0||(a[25]<=2&&a[50]<=0))r=false;
            else {
                a[25]--;
                if(a[50]>0){
                    a[50]--;
                }
                else{
                    a[25]-=2;
                }
            }
        }
        a[k]++;
    }
    if(r)puts("YES");
    else puts("NO");
    return 0;
}