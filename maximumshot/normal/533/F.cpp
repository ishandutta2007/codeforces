#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int const mod1 = inf + 7;
int const mod2 = inf + 9;

inline void magic(pii & a) {
    a.first = (a.first % mod1 + mod1) % mod1;
    a.second = (a.second % mod2 + mod2) % mod2;
}

inline pii sum(pii a, pii b) {
    return mp(
            (a.first + b.first) % mod1,
            (a.second + b.second) % mod2
    );
}

inline pii raz(pii a, pii b) {
    return mp(
            ((a.first - b.first) % mod1 + mod1) % mod1,
            ((a.second - b.second) % mod2 + mod2) % mod2
    );
}

inline pii mul(pii a, pii b) {
    return mp(
            (1ll * a.first * b.first) % mod1,
            (1ll * a.second * b.second) % mod2
    );
}

int binpow(int a, int p, int mod) {
    if(p == 0) return 1 % mod;
    int q = binpow(a, p / 2, mod);
    q = (1ll * q * q) % mod;
    if(p % 2) q = (1ll * q * a) % mod;
    return q;
}

inline pii del(pii a, pii b) {
    return mp(
            (1ll * a.first * binpow(b.first, mod1 - 2, mod1)) % mod1,
            (1ll * a.second * binpow(b.second, mod2 - 2, mod2)) % mod2
    );
}

char s[N];
char t[N];
int n, m;
pii pw[N];

int main_cnt[26];
pii main_hs[26];
vec< pair< pii, char > > main_mas;

int cnt[26];
pii hs[26];
vec< pair< pii, char > > mas;

bool solve() {

    pw[0] = {1, 1};
    for(int i = 1;i < N;i++) {
        pw[i] = mul(pw[i - 1], {2, 2});
    }

    scanf("%d %d %s %s", &n, &m, s, t);

    for(int i = 0;i < m;i++) {
        auto & x = main_hs[t[i] - 'a'];
        x = sum(x, pw[i]);
        main_cnt[t[i] - 'a']++;
    }

    for(int i = 0;i < 26;i++) {
        if(main_cnt[i] > 0) main_mas.push_back({main_hs[i], i + 'a'});
    }
    sort(ALL(main_mas));

    int ans[N], ans_sz = 0;

    /*cout << "# main \n";
    for(int j = 0;j < 26;j++) {
        if(main_cnt[j] > 0) {
            cout << char(j + 'a') << " : " << main_cnt[j] << " " << main_hs[j].first << "\n";
        }
    }*/

    vec< int > C(26, -1);

    pii del_pii = {
            binpow(2, mod1 - 2, mod1),
            binpow(2, mod2 - 2, mod2)
    };

    for(int i = 0;i < n;i++) {
        if(i + 1 <= m) {
            cnt[s[i] - 'a']++;
            auto & x = hs[s[i] - 'a'];
            x = sum(x, pw[i]);
        }

        if(i + 1 < m) continue;

        /*cout << "\n# " << i << "\n";
        for(int j = 0;j < 26;j++) {
            if(cnt[j] > 0 ) {
                cout << char(j + 'a') << " : " << cnt[j] << " " << hs[j].first << "\n";
            }
        }*/

        mas.clear();

        for(int j = 0;j < 26;j++) {
            if(cnt[j] > 0) {
                mas.push_back({hs[j], j + 'a'});
            }
        }
        sort(ALL(mas));

        if((int)mas.size() == (int)main_mas.size()) {
            C.assign(26, -1);
            int ok = 1;
            for(int c1, c2, j = 0;j < (int)mas.size();j++) {
                if(mas[j].first != main_mas[j].first) { ok = 0; break; }
                c1 = mas[j].second - 'a';
                c2 = main_mas[j].second - 'a';
                if(C[c1] != -1 && C[c1] != c2) { ok = 0; break; }
                if(C[c2] != -1 && C[c2] != c1) { ok = 0; break; }
                C[c1] = c2;
                C[c2] = c1;
            }
            if(ok) ans[ans_sz++] = i - m + 2;
        }

        if(i + 1 < n) {
            // del i - m + 1
            // add i + 1
            int x;

            x = s[i - m + 1] - 'a';
            cnt[x]--;
            hs[x] = raz(hs[x], pw[0]);

            for(int j = 0;j < 26;j++) {
                if(cnt[j] > 0) {
                    //hs[j] = del(hs[j], {2, 2});
                    hs[j] = mul(hs[j], del_pii);
                }
            }

            x = s[i + 1] - 'a';
            cnt[x]++;
            hs[x] = sum(hs[x], pw[m - 1]);
        }

    }

    printf("%d\n", ans_sz);
    for(int i = 0;i < ans_sz;i++) printf("%d ", ans[i]);
    printf("\n");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}