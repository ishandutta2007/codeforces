#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e5 + 5, INF = 1e9;

int N;
set <int> s;
map <int, int> cnt;
vi res;

void init(void) {
    cin >> N;
    ff(i, 1, N * N) { int x; cin >> x; s.insert(x); cnt[x]++; }
}

void process(void) {
    while (res.size() < N) {
        set <int> :: iterator it = s.end(); --it;
        int x = *it;
        //cerr << x << endl;
        res.pb(x);
        cnt[x]--; if (cnt[x] == 0) s.erase(x);
        ff(i, 0, (int)res.size() - 2) {
            int d = __gcd(x, res[i]);
            cnt[d] -= 2; if (cnt[d] == 0) s.erase(d);
        }
    }
    ff(i, 0, N - 1) cout << res[i] << ' ';
}

int main(void) {
    init();
    process();
    return 0;
}