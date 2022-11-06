#include <bits/stdc++.h>

#define sz(V) ((int)(V).size())
#define all(V) (V).begin(), (V).end()
#define vsort(V) sort(all(V))
#define vunique(V) (V).erase(unique(all(V)), (V).end())
#define vcomp(V) vsort(V), vunique(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }
size_t getCurrentTime() { return chrono::steady_clock::now().time_since_epoch().count(); }
struct __RandomLong__ {
    mt19937_64 rnd; __RandomLong__()
    : rnd(getCurrentTime()) {}
    ll operator()(ll Min, ll Max) { return uniform_int_distribution<ll>(Min, Max)(rnd); }
    ll operator()() { return (*this)(LONG_LONG_MIN, LONG_LONG_MAX); }
} randomLong;
struct my_hash {
    static uint64_t splitmix(uint64_t x) {
        x += 0x9e3779b97f4a7c15ull;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
        return x ^ (x >> 31); }
    size_t operator()(ll x) const {
        static ll T = getCurrentTime();
        return splitmix(x + T); }
};

int k;
char S[1000005];
char A[1000005];
char B[1000005];

int used[30];
int arr[30];

int solve(int i) {
    if (S[i] == 0) {
        cout << "YES\n";
        for (int j = 1; j <= k; j++) {
            if (!arr[j]) for (int t = 1; t <= k; t++) {
                if (used[t]) continue;
                used[t] = 1;
                arr[j] = t;
                break;
            }
            cout << (char)(arr[j] + 'a' - 1);
        }
        cout << '\n';
        return 1;
    }
    for (int j = A[i] + 1; j < B[i]; j++) {
        if (arr[S[i]] && arr[S[i]] != j) continue;
        if (used[j] && arr[S[i]] != j) continue;
        arr[S[i]] = j;
        used[j] = 1;
        cout << "YES\n";
        for (int j = 1; j <= k; j++) {
            if (!arr[j]) for (int t = 1; t <= k; t++) {
                if (used[t]) continue;
                used[t] = 1;
                arr[j] = t;
                break;
            }
            cout << (char)(arr[j] + 'a' - 1);
        }
        cout << '\n';
        return 1;
    }
    if (A[i] != B[i]) {
        if (A[i] > 0)
        if (!arr[S[i]] || arr[S[i]] == A[i]) {
            if (!used[A[i]] || arr[S[i]] == A[i]) {
                int tmpA = A[i];
                int tmpU = 1;
                char tmpB = k + 1;
                swap(arr[S[i]], tmpA);
                swap(used[A[i]], tmpU);
                swap(B[i + 1], tmpB);
                if (solve(i + 1)) return 1;
                swap(arr[S[i]], tmpA);
                swap(used[A[i]], tmpU);
                swap(B[i + 1], tmpB);
            }
        }
        if (B[i] <= k)
        if (!arr[S[i]] || arr[S[i]] == B[i]) {
            if (!used[B[i]] || arr[S[i]] == B[i]) {
                int tmpB = B[i];
                int tmpU = 1;
                char tmpA = 0;
                swap(arr[S[i]], tmpB);
                swap(used[B[i]], tmpU);
                swap(A[i + 1], tmpA);
                if (solve(i + 1)) return 1;
                swap(arr[S[i]], tmpB);
                swap(used[B[i]], tmpU);
                swap(A[i + 1], tmpA);
            }
        }
    }
    else {
        if (!arr[S[i]] || arr[S[i]] == A[i]) {
            if (!used[A[i]] || arr[S[i]] == A[i]) {
                int tmpA = A[i];
                int tmpU = 1;
                swap(arr[S[i]], tmpA);
                swap(used[A[i]], tmpU);
                if (solve(i + 1)) return 1;
                swap(arr[S[i]], tmpA);
                swap(used[A[i]], tmpU);
            }
        }
    }
    return 0;
}

void solve() {
    cin >> k >> S >> A >> B;
    for (int i = 1; i <= k; i++) arr[i] = used[i] = 0;
    for (int i = 0; S[i]; i++) {
        S[i] -= 'a' - 1;
        A[i] -= 'a' - 1;
        B[i] -= 'a' - 1;
    }
    if (solve(0)) return;
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}