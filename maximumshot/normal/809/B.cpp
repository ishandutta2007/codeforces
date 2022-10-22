#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

map< pii, string > have;

string ask(int x, int y) {
    if(have.count(make_pair(x, y))) {
        return have[make_pair(x, y)];
    }
    cout << "1 " << x << " " << y << endl;
    string s;
    cin >> s;
    return have[make_pair(x, y)] = s;
}

void print_ans(int x, int y) {
    cout << "2 " << x << " " << y << endl;
}

int f(int l, int r) {
    if(l == r) {
        return l;
    }else {
        int m = (l + r) / 2;
        if(ask(m, m + 1) == "TAK") {
            return f(l, m);
        }else {
            return f(m + 1, r);
        }
    }
}

int main() {

#ifdef maximumSHOT
//    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;

    int x = f(1, n);
    int y = x > 1 ? f(1, x - 1) : -1;

    if(y != -1 && ask(y, x) == "NIE") {
        y = -1;
    }

    if(y != -1) {
        print_ans(x, y);
    }else {
        print_ans(x, f(x + 1, n));
    }

    return 0;
}