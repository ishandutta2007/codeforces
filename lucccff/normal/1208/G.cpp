#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[1000010],b[100010];

void phi_table(int n, int* phi) {
    for (int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!phi[i])
        for (int j = i; j <= n; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>n>>k;
    phi_table(n,a);
    sort(a+3,a+n+1);
    LL ans=0;
    for(i=3;i<=k+2;i++) {
        ans+=a[i];
    }
    if (k>=2) cout<<ans+2;
    else cout<<3<<endl;
    return 0;
}