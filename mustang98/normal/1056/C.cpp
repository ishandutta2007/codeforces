#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

int p[max_n];
bool vis[max_n];

int pr[max_n];

int read() {
    int a;
    cin >> a;
    --a;
    return a;
}

int print(int a) {
    cout << a + 1 << endl;
    cout.flush();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        pr[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        pr[a] = b;
        pr[b] = a;
    }
    int t;
    cin >> t;
    if (t == 1) {
        for (int i = 0; i < n; ++i) {
            int st = -1;
            for (int i = 0; i < 2 * n; ++i) {
                if (pr[i] != -1 && !vis[i]) {
                    st = i;
                    break;
                }
            }
            if (st != -1) {
                int p1 = st, p2 = pr[st];
                if (p[p1] < p[p2]) {
                    swap(p1, p2);
                }
                print(p1);
                vis[p1] = 1;
            } else {
                for (int i = 0; i < 2 * n; ++i) {
                    if (vis[i]) continue;
                    if (st == -1 || p[i] > p[st]) {
                        st = i;
                    }
                }
                if (st == -1) {
                    exit(228);
                }
                print(st);
                vis[st] = 1;
            }
            int other = read();
            vis[other] = 1;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int other = read();
            vis[other] = 1;
            if (pr[other] != -1 && !vis[pr[other]]) {
                int my = pr[other];
                vis[my] = 1;
                print(my);
                continue;
            }

            int st = -1;
            for (int i = 0; i < 2 * n; ++i) {
                if (pr[i] != -1 && !vis[i]) {
                    st = i;
                    break;
                }
            }
            if (st != -1) {
                int p1 = st, p2 = pr[st];
                if (p[p1] < p[p2]) {
                    swap(p1, p2);
                }
                print(p1);
                vis[p1] = 1;
            } else {
                for (int i = 0; i < 2 * n; ++i) {
                    if (vis[i]) continue;
                    if (st == -1 || p[i] > p[st]) {
                        st = i;
                    }
                }
                if (st == -1) {
                    exit(228);
                }
                print(st);
                vis[st] = 1;
            }
        }
    }

    return 0;
}