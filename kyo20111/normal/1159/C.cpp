#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll ans, a[100100], b[100100];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=m;i++) scanf("%lld",b+i);
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    if(a[n] > b[1] || (n==1 && a[1] != b[1])) return !printf("-1");

    for(int i=1;i<=m;i++) ans += b[i];
    if(a[n] == b[1]){
        for(int i=1;i<n;i++) ans += a[i] * m;
    }else{
        ans += a[n] + a[n-1] * (m-1);
        for(int i=1;i<n-1;i++) ans += a[i] * m;
    }

    printf("%lld",ans);
}