#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<double> S;
int G;

void update(int t, double p) {
    t += G;
    S[t] = p;
    while (t>1) {
        S[t/2] = S[t]*S[t^1];
        t/=2;
    }
}

constexpr int TREE = 1;
constexpr int MUSH = 2;

#define x first
#define y second
int main() {
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    G = 1;
    while (G < 2*N) G *= 2;
    S = vector<double>(2*G, 1);
    vector<pair<pair<int,int>,pair<int,double>>> E;
    for (int i = 0; i < N; ++i) {
        int x, h, l, r; cin >> x >> h >> l >> r;
        E.emplace_back(pair<int,int>{x-h, TREE}, pair<int,double>{i,(100.0-l)/100.0});
        E.emplace_back(pair<int,int>{x+1, TREE}, pair<int,double>{i,(100.0-r)/100.0});
        E.emplace_back(pair<int,int>{x, TREE}, pair<int,double>{i, 1.0});
        E.emplace_back(pair<int,int>{x+h+1, TREE}, pair<int,double>{i, 1.0});
    }

    for (int i = 0; i < M; ++i) {
        int b; double z; cin >> b >> z;
        E.emplace_back(pair<int,int>{b, MUSH}, pair<int,double>{i, z});
    }

    double ans = 0;
    sort(E.begin(),E.end());
    for (auto&e: E) {
        if (e.x.y == TREE) {
            update(e.y.x, e.y.y);
        } else {
            ans += S[1] * e.y.y;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}