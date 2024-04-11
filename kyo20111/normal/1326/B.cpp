#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
int n;
ll b[200200], a[200200];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",b+i);

    a[1] = b[1];
    ll mx = a[1];
    for(int i=2;i<=n;i++){
        a[i] = b[i] + mx;
        mx = max(mx, a[i]);
    }

    for(int i=1;i<=n;i++) printf("%lld ",a[i]);
}