#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    int arr1[n],arr2[n];
    for(int *i = arr1; i < arr1+n; ++i){
        scanf("%d",i);
    }
    for(int *i = arr2; i < arr2+n; ++i){
        scanf("%d",i);
    }
    --l, --r;
    for(int i = 0; i < l; ++i){
        if(arr1[i] != arr2[i]){
            puts("LIE");
            return 0;
        }
    }
    for(int i = r+1; i < n; ++i){
        if(arr1[i] != arr2[i]){
            puts("LIE");
            return 0;
        }
    }
    int c1[n+1],c2[n+1];
    memset(c1,0,sizeof c1);
    memset(c2,0,sizeof c2);
    for(int i = l; i <= r; ++i){
        ++c1[arr1[i]];
        ++c2[arr2[i]];
    }
    for(int i = 1; i <= n; ++i){
        if(c1[i] != c2[i]){
            puts("LIE");
            return 0;
        }
    }
    puts("TRUTH");
}