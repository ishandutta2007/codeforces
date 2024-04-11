#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int c[max_n];
int call[max_n];
vector<int> v[max_n];
int ans[max_n];


int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i =0 ; i < n; ++i) {
            c[i] = 0;
            call[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            ans[i] = -1;
            v[i].clear();
            int c;
            scanf("%d", &c);
            for (int j = 0; j < c; ++j) {
                int fr;
                scanf("%d", &fr);
                --fr;
                v[i].PB(fr);
                call[fr]++;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (v[i].size() == 1) {
                c[v[i][0]]++;
            }
        }
        int canmx = (m + 1) / 2;
        int best = -1;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            //cout << canmx << ' ' << i << c[i] << endl;
            if (c[i] > canmx) {
                bad = true;
                break;
            }
        }
        if (bad) {
            puts("NO");
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (call[i] >= canmx) {
                best = i;
                break;
            }
        }
        puts("YES");
        if (best == -1) {
            for (int i = 0; i < m; ++i) {
                printf("%d ", v[i][0] + 1);
            }
        } else {
            int took = 0;
            for (int i = 0; i < m; ++i) {
                if (v[i].size() == 1 && v[i][0] == best) {
                    ans[i] = best;
                    ++took;
                }
            }
            for (int i = 0; i < m; ++i) {
                if (took == canmx || ans[i] != -1) {
                    continue;
                }
                int ind = -1;
                for (int j = 0; j < v[i].size(); ++j) {
                    if (v[i][j] == best) {
                        ind = j;
                        break;
                    }
                }
                if (ind == -1) {
                    continue;
                }
                ans[i] = best;
                ++took;
            }
            for (int i = 0; i < m; ++i) {
                if (ans[i] != -1) {
                    continue;
                }
                int k = -1;
                for (int j : v[i]) {
                    if (j != best) {
                        k = j;
                        break;
                    }
                }
                if (k == -1) {
                    exit(228);
                }
                ans[i] = k;
            }
            for (int i = 0; i < m; ++i) {
                printf("%d ", ans[i] + 1);
            }
        }
        printf("\n");
    }

    return 0;
}