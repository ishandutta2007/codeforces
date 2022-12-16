#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

const int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int fpow(int a, int n, int r = 1) {
    while (n) {
        if (n % 2)
            r = mult(r, a);

        n /= 2;
        a = mult(a, a);
    }

    return r;
}


const int max_n = 4.1e5;
int tree[4 * max_n];
int modif[4 * max_n];
int64_t pmask[4 * max_n], pushmask[4 * max_n];

vector<int> primes, revprimes;

void build(int v, int l, int r, vector<int>& a) {
    modif[v] = 1;
    
    if (l == r - 1) {
        tree[v] = a[l];

        for (int i = 0; i != SZ(primes); ++i)
            if (a[l] % primes[i] == 0)
                pmask[v] |= (int64_t(1) << int64_t(i));
    } else {
        int m = l + (r - l) / 2;
        build(2 * v + 1, l, m, a);
        build(2 * v + 2, m, r, a);

        tree[v] = mult(tree[2 * v + 1], tree[2 * v + 2]);
        pmask[v] = pmask[2 * v + 1] | pmask[2 * v + 2];
    }
}

void push(int v, int vl, int vr) {
    if (modif[v] != 1)
        tree[v] = fpow(modif[v], vr - vl, tree[v]);

    pmask[v] |= pushmask[v];
    
    if (vl != vr - 1) {
        modif[2 * v + 1] = mult(modif[2 * v + 1], modif[v]);
        modif[2 * v + 2] = mult(modif[2 * v + 2], modif[v]);

        pushmask[2 * v + 1] |= pushmask[v];
        pushmask[2 * v + 2] |= pushmask[v];
    }

    modif[v] = 1;
    pushmask[v] = 0;
}

pair<int, int64_t> get(int v, int vl, int vr, int l, int r) {
    if (vr <= l or r <= vl)
        return make_pair<int, int64_t>(1, 0);
    
    push(v, vl, vr);

    if (l <= vl and vr <= r)
        return make_pair(tree[v], pmask[v]);

    int vm = vl + (vr - vl) / 2;
    
    auto r1 = get(2 * v + 1, vl, vm, l, r);
    auto r2 = get(2 * v + 2, vm, vr, l, r);

    return make_pair(mult(r1.first, r2.first), r1.second | r2.second);
}

void multiply(int v, int vl, int vr, int l, int r, int x, int64_t mask) {
    if (vr <= l or r <= vl)
        return;

    push(v, vl, vr);
    
    if (l <= vl and vr <= r) {
        pushmask[v] = mask;
        modif[v] = x;
        return;
    }

    int vm = vl + (vr - vl) / 2;
    
    multiply(2 * v + 1, vl, vm, l, r, x, mask);
    multiply(2 * v + 2, vm, vr, l, r, x, mask);

    pmask[v] = pmask[2 * v + 1] | pmask[2 * v + 2] | pushmask[2 * v + 1] | pushmask[2 * v + 2];
    tree[v] = fpow(x, min(vr, r) - max(l, vl), tree[v]);
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int i = 2; i <= 300; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i and ok; ++j)
            if (i % j == 0)
                ok = false;

        if (ok) {
            primes.push_back(i);
            revprimes.push_back(fpow(i, mod - 2));
        }
    }

    int n = input<int>();
    int q = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    build(0, 0, n, a);

    for (int it = 0; it != q; ++it) {
        if (input<string>() == "TOTIENT") {
            int l = input<int>() - 1;
            int r = input<int>() - 1;
            
            pair<int, uint64_t> prod = get(0, 0, n, l, r + 1);
            for (int i = 0; i != SZ(primes); ++i)
                if (prod.second & (int64_t(1) << int64_t(i)))
                    prod.first = mult(mult(prod.first, primes[i] - 1), revprimes[i]);

            cout << prod.first << "\n";
        } else {
            int l = input<int>() - 1;
            int r = input<int>() - 1;
            int x = input<int>();

            int64_t msk = 0;
            for (int i = 0; i != SZ(primes); ++i)
                if (x % primes[i] == 0)
                    msk |= (int64_t(1) << int64_t(i));

            multiply(0, 0, n, l, r + 1, x, msk);
        }
    }
    
    return 0;
}