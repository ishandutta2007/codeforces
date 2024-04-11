#include<bits/stdc++.h>
using namespace std;
int n,a[60],mi,k;

int main(){
    mi=100;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mi=min(mi,a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]==mi)
        k++;
    }
    printf(k>n/2?"Bob":"Alice");
}