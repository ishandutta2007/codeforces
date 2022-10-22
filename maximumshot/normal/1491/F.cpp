#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

//#undef DEBUG

mt19937 rnd(42);

string S;
string ALPH = "NS-";
const int N = 100;
int asks = 0;

bool validate(vector<int> res) {
    sort(res.begin(), res.end());
    vector<int> exp;
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == '-')
            exp.push_back(i + 1);
    }
    return exp == res;
}

void init() {
    S.assign(N, '?');
    for (int i = 0; i < N; i++) {
        if (i < 3)
            S[i] = ALPH[i];
        else
            S[i] = ALPH[rnd() % 3];
    }
    shuffle(S.begin(), S.end(), rnd);
}

int calc(const vector<int>& a, const vector<int>& b) {
    int l = 0, r = 0;
    for (int i : a) {
        i--;
        if (S[i] == 'N') l++;
        else if (S[i] == 'S') l--;
    }
    for (int i : b) {
        i--;
        if (S[i] == 'N') r++;
        else if (S[i] == 'S') r--;
    }
    return l * r;
}

int ask(const vector<int>& a, const vector<int>& b) {
    asks++;
    cout << "? " << (int) a.size() << " " << (int) b.size() << "\n";
    for (int x : a)
        cout << x << " ";
    cout << "\n";
    for (int x : b)
        cout << x << " ";
    cout << "\n";
    cout.flush();
    int res;
#ifdef DEBUG
    res = calc(a, b);
    cout << "calc = " << res << "\n";
#else
    cin >> res;
#endif
    return res;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
#ifdef DEBUG
    t = 100;
#else
    cin >> t;
#endif

    int mn_rem = inf;
    int tot_val = 0;
    int T = t;

    while (t--) {
        asks = 0;
        init();
        int n;
#ifdef DEBUG
        n = (int) S.size();
#else
        cin >> n;
#endif
        vector<int> res;

        for (int i = 2; i <= n; i++) {
            vector<int> a, b;
            for (int j = 1; j < i; j++)
                a.push_back(j);
            if (ask(a, {i})) {
                for (int j = i + 1; j <= n; j++) {
                    if (!ask({i}, {j}))
                        res.push_back(j);
                }
                int bl = 1, br = i, bm;
                while (br - bl > 1) {
                    bm = (bl + br) / 2;
                    a.clear();
                    b.clear();
                    for (int j = 1; j <= i; j++) {
                        if (j < bm) a.push_back(j);
                        else b.push_back(j);
                    }
                    if (ask(a, b)) br = bm;
                    else bl = bm;
                }
                for (int j = 1; j < i; j++) {
                    if (j == br - 1) continue;
                    res.push_back(j);
                }
                break;
            }
        }

        cout << "! " << (int) res.size() << " "; for (int x : res) cout << x << " "; cout << "\n";
        cout.flush();

#ifdef DEBUG
        int limit = 1;
        while ((1 << limit) <= n) limit++; limit--;
        limit += n;
        cout << "limit = " << limit << ", used = " << asks << ", S = " << S << "\n";
        cout << "REMAIN = " << limit - asks << "\n";
        mn_rem = min(mn_rem, limit - asks);
        int val = validate(res);
        cout << (val ? "OK" : "WA") << "\n";
        tot_val += val;
#endif
    }

#ifdef DEBUG
    cout << "MIN REMAIN = " << mn_rem << "\n";
    cout << tot_val << " out of " << T << "\n";
#endif

    return 0;
}