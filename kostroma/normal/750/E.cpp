#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li

//const int mod = 1000000007;

const int INF = (int)1e9;

struct Node {
    std::array<std::array<int, 5>, 5> dp;
    Node() {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = INF;
            }
        }
        for (int i = 0; i < 5; ++i) {
            dp[i][i] = 0;
        }
    }
    Node(int num) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = INF;
            }
        }
        for (int i = 0; i < 5; ++i) {
            dp[i][i] = 0;
        }
        if (num == -1) {
            dp[3][3] = 1;
            dp[4][4] = 1;
        } else if (num < 4) {
            dp[num][num + 1] = 0;
            dp[num][num] = 1;
        }
    }
};

Node merge(const Node& l, const Node& r) {
    Node res;
    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            res.dp[i][j] = INF;
            for (int x = i; x <= j; ++x) {
                res.dp[i][j] = min(res.dp[i][j], l.dp[i][x] + r.dp[x][j]);
            }
        }
    }
    return res;
}

int shift = 1;

Node tree[2 * (1 << 18) + 5];

Node rmq(int l, int r) {
    if (l >= r) {
        return Node();
    }
    if (l & 1) {
        return merge(tree[l], rmq(l + 1, r));
    }
    if (r & 1) {
        return merge(rmq(l, r - 1), tree[r - 1]);
    }
    return rmq(l / 2, r / 2);
}

Node get_res(int l, int r) {
    return rmq(l + shift, r + shift);
}

void solve(bool read) {
    int n, Q;
    cin >> n >> Q;
    string s;
    cin >> s;
    while (shift < s.length()) {
        shift *= 2;
    }
    for (int i = 0; i < s.length(); ++i) {
        int val;
        switch(s[i]) {
            case '2' : val = 0; break;
            case '0': val = 1; break;
            case '1': val = 2; break;
            case '7' : val = 3; break;
            case '6' : val = -1; break;
            default: val = 4;
        }
        tree[i + shift] = Node(val);
    }
    for (int i = shift - 1; i > 0; --i) {
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        Node res = get_res(l, r);
        if (res.dp[0][4] > 1e8) {
            cout << "-1\n";
            continue;
        }
        cout << res.dp[0][4] << "\n";
    }
}