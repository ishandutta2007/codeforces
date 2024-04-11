#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],ne,pt,n;
long long sum;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=abs(a[i]);
        }
    sort(a+1,a+1+n);
    pt=1;
    for(int i=1;i<=n;i++){
        while(2*a[pt]<a[i])pt++;
        sum+=(i-pt);
        }
    printf("%lld\n",sum);
}