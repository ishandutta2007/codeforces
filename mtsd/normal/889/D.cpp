#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
// template<typename T> class Rational {
// private:
//     static Rational make(const T& x, const T& y){
//         Rational m; return m.num = x, m.den = y, m;
//     }
// public:
//     friend ostream& operator<<(ostream& os, const Rational& rn) {
//         return (os << rn.num << " / " << rn.den);
//     }
//     Rational& operator=(T val){ return *this = Rational(val); }
//     bool operator<(const Rational& val) const { return num*val.den < den*val.num; }
//     bool operator<(const T val) const { return *this < Rational(val); }
//     friend bool operator<(const T val1, const Rational& val2){ return Rational(val1) < val2; }
//     bool operator>(const Rational& val) const { return val < *this; }
//     bool operator>(const T val) const { return *this > Rational(val); }
//     friend bool operator>(const T val1, const Rational& val2){ return Rational(val1) > val2; }
//     bool operator<=(const Rational& val) const { return !(*this > val); }
//     bool operator<=(const T val) const { return *this <= Rational(val); }
//     friend bool operator<=(const T val1, const Rational& val2){ return Rational(val1) <= val2; }
//     bool operator>=(const Rational& val) const { return !(*this < val); }
//     bool operator>=(const T val) const { return *this >= Rational(val); }
//     friend bool operator>=(const T val1, const Rational& val2){ return Rational(val1) >= val2; }
//     bool operator==(const Rational& val) const { return num*val.den == den*val.num; }
//     bool operator==(const T val) const { return *this == Rational(val); }
//     friend bool operator==(const T val1, const Rational& val2){ return Rational(val1) == val2; }
//     bool operator!=(const Rational& val) const { return !(*this == val); }
//     bool operator!=(const T val) const { return *this != Rational(val); }
//     friend bool operator!=(const T val1, const Rational& val2){ return Rational(val1) != val2; }
//     explicit operator bool() const noexcept { return num; }
//     bool operator!() const noexcept { return !static_cast<bool>(*this); }
//     Rational operator+() const { return *this; }
//     Rational operator-() const { return make(-num, den); }
//     friend Rational abs(const Rational& val){ return make(abs(val.num), val.den); }
//     Rational operator+(const Rational& val) const { return make(num*val.den+val.num*den, den*val.den); }
//     Rational operator+(T val) const { return *this + Rational(val); }
//     friend Rational operator+(T a, const Rational& b){ return b + a; }
//     Rational& operator+=(const Rational& val){ return *this = *this + val; }
//     Rational& operator+=(const T& val){ return *this = *this + val; }
//     Rational& operator++(){ return *this += 1; }
//     Rational operator++(int){ return make(num + den, den); }
//     Rational operator-(const Rational& val) const { return make(num*val.den-val.num*den, den*val.den); }
//     Rational operator-(T val) const { return *this - Rational(val); }
//     friend Rational operator-(T a, const Rational& b){ return Rational(a) - b; }
//     Rational& operator-=(const Rational& val){ return *this = *this - val; }
//     Rational& operator-=(const T& val){ return *this = *this - val; }
//     Rational& operator--(){ return *this -= 1; }
//     Rational operator--(int){ return make(num - den, den); }
//     Rational operator*(const Rational& val) const { return make(num*val.num, den*val.den); }
//     Rational operator*(T val) const { return *this * Rational(val); }
//     friend Rational operator*(T a, const Rational& b){ return b * a; }
//     Rational& operator*=(const Rational& val){ return *this = *this * val;}
//     Rational& operator*=(const T& val){ return *this = *this * val; }
//     Rational operator/(const Rational& val) const { return make(num*val.den, den*val.num); }
//     Rational operator/(T val) const { return *this / Rational(val); }
//     friend Rational operator/(T a, const Rational& b){ return Rational(a) / b; }
//     Rational& operator/=(const Rational& val){ return *this / val; }
//     Rational& operator/=(const T& val){ return *this = *this / val; }
 
//     T num, den;
 
