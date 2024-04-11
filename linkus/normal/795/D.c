#include <stdio.h>
int main(){
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    --l;--r;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;++i)
        scanf("%d",&arr1[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&arr2[i]);
    for(int i=0;i<l;++i){
        if(arr1[i] != arr2[i]){
            printf("LIE");
            return 0;
        }
    }
    for(int i=r+1;i<n;++i){
        if(arr1[i] != arr2[i]){
            printf("LIE");
            return 0;
        }
    }
    printf("TRUTH");
    return 0;
}