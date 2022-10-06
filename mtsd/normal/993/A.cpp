#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <complex>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define EPS 1e-10

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
typedef complex<double> C;

const double PI = 4*atan(1.0);

bool eq(double a,double b)
{
  return (-EPS<a-b&&a-b<EPS);
}

namespace std
{
    bool operator < (const C a, const C b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
    //setmap(1e-10)
    // bool operator<(const C a, const C b){
    //     return abs(a.real()-b.real())>EPS ? a.real()<b.real()-EPS : a.imag()<b.imag()-EPS;
    // }
    bool operator==(const C a, const C b){
        return (eq(a.real(),b.real()) && eq(a.imag(),b.imag()));
    }
    bool operator!=(const C a, const C b){
        return !(a == b);
    }
}

struct L : public vector<C>
{
    L(){}
    L(const C a, const C b) {
        push_back(a); push_back(b);
    }
};

//sqrt
double Sqrt(double x)
{
    if(x<0) return 0;
    else    return sqrt(x);
}

//
C normalize(C c)
{
    return c / abs(c);
}

//(rad)
double getarg(C a,C b){
    return arg(b*conj(a));
}

//
double cross(const C a, const C b)
{
    return imag(conj(a)*b);
}
//
double dot(const C a, const C b)
{
    return real(conj(a)*b);
}
//bath(rad)
C rot(C a,C b,double th)
{
    return b + (a-b) * C(cos(th),sin(th));
}
int ccw(C a, C b, C c)
{
    b -= a; c -= a;
    if(cross(b, c) > 0)   return +1;       // counter clockwise
    if(cross(b, c) < 0)   return -1;       // clockwise
    if(dot(b, c) < 0)     return +2;       // c--a--b on line
    if(norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;   //b--a--c on line
}
//(True)
bool intersectLL(const L& l, const L& m)
{
    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;
}
//()
bool intersectLS(const L& l, const L& s)
{
    return cross(l[1]-l[0], s[0]-l[0]) * cross(l[1]-l[0], s[1]-l[0]) < EPS;
}
//()
bool intersectLP(const L& l, const C p)
{
    return abs(cross(l[1]-p, l[0]-p)) < EPS;
}
//()
bool intersectSS(const L& s, const L& t)
{
    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
//(0,1,2)
int contains(const vector<C>& ps, const C p)
{
    bool flag = false;
    rep(i,ps.size()) {
        C a = ps[i] - p, b = ps[(i+1)%ps.size()] - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b)){
            if (cross(a, b) < 0) flag = !flag;
        }
        if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
  }
  return flag ? 2 : 0;
}
int main(){
    vector<C>a(4),b(4);
    rep(i,4){
        double x,y;
        cin >> x >> y;
        a[i]=C(x,y);
    }
    rep(i,4){
        double x,y;
        cin >> x >> y;
        b[i]=C(x,y);
    }
    bool flag =0;
    for(int i=0;i<4;i++){
        if(contains(a,b[i])>=1){
            flag = 1;
        }
        if(contains(b,a[i])>=1){
            flag = 1;
        }
    }
    vector<L>v(4),u(4);
    v[0] = L(a[0],a[1]);
    v[1] = L(a[1],a[2]);
    v[2] = L(a[2],a[3]);
    v[3] = L(a[3],a[0]);
    u[0] = L(b[0],b[1]);
    u[1] = L(b[1],b[2]);
    u[2] = L(b[2],b[3]);
    u[3] = L(b[3],b[0]);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(intersectSS(v[i],u[j])){
                flag = 1;
            }
        }
    }
    if(flag)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}