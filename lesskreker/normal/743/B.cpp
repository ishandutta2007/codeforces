#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int get(int n, lint k) {
    lint l = (1LL << (n - 1)) - 1;
    if (k == l) {
        return n;
    }
    if (k < l) {
        return get(n - 1, k);
    }
    return get(n - 1, k - l - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    scidl(k);
    cout << get(n, k - 1);

    return 0;
}