#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define MP make_pair
#define X first
#define Y second
 
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define err(x) cerr << #x << " = " << x << endl;
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
 
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;
 
clock_t start_clock;
void Time() {
	clock_t end_clock = clock();
	double elapsed_time = ((db)end_clock - (db)start_clock) / (db)CLOCKS_PER_SEC;
	fprintf(stderr, "Time elapsed = %0.4lf\n", elapsed_time);
}
 
#define LINF (long long)1e18
#define EPS 1e-9
#define INF 1000000007ll
#define SIZE 2010
#define MAX_A 1000010
 
const int LCM = 2520, BASE = LCM;
int num[SIZE], nxt[BASE * BASE] = {0}, m[SIZE], d[BASE * BASE];
int visT[BASE * BASE];
vi e[SIZE];
 
set<int> curr_set;
vi curr_vec;
 
void dfs(int v) {
    int u = nxt[v];
    curr_vec.PB(v);
    if (u == v) {
        d[u] = 1;
        curr_vec.clear();
        return;
    }
    if (visT[u]) {
        if (d[u]) d[v] = d[u];
        else {
            assert(visT[u] < visT[v]);
            for (int i = visT[u] - 1 ; i < visT[v] ; ++i) {
                curr_set.insert(curr_vec[i] / BASE);
            }
            d[v] = curr_set.size();
            curr_set.clear();
        }
        curr_vec.clear();
        return;
    }
    visT[u] = visT[v] + 1;
    dfs(u);
    d[v] = d[u];
    return;
}
 
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d", &num[i]);
    }
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d", &m[i]);
        for (int j = 0 ; j < m[i] ; ++j) {
            int v;
            scanf("%d", &v);
            e[i].PB(v);
        }
    }
 
    for (int i = 1 ; i <= n ; ++i) {
        for (int j = 0 ; j < LCM ; ++j) {
            int nxt_edge_idx = ((j + num[i]) % m[i] + m[i]) % m[i]; 
            nxt[i * BASE + j] = e[i][nxt_edge_idx] * BASE + ((j + num[i]) % LCM + LCM) % LCM;
        }
    }
 
    for (int i = 1 ; i < BASE * BASE ; ++i) {
        if (!visT[i]) {
            visT[i] = 1;
            dfs(i);
        }
    }
 
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", d[x * BASE + (y % LCM + LCM) % LCM]);
    }
 
    Time();
    return 0;
}