#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


template<int m>
struct modint
{
    int x;

    modint() :
        x(0) {}

    modint(long long arg)
    {
        arg%= m;
        if (arg < 0) x = arg + m;
        else x = arg;
    }

    modint& operator+= (const modint& other)
    {
        x += other.x;
        if (x >= m) x -= m;

        return *this;
    }

    modint& operator*= (const modint& other)
    {
        x = (x * 1ll * other.x) % m;
        return *this;
    }

    modint& operator-= (const modint& other)
    {
        x+= m - other.x;
        if (x >= m) x-= m;

        return *this;
    }

    modint operator+ (const modint& other) const
    {
        modint tmp = *this;
        tmp += other;
        return tmp;
    }

    modint operator- (const modint& other) const
    {
        modint tmp = *this;
        tmp -= other;
        return tmp;
    }

    modint operator* (const modint& other) const
    {
        modint tmp = *this;
        tmp *= other;
        return tmp;
    }

    explicit operator int () const
    {
        return x;
    }

    modint& operator++ ()
    {
        ++x;
        if (x == m) x = 0;

        return *this;
    }

    modint& operator-- ()
    {
        if (x == 0) x = m-1;
        else --x;

        return *this;
    }

    modint operator++ (int)
    {
        modint tmp = *this;
        ++*this;

        return tmp;
    }

    modint operator-- (int)
    {
        modint tmp = *this;
        --*this;

        return tmp;
    }

    bool operator== (const modint& other) const
    {
        return x == other.x;
    }

    bool operator!= (const modint& other) const
    {
        return x != other.x;
    }

    template<class T>
    modint operator^ (T arg) const
    {
        if (arg == 0) return 1;
        if (arg == 1) return x;

        auto t = *this ^ (arg >> 1);
        t*= t;

        if (arg & 1) t*= *this;

        return t;
    }

    modint inv() const // works clearly only when 'm' is prime number
    {
        return *this ^ (m-2);
    }
};

const int MOD = 998244353;
typedef modint<MOD> mint;

std::vector<mint> factorial;
std::vector<mint> invfactorial;

inline mint C(int N, int K)
{
    if (N < K || K < 0)
        return mint();

    return factorial[N] * invfactorial[K] * invfactorial[N-K];
}

inline void SetupFactorial(int sz)
{
    ++sz;
    ::factorial.resize(sz);
    ::invfactorial.resize(sz);

    ::factorial[0] = 1;
    for (int i = 1; i < sz; ++i)
        ::factorial[i] = ::factorial[i-1] * mint(i);

    ::invfactorial[sz-1] = ::factorial[sz-1].inv();
    for (int i = sz-2; i >= 0; --i)
        ::invfactorial[i] = ::invfactorial[i+1]*mint(i+1);
}

#include<vector>

struct SegmentTreeMin
{
    int sz;
    std::vector<std::pair<int, int>> tree;
    std::vector<int> adds;
    std::vector<int> tempr;


    SegmentTreeMin() {}

    SegmentTreeMin(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
    }

    inline std::pair<int, int> getValue(int v)
    {
        return {tree[v].first + adds[v], tree[v].second};
    }

    inline void push(int v)
    {
        adds[2 * v] += adds[v];
        adds[2 * v + 1] += adds[v];
        adds[v] = 0;
    }

    inline std::pair<int, int> mergeVal(std::pair<int, int> val1, std::pair<int, int> val2)
    {
        if (val2.first < val1.first)
            return val2;
        if (val1.first < val2.first)
            return val1;

        if (val2.second > val1.second)
            return val2;
        else
            return val1;
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = {tempr[tl], tl};
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    inline void Build(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    SegmentTreeMin(const std::vector<int>& dt)
    {
        Build(dt);
    }

    std::pair<int, int> query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {1400000000, -1};
		if (tl >= l && tr <= r)
            return getValue(v);

        int tm = (tl + tr) / 2;

        push(v);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));

        return mergeVal(query(v * 2, tl, tm, l, std::min(r, tm)),
                        query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline std::pair<int, int> Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int l, int r, int diff)
    {
        if (tr < l) return;
        if (r < tl) return;
		if (tl == l && tr == r)
        {
			adds[v] += diff;
			return;
		}

		int tm = (tl + tr) / 2;

		push(v);

        update (v * 2, tl, tm, l, std::min(r, tm), diff);
        update (v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, diff);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    inline void Update(int l, int r, int diff)
    {
        update(1, 0, sz - 1, l, r, diff);
    }
};


long long a, b, k, n, m, tmp, ans = 0;



mint Get(int sz, int blocks)
{
    int left = sz - blocks - 1;
    return C(sz + left, left);
}

int solve()
{
    cin >> n >> m;


    vi pst(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp >> pst[i];
    }

    int tot = 0;

    //log("h");

    if (m > 0)
    {

        SegmentTreeMin tree(pst);
        //log("i");

        int prev = -100;
        int previd = -100;
        for (int idd = 0; idd < m; ++idd)
        {
            auto rsp = tree.Query(0, m-1);

            int val = rsp.ft;
            int id = rsp.sd;

            tree.Update(0, id, 1);
            tree.Update(id, id, 10000000);

            if (val - prev > 1 || id < previd)
                ++tot;

            prev = val;
            previd = id;
        }
    }



    cout << Get(n, tot).x << endl;

    return 0;
}


int main()
{

    SetupFactorial(500000);
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}