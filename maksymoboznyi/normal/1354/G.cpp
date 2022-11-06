#include <bits/stdc++.h>
#define pb push_back
using namespace std;

mt19937 gen;

int n, k, l, prev_l;

bool check(int m) {
    vector<int> a1, a2;
    for (int i = prev_l + 1; i <= m; i++)
        a2.pb(i);
    for (int i = 1; i <= a2.size(); i++)
        a1.pb(i);
    cout << "? " << a1.size() << ' ' << a2.size() << endl;
    for (auto x: a1)
        cout << x << ' ';
    cout << endl;
    for (auto x: a2)
        cout << x << ' ';
    cout << endl;
    string s;
    cin >> s;
    return s != "EQUAL";
}

int main()
{
    gen.seed(time(0));
    int o;
    cin >> o;
    while (o--) {
        cin >> n >> k;
        bool is_less = 0;
        for (int i = 1; i <= 30; i++) {///change to 30
            int pos = gen() % n + 1;
            if (pos == 1)
                continue;
            cout << "? 1 1" << endl;
            cout << 1 << endl;
            cout << pos << endl;
            string s;
            cin >> s;
            if (s == "SECOND")
                is_less = 1;
        }
        if (is_less) {
            cout << "! 1" << endl;
            continue;
        }
        prev_l = 1, l = 1;
        while (l < n) {
            prev_l = l;
            l *= 2;
            l = min(l, n);
            vector<int> a1, a2;
            for (int i = prev_l + 1; i <= l; i++)
                a2.pb(i);
            for (int i = 1; i <= a2.size(); i++)
                a1.pb(i);
            cout << "? " << a1.size() << ' ' << a2.size() << endl;
            for (auto x: a1)
                cout << x << ' ';
            cout << endl;
            for (auto x: a2)
                cout << x << ' ';
            cout << endl;
            string s;
            cin >> s;
            if (s == "FIRST")
                break;
        }
        int L = prev_l, R = l;
        while (L < R - 1) {
            int m = (L + R) / 2;
            if (check(m))
                R = m;
            else
                L = m;
        }
        cout << "! " << R << endl;
    }
    return 0;
}