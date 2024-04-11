#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;

struct pupil {
    int a, b, c, d, id;

    pupil() = default;

    pupil(int i): id(i) {
        cin >> a >> b >> c >> d;
    }

    int get_sum() const {
        return a + b + c + d;
    }

    bool operator < (const pupil &o) const {
        int s1 = get_sum();
        int s2 = o.get_sum();
        if(s1 > s2) return true;
        else if(s1 < s2) return false;
        else return id < o.id;
    }
} a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    for(int i = 0;i < n;i++) {
        a[i] = pupil(i);
    }

    sort(a, a + n);

    for(int i = 0;i < n;i++) {
        if(a[i].id == 0) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    return 0;
}