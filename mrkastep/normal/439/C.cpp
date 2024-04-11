#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define For(i,n) for(i=0;i<(n);i++)

int arr[100005];

bool srt(int x,int y){
    return x%2>y%2;
}

void solve(int n,int k,int p){
    int i,j,t=0,s=0;
    For(i,n){
        scanf("%d",&arr[i]);
        s+=arr[i]%2;
    }
    std::sort(arr,arr+n,srt);
    if(s%2!=p%2){
        printf("NO");
        return;
    }
    if(s<p){
        printf("NO");
        return;
    }
    if((n-s)+(s-p)/2<k-p){
        printf("NO");
        return;
    }
    printf("YES\n");
    if(p==k){
        For(i,p-1){
            printf("1 %d\n",arr[i]);
            t++;
        }
        printf("%d ",n-p+1);
        for(i=i;i<n;i++){
            printf("%d ",arr[i]);
        }
        return;
    }
    For(i,p){
        printf("1 %d\n",arr[i]);
        t++;
    }
    for(i=i;t<k-1;i++){
        if(arr[i]%2==1){
            printf("2 %d %d\n",arr[i],arr[i+1]);
            i++;
        }
        else printf("1 %d\n",arr[i]);
        t++;
    }
    if(n==i) return;
    printf("%d ",n-i);
    for(i=i;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        solve(n,m,m-k);
    }
    return 0;
}