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

ll a[maxn];
ll new_sz[maxn];
int was[maxn];
ll l[2][maxn];

inline void merge(int& pred_sz, int& sz_nex, int& cur, int& cur_sz, int& k) {
    int i = 1, j = 1, ok = 1;

    while (j <= sz_nex || i <= pred_sz) {
        if(j <= sz_nex) {
            if (ok) {
                l[cur][++cur_sz] = new_sz[j++];
                ok = 0;
                continue;
            }
        }
        l[cur][++cur_sz] = l[1 - cur][i++];
        if(l[cur][cur_sz] & (1ll << k))
            ok ^= 1;
    }
}

int n, sz_nex;
int find_cnt(int k) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if(!was[i] && (a[i] & (1ll << k))) {
            new_sz[++sz_nex] = a[i];
            cnt++;
            was[i] = 1;
        }
    return cnt;
}

int main()
{
    // files1;
    fast_io;

    int cur_sz = 0; 

    cin >> n;
    
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        amax(mx, a[i]);
    }
    
    int mxbit = 0;
    for (int i = 0; i <= 60; i++) {
        if (mx & (1ll << i))
            mxbit = i;
    }

    int cur = 0;

    for (int k = mxbit; k >= 0; k--){
        sz_nex = 0;
        int cnt = find_cnt(k);

        int now = 1;

        for (int i = 1; i <= cur_sz; i++)
            if((1ll << k) & l[cur][i])
                now++;

        cur ^= 1;

        int pred_sz = cur_sz;
        cur_sz = 0;

        if(cnt > now) {
            cout << "No\n";
            return 0;
        } else merge(pred_sz, sz_nex, cur, cur_sz, k);
    }
    
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << l[cur][i] << ' ';
    cout << endl;
    return 0;
}