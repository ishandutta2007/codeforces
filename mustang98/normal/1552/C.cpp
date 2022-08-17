#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 300, inf = 1000111222;

int to[max_n];
int n, k;

bool is_in(int a, int b, int c) {
    return c > a && c < b;
}

int calc() {
    vector<pair<int, int>> v;
    for (int i = 0; i < 2 * n; ++i) {
        int a = i;
        int b = to[a];
        if (a > b) {
            continue;
        }
        v.emplace_back(a, b);
    }
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (is_in(v[i].F, v[i].S, v[j].F) && !is_in(v[i].F, v[i].S, v[j].S) ||
                is_in(v[i].F, v[i].S, v[j].S) && !is_in(v[i].F, v[i].S, v[j].F))
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {

        cin >> n >> k;
        for (int i = 0; i < 2 * n; ++i) {
            to[i] = -1;
        }
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            to[a] = b;
            to[b] = a;
        }
        //int ans = -calc();
        //cout << "$ " << ans << endl;
        vector<int> v;
        for (int i = 0; i < 2 * n; ++i) {
            if (to[i] == -1) {
                v.PB(i);
            }
        }
        int cnt = (n - k);
        for (int i = 0; i < cnt; ++i) {
            int a = v[i];
            int b = v[i + cnt];
            to[a] = b;
            to[b] = a;
        }
        int ans = calc();
        cout << ans << "\n";
    }


    return 0;
}