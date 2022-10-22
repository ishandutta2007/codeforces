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

vector<int> int_to_vec(int x) {
    assert(x > 0);
    vector<int> res;
    while (x > 0) {
        res.push_back(x & 1);
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

pii calc(vector<int> x) {
    int c0 = 0, c1 = 0;
    for (int t : x) {
        if (t == 0) c0++;
        else c1++;
    }
    return {c0, c1};
}

pii calc(int x) {
    return calc(int_to_vec(x));
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;

    if (k == 0) {
        cout << "Yes\n";
        for (int i = 0; i < b; i++) cout << 1;
        for (int i = 0; i < a; i++) cout << 0;
        cout << "\n";
        for (int i = 0; i < b; i++) cout << 1;
        for (int i = 0; i < a; i++) cout << 0;
        cout << "\n";
        return 0;
    }

    if (k >= a + b) {
        cout << "No\n";
        return 0;
    }

    if (a >= 1 && b >= 2 && k < a + b - 1) {
        a -= 1;
        b -= 2;
        vector<int> x = {1}, y = {0};
        for (int i = 1; i < k; i++) {
            if (a > 0) {
                x.push_back(0);
                y.push_back(0);
                a--;
            } else {
                x.push_back(1);
                y.push_back(1);
                b--;
            }
        }
        x.push_back(0);
        y.push_back(1);
        while (a > 0) {
            x.push_back(0);
            y.push_back(0);
            a--;
        }
        while (b > 0) {
            x.push_back(1);
            y.push_back(1);
            b--;
        }
        x.push_back(1);
        y.push_back(1);
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        cout << "Yes\n";
        for (int t : y) cout << t;
        cout << "\n";
        for (int t : x) cout << t;
        cout << "\n";
        return 0;
    }

    if (a >= 1 && b >= 2 && a + b - 1 == k) {
        cout << "No\n";
        return 0;
    }

    for (int x = 1; x <= 100; x++) {
        vector<int> ax = int_to_vec(x);
        if (calc(ax) != make_pair(a, b))
            continue;
        for (int y = 1; y < x; y++) {
            vector<int> ay = int_to_vec(y);
            if (calc(ay) != make_pair(a, b))
                continue;
            int z = x - y;
            vector<int> az = int_to_vec(z);
            if (calc(az).second == k) {
                cout << "Yes\n";
                for (int t : ax) cout << t; cout << "\n";
                for (int t : ay) cout << t; cout << "\n";
                return 0;
            }
        }
    }

    cout << "No\n";

    return 0;
}