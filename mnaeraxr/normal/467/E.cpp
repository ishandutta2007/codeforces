#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vi value(n), nxt(n, -1), idx(n);

    for (int i = 0; i < n; ++i){
        cin >> value[i];
        idx[i] = i;
    }

    auto compare = [&](int a, int b){
        if (value[a] == value[b]) return a < b;
        return value[a] < value[b];
    };

    sort(idx.begin(), idx.end(), compare);

    for (int i = 0; i + 1 < n; ++i){
        int u = idx[i], v = idx[i + 1];
        if (value[u] == value[v])
            nxt[u] = v;
    }

    vi ans, mark(n), num(n);
    stack<int> pos;

    for (int i = 0, t = 1, r = n; i < n; ++i){
        if (!pos.empty() && pos.top() == i)
            pos.pop();

        if (i == r){
            for (int k = 0; k < 4; ++k)
                ans.push_back(value[i]);

            while (!pos.empty()) pos.pop();
            t++; r = n;
            continue;
        }

        int j = i;
        for (int k = 0; k < 3 && j != -1; ++k)
            j = nxt[j];

        if (j != -1)
            r = min(r, j);

        if (mark[i] == t){
            ans.push_back(num[i]);
            ans.push_back(value[i]);
            ans.push_back(num[i]);
            ans.push_back(value[i]);

            while (!pos.empty()) pos.pop();
            t++; r = n;
        }
        else if (nxt[i] == -1){
            continue;
        }
        else if (pos.empty() || nxt[i] < pos.top()){
            pos.push(nxt[i]);
        }
        else{
            mark[ nxt[i] ] = t;
            num[ nxt[i] ] = value[ pos.top() ];
        }
    }

    cout << ans.size() << endl;

    for (auto v : ans)
        cout << v << " ";

    cout << endl;

    return 0;
}