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

ll a[max_n];

vector<int> v[max_n];
int n;

int cntdel[max_n];
int ans[max_n];

int del[max_n];
int dell = 0;

void get_del(int n) {
    dell = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (i * i == n) {
            del[dell++] = i;
        } else {
            if (n % i == 0) {
                del[dell++] = i;
                del[dell++] = n / i;
            }
        }
    }
}

//int hasd[max_n];
int nxt = 0;

int hasd[max_n];
int hasdmin1[max_n];
int hl = 0, hl1 = 0;

void dfs(int cur, int pr, int d) {
    get_del(a[cur]);
    ans[cur] = 1;
    for (int i = 0; i < hl1; ++i) {
        ans[cur] = max(ans[cur], hasdmin1[i]);
    }
    hl1 = 0;
    for (int i = 0; i < dell; ++i) {
        int curdel = del[i];
        cntdel[curdel]++;
        if (cntdel[curdel] == d) {
            hasd[hl++] = del[i];
            ans[cur] = max(ans[cur], hasd[hl-1]);
        } else if (cntdel[curdel] == d - 1) {
            hasdmin1[hl1++] = curdel;
            ans[cur] = max(ans[cur], curdel);
        }
    }
    hl1 = 0;
    hl = 0;

    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to != pr) {
            get_del(a[cur]);
            hl1 = 0;
            for (int i = 0; i < dell; ++i) {
                int curdel = del[i];
                if (cntdel[curdel] == d) {
                    hasdmin1[hl1++] = del[i];
                }
            }
            dfs(to, cur, d + 1);
        }
    }
    get_del(a[cur]);
    for (int i = 0; i < dell; ++i) {
        int curdel = del[i];
        cntdel[curdel]--;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        //a[i] = 2 * 2 * 2 * 2 * 2 * 2* 2 * 2 * 2 * 2* 2* 2* 2* 2 * 2 * 2 * 2;
    }
    int from, to;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &from, &to);
        //from = i + 1;
        //to = i + 2;
        --from, --to;
        v[from].PB(to);
        v[to].PB(from);
    }
    vector<int> v;
    dfs(0, -1, 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);// << ' ';
    }
    return 0;
}