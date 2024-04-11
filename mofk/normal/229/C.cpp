#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e6 + 5, INF = 1e9;

int n, m, x;
int d[MAX];

void init(void) {
    scanf("%d%d", &n, &m);
    ff(i, 1, 2 * m) {
        scanf("%d", &x); d[x]++;
    }
}

void process(void) {
    ll res = 0;
    ff(i, 1, n) res += 1ll * d[i] * (d[i] - 1) + 1ll * (n - 1 - d[i]) * (n - 2 - d[i]) - 1ll * d[i] * (n - 1 - d[i]);
    printf("%I64d", res / 6);
}

int main(void) {
    init();
    process();
    return 0;
}