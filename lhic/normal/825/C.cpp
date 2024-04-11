#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


int n, k;
int a[12000];
int ans = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        while (k * 2 < a[i])
            ++ans, k *= 2;
        k = max(k, a[i]);
    }
    cout << ans << "\n";
    return 0;
}