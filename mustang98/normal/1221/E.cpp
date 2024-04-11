#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

int a, b;
string s;


char buf[max_n];
string read_str() {
    scanf("%s", buf);
    return buf;
}

bool solve() {
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'X') {
            v.PB(cnt);
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    v.PB(cnt);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    while (v.size() && v.back() < b) {
        v.pop_back();
    }
    if (v.empty()) {
        return 0;
    }
    reverse(v.begin(), v.end());
    if (v[0] < a) {
        return 0;
    }
    int cm2b = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] >= b * 2) {
            ++cm2b;
        }
    }
    if (cm2b == 0) {
        return v.size() % 2;
    }
    if (cm2b >= 2) {
        return 0;
    }
    int len = v.back();
    bool cana = 0;
    v.pop_back();
    for (int i = 0; i <= len - a; ++i) {
        int l = i;
        int r = len - l - a;
        if (l > r) {
            swap(l, r);
        }
        if (l >= 2 * b || r >= 2 * b) {
            continue;
        }
        if (r >= b && r < a) {
            continue;
        }
        if (l >= b && l < a) {
            continue;
        }
        if (l < b && r < b) {
            if (v.size() % 2 == 0) {
                cana = 1;
                break;
            } else {
                continue;
            }
        } else if (l < b && r >= a) {
            if (v.size() % 2 == 1) {
                cana = 1;
                break;
            } else {
                continue;
            }
        } else if (l >= a && r >= a) {
            if (v.size() % 2 == 0) {
                cana = 1;
                break;
            } else {
                continue;
            }
        } else {
            exit(228);
        }
    }
    return cana;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        int n;
        scanf("%d%d", &a, &b);
        s = read_str();
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}