#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;

int ans[max_n];
vector<int> v[max_n];

int maxc = -1;

void f(int cur, int p)
{
    int cc = ans[cur];
    int pc = p == -1 ? cc : ans[p];
    int color = 1;
    for (int to : v[cur]) {
        if (to == p) continue;
        while (color == pc || color == cc) {
            ++color;
        }
        ans[to] = color;
        maxc = max(maxc, color);
        f(to, cur);
        color++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ans[0] = 1;
    f(0, -1);
    cout << maxc << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}