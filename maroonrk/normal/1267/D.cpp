#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N; cin >> N;
    V<int> tar(N),fil(N);
    rep(i,N){
        int x=0;
        rep(j,3) {
            int a;
            cin >> a;
            if (a) x |= 1 << j;
        }
        tar[i] = x;
    }
    rep(i,N){
        int x=0;
        rep(j,3) {
            int a;
            cin >> a;
            if (a) x |= 1 << j;
        }
        fil[i] = x;
    }
    V<int> cand(8,-1); cand[7] = 0;
    V<bool> done(N); done[0] = true;
    V<bool> ON(N);
    rep(i,N) if(tar[i] == 0) done[i] = true;
    using P = pair<int,int>;
    V<P> es;
    auto ADD = [&](int x,int y){
        es.eb(x,y);
        ON[y] = true;
        int b = tar[y] & fil[y];
        if(cand[b] == -1){
            cand[b] = y;
            ON[y] = true;
        }
        done[y] = true;
    };
    auto ADD2 = [&](int x,int y,int z){
        es.eb(x,z);
        es.eb(y,z);
        cand[tar[z]] = z;
        done[z] = true;
    };

    while(true){
        bool update = false;
        rep(i,N) if(!done[i] && cand[tar[i]] != -1){
            ADD(cand[tar[i]],i);
            update = true;
            break;
        }
        if(update) continue;
        rep(i,N) if(!done[i] && __builtin_popcount(tar[i]) == 2){
            V<int> m;
            rep(j,3) if((tar[i]>>j)&1){
                if(cand[1<<j] != -1) m.pb(cand[1<<j]);
            }
            if((int)m.size() != 2) continue;
            ADD2(m[0],m[1],i);
            update = true;
            break;
        }
        if(!update) break;
    }
    rep(i,N){
        if(!done[i]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    rep(i,N) cout << ON[i] << " ";
    cout << endl;
    cout << es.size() << endl;
    for(P p: es) cout << p.fs+1 << " " << p.sc+1 << endl;
}