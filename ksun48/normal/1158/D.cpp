#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
};

typedef Point<ll> P;
pair<vi, vi> ulHull(const vector<P>& S) {
    vi Q(sz(S)), U, L;
    iota(all(Q), 0);
    sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; });
    trav(it, Q) {
#define ADDP(C, cmp) while(sz(C) > 1 && S[C[sz(C)-2]].cross(S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
        ADDP(U, <=); ADDP(L, >=);
    }
    return {U, L};
}

vi convexHull(const vector<P>& S) {
    vi u, l; tie(u,l) = ulHull(S);
    if(sz(S) <= 1) return u;
    if(S[u[0]] == S[u[1]]) return {0};
    l.insert(l.end(), u.rbegin()+1, u.rend() - 1);
    return l;
}

// ccw 

int main(){
    int n;
    cin >> n;
    vector<P> ps;
    vector<LL> ids;
    for(int i = 0; i < n; i++){
        LL x, y;
        cin >> x >> y;
        ps.push_back(P(x,y));
        ids.push_back(i+1);
    }
    string g;
    cin >> g;

    vector<int> starthull = convexHull(ps);

    cout << ids[starthull[0]] << " ";

    int cur = ids[starthull[0]];

    for(int i = 0; i < n-2; i++){
        vector<int> newhull = convexHull(ps);

        int idx;
        for(int j = 0; j < newhull.size(); j++){
            if(ids[newhull[j]] == cur){
                idx = j;
            }
        }

        int idofnext;
        if(g[i] == 'L'){
            idofnext = ids[newhull[(idx+1) % newhull.size()]];
        } else {
            idofnext = ids[newhull[(idx-1 + newhull.size() ) % newhull.size()]];
        }

        cout << idofnext << " ";

        vector<P> newps;
        vector<LL> newids;
        for(int j = 0; j < ids.size(); j++){
            if(ids[j] == cur){
                continue;
            }
            newps.push_back(ps[j]);
            newids.push_back(ids[j]);
        }
        ps = newps;
        ids = newids;

        cur = idofnext;
    }
    for(int j = 0; j < ids.size(); j++){
        if(ids[j] == cur){
            continue;
        }
        cout << ids[j] << endl;
    }

}