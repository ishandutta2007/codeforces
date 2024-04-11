#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ull n;
    cin >> n;
    vector<ull> f{1, 2};
    for (int i = 2; i < 100; i++) {
        ull new_f = f[i - 1] + f[i - 2];
        f.push_back(new_f);
    }
    int res = 0;
    while (f[res] <= n)
        res++;
    cout << res - 1 << endl;
}