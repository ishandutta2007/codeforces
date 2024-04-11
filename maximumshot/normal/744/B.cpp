#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n;
int ans[1005];
bool used[1005];
int res[1005];
int tot = 0;

void ask(vec< int > w) {
    if(w.empty()) return;
    for(int i = 1;i <= n;i++) used[i] = 0;
    int sz = 0;
    for(int x : w) {
        if(x >= 1 && x <= n) used[x] = 1;
    }
    sort(ALL(w));
    w.resize( unique(ALL(w)) - w.begin() );
    for(int x : w) if(x >= 1 && x <= n) sz++;
    cout << sz << "\n";
    for(int x : w) {
        if(x >= 1 && x <= n) cout << x << " ";
    }
    cout << endl;
    tot++;
    for(int i = 1;i <= n;i++) {
        cin >> ans[i];
        if(!used[i]) {
            res[i] = min(res[i], ans[i]);
        }
    }
}

int main() {

    cin >> n;

    for(int i = 1;i <= n;i++) res[i] = inf + 1;

    vec< vec< int > > q, t;
    vec< int > add;

    for(int i = 2;;i <<= 1) {

        t.clear();

        {
            for(int j = 1;j <= i / 2;j++) add.push_back(j);
            t.push_back( add );
            add.clear();
            for(int j = i / 2 + 1;j <= i;j++) add.push_back(j);
            t.push_back( add );
            add.clear();
        }

        {
            for(auto iter : q) {
                add.clear();
                add = iter;
                for(int x : iter) add.push_back( x + i / 2 );
                t.push_back( add );
            }
        }

        q = t;

        if(i >= n) break;
    }

    for(auto i : q) {
        ask(i);
    }

    cout << "-1\n";

    for(int i = 1;i <= n;i++) {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}