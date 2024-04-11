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
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
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

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//various geometric functions (2D)

typedef double ftype;
//typ (int, ll, double)?

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
};
point operator*(ftype a, point b) { return b*a; }
ostream& operator<<(ostream &os, point v) { os<<"[";os<<v.x<<' '<<v.y<<"]"; return os; }
istream& operator>>(istream &is, point v) { is >> v.x >> v.y; return is; }

//Czy sa w jednej fukcji liniowej, bez floatow, bez dzielenia, bez edge casow
bool isInLine(const point& p1, const point& p2, const point& p3) {
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

ftype cross(point a, point b){ //vectory
    return a.x*b.y - a.y*b.x;
    //|A|*|B|*sin(a,b)
    //pole trjkta ABC to crossproduct(AB,BC)/2.0
    //0 -> na tej samej prostej
    //>0 -> na lewo od a (najkrcej ofc)
    //<0 -> na prawo od b
}

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

double polygonarea(vector<point> &v){ //sum of areas of triangles from first vertex, with every 2 adjacent vertexes. Works for non and yes convex, because areas are signed.
    int n = v.size();
    double res = 0;
    for(int i = 1; i+1 < n; ++i){
        res += cross(v[i]-v[0],v[i+1]-v[0]);
    }
    return abs(res/2.0);
}

point intersect(point a1, point a2, point b1, point b2){ //intersection of 2 lines
    ftype c1 = cross(a2-a1,b2);
    ftype c2 = cross(b1,b2);
    if(!c2) return {-INF,INF}; //parallel
    return a1+c1/c2*b1;
}

double a,b,c;

double fx(double x){
    if(!b) return INF;
    return (a*x+c)/-b;
}

double fy(double y){
    if(!a) return INF;
    return (b*y+c)/-a;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(9);
    point x,y;
    cin >> a >> b >> c >> x.x >> x.y >> y.x >> y.y;
    vector<point> f1,f2;
    double ans = abs(x.x-y.x)+abs(x.y-y.y);
    whatis(ans)
    auto t = fx(x.x),t2 = fy(x.y);
    if(t != INF)
        f1.push_back({x.x,t});
    if(t2 != INF)
        f1.push_back({t2,x.y});
    t = fx(y.x),t2 = fy(y.y);
    if(t != INF)
        f2.push_back({y.x,t});
    if(t2 != INF)
        f2.push_back({t2,y.y});
    FORR(i,f1){
        FORR(j,f2){
            ans = min(ans,dist(x,i)+dist(i,j)+dist(j,y));
        }
    }
    cout << ans << '\n';
}