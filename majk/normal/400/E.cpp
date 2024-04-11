#include <iostream>
#include <vector>


using namespace std;
typedef long long ll;

int S;
struct Record {
    int prefix, suffix;
    ll count;
    bool full;
};

vector<vector<Record>> T;

void fix(int b, int i) {
    auto &t = T[b][2*i];
    auto &u = T[b][2*i+1];
    T[b][i] = {
        t.prefix + (t.full?u.prefix:0), 
        u.suffix + (u.full?t.suffix:0), 
        t.count + u.count + (!t.full&&!u.full?ll(t.suffix+u.prefix)*ll(t.suffix+u.prefix+1):0), 
        t.full && u.full
    };
}

void update(int b, int i, int v) {
    i += S;
    T[b][i] = {v,v,0,v==1};
    while (i) fix(b, i /= 2);    
}

constexpr int bits = 17;

int main() {
    int N, M; cin >> N >> M;
    S = 1;
    while (S < N) S *= 2;
    T = vector<vector<Record>>(bits, vector<Record>(2*S, {0,0,0,false}));
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        for (int j = 0; j < bits; ++j) {
            if (a&(1<<j)) T[j][i+S] = {1,1,0,true};
        }
    }

    for (int i = S-1; i > 0; --i) {
        for (int j = 0; j < bits; ++j) {
            fix(j,i);
        }
    }

    for (int i = 0; i < M; ++i) {
        int p, v; cin >> p >> v;
        --p;
        for (int j = 0; j < bits; ++j) update(j, p, (v&(1<<j))?1:0);
    
        ll ans = 0;
        for (int j = 0; j < bits; ++j) {
            ll cnt = T[j][1].count + ll(T[j][1].suffix)*ll(T[j][1].suffix+1) + (T[j][1].full?0:ll(T[j][1].prefix)*ll(T[j][1].prefix+1));
            ans += cnt<<j;
        }
        cout << ans/2 << '\n';
    }
}