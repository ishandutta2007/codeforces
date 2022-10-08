
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int pot(int a, int b, int n) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) res = (res * (LL)a) % n;
        a = (a * (LL)a) % n;
    }
    return res;
}

int p[100005];
bool np[100005];
int cp;

void era() {
    FOR (i, 2, 100000) {
        if (np[i]) continue;
        p[cp++] = i;
        for (int j = 2 * i; j <= 100000; j += i) {
            np[j] = true;
        }
    }
}

vector<int> pdiv;

void phi(int n) {
    REP (i, cp) {
        if ((n - 1) % p[i] == 0) {
            pdiv.PB(p[i]);
        }
    }
}

bool gen(int g, int n) {
    if (g == 0) {
        return false;
    }
    for (int d : pdiv) {
        if (pot(g, (n - 1) / d, n) == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }
    if (n == 4) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 2 << endl;
        cout << 4 << endl;
        return 0;
    }
    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    era();
    for (int i = 0; p[i] < n; ++i) {
        if (n % p[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    phi(n);
    cout << "YES" << endl;
    int g = 0;
    while (!gen(g, n)) {
        g = rand() % n;
    }
    vector<int> pots;
    int c = 1;
    for (int i = 0; i < n - 1; ++i) {
        pots.PB(c);
        c = (c * (LL)g) % n;
    }
    cout << 1 << endl;
    int l = 1;
    int r = n - 2;
    int last = 0;
    while (true) {
        int c = (r - last + n - 1) % (n - 1);
        cout << pots[c] << endl;
        last = r;
        --r;
        if (l > r) {
            break;
        }
        c = (l - last + n - 1) % (n - 1);
        cout << pots[c] << endl;
        last = l;
        ++l;
    }
    cout << n << endl;
}