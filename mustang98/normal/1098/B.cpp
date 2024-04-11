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

string s[max_n];
string s2[max_n];
string ans[max_n];
string ans2[max_n];
string ans3[max_n];

char buf[max_n];
string read_s() {
    scanf("%s", buf);
    return string(buf);
}
int n, m;
string pat = "AGCT";

int diff(string& s1, string& s2) {
    int ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
        ans += (s1[i] != s2[i]);
    }
    return ans;
}

int fill_hor(string p1, string p2, bool build = 0) {
    string ch1[2];
    string ch2[2];
    for (int i = 0; i < m; ++i) {
        ch1[0] += p1[i % 2];
        ch1[1] += p1[(i + 1) % 2];

        ch2[0] += p2[i % 2];
        ch2[1] += p2[(i + 1) % 2];
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            int d1 = diff(s[i], ch1[0]);
            int d2 = diff(s[i], ch1[1]);
            if (d1 < d2) {
                res += d1;
                if (build) {
                    ans[i] = ch1[0];
                }
            } else {
                res += d2;
                if (build) {
                    ans[i] = ch1[1];
                }
            }
        } else {
            int d1 = diff(s[i], ch2[0]);
            int d2 = diff(s[i], ch2[1]);
            if (d1 < d2) {
                res += d1;
                if (build) {
                    ans[i] = ch2[0];
                }
            } else {
                res += d2;
                if (build) {
                    ans[i] = ch2[1];
                }
            }
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        s[i] = read_s();
    }
    int best_hor = inf;
    for (int i = 0; i < pat.size(); ++i) {
        for (int j = i + 1; j < pat.size(); ++j) {
            string p1, p2;
            for (int k = 0; k < pat.size(); ++k) {
                if (k == i || k == j) {
                    p1 += pat[k];
                } else {
                    p2 += pat[k];
                }
            }
            int cur = fill_hor(p1, p2, 0);
            if (cur < best_hor) {
                best_hor = fill_hor(p1, p2, 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans2[i] = ans[i];
        s2[i] = s[i];
        ans[i] = "";
        s[i] = "";
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            s[j] += s2[i][j];
        }
    }
    swap(n, m);
    int best_ver = inf;
    for (int i = 0; i < pat.size(); ++i) {
        for (int j = i + 1; j < pat.size(); ++j) {
            string p1, p2;
            for (int k = 0; k < pat.size(); ++k) {
                if (k == i || k == j) {
                    p1 += pat[k];
                } else {
                    p2 += pat[k];
                }
            }
            int cur = fill_hor(p1, p2, 0);
            if (cur < best_ver) {
                best_ver = fill_hor(p1, p2, 1);
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            ans3[j] += ans[i][j];
        }
    }
    swap(n, m);
    if (best_hor < best_ver) {
        for (int i = 0; i < n; ++i) {
            printf("%s\n", ans2[i].c_str());
        }
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%s\n", ans3[i].c_str());
        }
    }
    return 0;
}