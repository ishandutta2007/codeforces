#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
constexpr pair <int, int> fail = make_pair(INT_MAX, INT_MAX);
int n, m;
bool found;
bool cannot;
bool vis[nax];
pair <int, int> b[nax];
double ans;
const double invalid = 1e9 + 7;
double c[nax];
/**
    bx + c at node i
*/
vector <pair <int, int>> a[nax];
vector <int> stk ;

pair <int, int> trans (pair <int, int> inp, int sum) {
    inp.first = -inp.first;
    inp.second = sum - inp.second;
    return inp;
}

double app (pair <int, int> in1, double x) {
    if (in1 == fail) assert(false);
    return x * in1.first + in1.second;
}

double solve (pair <int, int> a, pair <int, int> b) {
    int coeff = a.first - b.first;
    int dif = b.second - a.second;
    if (coeff == 0) return invalid;
    return double(dif) / double(coeff);
}

void dfs (int nod) {
    vis[nod] = true;
    stk.push_back(nod);
    for (auto [i, col] : a[nod]) {
        if (!vis[i]) {
            b[i] = trans(b[nod], col);
            dfs(i);
        } else {
            assert(b[i] != fail && b[nod] != fail);
            if (trans(b[i], col) != b[nod]) {
                double get = solve(trans(b[i], col), b[nod]);
                if (get == invalid || (ans != invalid && get != ans)) {
                    printf("NO\n");
                    exit(0);
                } else {
                    ans = get;
                }
            }
        }
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m ; ++ i) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        a[x].emplace_back(y, c);
        a[y].emplace_back(x, c);
    }

    for (int i = 1 ; i <= n;  ++ i)
        b[i] = fail;

    for (int i = 1 ; i <= n;  ++ i) {
        if (vis[i]) continue;
        b[i] = make_pair(1, 0);
        ans = invalid;
        dfs(i);

        if (ans == invalid) {
            vector <int> v;
            for (int j : stk) {
             //   printf("j %d %d %d\n", j, b[j].first, b[j].second);

                if (b[j].first < 0) {
                    v.push_back(b[j].second);
                } else v.push_back(-b[j].second);
            }
            sort(v.begin(), v.end());
            double med;
            if (int(v.size()) % 2) {
                med = v[int(v.size()) / 2];
            } else {
                med = (v[int(v.size()) / 2] + v[int(v.size()) / 2 - 1]) / 2.0;
            }

            for (int j :stk) {
                c[j] = app(b[j], med);
            }

        } else {
            for (int j : stk) {
                c[j] = app(b[j], ans);
            }
        }
        stk.clear();
    }

    printf("YES\n");

    for (int i = 1 ; i <= n ; ++ i) {
        printf("%.1lf ", c[i]);
    }

    printf("\n");

}