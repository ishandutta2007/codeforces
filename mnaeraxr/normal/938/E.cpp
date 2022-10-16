#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;
const int mod = 1000000007;

void add(int &a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
}

int fak[maxn];
int ifak[maxn];

int modpow(int a, int b){
    int c = 1;

    while (b){
        if (b & 1)
            c = 1LL * c * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }

    return c;
}

int comb(int n, int k){
    return 1LL * fak[n] * ifak[k] % mod * ifak[n - k] % mod;
}

int main(){
    // Compute the inverse of each factorial mod 10^9+7 in O(n)
    fak[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fak[i] = 1LL * fak[i-1] * i % mod;
        
    ifak[maxn-1] = modpow(fak[maxn-1], mod-2);
    
    for (int i = maxn-2; i >= 0; --i)
        ifak[i] = 1LL * ifak[i + 1] * (i+1) % mod;
    // End calculation

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    vector<int> value(n);

    for (int i = 0; i < n; ++i)
        cin >> value[i];

    sort(value.begin(), value.end());

    int answer = 0;

    for (int i = 0, j; i < n; i=j){
        for (j = i; j < n && value[j] == value[i]; ++j);

        if (j == n) break;

        int k = i;

        int x = 1LL * fak[k] * fak[n-k-1] % mod * comb(n, k) % mod;

        x = 1LL * value[i] * x % mod * (j - i) % mod;

        add(answer, x);
    }

    cout << answer << endl;

    return 0;
}