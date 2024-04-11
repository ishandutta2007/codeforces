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
  
#include <bits/stdc++.h>
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
const int maxn = (int)1e6 + 12, base = 1e9 + 7;
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

int n, m;
vector<int> g[maxn];

int have_one[maxn], have_n[maxn], second_from_one[maxn], second_from_n[maxn];
bool used[maxn];
set<int> blocked;

void try2() {
    for (auto v: g[n]) {
        if(have_one[v]) {
            cout << 2 << endl << 1 << ' ' << v << ' ' << n << endl;
            exit(0);
        }
    }
}

void try3() {
    for (int u = 1; u <= n; u++) 
        if(have_one[u]){
             for (auto v : g[u]) {
                 if(have_n[v]) {
                    cout << 3 << endl << 1 << ' ' << u << ' ' << v << ' ' << n << endl;
                    exit(0);
                 }
             }
        }
}

void try4() {
    for (int u = 2; u <= n; u++) 
        if(have_one[u]){
            for(auto v : g[u]){
                if (v == 1)
                    continue;
                if(!have_one[v]) {
                    cout << 4 << endl << 1 << ' ' << u << ' ' << v << ' ' << 1 << ' ' << n << endl;
                    exit(0);
                }
            }
        }

    for (int u = 2; u <= n; u++) 
        if(have_one[u]){
            for (auto v : g[u]){
                if (v == 1)
                    continue;
                second_from_one[v] = u;
            }
        }

    for (int u = 2; u <= n; u++)
        if(have_n[u]){
            for (auto v : g[u]){
                if (v == n)
                    continue;
                second_from_n[v] = u;
            }
        }

    for (int u = 2; u <= n; u++) 
        if(second_from_one[u] && second_from_n[u]){
            cout << 4 << endl << 1 << ' ' << second_from_one[u] << ' ' << u << ' ' <<  second_from_n[u] << ' ' << n << endl;
            exit(0);
        }
}

int main()
{
    // files1;
    fast_io;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);

        if (u > v) swap(u, v);

        if (u == 1) {
            if (v == n) {
                cout << 1 << endl << 1 << ' ' << n << endl;
                return 0;
            }
            have_one[v] = 1;
        }
        if (v == n) {
            have_n[u] = 1;
        }
    }

    try2();
    try3();
    try4();

    vector<int> cur;
    for (int u = 2; u <= n; u++) 
        if(have_one[u] && !used[u]) {
            used[u] = 1;
            cur.clear();

            cur.pb(u);

            for (auto i : g[u]) {
                if(i == 1)
                    continue;
                used[i] = 1;
                cur.pb(i);
            }

            for (int i = 1; i < cur.size(); i++){
                int u1 = cur[i];
                blocked.clear();
                
                for (auto v1 : g[u1]){
                    if(v1 == 1)
                        continue;
                    blocked.insert(v1);
                }

                for (int j = 0; j < cur.size(); j++){
                    if(j == i) continue;
                    int v1 = cur[j];
                    if(blocked.count(v1)){
                        blocked.erase(v1);
                    }else {
                        cout << 5 << endl << 1 << ' ' << u1 << ' ' << u << ' ' << v1 << ' ' << u1 << ' ' << n << endl;
                        return 0;
                    }
                }
                if(!blocked.empty()){
                    int v1 = *blocked.begin();
                    cout << 5 << endl << 1 << ' ' << u << ' ' << u1 << ' ' << v1 << ' ' << u << ' ' << n << endl;
                    return 0;
                }
            }
    }
    cout << -1 << endl;
    return 0;
}