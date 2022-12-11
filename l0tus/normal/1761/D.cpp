#include <bits/stdc++.h>


using namespace std;


#define FOR(i, a, b) for (int i = (a); i < (b); ++i)


#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);


template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U &x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U &x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other)
    {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    
    
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs)
    {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    
    
    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    
private:
    Type value;
};


template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }


template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }


// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
    return stream << number();
}


/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

/*
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/
constexpr int MOD = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

const int MN = (int)1e6 + 5;


vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Mint pow3[MN];
int main()
{
    FAST_IO;
    int n, k;
    cin >> n >> k;
    Mint ans = 0;
    pow3[0] = 1;
    FOR(i, 1, n + 5)
    {
        pow3[i] = pow3[i - 1] * 3;
    }
    if (k == 0)
    {
        cout << pow3[n];
        return 0;
    }
    for (int t = 1; t <= k; t++)
    {
        if (n - k >= t && n >= t * 2)
            ans += C(k - 1, t - 1) * C(n - k, t) * pow3[n - t * 2];
        if (n - k >= t - 1 && n >= t * 2 - 1)
            ans += C(k - 1, t - 1) * C(n - k, t - 1) * pow3[n - t * 2 + 1];
    }
    cout << ans;
}