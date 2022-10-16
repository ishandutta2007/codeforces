#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct twoset{
    int64 a, b;

    twoset(){
        a = b = 0;
    }

    void insert(int64 x){
        if (x >= a) swap(a, x);
        if (x >= b) swap(b, x);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int64> w(n);
    vector<vector<pii>> tree(n);

    for (int i = 0; i < n; ++i){
        cin >> w[i];
    }

    for (int i = 0; i + 1 < n; ++i){
        int64 u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        tree[u].push_back(pii(v, w));
        tree[v].push_back(pii(u, w));
    }

    int64 answer = 0;

    function<int64(int64,int64)> dfs = [&](int64 s, int64 p){
        twoset foo;

        for (auto e : tree[s]){
            if (e.first == p) 
                continue;

            int64 ja = dfs(e.first, s);
            foo.insert(ja - e.second);
        }

        answer = max(foo.a + foo.b + w[s], answer);

        // cout << s << " " << foo.a << " " << foo.b << " " << w[s] << endl;

        return foo.a + w[s];
    };

    dfs(0, -1);

    cout << answer << endl;

    return 0;
}