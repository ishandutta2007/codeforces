#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

const int64 BASE = 37;
const int64 MOD = 1000000097;

int64 H[maxn];
int64 P[maxn];

void build_hash(int n, string &S){
    P[0] = 1;

    for (int i = 0; i < n; ++i){
        P[i + 1] = P[i] * BASE % MOD;
        H[i + 1] = (H[i] * BASE % MOD + S[i] - 'a' + 1) % MOD;
    }
}

int64 get_hash(int b, int e){
    return (H[e] - H[b] * P[e - b] % MOD + MOD) % MOD;
}

int64 hash_exp(int64 h, int n, int l){
    if (n == 0) return 0;

    if (n & 1){
        int64 th = hash_exp(h, n - 1, l);
        return (th * P[l] % MOD + h) % MOD;
    }

    int64 th = hash_exp(h, n / 2, l);
    return (th * P[l * n / 2] % MOD + th) % MOD;
}

int C[maxn];

vector<int> zfunction(const string &s)
{
    int n = s.length();
    vector<int> z(n, n);

    for (int i = 1, g = 0, f; i < n; ++i)
        if (i < g && z[i - f] != g - i)
            z[i] = min(z[i - f], g - i);
        else
        {
            for (g = max(g, i), f = i; g < n && s[g] == s[g - f]; ++g);
            z[i] = g - f;
        }

    return z;
}

bool check(int l, int k){
    if (l % k) return false;
    int sz = l / k;
    int64 h1 = get_hash(0, sz);
    int64 h2 = get_hash(0, l);
    return hash_exp(h1, k, sz) == h2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    build_hash(n, s);

    vi z = zfunction(s);
    z.push_back(0);

    for (int i = 0; i < n; ++i){
        if (check(i + 1, k)){
            int e = i + 1 + min(z[i + 1], (i + 1) / k);
            C[i]++; C[e]--;
        }
    }

    for (int i = 0, c = 0; i < n; ++i){
        c += C[i];
        cout << (c ? 1 : 0);
    }
    cout << endl;

    return 0;
}