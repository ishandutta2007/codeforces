#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int m[max_n];
int n;

bool solve(vector<int>& ans) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += m[i];
    }
    if (sum % 2 || sum == n) {
        return false;
    }
    int from = 0;
    //cout << endl;
    int l = -1, r = -1;
    while(true) {
        if (l == -1) {
            for (int i = from; i < n; ++i) {
                if (m[i] == 1) {
                    l = i;
                    break;
                }
            }
            if (l == -1) {
                return true;
            }
            r = l;
            while(r + 1 < n && m[r + 1] == 1) {
               // cout << "## " << r << endl;
                ++r;
            }
        }
        //cout << l << ' ' << r << endl;
        //exit(0);
        from = max(from, r + 1);
        if ((r - l + 1) % 2 == 0) {
            if (l == 0 && r == n - 1) {
                return false;
            }
            from = r + 1;
            int c = (r - l + 1);
            while(r - l + 1 > 0) {
                if (l > 0) {
                    ans.push_back(l - 1);
                    m[l] = m[l + 1] = 0;
                    l += 2;
                } else {
                    ans.push_back(r - 1);
                    m[r - 1] = m[r] = 0;
                    r -= 2;
                }
            }
            l = r = -1;
            continue;
        } else {
            int nxt = -1;
            for (int i = r + 1; i < n; ++i) {
                if (m[i] == 1) {
                    nxt = i;
                    break;
                }
            }
            if (nxt == -1) {
                return false;
            }
            int d = (nxt - r - 1);
            if (d % 2 == 0) {
                for (int i = r; i + 1< nxt; i += 2) {
                    ans.PB(i);
                    m[i + 1] = m[i + 2] = 1;
                }
                r = nxt;
                while(r + 1 < n && m[r + 1] == 1) {
                    ++r;
                }
                continue;
            } else {
                while(m[r + 2] != 1) {
                    ans.PB(r);
                    m[r + 1] = m[r + 2] = 1;
                    r += 2;
                }
                ans.PB(r);
                m[r] = m[r + 2] = 0;
                from = r + 2;
                while(r > 0 && m[r - 1] == 1) {
                    ans.PB(r - 2);
                    m[r - 1] = m[r - 2] = 0;
                    r -= 2;
                }
                l = r = -1;
                continue;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        vector<int> v;
        if (solve(v) == false) {
            puts("NO");
            continue;
        }
        puts("YES");
//        check(v);
        cout << v.size() << "\n";
        for (int x : v) {
            cout << x + 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}