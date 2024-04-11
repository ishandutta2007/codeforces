/*input
abcdefa
ddcb
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 125005;

// tested on MAXMATCH and POLYMUL
struct cd {
    double x, y;
    cd(double _x = 0, double _y = 0): x(_x), y(_y) {};
    cd operator + (const cd &d) const {return (cd) {x + d.x, y + d.y};}
    cd operator - (const cd &d) const {return (cd) {x - d.x, y - d.y};}
    cd operator * (const cd &d) const {return (cd) {x*d.x - y*d.y, x*d.y + y*d.x};}
    cd operator / (const double &d) const {return (cd) {x / d, y / d};}
};

using ll = long long;
const double PI = acos(-1);

#define pow binPow
cd binPow(cd a, long long q) {
    cd ret = 1;
    while (q) {
        if (q & 1LL) ret = ret * a;
        a = a * a;
        q >>= 1LL;
    }
    return ret;
}

struct FFT {
public:
    FFT() {}
    void fft(vector<cd> &a, bool invert) {
        int n = a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                cd w(1);
                for (int j = 0; j < len / 2; j++) {
                    cd u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w = w * wlen;
                }
            }
        }

        if (invert) {
            for (cd & x : a)
                x = x / n;
        }
    }

    int f2(int x) {
        if (__builtin_popcountll(x) != 1) return 1LL << ((63 - __builtin_clzll(x)) + 1);
        return x;
    }

    vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
        vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int rlen = a.size() + b.size() - 1;
        int len = f2(rlen);
        fa.resize(len); fb.resize(len);

        fft(fa, false); fft(fb, false);
        loop(i, 0, len - 1)fa[i] = fa[i] * fb[i];
        fft(fa, true);

        vector<ll> result(rlen);
        loop(i, 0, rlen - 1) result[i] = round(fa[i].x);
        return result;
    }

    vector<ll> power(const vector<int> &a, int q) {
        int len = f2(q * a.size());
        vector<cd> fa(a.begin(), a.end());
        fa.resize(len, 0);
        fft(fa, false);
        for (auto &it : fa) it = binPow(it, q);
        fft(fa, true);
        vector<ll> ret(fa.size());
        loop(i, 0, fa.size() - 1) ret[i] = round(fa[i].x);
        return ret;
    }
} fft;

string a, b;
bool res[N][6][6];
vector<int> va, vb;


void solve(char c1, char c2) {
    loop(i, 0, a.size() - 1) va[i] = (a[i] == c1);
    loop(i, 0, b.size() - 1) vb[i] = (b[i] == c2);
    auto rec = fft.multiply(va, vb);

    for (int i = b.size() - 1; i < a.size(); i++) {
        res[i - b.size() + 1][c1 - 'a'][c2 - 'a'] = max(res[i - b.size() + 1][c1 - 'a'][c2 - 'a'], (bool)rec[i]);
        res[i - b.size() + 1][c2 - 'a'][c1 - 'a'] = max(res[i - b.size() + 1][c2 - 'a'][c1 - 'a'], (bool)rec[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b;
    va = vector<int>(a.size(), 0);
    vb = vector<int>(b.size(), 0);
    reverse(b.begin(), b.end());
    for (char c1 = 'a'; c1 <= 'f'; c1++) {
        for (char c2 = 'a'; c2 <= 'f'; c2++) {
            if (c1 == c2) continue;
            solve(c1, c2);
        }
    }
    for (int i = 0; i + b.size() - 1 < a.size(); i++) {
        bool vis[6];  memset(vis, 0, sizeof(vis));
        int numcc = 0;
        loop(c1, 0, 5) {
            if (vis[c1]) continue;
            queue<int> q; q.push(c1); int cnt = 0;
            while (!q.empty()) {
                auto u = q.front(); q.pop(); cnt++;
                loop(v, 0, 5) if (res[i][u][v] && !vis[v]) {
                    q.push(v); vis[v] = true;
                }
            }
            if (cnt >= 2) numcc--;
        }
        loop(c1, 0, 5) numcc += vis[c1];
        cout << numcc << sp;
    }
    cout << endl;
}