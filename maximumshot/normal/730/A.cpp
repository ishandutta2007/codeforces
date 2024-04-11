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

pair <int, int> arr[100];
int n;

vector < vector <int> > to_del;

bool check() {
    FOR(i, 0, n - 1) if (arr[i].F != arr[i + 1].F) return 0;
    return 1;
}

int g_count() {
    int res = 1;
    FORD(i, n - 1, 1) if (arr[i].F != arr[i - 1].F) return res;
    else ++res;
    cout << res << endl;
    return res;
}

void clear(string &str) {
    str.clear();
    FOR(i, 0, n) str += '0';
}

void g_show() {
    string gg_wp;
    for (auto i : to_del) {
        clear(gg_wp);
        for (auto j : i) gg_wp[j] = '1';
        cout << gg_wp << '\n';
    }
}

int main() {
    cin >> n;
    FOR(i, 0, n) {
        RE("%d", &arr[i].F);
        arr[i].S = i;
    }
    sort(arr, arr + n);
    while (arr[n - 1].F != arr[n - 2].F) {
        to_del.PB({ arr[n - 1].S, arr[n - 2].S });
        --arr[n - 1].F;
        if (arr[n - 1].F < 0) ++arr[n - 1].F;
        --arr[n - 2].F;
        if (arr[n - 2].F < 0) ++arr[n - 2].F;
        sort(arr, arr + n);
    }
    while (!check()) {
        if (g_count() & 1) {
            to_del.PB({ arr[n - 1].S, arr[n - 2].S, arr[n - 3].S });
            --arr[n - 1].F;
            if (arr[n - 1].F < 0) ++arr[n - 1].F;
            --arr[n - 2].F;
            if (arr[n - 2].F < 0) ++arr[n - 2].F;
            --arr[n - 3].F;
            if (arr[n - 3].F < 0) ++arr[n - 3].F;
        } else {
            to_del.PB({ arr[n - 1].S, arr[n - 2].S });
            --arr[n - 1].F;
            if (arr[n - 1].F < 0) ++arr[n - 1].F;
            --arr[n - 2].F;
            if (arr[n - 2].F < 0) ++arr[n - 2].F;
        }
        sort(arr, arr + n);
    }
    cout << arr[0].F << '\n' << to_del.size() << '\n';
    g_show();

    return 0;
}