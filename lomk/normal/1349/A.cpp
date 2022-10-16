/*input
2
1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
// const int N =;

const int M = 200005;
int primes[M];
void eratosthene() {
    for (int i = 2; i <= M - 5; i++) if (primes[i] == 0) for (int j = i; j <= M - 5; j += i) primes[j] = i;
}


#define pow binPow
int binPow(int a, int q) {
    int ret = 1;
    while (q) {
        if (q & 1) ret = 1LL * ret * a;
        a = 1LL * a * a;
        q >>= 1LL;
    }
    return ret;
}


int n;
vector<int> a;
vector<vector<int> > all(M);

void addDiv(int X) {
    while (X > 1) {
        int t = primes[X]; int cnt = 0;
        while (X % t == 0) {
            X /= t; cnt++;
        }
        all[t].push_back(cnt);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    eratosthene();
    cin >> n;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
        addDiv(t);
    }
    int ans = 1;
    loop(i, 2, M - 5) {
        if (all[i].empty()) continue;
        sort(all[i].begin(), all[i].end());
        if (n - all[i].size() == 0) {
            ans *= binPow(i, all[i][1]);
        }
        else if (n - all[i].size() == 1) {
            ans *= binPow(i, all[i][0]);
        }
        else continue;
    }
    cout << ans << endl;
}