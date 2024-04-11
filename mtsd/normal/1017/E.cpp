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
    bool operator > (const C a, const C b) {
        return a.real() != b.real() ? a.real() > b.real() : a.imag() > b.imag();
    }
    bool operator==(const C a, const C b){
        return (eq(a.real(),b.real()) && eq(a.imag(),b.imag()));
    }
    bool operator!=(const C a, const C b){
        return !(a == b);
    }
    C operator* (const C a, const C b){
        return C(a.real()*b.real()-a.imag()*b.imag(),a.real()*b.imag()+a.imag()*b.real());
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
//()
bool intersectSP(const L& s, const C p)
{
    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS;
}
//
C crosspointLL(const L& l, const L& m)
{
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    //
    if(abs(A) < EPS && abs(B) < EPS){
        return m[0];
    }
    return m[0] + B / A * (m[1] - m[0]);
}
//pl
C projection(const L& l, const C p)
{
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
double get(C c1,C c2)
{
    return (dot(c1,c2) < 0 ? -1.0 : 1.0 ) * abs(c2) / abs(c1);
}



//(O(nlogn))
vector<C> convex_hull(vector<C> ps)
{
    int n = (int)ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<C> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]){
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]){
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
    }
    ch.resize(k-1);
    return ch;
}

bool isCongruence(vector<C> x,vector<C>y){
    vector<C>a,b;
    if(x.size()!=y.size())return false;
    int n = x.size();
    for(int i=0;i<n;i++){
        if(i!=n-1){
            a.PB(x[i+1]-x[i]);
            b.PB(y[i+1]-y[i]);
        }else{
            a.PB(x[0]-x[i]);
            b.PB(y[0]-y[i]);
        }
    }
    for(int i=0;i<n;i++){
        C p;
        for(int j=0;j<=n;j++){
            if(j==n)return true;
            if(j==0){
                if(abs(abs(a[j])-abs(b[(i+j)%n]))>EPS)break;
                p = a[j]/b[(i+j)%n];
                //cout << a[j] << " " << b[(i+j)%n] << " " << p << endl;
            }else{
                if(abs(a[j]-p*b[(i+j)%n])>EPS)break;
            }
        }
    }
    return false;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<C>a,b;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a.PB(C((double)x,(double)y));
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        b.PB(C((double)x,(double)y));
    }
    vector<C> x,y;
    x= convex_hull(a);
    y= convex_hull(b);
    if(isCongruence(x,y)){
        cout <<"YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}