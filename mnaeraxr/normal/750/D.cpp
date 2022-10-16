#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

vector<int> sz;

int dx[2] = {0, 1};
int dy[2] = {1, 1};

set<pii> paint(int p, int x, int y){
    if (p == (int)sz.size()) return{};

    int d = p & 1;

    int xx = x, yy = y;
    set<pii> ans;

    for (int i = 0; i < sz[p]; ++i){
        xx += dx[d], yy += dy[d];
        ans.insert({xx, yy});
    }

    set<pii> tmp = paint(p + 1, xx, yy);
    ans.insert(tmp.begin(), tmp.end());


    for (auto pp : tmp){
        int X = pp.first, Y = pp.second;

        if (d == 0) X = x - (X - x);
        else{
            int dx = X - xx;
            int dy = Y - yy;
            X = xx + dy;
            Y = yy + dx;
        }

        ans.insert({X, Y});
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        sz.push_back(v);
    }

    auto ans = paint(0, 0, 0);

    cout << ans.size() << endl;

    return 0;
}

// 39