#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

typedef long long ftype;
//typ (int, ll, double)?

// geo stuff in other files:
// halfplane intersections

struct point{
    ftype x,y;
    point(): x(0), y(0){};
    point(ftype x, ftype y): x(x), y(y){};
    point& operator+=(const point &t){
        x += t.x;
        y += t.y;
        return *this;
    }
    point& operator-=(const point &t){
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point& operator*=(ftype t){
        x *= t;
        y *= t;
        return *this;
    }
    point& operator/=(ftype t){
        x /= t;
        y /= t;
        return *this;
    }
    point operator+(const point &t) const {
        return point(*this) += t;
    }
    point operator-(const point &t) const {
        return point(*this) -= t;
    }
    point operator*(ftype t) const {
        return point(*this) *= t;
    }
    point operator/(ftype t) const {
        return point(*this) /= t;
    }
    bool operator==(point t) const {
        return x == t.x && y == t.y;
    }
    bool operator<(point t) const {
        return x != t.x ? x < t.x : y < t.y;
    }
};

struct point3d{
    ftype x,y,z;
    point3d(): x(0), y(0), z(0){};
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z){};
    point3d& operator+=(const point3d &t){
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t){
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t){
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t){
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
    bool operator==(point3d t) const {
        return x == t.x && y == t.y && z == t.z;
    }
};

point operator*(ftype a, point b) { return b*a; }
ostream& operator<<(ostream &os, point v) { os<<"[";os<<v.x<<' '<<v.y<<"]"; return os; }
istream& operator>>(istream &is, point &v) { is >> v.x >> v.y; return is; }
ostream& operator<<(ostream &os, point3d v) { os<<"[";os<<v.x<<' '<<v.y<<' '<<v.z<<"]"; return os; }
istream& operator>>(istream &is, point3d &v) { is >> v.x >> v.y >> v.z; return is; }

//Czy sa w jednej fukcji liniowej, bez floatow, bez dzielenia, bez edge casow
bool isinline(const point& p1, const point& p2, const point& p3) {
    // mozna tez uzyc cross produkt po prostu
    ftype d1x = p2.x - p1.x;
    ftype d1y = p2.y - p1.y;
    ftype d2x = p3.x - p1.x;
    ftype d2y = p3.y - p1.y;
    return d1x * d2y == d1y * d2x;
}

double dist(point a, point b){
    double d1 = a.x-b.x, d2 = a.y-b.y;
    return sqrt(d1*d1+d2*d2);
}

ftype dot(point a, point b){ //vectory
    return a.x*b.x+a.y*b.y; //to samo co |A|*|B|*cos(kat a,b)
    //wiec cos(a,b) to jest
    //dotproduct(a,b)/(|A|*|B|)
    //z tego, (najkrotszy, czyli (0,180 [stopni]) kat miedzy vectorami to
    //acos(cos(a,b))
    //0 -> prostopade
    //>0 -> skierowane w t sam stron (<180 deg)
    //<0 -> skierowane w przeciwn stron
}

ftype dot(point3d a, point3d b){
    // pomocne do sprawdzenia, czy wektory s prostopade
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

ftype cross(point a, point b){ //vectory
    return a.x*b.y - a.y*b.x;
    //|A|*|B|*sin(a,b)
    //pole trjkta ABC to crossproduct(AB,BC)/2.0
    //0 -> na tej samej prostej
    //>0 -> na lewo od a (najkrcej ofc)
    //<0 -> na prawo od b
}

point3d cross(point3d a, point3d b){
    // zwraca punkt zerowy, jeli wektory maj rwny kierunek
    // w przeciwnym wypadku, zwraca wektor prostopady do paszczyzny
    // zawierajcej oba wejciowe wektory
    return point3d(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

ftype operator*(point a, point b) { return cross(a,b); }

double disttoline(point p, point a, point b){ //dystans punktu p do lini AB
    ftype crss = cross(b-a,p-a);
    return abs(crss/dist(a,b));
}

double disttosegment(point p, point a, point b){ //dystans punktu p do odcinka AB
    int dst = cross(b-a,a-p)/dist(a,b);
    int dot1 = dot(a-b,b-p);
    if(dot1 > 0) return dist(b,p);
    int dot2 = dot(b-a,a-p);
    if(dot2 > 0) return dist(a,p);
    return abs(dst);
}

// triangulacja te moe by
ll polygonarea(vector<point> &v){
    int n = v.size();
    ll res = 0;
    for(int i = 0; i < n; ++i){
        /* res += cross(v[i]-v[0],v[i+1]-v[0]); */
        res += cross(v[i],v[(i+1)%n]); //works interestingly
    }
    // some another interesting way
    /* for (int i = 0; i < n; ++i) */
    /*         area += poly[i].x * (poly[next(i, n)].y - poly[prev(i, n)].y); */
    return abs(res);
    /* if(res < 0) */
    /*     cout << "CW "; */
    /* else */
    /*     cout << "CCW "; */
    /* cout << abs(res/2); */
    /* if(res&1) */
    /*     cout << ".5"; */
    /* else */
    /*     cout << ".0"; */
    /* cout << '\n'; */
    /* return abs(res/2.0); */
}

// a1, a2 -> punkty
// b1, b2 -> wektory
// jak linia to dwa punkty, to b1 = pa2 - pa1
point intersect(point a1, point a2, point b1, point b2){ // intersection of 2 lines
    ftype c1 = cross(a2-a1,b2);
    ftype c2 = cross(b1,b2);
    if(!c2) return {-INF,INF}; //parallel
    return a1+c1/c2*b1;
}

// Ax + By + C = 0
// useful for getting all lines made by all pairs of points into a set
array<ftype,3> line_function(point a1, point a2){
    ftype A = a1.y - a1.y;
    ftype B = a1.x - a2.x;
    ftype C = a1.x * a2.y - a1.y * a2.x;
    ftype gc = __gcd(A,__gcd(B,C));
    A /= gc;
    B /= gc;
    C /= gc;
    // idk if that truly needed
    if(A < 0)
        A *= -1, B *= -1, C *= -1;
    return {A,B,C};
}

bool cmp(const point &f, const point &s){
    return f.x<s.x || (f.x==s.x && f.y<s.y);
}

vector<point> convex_hull(vector<point> a){
    sort(all(a),cmp);
    a.erase(unique(all(a)),a.end());
    if(a.size() == 1) return a;
    vector<point> res;
    int L = 0;
    FOR(_,0,2){
        FORR(C,a){
            while((int)res.size() >= L + 2){
                point A = res[(int)res.size() - 2];
                point B = res[(int)res.size() - 1];
                if(cross(C-A, B-A) > 0) break; //idk czy nie >=
                res.pop_back();
            }
            res.push_back(C);
        }
        res.pop_back();
        L = res.size();
        if(!_)
            reverse(all(a));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int w,h;
        sc(w,h);
        vi a[4];
        FORR(i,a){
            int m;
            sc(m);
            i.resize(m);
            GET(i);
        }
        ll res = 0;
        FOR(i,0,4){
            vector<point> cr;
            if(i == 0){
                cr.emplace_back(a[i].front(), 0);
                cr.emplace_back(a[i].back(), 0);
            }
            if(i == 1){
                cr.emplace_back(a[i].front(), h);
                cr.emplace_back(a[i].back(), h);
            }
            if(i == 2){
                cr.emplace_back(0, a[i].front());
                cr.emplace_back(0, a[i].back());
            }
            if(i == 3){
                cr.emplace_back(w, a[i].front());
                cr.emplace_back(w, a[i].back());
            }
            FOR(x,0,4){
                if(x == i)
                    continue;
                FORR(j,a[x]){
                    if(x == 0){
                        cr.emplace_back(j, 0);
                    }
                    if(x == 1){
                        cr.emplace_back(j, h);
                    }
                    if(x == 2){
                        cr.emplace_back(0, j);
                    }
                    if(x == 3){
                        cr.emplace_back(w, j);
                    }
                    res = max(res, polygonarea(cr));
                    cr.pop_back();
                }
            }
        }
        cout << res << '\n';
    }
}