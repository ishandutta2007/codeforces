/*
                     .:*+=%@@@@@@=-.
                 .:=@#@@@#@@#######%==*.
              .-=####@######%*-.....:%##%.
            .*@###########%+:--........-%@-
          .*@##############@+--.........-:%-
        .+##################@==%%%%=+*:----+.
      .-@####################%++%@@@@@=+**%@@*
      .%###################@%%@@@###@%+:--%@@%.
     -@###################@%%%%*::*%++:-----=@+.
    -#####################@%=++++++*:-------.-=:
   .+####################@%++*::-:::--::*:::***=:
   .@#####################%=++*::::-:::++*=##@@#@-
  ..#####################@%%=++**:::::**+%@#@%%##-..
   .%####################@@%=+++*+****::*=@######@.
  .=######################@%%==+==++**+=@%@##@###+:...
  -#######################@@@%%%===++=@@@%=++===*::--...
  -########################@@@@@@@%==%%=++==@@:::::*:--.
..:#########################@@@@@@%%======++++::-..:-.--...
%#############################@###@%%@@%==%=%*----.--.::---.
#############################################*-:*:-:---*---- .
#############################################*--*--:---*---:-.
#############################################+--::--::-*::-::.
###########################################+:*-.---.---.:---*-..
###########################################**:-----------------.
##########################################@::**:--::::::--:::::-
###########################################:--:*:::::::::**::*+*
###########################################=:::***::::::**:::*+*
############################@@@@@@#########@+****::::********+++
############################@%%%%%@@@@@@@###%+***::::::::***+==+
############################@%%%%%%%%%%%@####=+:::-::::-::*+=%%+
#############################@%%%%%%%%%%@#####=::--------:*=%@%+
%###########################@%%%%==%%%%%%@##@#=:------..-:+%@@%=
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-const-variable"
#define popcnt(x) __builtin_popcount(x)

#define fr first

#define sc second

#define m_p make_pair

#define low_bo(a, x) (lower_bound(a.begin(), a.end(), x) - a.begin())

#define up_bo(a, x) (upper_bound(a.begin(), a.end(), x) - a.begin())

#define unique(a) a.resize(unique(a.begin(), a.end()) - a.begin())

#define popcnt(x) __builtin_popcount(x)

#define shuffle(a) shuffle(a.begin(), a.end(), rnd)

//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;

//gp_hash_table<int, int> table;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))

/*char memory[(int)1e8];

char memorypos;

inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}

inline void operator delete(void *){}
*/

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef unsigned int uint;

template<typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    // 10^9 + 7
    static uint32_t barret;
    static uint32_t kbarret;
    // 998244353


    constexpr Modular() : value() {}

    template<typename U>
    Modular(const U &x) {
        value = normalize(x);
    }

    static Type inverse(Type a, Type mod) {
        Type b = mod, x = 0, y = 1;
        while (a != 0) {
            Type t = b / a;
            b -= a * t;
            x -= t * y;
            swap(a, b);
            swap(x, y);
        }
        if (x < 0)
            x += mod;
        return x;
    }

    template<typename U>
    static Type normalize(const U &x) {
        Type v;
        if ((x >= 0 || -mod() <= x) && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type &operator()() const { return value; }

    template<typename U>
    explicit operator U() const { return static_cast<U>(value); }

    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other) {
        if ((value += other.value) >= mod()) value -= mod();
        return *this;
    }

    Modular &operator-=(const Modular &other) {
        if ((value -= other.value) < 0) value += mod();
        return *this;
    }

    template<typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }

    template<typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }

    Modular &operator++() { return *this += 1; }

    Modular &operator--() { return *this -= 1; }

    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }

    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }

    Modular operator-() const { return Modular(-value); }

    template<typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs) {
/*        int64_t cur = value * (int64_t)rhs.value;
        value = cur - ((cur * (__int128)Modular::barret) >> Modular::kbarret) * mod();
        if (value >= mod())
            value -= mod();
        return *this;*/

#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;

    }

    template<typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &
    operator*=(const Modular &rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    //template <typename U>
    //friend const Modular<U>& abs(const Modular<U>& v) { return v; }

    template<typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template<typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template<typename U>
    friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

private:
    Type value;
};

template<typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }

template<typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }

template<typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template<typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template<typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }

template<typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template<typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template<typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template<typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }

template<typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template<typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template<typename T>
bool IsZero(const Modular<T> &number) {
    return number() == 0;
}

template<typename T>
string to_string(const Modular<T> &number) {
    return to_string(number());
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
    return stream << number();
}

template<typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x = nullptr;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}


const int md = 998244353;
using Mint = Modular<std::integral_constant<int, md>>;
template<> uint32_t Mint::barret = 0;
template<> uint32_t Mint::kbarret = 0;

void calc_barret() {
    int k = 0;
    while ((1ll << k) <= md)
        k++;
    Mint::kbarret = k * 2;
    Mint::barret = (1ll << (2 * k)) / md;
}


ll sqr(ll x) {
    return x * x;
}

