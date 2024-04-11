#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<ll> P;
pair<vi, vi> ulHull(const vector<P>& S) {
    vi Q(sz(S)), U, L;
    iota(all(Q), 0);                                                                                                                                                                         
    sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; }); 
    trav(it, Q) {
#define ADDP(C, cmp) while (sz(C) > 1 && S[C[sz(C)-2]].cross(\
    S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
        ADDP(U, <=); ADDP(L, >=);
    }   
    return {U, L}; 
}

vi convexHull(const vector<P>& S) {
    vi u, l; tie(u, l) = ulHull(S);
    if (sz(S) <= 1) return u;
    if (S[u[0]] == S[u[1]]) return {0};
    l.insert(l.end(), u.rbegin()+1, u.rend()-1);
    return l;
}


pair<LL,LL> neg(pair<LL,LL> d){
    return make_pair(-d.first, -d.second);
}

typedef Point<LL> P;
int main(){
    LL n;
    cin >> n;
    pair<LL,LL> a[n];
    pair<LL,LL> sum = make_pair(0,0);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        sum.first += a[i].first;
        sum.second += a[i].second;
        a[i].first *= n;
        a[i].second *= n;
    }
    map<pair<LL,LL>, LL> g;
    for(int i = 0; i < n; i++){
        a[i].first -= sum.first;
        a[i].second -= sum.second;
        g[a[i]]++;
        //cout << a[i].first << " " << a[i].second << endl;
    }
    for(int i = 0; i < n; i++){
        if(g[a[i]] > 0 && g[neg(a[i])] > 0){
            g.erase(a[i]);
            g.erase(neg(a[i]));
        }
    }
    g.erase(make_pair(0,0));
    vector<pair<LL,LL> > pts;
    for(map<pair<LL,LL>, LL>::iterator it = g.begin(); it != g.end(); it++){
        if(it->second <= 0) continue;
        pts.push_back(it->first);
    }
    if(pts.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    vector<P> z;
    for(int i = 0; i < pts.size(); i++){
        z.push_back(P(pts[i].first, pts[i].second));
        //cout << z[i].x << " " << z[i].y << endl;
    }

    vector<int> hull = convexHull(z);

    vector<P> checks;
    for(int j = 0; j < hull.size(); j++){
        int nj = (j+1) % (hull.size());
        P diff = z[hull[nj]] - z[hull[j]];
        LL maxcross = 0;
        LL mincross = 0;
        for(int c = 0; c < z.size(); c++){
            maxcross = max(maxcross, diff.cross(z[c]));
            mincross = min(mincross, diff.cross(z[c]));
        }
        vector<int> maxs;
        vector<int> mins;
        for(int c = 0; c < hull.size(); c++){
            if(diff.cross(z[hull[c]]) == maxcross) maxs.push_back(hull[c]);
            if(diff.cross(z[hull[c]]) == mincross) mins.push_back(hull[c]);
        }
        for(int b = 0; b < maxs.size(); b++){
            for(int a = 0; a < mins.size(); a++){
                if(maxs[b] == mins[a]) continue;
                P del = z[maxs[b]] + z[mins[a]];
                LL gg = __gcd(del.x, del.y);
                del.x /= gg; del.y /= gg;
                if(del.x < 0 || (del.x == 0 && del.y < 0)){
                    del.x *= -1;
                    del.y *= -1;
                }
                checks.push_back(del);
            }
        }
    }
    map<pair<LL,LL>, int> fans;
    for(int j = 0; j < checks.size(); j++){
        map<LL,int> freq;
        for(int i = 0; i < z.size(); i++){
            freq[z[i].cross(checks[j])]++;
        }
        LL ok = 1;
        for(int i = 0; i < z.size(); i++){
            LL cur = z[i].cross(checks[j]);
            if(freq[cur] != freq[-cur]) ok = 0;
        }
        if(ok){
            fans[make_pair(checks[j].x, checks[j].y) ] = 1;
        }
    }
    cout << fans.size() << endl;
}