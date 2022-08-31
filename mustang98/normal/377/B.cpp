#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int n, m, s; // stud n, zad m
pair<int, int> a[max_n];
int ans[max_n];
pair<int, pair<int, int>> b[max_n]; // sposobn, price

bool check(int days) {
    vector<pair<int, int>> aa(a, a + m);
    vector<pair<int, pair<int, int>>> bb(b, b + n);
    set<pair<int, int>> price;
    int alls = 0;
    while (aa.size()) {
        int comp = aa.back().F;
        while (!bb.empty() && bb.back().F >= comp) {
            price.insert(bb.back().S);
            bb.pop_back();
        }
        if (price.empty()) {
            return 0;
        }
        int stind = price.begin()->S;
        int stpr = price.begin()->F;
        price.erase(price.begin());
        alls += stpr;
        if (alls > s) {
            return 0;
        }
        for (int j = 0; aa.size() && j < days; ++j) {
            ans[aa.back().S] = stind;
            aa.pop_back();
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].F);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].S.F);
        b[i].S.S = i;
    }
    sort(b, b + n);
    sort(a, a + m);
    int l = 0, r = m;
    if (!check(r)) {
        puts("NO");
        return 0;
    }
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    check(r);
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i] + 1);
    }

    return 0;
}