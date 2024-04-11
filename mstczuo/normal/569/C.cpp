# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

long long p, q;

bool prime[2000010], pad[2000010];

bool check(int val) {
    static int dig[20], n;
    n = 0;
    while(val > 0) {
        dig[n++] = val % 10;
        val = val / 10;
    }
    for(int l = 0, r = n; l < r; ++l, --r) 
        if(dig[l] != dig[r - 1]) return false;
    return true;
}

void pre() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 2000000; ++i) if(prime[i])
        for(int j = i << 1; j <= 2000000; j += i) prime[j]=false;
    memset(pad, true, sizeof(pad));
    for(int i = 2; i <= 2000000; ++i) pad[i] = check(i);
}

int main() {
    cin >> p >> q; pre();
    int pi = 0, rub = 0, ans = 0;
    for(int i = 1; i <= 2000000; ++i) {
        pi += prime[i];
        rub += pad[i];
        if(pi * q <= p * rub) {
            ans = i;
        }
    }
    cout << ans << endl;
}