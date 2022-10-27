#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    if(a[n-1]+a[n-2]<=a[n])return !printf("NO\n");
    printf("YES\n");
    for(int i=1;i<n-2;i++)
        printf("%d ",a[i]);
    printf("%d %d %d\n",a[n-2],a[n],a[n-1]);

}
/*
    Good Luck
        -Lucina
*/