//     Rational(){}
//     Rational(T num_) : num(num_), den(1){}
//     Rational(T num_, T den_) : num(num_), den(den_){ if(den < 0) num = -num, den = -den; }
// };
// using R = Rational<ll>;
#define EPS 1e-7
struct point{
    long double x;
    long double y;
    point(){};
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll>x(n),y(n);
    // vector<pair<R,R> >p;
    vector<point> v;
    long double sx = 0.0,sy = 0.0;
    rep(i,n){
        cin >> x[i] >> y[i];
        sx += x[i];
        sy += y[i];
    }
    if(n<=2){
        cout << -1 << endl;
        return 0;
    }
    sx /= (long double)n;
    sy /= (long double)n;
    rep(i,n){
        if(abs(sx-x[i])<=EPS&&abs(sy-y[i])<=EPS){

        }else{
            // p.push_back(MP(R(x[i]),R(y[i])));
            point a;
            a.x = x[i];
            a.y = y[i];
            v.push_back(a);
        }
    }
    n = v.size();
    
    
    if(n<=2){
        cout << -1 << endl;
        return 0;
    }
    bool ok = 1;
    vector<pair<long double,long double> > s;
    rep(i,n){
        s.push_back(MP(v[i].x,v[i].y));
    }
    sort(s.begin(),s.end());
    vector<bool> flag(n,1);
    rep(i,n){
        rep(j,n){
            if(abs(s[i].first+s[j].first - 2*sx)<EPS&&abs(s[i].second+s[j].second - 2*sy)<EPS){
                flag[i] = 0;
                flag[j] = 0;
            }
        }
    }
    int ss = 0;
    v.clear();
    rep(i,n){
        if(flag[i]){
            ss++;
            point a;
            a.x = s[i].first;
            a.y = s[i].second;
            v.push_back(a);
        }
    }
    if(ss<=2){
        cout << -1 << endl;
        return 0;
    }
    n = ss;
    vector<pair<long double,long double> > res;
    if(n%2==0){
        rep(i,n-1){
            point a = v[0];
            point b = v[i+1];
            long double mx = (a.x+b.x)/2.0;
            long double my = (a.y+b.y)/2.0;
            long double rx = (mx-sx);
            long double ry = (my-sy);
            swap(rx,ry);
            ry = -ry;
            long double d = sqrt(rx*rx+ry*ry);
            
            rx /= d;
            ry /= d;
            if(rx<0){
                rx = -rx;
                ry = -ry;
            }
            vector<long double> s;
            rep(j,n){
                long double X = v[j].x;
                long double Y = v[j].y;
                s.push_back(rx * (sx-X) + ry*(sy-Y));
            }
            sort(s.begin(),s.end());
            bool ng = 0;
            rep(j,n){
                if(abs(s[j]+s[n-1-j])>EPS){
                    ng = 1;
                }
            }
            if(!ng){
                res.push_back(MP(rx,ry));
            }
        }
    }else{
        rep(i,n){
            point a = v[i];
            long double mx = a.x;
            long double my = a.y;
            long double rx = (mx-sx);
            long double ry = (my-sy);
            swap(rx,ry);
            ry = -ry;
            long double d = sqrt(rx*rx+ry*ry);
            rx /= d;
            ry /= d;
            if(rx<0){
                rx = -rx;
                ry = -ry;
            }
            vector<long double> s;
            rep(j,n){
                long double X = v[j].x;
                long double Y = v[j].y;
                s.push_back(rx * (sx-X) + ry*(sy-Y));
            }
            sort(s.begin(),s.end());
            bool ng = 0;
            rep(j,n){
                if(abs(s[j]+s[n-1-j])>EPS){
                    ng = 1;
                }
            }
            if(!ng){
                res.push_back(MP(rx,ry));
            }
        }
    }
    sort(res.begin(),res.end());
    int m = res.size();
    int sm = m;
    vector<bool> used(m);
    rep(i,m){
        for(int j=i+1;j<m;j++){
            if(abs(res[i].first-res[j].first)<=EPS&&abs(res[i].second-res[j].second)<=EPS){
                used[j] = 1;
            }
        }
    }
    rep(i,m){
        if(used[i])sm--;
    }
    cout << sm << endl;
    return 0;
}