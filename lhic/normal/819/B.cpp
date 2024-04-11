#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
int a[2200000];
int ad[2200000];
ll go[2200000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i), --a[i];
    for (int i = 0; i < n; ++i) {
        go[0] += abs(a[i] - i);
        if (a[i] <= i) {
            ad[1] += 1;
            ad[n - i] -= 1;
            go[n - i] -= n - 1 - a[i];
            go[n - i] += a[i];
            ad[n - i + 1] -= 1;
            ad[n - i + a[i] + 1] += 2;
        }
        else {
            ad[1] -= 1;
            ad[a[i] - i + 1] += 2;
            go[n - i] -= n - 1 - a[i];
            go[n - i] += a[i];
            ad[n - i] -= 1;
            ad[n - i + 1] -= 1;
        }
    }
    ll now = 0;
    int bst = 0;
    ll bstc = 1e15;
    ll d = 0;
    for (int i = 0; i < n; ++i) {
        now += go[i];
        d += ad[i];
        now += d;
        if (now < bstc)
            bstc = now, bst = i;
    }
    cout << bstc << " " << bst << "\n";
    return 0;
}