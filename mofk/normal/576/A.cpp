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

int n;
vi v;

void init(void) {
    cin >> n;
}

void process(void) {
    ff(i, 2, n) {
        bool FL = 0;
        ff(j, 1, i - 1) {
            bool fl = 0;
            ff(k, 0, (int)v.size() - 1) if ((i % v[k] == 0) ^ (j % v[k] == 0)) { fl = 1; break; }
            if (!fl) { FL = 1; break; }
        }
        if (FL) v.pb(i);
    }
    cout << v.size() << "\n";
    ff(i, 0, (int)v.size() - 1) cout << v[i] << " ";
}

int main(void) {
    init();
    process();
    return 0;
}