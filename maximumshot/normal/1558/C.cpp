#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<int> fast(int n, vector<int> a) {
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 != i % 2)
            return {-1};
    }
    vector<int> res;
    auto do_op = [&](int p) {
        assert(p % 2 == 1);
        res.push_back(p);
        reverse(a.begin() + 1, a.begin() + p + 1);
    };
    for (int i = n; i > 1; i -= 2) {
        int p_odd, p_even;

        p_odd = p_even = i;
        while (a[p_odd] != i) p_odd--;
        while (a[p_even] != i - 1) p_even--;
        do_op(p_odd);

        p_odd = p_even = i;
        while (a[p_odd] != i) p_odd--;
        while (a[p_even] != i - 1) p_even--;
        do_op(p_even - 1);

        p_odd = p_even = i;
        while (a[p_odd] != i) p_odd--;
        while (a[p_even] != i - 1) p_even--;
        do_op(p_even + 1);
        do_op(3);
        do_op(i);
    }
//    cout << "a = ";
//    for (int i = 1; i <= n; i++)
//        cout << a[i] << " ";
//    cout << "\n";
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> res = fast(n, a);
        if ((int) res.size() == 1 && res.front() == -1) {
            cout << "-1\n";
        } else {
            cout << (int) res.size() << "\n";
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}