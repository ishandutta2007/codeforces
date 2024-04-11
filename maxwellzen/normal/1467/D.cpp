#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll MOD = 1e9 + 7;

int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    ll nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll cur[k+1][n];
    for (int i = 0; i < n; i++) {
        cur[0][i]=1;
    }
    ll total[n];
    for (int step = 1; step <= k; step++) {
        for (int i = 0; i < n; i++) {
            cur[step][i]=0;
            if (i>0) cur[step][i] = (cur[step][i]+cur[step-1][i-1])%MOD;
            if (i<n-1) cur[step][i] = (cur[step][i]+cur[step-1][i+1])%MOD;
            if (cur[step][i]<0) cur[step][i]+=MOD;
        }
    }
    for (int i = 0; i < n; i++) {
        total[i]=0;
        for (int j = 0; j <= k; j++) {
            total[i] = (total[i]+(cur[j][i]*cur[k-j][i])%MOD)%MOD;
            if(total[i]<0) total[i]+=MOD;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (total[i] * nums[i]) % MOD;
    }
    for (int i = 0; i < q; i++) {
        int a;
        ll b;
        cin >> a >> b;
        a--;
        sum = (sum + (((b-nums[a])%MOD)*total[a])%MOD)%MOD;
        if (sum<0) sum += MOD;
        nums[a]=b;
        cout << sum << endl;
    }
}