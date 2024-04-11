#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY

#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200011, inf = 1000111222;

int as[max_n];
int bs[max_n];
int a[max_n];
int b[max_n];
int pr[max_n];
int l[max_n];
int sz[max_n];
int order[max_n];

vector<int> v[max_n];
int n, q;

int curt = 0;
void dfs(int cur) {
    l[cur] = curt;
    order[curt++] = cur;
    sz[cur] = 1;
    for (int to : v[cur]) {
        dfs(to);
        sz[cur] += sz[to];
    }
}

void my_add(int* from, int* to, int val) {
    while(from != to) {
        *from++ += val;
    }
}

ll get_max(int* fa, int* ta, int* fb) {
    ll mx = 1LL * *fa * *fb;
    ll mn = 1LL * *fa * *fb;
    while (fa != ta) {
        ll val = 1LL * *fa++ * *fb++;
        //val = val < 0 ? -val : val;
        mx = val > mx ? val : mx;
        //mx = -val > mx ? -val : mx;
        mn = val < mn ? val : mn;
    }
    return  max(abs(mx), abs(mn));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d", pr + i);
        --pr[i];
        v[pr[i]].PB(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", as + i);
        if (i) {
            as[i] += as[pr[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", bs + i);
        if (i) {
            bs[i] += bs[pr[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        bs[i] = abs(bs[i]);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        a[i] = as[order[i]];
        b[i] = bs[order[i]];
    }
    vector<ll> ans;
    while(q--) {
        //if (q % 1000 == 0) cout << q << endl;
        int t, v, val;
        scanf("%d%d", &t, &v);
        --v;
        if (t == 1) {
            scanf("%d", &val);
            my_add(a + l[v], a + l[v] + sz[v], val);
        } else {
            ans.PB(get_max(a + l[v], a + l[v] + sz[v], b + l[v]));
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}