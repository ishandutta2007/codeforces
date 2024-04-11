#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using vec = vector<T>;
template<typename A, typename B = A> using pr = pair<A, B>;
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()
#define ar array

inline vec<int> get(int x) {
    if (x == 0)
        return {0, 1};
    int k = 2;
    while (k * (k - 1) / 2 < x)
        k++;
    if (k * (k - 1) / 2 != x) {
        cout << "Impossible\n";
        exit(0);
    }
    return {k};
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
        cout << "0\n";
        return 0;
    }
    auto zz = get(a00);
    auto oo = get(a11);
    for (auto z : zz)
        for (auto o : oo)
            if (z * o == a01 + a10) {
                vec<int> cnt(z + 1);
                int need01 = a01;
                for (int i = 0; i < o; i++) {
                    cnt[min(need01, z)]++;
                    need01 -= min(need01, z);
                }
                for (int i = 0; i <= z; i++) {
                    cout << string(cnt[i], '1');
                    if (i != z)
                        cout << "0";
                }
                cout << '\n';
                return 0;
            }

    cout << "Impossible\n";
}