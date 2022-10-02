#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<ll> L(N), R(N);
    for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
    set<pair<ll,int>> B;
    for (int i = 0; i < M; ++i) {
        ll b; 
        cin >> b;
        B.insert({b,i+1});
    }
    
    set<pair<pair<ll,ll>,int>> I;
    for (int i = 0; i < N-1; ++i) {
        I.insert({{R[i+1]-L[i],L[i+1]-R[i]},i});
    }

    vector<int> Ans(N-1);
    for (auto&i: I) {
        auto it = B.lower_bound({i.x.y, 0});
        if (it == B.end() || it->x > i.x.x) { cout << "No\n"; return 0; }
        Ans[i.y] = it->y;
        B.erase(it);
    }

    cout << "Yes\n";
    for (int i = 0; i < N-1; ++i) {
        cout << Ans[i] << " \n"[i==N-2];
    }
}