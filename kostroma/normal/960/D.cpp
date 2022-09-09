#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
//    cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

#define int li
//const int mod = 1000000007;

const int L = 60;

int get_level(int x) {
    int res = 0;
    while (x > 1) {
        x >>= 1;
        ++res;
    }
    return res;
}

void solve(__attribute__((unused)) bool read) {
    vector<int> shift(L, 0);
    int Q;
    cin >> Q;
    while (Q--) {
        int type, x;
        cin >> type >> x;
        int lev = get_level(x);
        if (type == 1) {
            int k;
            cin >> k;
            shift[lev] = (shift[lev] + k) % (1LL << lev);
            if (shift[lev] < 0) {
                shift[lev] += (1LL << lev);
            }
        } else if (type == 2) {
            int k;
            cin >> k;
            for (int i = lev; i < L; ++i) {
                shift[i] = (shift[i] + k) % (1LL << i);
                if (shift[i] < 0) {
                    shift[i] += (1LL << i);
                }
                k *= 2;
            }
        } else {
            int old_pos = x - (1LL << lev);
            int new_pos = (old_pos + shift[lev]) % (1LL << lev);
            int cur_v = new_pos + (1LL << lev);
            while (cur_v > 1) {
                int pos = cur_v - (1LL << lev);
                int val = (pos - shift[lev] + (1LL << lev)) % (1LL << lev);
                cout << val + (1LL << lev) << " ";
                cur_v /= 2;
                --lev;
            }
            cout << cur_v << "\n";
        }
    }

}