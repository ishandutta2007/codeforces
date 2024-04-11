#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 1000000007
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}
LL fact[1100000];
LL invfact[1100000];
LL pow10[1100000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    LL inv2 = inv(2);
    pow10[0] = 1;
    for(LL i = 1; i < 11000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
        pow10[i] = (pow10[i-1] * 10) % MOD;
    }
}

// call init();

int main(){
    init();
    string num;
    cin >> num;

    int n = num.size();
    num[n-1]++;
    vector<int> freq(10);

    LL ans = 0;

    LL sums[n+1][n][10];
    for(LL k = 0; k < n; k++){
        for(LL d = 0; d < 10; d++){
            for(LL low = n; low >= 0; low--){
                if(low > k){
                    sums[low][k][d] = 0;
                } else {
                    sums[low][k][d] = sums[low+1][k][d];
                    LL term = powmod(d, low) * powmod(10-d, k-low);
                    term %= MOD;
                    term = (term * ncr(k, low)) % MOD;
                    sums[low][k][d] += term;
                    sums[low][k][d] %= MOD;
                }
            }
        }
    }

    for(int dig = 0; dig < n; dig++){
        int k = n - 1 - dig;
        for(int z = 0; z < num[dig] - '0'; z++){
            freq[z]++;
            for(int d = 0; d < 10; d++){
                for(int a = 1; a <= n; a++){
                    int botlimit = a;
                    int toplimit = (n+1-a);
                    for(int j = 0; j < 10; j++){
                        if(j < d) botlimit -= freq[j];
                        if(j > d) toplimit -= freq[j];
                    }
                    LL contrib = pow10[k];
                    /*for(int b = max(0, botlimit); b <= k; b++){
                    }

                    for(int b = max(0, toplimit); b <= k; b++){
                        LL term = powmod(9-d, b) * powmod(d+1, k-b);
                        term %= MOD;
                        term = (term * ncr(k, b) ) % MOD;
                        contrib -= term;
                        contrib %= MOD;
                    }*/

                    contrib -= sums[max(0,botlimit)][k][d];
                    contrib -= sums[max(0,toplimit)][k][9-d];

                    ans += ( (contrib * pow10[n-a]) % MOD) * d;
                    ans %= MOD;
                }
            }
            freq[z]--;
        }
        if(dig < n-1) freq[num[dig]-'0']++;
    }
    ans %= MOD;
    while(ans < 0) ans += MOD;
    cout << ans << endl;

}