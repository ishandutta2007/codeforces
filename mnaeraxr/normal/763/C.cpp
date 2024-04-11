#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;

int64 mod;

void add(int64 &a, int64 b){
    a += b;
    if (a >= mod)
        a -= mod;
}

void sub(int64 &a, int64 b){
    a -= b;
    if (a < 0)
        a += mod;
}

int64 modpow(int64 a, int64 n){
    if (n == 0) return 1;
    if (n & 1) return a * modpow(a, n - 1) % mod;
    return modpow(a * a % mod, n / 2);
}

int check(set<int64> &S, int64 x, int64 d){
    int ans = 0;
    while (S.count(x)){
        ans++;
        add(x, d);
    }
    return ans;
}

int64 solve(set<int64> &S){
    if (S.size() == 1) return 1LL;

    int64 cd = *S.rbegin() - *S.begin();
    int cnt = 0;

    for (auto val : S){
        add(val, cd);
        if (S.count(val))
            cnt++;
    }

    int64 ans = cd * modpow(S.size() - cnt, mod - 2) % mod;

    int tot = check(S, *S.begin(), ans) + check(S, *S.begin(), mod - ans) - 1;

    if (tot == (int)S.size()) return ans;
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> mod >> n;

    if (n == mod){
        cout << 0 << " " << 1 << endl;
        return 0;
    }

    int64 x0 = -1;

    set<int64> S, R;

    for (int i = 0; i < n; ++i){
        int64 v; cin >> v;

        if (x0 == -1) x0 = v;

        R.insert(v);
        sub(v, x0);
        S.insert(v);
    }

    bool rev = false;

    if (2 * n > mod){
        rev = true;
        set<int64> K;
        for (int i = 0; i < mod; ++i)
            if (!S.count(i))
                K.insert(i);

        S.swap(K);
    }

    int64 diff = solve(S);

    if (diff == -1)
        cout << -1 << endl;
    else{
        if (rev){
            diff = mod - diff;
        }

        while (R.count(x0))
            sub(x0, diff);
        add(x0, diff);

        cout << x0 << " " << diff << endl;
    }

    return 0;
}