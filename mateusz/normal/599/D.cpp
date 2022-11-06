#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

long long y;

int main() {

    ios_base::sync_with_stdio(0);
    cin >> y;

    vector<pair<long long, long long> > v;
    long long ans = 0;
    if (y == 1) {
        cout << "1\n1 1\n";
        return 0;
    }
    for (long long n = 1; n <= 12 * 1e6; n++) {
        long long wynik = 2 * y + n * n * (n - 1) - n * (n - 1) * (2 * n - 1) / 3;
        long long m = wynik / n / (n + 1);
        if (m >= n && wynik % (n * (n + 1)) == 0) {
//             cerr << wynik << endl;
            ans += 2;
            v.push_back({n, wynik / n / (n + 1)});
            if (n != wynik / n / (n + 1))
                v.push_back({wynik / n / (n + 1), n});
        }
    }

    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (auto x: v) {
        if (x.first <= x.second)
        assert(x.first*x.first*x.second-(x.first - 1)*x.first*x.first/2 - (x.first-1)*x.first*x.second/2 + x.first*(x.first-1)*(2 * x.first-1)/6 == y);
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}