int mysqrt(ll x) {
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m * (ll) m <= x)
            l = m;
        else
            r = m;
    }
    return l;
}

#ifdef ONPC
mt19937 rnd(23);
mt19937_64 rndll(231);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    mt19937_64 rndll(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
T gcd(T a, T b) {
    return a ? gcd(b % a, a) : b;
}

int gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

void setmin(int &x, int y) {
    x = min(x, y);
}

void setmax(int &x, int y) {
    x = max(x, y);
}

void setmin(ll &x, ll y) {
    x = min(x, y);
}

void setmax(ll &x, ll y) {
    x = max(x, y);
}

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, maxw = 5e6 + 100, inf = 1e9 + 100, sq = 450, LG = 17, mod = 1e9 + 933, mod1 = 1e9 + 993;

int sign(ll w) {
    return w > 0 ? 1 : w < 0 ? -1 : 0;
}

namespace INT {

    const double EPS = 1E-9;

    struct pt {
        double x, y;
        bool operator< (const pt & p) const {
            return x < p.x-EPS || (abs(x-p.x) < EPS && y < p.y - EPS);
        }
    };

    struct line {
        double a, b, c;

        line() {}

        line(pt p, pt q) {
            a = p.y - q.y;
            b = q.x - p.x;
            c = -a * p.x - b * p.y;
            norm();
        }

        void norm() {
            double z = sqrt(a * a + b * b);
            if (abs(z) > EPS)
                a /= z, b /= z, c /= z;
        }

        double dist(pt p) const {
            return a * p.x + b * p.y + c;
        }
    };

#define det(a, b, c, d)  (a*d-b*c)

    inline bool betw(double l, double r, double x) {
        return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
    }

    inline bool intersect_1d(double a, double b, double c, double d) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return max(a, c) <= min(b, d) + EPS;
    }

    bool intersect(pt a, pt b, pt c, pt d, pt &left, pt &right) {
        line m(a, b);
        line n(c, d);
        double zn = det (m.a, m.b, n.a, n.b);
        if (abs(zn) < EPS) {
            if (b < a) swap(a, b);
            if (d < c) swap(c, d);
            left = max(a, c);
            right = min(b, d);
            return true;
        } else {
            left.x = right.x = -det (m.c, m.b, n.c, n.b) / zn;
            left.y = right.y = -det (m.a, m.c, n.a, n.c) / zn;
            return betw(a.x, b.x, left.x)
                   && betw(a.y, b.y, left.y)
                   && betw(c.x, d.x, left.x)
                   && betw(c.y, d.y, left.y);
        }
    }

    double dist(pt a, pt b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
}

struct pt {
    ll x, y;
};

namespace checker {

    inline int area(pt a, pt b, pt c) {
        return sign((b.x - a.x) * (ll) (c.y - a.y) - (b.y - a.y) * (ll) (c.x - a.x));
    }

    inline bool intersect_1(int a, int b, int c, int d) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return max(a, c) <= min(b, d);
    }

    bool intersect(pt a, pt b, pt c, pt d) {
        return intersect_1(a.x, b.x, c.x, d.x)
               && intersect_1(a.y, b.y, c.y, d.y)
               && area(a, b, c) * area(a, b, d) <= 0
               && area(c, d, a) * area(c, d, b) <= 0;
    }
}

pt operator-(pt a, pt b) {
    return {a.x - b.x, a.y - b.y};
}

pt operator+(pt a, pt b) {
    return {a.x + b.x, a.y + b.y};
}

pt operator *(pt a, int w) {
    return {a.x * w, a.y * w};
}
INT::pt dai(pt x) {
    return INT::pt({(double)x.x, (double)x.y});
}

void inter(pt a, pt b, pt c, pt d, INT::pt &L, INT::pt &R) {
    INT::intersect(dai(a), dai(b), dai(c), dai(d), L, R);
}

// a - sun

const int bx = 5e5 + 100, by = 1e4 + 100;

pt sun;

pt get(pt b) {
    pt c = b - sun;
    int l = 0, r = bx + 5;
    while (r - l > 1) {
        int m = (l + r) / 2;
        pt o = b + (c * m);
        if (min(o.x, o.y) < 0 || o.x > bx || o.y > by)
            r = m;
        else
            l = m;
    }
    return b + (c * r);
}

int dot(pt a, pt b) {
    return sign(a.x * (ll)b.y - a.y * (ll)b.x);
}

pt get(pair<int, int> w) {
    return {w.fr, w.sc};
}

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, H;
    cin >> n >> H;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].fr >> a[i].sc;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
        pts[i] = get(a[i]);
    double ans = 0;
    sun = pts.back();
    sun.y += H;
    pt z = get(pts.back());
    for (int i = n - 1; i > 0; i--) {
        pt A = pts[i], B = pts[i - 1];
        if (checker::intersect(sun, z, A, B)) {
            INT::pt L, R;
            inter(sun, z, A, B, L, R);
            INT::pt moi = max(L, R);
            if (dot(B - A, z - sun) >= 0) {
                ans += INT::dist(moi, dai(B));
                z = get(B);
            }
        }
    }
    cout << fixed << setprecision(20) << ans << '\n';
}