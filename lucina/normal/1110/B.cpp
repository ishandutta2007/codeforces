#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,k,dif[maxn],sum,a[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dif[i-1]=a[i]-a[i-1]-1;
    }
    sum=n;
    sort(dif+1,dif+n);
    for(int i=1;i<=n-k;i++){
        sum+=(dif[i]);
    }
    printf("%d",sum);
}