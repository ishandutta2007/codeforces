#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[200200], c[30];

void solve(){
    memset(c, 0, sizeof c);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<30;j++) if((1 << j) & a[i]) c[j]++;
    }

    for(int i=1;i<=n;i++){
        bool flag = 1;
        for(int j=0;j<30;j++) if(c[j] % i) flag = 0;
        if(flag) cout << i << " ";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}