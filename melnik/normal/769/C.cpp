// hloya template v24
  
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
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
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
const long double eps = 1e-12;
const int maxn = 1e3 + 12, base = 1e9 + 7;
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

int a[maxn][maxn], used[maxn][maxn], dist[maxn][maxn];
string kek = "DLRU";

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int n, m, k;
    // files1;
    read(n, m, k);
    
    if (k % 2)
        bad("IMPOSSIBLE");

    int x, y;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c = endl;
            while (c == endl) c = getchar();
            if (c != '*')
                a[i][j] = 1;
            if (c == 'X')
                x = i, y = j;
            dist[i][j] = inf;
        }
    
    dist[x][y] = 0;
    used[x][y] = 1;
    
    queue<pii> q;
    q.push(mp(x, y));

    while (!q.empty()) {
        int x1 = q.front().f, y1 = q.front().s;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x1 + dx[i], ny = y1 + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && a[nx][ny]) {
                dist[nx][ny] = dist[x1][y1] + 1;
                used[nx][ny] = 1;
                q.push(mp(nx, ny));
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << dist[i][j] << ' ';
    //     cout << endl;
    // }
    
    string ans = "";
    for (int i = 0; i < k; i++) {
        bool rng = 0;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] && 
                i + dist[nx][ny] + 1 <= k) {
                rng = 1;
                ans += kek[j];
                x = nx, y = ny;
                break;
            }
        }
        // cout << x << ' ' <
        if (!rng)
            bad("IMPOSSIBLE");
    }
    cout << ans;
    return 0;
}