#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+2*n);
    if(a[1]==a[2*n])return !printf("-1");
    for(int i=1;i<=2*n;i++)
        printf("%d ",a[i]);

}