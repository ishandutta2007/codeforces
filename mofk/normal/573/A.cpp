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

const int MAX = 1e5 + 5, INF = 1e9;

int N;
int a[MAX];

bool ch(int x, int y) {
    while (x % 2 == 0) x >>= 1;
    while (x % 3 == 0) x /= 3;
    while (y % 2 == 0) y >>= 1;
    while (y % 3 == 0) y /= 3;
    return (x == 1 && y == 1);
}

void fail(void) { cout << "No" << endl; }

void init(void) {
    cin >> N;
    ff(i, 1, N) cin >> a[i];
}

void process(void) {
    ff(i, 2, N) {
        int d = __gcd(a[1], a[i]);
        int a1 = a[1] / d, ai = a[i] / d;
        if (!ch(a1, ai)) return fail();
    }
    cout << "Yes" << endl;
}

int main(void) {
    init();
    process();
    return 0;
}