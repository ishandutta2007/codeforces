#include <bits/stdc++.h>

using namespace std;

#define FOR(i, p, n) for (int i = (int)(p); i < (int)(n); ++i)
#define FORD(i, p, n) for (int i = (int)(p); i >= (int)(n); --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf
#define SKP scanf("%*c")

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

string arr[101];
set <int> to_del;

int main() {
    int n, m, t;
    cin >> n >> m;
    FOR(i, 1, n + 1) cin >> arr[i];
    FOR(i, 0, m) {
        cin >> t;
        to_del.insert(t);
    }
    string a = arr[*to_del.begin()];
    for (auto i : to_del) if (arr[i].size() != a.size()) {
        puts("No");
        return 0;
    }
    FOR(i, 0, a.size()) for (auto j : to_del) if (arr[j][i] != a[i]) {
        a[i] = '?';
        break;
    }
    FOR(i, 1, n + 1) if (!to_del.count(i) && arr[i].size() == a.size()) {
        FOR(j, 0, a.size()) if (a[j] != '?' && a[j] != arr[i][j]) goto shit;
        cout << "No";
        return 0;
        shit:;
    }
    cout << "Yes\n" << a;

    return 0;
}