    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    int n;
    const int mod = (int)1e9 + 7;
    int sum(int a, int b) {
        int s = a + b;
        if (s >= mod) s -= mod;
        return s;
    }
    int sub(int a, int b) {
        int s = a - b;
        if (s < 0) s += mod;
        return s;
    }
    int mult(int a, int b) {
        return (1LL * a * b) % mod;
    }
    const int maxN = 1005;
    pair < int, int > x[maxN], y[maxN];
    ll gcd(ll a, ll b) {
        while (a > 0 && b > 0) {
            if (a < b) swap(a, b);
            a %= b;
        }
        return a + b;
    }
    ll lcm(ll a, ll b) {
        return (a * b) / gcd(a, b);
    }
    pair < ll, ll > sum(pair < ll, ll > a, pair < ll, ll > b) {
        ll den = lcm(a.second, b.second);
        ll num = a.first * (den / a.second) + b.first * (den / b.second);
        if (den < 0) {
            den = -den;
            num = -num;
        }
        ll d = gcd(abs(num), abs(den));
        num /= d;
        den /= d;
        return make_pair(num, den);
    }
    vector < pair < pair < ll, ll >, pair < ll, ll > > > all;
    map < pair < pair < ll, ll >, pair < ll, ll > >, int > mp;
    int f[maxN];
    int c[maxN][maxN], fact[maxN];
    int pw2[maxN];
    ld xx[maxN], yy[maxN];
    const ld INF = 13232;
    int solve(vector < int > nums) {
        int ans = 1;
        for (int v : nums) {
            ans = mult(ans, v + 1);
        }
        ans = sub(ans, 1);
        for (int v : nums) {
            ans = sub(ans, v);
        }
        return ans;
    }
    const ld eps = 1e-9;
    bool eq(ld a, ld b) {
        return (abs(a - b) < eps);
    }
    bool eq(pair < ld, ld > t1, pair < ld, ld > t2) {
        return eq(t1.first, t2.first) && eq(t1.second, t2.second);
    }
    bool cmp(pair < pair < ld, ld >, ld >& t1, pair < pair < ld, ld >, ld >& t2) {
        if (!eq(t1.first.first, t2.first. first)) {
            return t1.first.first < t2.first.first;
        }
        else if (!eq(t1.first.second, t2.first.second)) {
            return t1.first.second < t2.first.second;
        }
        else {
            return t1.second < t2.second;
        }
    }
    int main() {
        //freopen("input.txt", "r", stdin);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        srand(239);
        c[0][0] = 1;
        for (int i = 1; i < maxN; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
            }
        }
        for (int i = 1; i < maxN; i++) {
            for (int cnt = 2; cnt <= i; cnt++) {
                f[i] = sum(f[i], c[i][cnt]);
            }
        }
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, b;
            int c, d;
            cin >> a >> b >> c >> d;
            ld x1 = 1.0 * a / b;
            ld y1 = 1.0 * c / d;
            xx[i] = x1 / (x1 * x1 + y1 * y1);
            yy[i] = y1 / (x1 * x1 + y1 * y1);
           // x[i] = make_pair((d * d * b * a), a * a * d * d + b * b * c * c);
           // y[i] = make_pair((c * d * b * b), a * a * d * d + b * b * c * c);
        }
        vector < pair < pair < ld, ld >, ld > > all;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ld mdx = (xx[i] + xx[j]) / 2;
                ld mdy = (yy[i] + yy[j]) / 2;
                ld coef;
                if (eq(yy[i], yy[j])) coef = INF;
                else {
                    coef = (xx[i] - mdx) / (yy[i] - mdy);
                }
                all.push_back(make_pair(make_pair(mdx, mdy), coef));
            }
        }
        sort(all.begin(), all.end(), cmp);
        int it = 0;
        int ans = 0;
        /*cout << "--" << endl;
        for (int i = 0; i + 1 < all.size(); i++) {
            cout << all[i].first.first << " " << all[i].first.second;
            cout << "second " << endl
            cout << << all[i + 1].first.second << endl;
        }*/
        while (it < all.size()) {
            int jit = it;
            vector < int > nums;
            int cnt = 0;
            while (jit < all.size() && eq(all[it].first, all[jit].first)) jit++; jit--;
            vector < ld > all_coefs;
            for (int k = it; k <= jit; k++) all_coefs.push_back(all[k].second);
            sort(all_coefs.begin(), all_coefs.end());
            int st = 0;
            while (st < all_coefs.size()) {
                int nxt = st;
                while (nxt < all_coefs.size() && eq(all_coefs[nxt], all_coefs[st])) nxt++; nxt--;
                nums.push_back(nxt - st + 1);
                st = nxt + 1;
            }
            ans = sum(ans, solve(nums));
            it = jit + 1;
        }
        cout << ans;
        return 0;
    }