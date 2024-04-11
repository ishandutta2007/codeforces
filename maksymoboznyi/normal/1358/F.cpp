#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, a[N], b[N];

bool dec() {
    for (int i = 2; i <= n; i++)
        if (b[i] >= b[i - 1])
            return 0;
    return 1;
}

bool inc() {
    for (int i = 2; i <= n; i++)
        if (b[i] <= b[i - 1])
            return 0;
    return 1;
}

void revb() {
    for (int i = 1; i + i <= n; i++)
        swap(b[i], b[n - i + 1]);
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n > 2) {
        string ans = "";
        int kol = 0;
        while (1) {
            bool is = 1;
            for (int i = 1; i <= n; i++)
                if (b[i] != a[i])
                    is = 0;
            if (is)
                break;
            is = 1;
            revb();
            for (int i = 1; i <= n; i++)
                if (b[i] != a[i])
                    is = 0;
            if (is) {
                ans += "R";
                break;
            }
            revb();
            if (dec())
                ans += "R", revb();

            if (inc()) {
                kol++;
                ans += "P";
                for (int i = n; i > 0; i--)
                    b[i] -= b[i - 1];
            } else {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        if (kol > 2e5) {
            cout << "BIG\n" << kol;
            return 0;
        }
        cout << "SMALL\n";
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        cout << ans;
        return 0;
    }
    if (n == 1) {
        if (a[1] == b[1])
            cout << "SMALL\n0";
        else
            cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> kol;
    bool r1 = 0, r2 = 0;
    if (a[1] > a[2])
        swap(a[1], a[2]), r1 = 1;
    if (b[1] > b[2])
        swap(b[1], b[2]), r2 = 1;
    int x = b[1], y = b[2];
    while (x != 0 && y != 0) {
        if (x == a[1] && (y - a[2]) % x == 0) {
            kol.pb((y - a[2]) / x);
            y = a[2];
            break;
        }
        kol.pb(y / x);
        y %= x;
        swap(x, y);
    }
    if (x != a[1] || y != a[2]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int sum = 0;
    for (auto x: kol)
        sum += x;
    if (sum > 2e5) {
        cout << "BIG\n" << sum;
        return 0;
    }
    string ans = "";
    reverse(kol.begin(), kol.end());
    for (int i = 0; i < kol.size(); i++) {
        //cout << kol[i] << endl;
        for (int j = 0; j < kol[i]; j++)
            ans += "P";
        if (i != kol.size() - 1)
            ans += "R";
    }
    if (r1)
        ans = "R" + ans;
    if (r2)
        ans = ans + "R";
    cout << "SMALL\n" << ans.size() << "\n" << ans;
    return 0;
}