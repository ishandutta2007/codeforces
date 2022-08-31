#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1022, inf = 1000111222;

bool m[max_n][max_n];
int cnt[max_n];

int qr(int a, int b) {
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int c;
    cin >> c;
    --c;
    return c;
}
bool del[max_n];
set<int> v;

void ans(int a) {
    cout << "! " << a + 1 << endl;
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        v.insert(i);
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        m[a][b] = m[b][a] = 1;
        cnt[a]++;
        cnt[b]++;
    }
    while (v.size() > 1) {
        int p1 = -1, p2 = -1;
        for (int i = 0; i < n; ++i) {
            if (del[i]) {
                continue;
            }
            if (cnt[i] == 1) {
                if (p1 == -1) {
                    p1 = i;
                } else {
                    p2 = i;
                    break;
                }
            }
        }
        if (p1 == -1 || p2 == -1) {
            exit(228);
        }
        int lca = qr(p1, p2);
        if (lca == p1) {
            ans(p1);
        }
        if (lca == p2) {
            ans(p2);
        }
        v.erase(v.find(p1));
        v.erase(v.find(p2));
        del[p1] = 1;
        del[p2] = 1;
        for (int i = 0; i < n; ++i) {
            if (i == p1 || i == p2 || del[i]) {
                continue;
            }
            if (m[p1][i]) {
                m[p1][i] = 0;
                m[i][p1] = 0;
                cnt[i]--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == p2 || i == p1 || del[i]) {
                continue;
            }
            if (m[p2][i]) {
                m[p2][i] = 0;
                m[i][p2] = 0;
                cnt[i]--;
            }
        }
    }
    ans(*v.begin());
    return 0;
}