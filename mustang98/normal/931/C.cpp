#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int minn = inf;
    int maxx = -inf;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
        minn = min(minn, a);
        maxx = max(maxx, a);
    }
    if (maxx - minn < 2) {
        cout << n << endl;
        for (int a : v) {
            cout << a << ' ';
        }
        return 0;
    }
    int cntmid = 0;
    int cntmin = 0;
    int cntmax = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == maxx) {
            cntmax++;
        } else if (v[i] == minn) {
            cntmin++;
        } else {
            cntmid++;
        }
    }
    if (cntmid / 2 > min(cntmin, cntmax)) {
        // change MID
        cout << n - (cntmid - cntmid % 2) << endl;
        for (int i = 0, a = cntmid / 2; i < v.size() && a; ++i) {
            if (v[i] == maxx - 1) {
                v[i]--;
                a--;
            }
        }
        for (int i = 0, a = cntmid / 2; i < v.size() && a; ++i) {
            if (v[i] == maxx - 1) {
                v[i]++;
                a--;
            }
        }
        for (int a : v) {
            cout << a << ' ';
        }
    } else {
        int cntd = min(cntmin, cntmax);
        cout << n - (cntd * 2) << endl;
        for (int i = 0, a = cntd; i < v.size() && a; ++i) {
            if (v[i] == minn) {
                v[i]++;
                a--;
            }
        }
        for (int i = 0, a = cntd; i < v.size() && a; ++i) {
            if (v[i] == maxx) {
                v[i]--;
                a--;
            }
        }
        for (int a : v) {
            cout << a << ' ';
        }
    }

    return 0;
}