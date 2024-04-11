// hloya template v25
  
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
  
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <time.h>
// #Include
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-15;
const int maxn = (int)4e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

string name[maxn];
int a[maxn];
map<pair<string, int>, int> sot;
vector<pair<string, int> > g[maxn];
bool used[maxn];

vector<int> lay[maxn];
bool cmp(int i, int j) {
    return name[i] < name[j] || (name[i] == name[j] && a[i] < a[j]);
}

int main() {
    // files1;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i] >> a[i];
        sot[mp(name[i], a[i])] = i;

        // cout << name[i] << ' ' << a[i] << endl;

        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            string name_to;
            int x;
            cin >> name_to >> x;

            // cout << name_to << ' ' << x << endl;

            g[i].pb(mp(name_to, x));
        }
    }

    // return 0;
    map<string, int> got;
    lay[0].pb(0);

    for (int d = 0; d <= n; d++) {
        sort(all(lay[d]), cmp);

        for (int i = 0; i < lay[d].size(); i++) {
            // if (d == 1) {
                // cout << lay[d][i] << endl;
            // }
            if (i == lay[d].size() - 1 || name[lay[d][i]] != name[lay[d][i + 1]]) {
                int p = lay[d][i];
                if (!got.count(name[p])) {
                    got[name[p]] = a[p];
                    for (auto _to : g[p]) {
                        // cout << sot[_to] << endl;
                        // cout << sot.count(_to) << endl;
                        lay[d + 1].pb(sot[_to]);
                    }
                }
            }
        }
    }

    cout << got.size() - 1 << endl;
    for (auto e : got) {
        if (e.f != name[0])
            cout << e.f << ' ' << e.s << endl;
    }
    return 0;
}