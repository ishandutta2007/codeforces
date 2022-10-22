#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

unordered_map<string, int> mem;

int ask(string s) {
    if (mem.count(s))
        return mem[s];
    cout << s << endl;
    int res;
    cin >> res;
    if (res == 0) {
        exit(0);
    }
    return mem[s] = res;
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r2 = ask("b");
    int n = r2 + 1;

    if (r2 == 1) {
        int r1 = ask("a");
        if (r1 == r2) {
            ask("ab");
            ask("ba");
        } else {
            ask("aa");
            ask("bb");
        }
    }

    if (n > 300) {
        n = 300;
        string s(n, 'a');
        int cur = ask(s);
        for (int i = 0; i < n; i++) {
            string s2 = s;
            s2[i] = s2[i] ^ 'a' ^ 'b';
            int ncur = ask(s2);
            if (ncur < cur) {
                cur = ncur;
                s = s2;
            }
        }
    }

    string s(n, 'a');
    int cur = ask(s);

    if (cur == 1) {
        for (int i = 0; i < n; i++) {
            s = string(n, 'a');
            s[i] = 'b';
            int tmp = ask(s);
            if (i == 0 && tmp == 1) {
                ask(string(n - 1, 'a'));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string s2 = s;
        s2[i] = s2[i] ^ 'a' ^ 'b';
        int ncur = ask(s2);
        if (ncur < cur) {
            cur = ncur;
            s = s2;
        }
    }

    return 0;
}