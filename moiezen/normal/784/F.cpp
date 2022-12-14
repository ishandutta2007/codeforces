#include <bits/stdc++.h>
int n,a[15],b[15];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=10000000;i++) std::random_shuffle(b+1,b+10+1);
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}