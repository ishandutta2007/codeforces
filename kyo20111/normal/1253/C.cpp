#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200200];
ll s[200200];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1, a+1+n);
    for(int i=m+1;i<=n;i++) s[i] += s[i-m] + a[i-m];

    for(int i=1;i<=n;i++){
        s[i] += s[i-1] + a[i];
        printf("%lld ",s[i]);
    }
}