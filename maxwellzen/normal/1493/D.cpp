#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

vector<int> primes, factor;

void sieve2(int n) {
    factor.clear(); factor.resize(n+1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (factor[i]==0) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) factor[j]=i;
        }
    }
}

int n, q, np, x, ind;
vi a;
map<int, int> ptoi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve2(200000);
    np = primes.size();
    multiset<int> pow[np];
    F0R(i, np) ptoi[primes[i]]=i;
    cin >> n >> q;
    map<int, int> f[n];
    a.rsz(n);
    F0R(i, n) {
        cin >> a[i];
        x = a[i];
        while (x>1) {
            f[i][factor[x]]++;
            x /= factor[x];
        }
        for (auto p : f[i]) {
            pow[ptoi[p.F]].insert(p.S);
        }
    }
    F0R(i, np) if (pow[i].size()<n) pow[i].insert(0);
    ll g = 0;
    F0R(i, n) g = __gcd((int)g, a[i]);
    F0R(query, q) {
        int i;
        cin >> i >> x;
        i--;
        map<int, int> copy;
        set<int> consider;
        while (x>1) {
            if (copy.find(factor[x])==copy.end()) copy[factor[x]]=f[i][factor[x]];
            f[i][factor[x]]++;
            consider.insert(factor[x]);
            x /= factor[x];
        }
        for (int pr : consider) {
            int pri = ptoi[pr];
            if (f[i][pr]>copy[pr]) {
                int freq = *pow[pri].begin();
                if (copy[pr]>0 || pow[pri].size()==n) pow[pri].erase(pow[pri].find(copy[pr]));
                pow[pri].insert(f[i][pr]);
                if (*pow[pri].begin() > freq) {
                    freq = *pow[pri].begin() - freq;
                    F0R(j, freq) g = (g*pr)%MOD;
                }
            }
        }
        cout << g << '\n';
    }
}