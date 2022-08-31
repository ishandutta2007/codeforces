#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> a;
vector<int> b;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    ll c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a.PB(c);
    }
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        b.PB(c);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2 == 0) {
            if (a.size() == 0) {
                b.pop_back();
                continue;
            }
            if (b.size() == 0) {
                c1 += a.back();
                a.pop_back();
                continue;
            }
            if (a.back() >= b.back()) {
                c1 += a.back();
                a.pop_back();
            } else {
                b.pop_back();
            }
        } else {
            if (b.size() == 0) {
                a.pop_back();
                continue;
            } else if (a.size() == 0) {
                c2 += b.back();
                b.pop_back();
                continue;
            }
            if (b.back() >= a.back()) {
                c2 += b.back();
                b.pop_back();
            } else {
                a.pop_back();
            }
        }
    }
    cout << c1 - c2;

    return 0;
}