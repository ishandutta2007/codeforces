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

string solve(int n, string a, string b) {
    vector<pii> seq0, seq1;
    for (int i = 0, j = 0; i < 2 * n && j < 2 * n;) {
        while (i < 2 * n && a[i] != '0') i++;
        while (j < 2 * n && b[j] != '0') j++;
        if (i == 2 * n || j == 2 * n)
            break;
        seq0.emplace_back(i, j);
        i++, j++;
    }
    for (int i = 0, j = 0; i < 2 * n && j < 2 * n;) {
        while (i < 2 * n && a[i] != '1') i++;
        while (j < 2 * n && b[j] != '1') j++;
        if (i == 2 * n || j == 2 * n)
            break;
        seq1.emplace_back(i, j);
        i++, j++;
    }
    vector<pii> seq = seq0.size() > seq1.size() ? seq0 : seq1;
    if (seq.empty())
        return "";
    string res;
    int I = 0, J = 0;
    for (int it = 0; it < (int) seq.size(); it++) {
        auto [i, j] = seq[it];
        while (I < i) res.push_back(a[I++]); I++;
        while (J < j) res.push_back(b[J++]); J++;
        res.push_back(a[i]);
    }
    while (I < 2 * n) res.push_back(a[I++]);
    while (J < 2 * n) res.push_back(b[J++]);
    if ((int) res.size() > 3 * n)
        res = "";
    return res;
}

string gen(int n, mt19937& rnd) {
    string res;
    for (int i = 0; i < n; i++)
        res.push_back(rnd() % 2 ? '1' : '0');
    return res;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
//    t = 1000;

    mt19937 rnd(42);

    while (t--) {
        int n;
        cin >> n;
//        n = 1000;
        vector<string> a(3);
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
//            a[i] = gen(2 * n, rnd);
        }
        string res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                res = solve(n, a[i], a[j]);
                if (!res.empty())
                    break;
            }
            if (!res.empty())
                break;
        }
//        if (res.empty()) {
//            cout << "WA\n";
//            cout << n << "\n";
//            for (int i = 0; i < 3; i++)
//                cout << a[i] << "\n";
//            return 0;
//        }
        cout << res << "\n";
    }

    return 0;
}