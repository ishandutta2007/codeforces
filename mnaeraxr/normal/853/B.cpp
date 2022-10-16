#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct event{
    int t, city, cost, mode;

    bool operator<(const event &e) const{
        return t < e.t;
    }
};

int value[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<event> E;

    for (int i = 0; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        E.push_back({a, b + c, d, b == 0 ? 1 : -1});
    }

    sort(E.begin(), E.end());

    int rem = n;
    int64 cost = 0;

    for (int i = 1; i <= n; ++i)
        value[i] = -1;

    set<pair<int,int64>> dep;

    for (int i = m - 1; i >= 0; --i){
        auto &e = E[i];

        if (e.mode == 1){ // departure
            if (value[e.city] == -1){
                value[e.city] = e.cost;
                cost += e.cost;
                rem--;
            }
            else{
                cost -= value[e.city];
                value[e.city] = min(value[e.city], e.cost);
                cost += value[e.city];
            }

            if (rem == 0) dep.insert({e.t, cost});
        }
    }

    memset(value, -1, sizeof value);

    int64 answer = oo;
    rem = n;
    cost = 0;

    for (int i = 0; i < m; ++i){
        auto &e = E[i];

        if (e.mode == -1){ // arrive
            if (value[e.city] == -1){
                value[e.city] = e.cost;
                cost += e.cost;
                rem--;
            }
            else{
                cost -= value[e.city];
                value[e.city] = min(value[e.city], e.cost);
                cost += value[e.city];
            }

            if (rem == 0){
                auto it = dep.lower_bound({e.t + k + 1, -1});
                if (it == dep.end()) break;
                answer = min(answer, cost + it->second);
            }
        }
    }


    if (answer == oo) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}