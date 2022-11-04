#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, a[111];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        sort(a+1, a+1+n, greater<>());
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
}