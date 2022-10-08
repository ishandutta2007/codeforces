
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// int ansArray[5] = {-1, 5, 6, 8, 7};

int query(const string &type, int i, int j) {
    cout << type << ' ' << i << ' ' << j << endl;
    // if(type == "and") return (ansArray[i] & ansArray[j]);
    // else return (ansArray[i] | ansArray[j]);
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<int, 3> ans[2][2][2][2][2][2];
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2) {
        int aij = (i & j);
        int ajk = (j & k);
        int aki = (k & i);
        int oij = (i | j);
        int ojk = (j | k);
        int oki = (k | i);
        ans[aij][ajk][aki][oij][ojk][oki] = {i, j, k};
    }
    int n, k;
    cin >> n >> k;
    int a12 = query("and", 1, 2);
    int a23 = query("and", 2, 3);
    int a31 = query("and", 3, 1);
    int o12 = query("or", 1, 2);
    int o23 = query("or", 2, 3);
    int o31 = query("or", 3, 1);
    vi a(n + 1);
    rep(i, 0, 30) {
        array<int, 3> vals = ans[a12 >> i & 1][a23 >> i & 1][a31 >> i & 1][o12 >> i & 1][o23 >> i & 1][o31 >> i & 1];
        a[1] ^= vals[0] * (1 << i);
        a[2] ^= vals[1] * (1 << i);
        a[3] ^= vals[2] * (1 << i);
    }
    rep(i, 4, n + 1) {
        int AND = query("and", 1, i);
        int OR = query("or", 1, i);
        rep(b, 0, 30) {
            if(AND >> b & 1) a[i] ^= (1 << b);
            else if((OR >> b & 1) && (~a[1] >> b & 1)) a[i] ^= (1 << b);
        }
    }
    sort(1 + all(a));
    cout << "finish " << a[k] << endl;
}