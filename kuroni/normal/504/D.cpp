#include <bits/stdc++.h>
using namespace std;

const int M = 2000, LG = 59;
const long long MOD = 1LL << LG;

int n;
string s;
vector<bitset<M>> bas, com;
bitset<M> val, eli;

void convert(string &s) {
    val.reset();
    reverse(s.begin(), s.end());
    for (int i = 0; i < M && !s.empty(); i += LG) {
        long long cur = 0;
        for (int j = min((int)s.size(), i + LG) - 1; j >= 0; j--) {
            ((cur *= 10) += s[j] - '0') %= MOD;
        }
        for (int j = 0; j < LG; j++) {
            if (cur >> j & 1) {
                val.set(i + j);
            }
        }
        cur = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            (cur *= 10) += s[i] - '0';
            s[i] = cur / MOD + '0';
            assert(s[i] >= '0' && s[i] <= '9');
            cur %= MOD;
        }
        while (s.back() == '0') {
            s.pop_back();
        }
    }
}

void gauss(int u) {
    for (int i = 0; i < bas.size(); i++) {
        if (bas[i]._Find_first() == val._Find_first()) {
            val ^= bas[i];
            eli ^= com[i];
        }
    }
    if (val.count() == 0) {
        cout << eli.count() << " ";
        for (int i = eli._Find_first(); i < M; i = eli._Find_next(i)) {
            cout << i << " ";
        }
        cout << '\n';
    } else {
        cout << "0\n";
        eli.set(u);
        bas.push_back(val); com.push_back(eli);
        for (int i = bas.size() - 1; i > 0; i--) {
            if (bas[i]._Find_first() < bas[i - 1]._Find_first()) {
                swap(bas[i], bas[i - 1]);
                swap(com[i], com[i - 1]);
            } else {
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        val.reset(); eli.reset();
        cin >> s;
        convert(s);
        gauss(i);
    }
}