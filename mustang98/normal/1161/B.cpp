#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;


vector<int> get_divs(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.pop_back();
    return ans;
}
pair<int, int> e[max_n];
pair<int, int> ee[max_n];

int n, m;

bool check(int d) {
    for (int i = 0; i < m; ++i) {
        ee[i] = e[i];
        ee[i].F += d;
        ee[i].S += d;
        if (ee[i].F >= n) {
            ee[i].F -= n;
        }
        if (ee[i].S >= n) {
            ee[i].S -= n;
        }
        if (ee[i].F > ee[i].S) {
            swap(ee[i].F, ee[i].S);
        }
    }
    sort(ee, ee + m);
    for (int i = 0; i < m; ++i) {
        if (ee[i] != e[i]) {
           return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector<int> divs = get_divs(n);
    random_shuffle(divs.begin(), divs.end());
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        if (a > b) {
            swap(a, b);
        }
        e[i] = make_pair(a, b);
    }
    sort(e, e + m);
    for (int d : divs) {
        if (check(d)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}