#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1003, inf = 1000111222;

int m[max_n][max_n];
int n;

int tmp[max_n];
int tmp2[max_n][max_n];;

void opI(int i) {
    for (int j = 0; j < n; ++j) {
        tmp[m[i][j]] = j;
    }
    for (int j = 0; j < n; ++j) {
        m[i][j] = tmp[j];
    }
}

void opI() {
    for (int i = 0; i < n; ++i) {
        opI(i);
    }
}


void opJ(int j) {
    for (int i = 0; i < n; ++i) {
        tmp[m[i][j]] = i;
    }
    for (int i = 0; i < n; ++i) {
        m[i][j] = tmp[i];
    }
}

void opJ() {
    for (int j = 0; j < n; ++j) {
        opJ(j);
    }
}

void tran() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp2[j][i] = m[i][j];
        }
    }
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = tmp2[i][j];
        }
    }
}


void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int len;
        cin >> n >> len;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
                --m[i][j];
            }
        }
        string s;
        cin >> s;
        vector<char> v;
        for (char& c : s) {
            if (c == 'C') {
                c = 'J';
            }
            if (c != 'I' && c != 'J') {
                continue;
            }
            if (v.empty() || v.back() != c) {
                v.PB(c);
            } else {
                v.pop_back();
            }
        }
        reverse(v.begin(), v.end());
        bool tr = 0;
        while (v.size() >= 3) {
            tr = !tr;
            v.pop_back();
            v.pop_back();
            v.pop_back();
        }
        if (tr) {
            tran();
        }
        while (!v.empty()) {
            if (v.back() == 'J') {
                opJ();
            } else {
                opI();
            }
            v.pop_back();
        }
        v.clear();
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == 'I' || c == 'J') {
                if (v.empty() || v.back() != c) {
                    v.PB(c);
                } else {
                    v.pop_back();
                }
                continue;
            }
            if (v.empty()) {
                continue;
            }
            if (c == 'R' || c == 'L') {
                int k = v.size();
                if (v.back() == 'J') {
                    --k;
                }
                int sw = (((k + 1) / 3) % 2);
                if (sw) {
                    c = c == 'R' ? 'D' : 'U';
                }
                if (k % 3 == 1) {
                    if (c == 'U' || c == 'L') {
                        c = 'm';
                    } else {
                        c = 'p';
                    }
                }
            } else {
                int k = v.size();
                if (v.back() == 'I') {
                    --k;
                }
                int sw = (((k + 1) / 3) % 2);
                if (sw) {
                    c = c == 'D' ? 'R' : 'L';
                }
                if (k % 3 == 1) {
                    if (c == 'U' || c == 'L') {
                        c = 'm';
                    } else {
                        c = 'p';
                    }
                }
            }
            s[i] = c;
        }
        int add = 0;
        for (char c : s) {
            if (c == 'm') {
                --add;
            }
            if (c == 'p') {
                ++add;
            }
        }
        vector<int> vi, vj;
        for (int i = 0; i < n; ++i) {
            vi.PB(i);
            vj.PB(i);
        }
        for (char c : s) {
            if (c == 'L') {
                vj.PB(vj[0]);
                vj.erase(vj.begin());
            }
            if (c == 'R') {
                vj.insert(vj.begin(), vj.back());
                vj.pop_back();
            }

            if (c == 'U') {
                vi.PB(vi[0]);
                vi.erase(vi.begin());
            }
            if (c == 'D') {
                vi.insert(vi.begin(), vi.back());
                vi.pop_back();
            }
        }
        if (add < 0) {
            add = (-add) % n;
            add = -add;
        }
        add += n;
        add %= n;
        for (int i = 0; i < n; ++i) {
            int ii = vi[i];
            for (int j = 0; j < n; ++j) {
                int jj = vj[j];
                int res = (m[ii][jj] + add) % n + 1;
                cout << res << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}