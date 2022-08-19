/*
    author:  Maksim1744
    created: 09.05.2021 21:07:11
*/

#include "bits/stdc++.h"

using namespace std;

using ll = __int128;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

mt19937 rnd = mt19937(934287);

template<typename T, vector<T>& v>
struct static_pointer {
    int ind = -1;
    static_pointer() {}
    static_pointer(int ind) : ind(ind) {}
    static_pointer(T *ptr) {
        v.push_back(*ptr);
        delete ptr;
        ind = v.size() - 1;
    }
    static_pointer(nullptr_t p) : ind(-1) {}

    template<typename... Args>
    static static_pointer<T, v> new_node(Args... args) {
        v.emplace_back(args...);
        return v.size() - 1;
    }

    T* operator -> () const {
        return &v[ind];
    }

    T& operator * () {
        return v[ind];
    }

    operator bool () const {
        return ind != -1;
    }
    operator int () const {
        return ind;
    }

    bool operator == (nullptr_t p) const {
        return ind == -1;
    }
    bool operator == (int k) const {
        return ind == k;
    }
    bool operator != (nullptr_t p) const {
        return ind != -1;
    }
    bool operator != (int k) const {
        return ind != k;
    }
};

template<typename T, vector<T>& v>
ostream &operator << (ostream &o, const static_pointer<T, v> &ptr) {
    return o << (int)ptr;
}

struct treapArNode;

vector<treapArNode> node_pool;
using treap_ar_node_ptr = static_pointer<treapArNode, node_pool>;

struct treapArNode {
    treap_ar_node_ptr  left = nullptr;
    treap_ar_node_ptr  right = nullptr;
    int value;
    int size;
    ll sm;
    bool is_set = false;
    int set;
    int ind;

    treapArNode(int ind, int _value) : value(_value), size(1), ind(ind) {
        sm = value;
    }

    void reset() {
        size = 1;
        sm = value;
        if (left != nullptr) {
            size += left->size;
            sm += left->sm;
        }
        if (right != nullptr) {
            size += right->size;
            sm += right->sm;
        }
    }
};

struct treapAr {
    treap_ar_node_ptr  root = nullptr;

    treapAr() {}
    treapAr(treap_ar_node_ptr  _root) {
        root = _root;
    }

    pair<treap_ar_node_ptr , treap_ar_node_ptr > split(treap_ar_node_ptr  node, int k) {
        push(node);
        if (node == nullptr) {
            return {nullptr, nullptr};
        }
        if (node->ind == k) {
            auto left = node->left;
            node->left = nullptr;
            node->reset();
            return {left, node};
        }
        if (node->ind > k) {
            auto ans = split(node->left, k);
            node->left = ans.second;
            node->reset();
            return {ans.first, node};
        } else {
            auto ans = split(node->right, k);
            node->right = ans.first;
            node->reset();
            return {node, ans.second};
        }
    }

    ll ask() {
        if (!root) return 0;
        return root->sm;
    }

    treap_ar_node_ptr  merge(treap_ar_node_ptr  a, treap_ar_node_ptr  b) {
        push(a);
        push(b);
        if (a == nullptr) {
            return b;
        } else if (b == nullptr) {
            return a;
        }
        if (rnd() % (a->size + b->size) < a->size) {
            a->right = merge(a->right, b);
            a->reset();
            return a;
        } else {
            b->left = merge(a, b->left);
            b->reset();
            return b;
        }
    }

    void modify(treap_ar_node_ptr node, int val) {
        if (!node) return;
        node->is_set = true;
        node->set = val;
        node->value = val;
        node->sm = (ll)val * node->size;
    }

    void push(treap_ar_node_ptr node) {
        if (!node) return;
        if (node->is_set) {
            modify(node->left, node->set);
            modify(node->right, node->set);
            node->is_set = false;
        }
    }

    void insert(int i, int val) {
        treap_ar_node_ptr newNode = treap_ar_node_ptr::new_node(i, val);
        root = merge(root, newNode);
    }

    void set(int i, int val) {
        show(i, val);
        auto [L, R] = split(root, i);
        if (R) {
            push(R);
            modify(R, val);
        }
        root = merge(L, R);
    }

    treap_ar_node_ptr  get(int i) {
        treap_ar_node_ptr  node = root;
        while (node != nullptr) {
            if (node->left == nullptr) {
                if (i == 0) {
                    return node;
                } else {
                    --i;
                    node = node->right;
                }
            } else {
                if (i == node->left->size) {
                    return node;
                } else if (i < node->left->size) {
                    node = node->left;
                } else {
                    i -= node->left->size + 1;
                    node = node->right;
                }
            }
        }
    }

    int operator[] (int i) {
        return get(i)->value;
    }

    vector<int> toVector(treap_ar_node_ptr  node) {
        if (node == nullptr) {
            return vector<int>({});
        }
        vector<int> vLeft = toVector(node->left);
        vector<int> vRight = toVector(node->right);
        vLeft.push_back(node->value);
        vLeft.insert(vLeft.end(), vRight.begin(), vRight.end());
        return vLeft;
    }

    vector<int> toVector() {
        return toVector(root);
    }

    int extract(int k) {
        auto p1 = split(root, k);
        auto p2 = split(p1.second, k + 1);
        int x = p2.first->value;
        root = merge(p1.first, p2.second);
        return x;
    }

    treap_ar_node_ptr  cut(int l, int r) {
        auto p1 = split(root, l);
        auto p2 = split(p1.second, r + 1 - l);
        root = merge(p1.first, p2.second);
        return p2.first;
    }
};

string to_string(__int128 x) {
    if (x == 0) return "0";
    __uint128_t k = x;
    if (k == (((__uint128_t)1) << 127)) return "-170141183460469231731687303715884105728";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream &operator << (ostream &o, __int128 x) {
    return o << to_string(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> next_good(n, 0);
    vector<int> v(n);
    string s;

    node_pool.reserve(1.5e6);

    vector<vector<int>> next_if(26, vector<int>(n, 0));

    ll prev_ans = 0;
    ll total = 0;
    int min_all = 2e9;
    ll other = 0;
    treapAr cur;

    vector<int> st;

    for (int i = 0; i < n; ++i) {
        char c; int val;
        cin >> c >> val;
        c = (c - 'a' + prev_ans) % 26 + 'a';
        val = val ^ (prev_ans & ((1ll << 30) - 1));

        min_all = min(min_all, val);
        v[i] = val;
        s.pb(c);

        if (i == 0) {
            prev_ans = total = val;
            cout << val << '\n';
            continue;
        }
        {
            int x = i;
            while (x) {
                x = next_good[x - 1];
                if (next_if[s[x] - 'a'][i] == 0)
                    next_if[s[x] - 'a'][i] = x + 1;
                if (s[i] == s[x]) {
                    if (next_good[i] == 0)
                        next_good[i] = x + 1;
                    break;
                }
            }
            if (s.back() == s[0] && next_good[i] == 0) next_good[i] = 1;
        }

        for (int j = 0; j < 26; ++j) {
            if (next_if[j][i] != 0) continue;
            if (next_good[i] == 0) continue;
            next_if[j][i] = next_if[j][next_good[i] - 1];
        }

        s.back() = c;
        next_good[i] = next_if[s.back() - 'a'][i];

        for (int j = 0; j < 26; ++j) {
            if (s.back() == 'a' + j) continue;
            int x = i;
            x = next_if[j][x];
            while (x) {
                if (x <= 1) break;
                int v = cur.extract(i - x + 1);
                total += v;
                other -= v;
                x = next_good[x - 1];
            }
        }

        total += other;

        while (!st.empty() && v[st.back()] >= v[i]) st.pop_back();
        cur.set(st.empty() ? 0 : st.back() + 1, v[i]);
        other = cur.ask();

        if (s[i] == s[0]) {
            cur.insert(i, val);
            other += val;
        }
        prev_ans = total + other + min_all;

        total += min_all;
        cout << prev_ans << '\n';

        st.pb(i);
    }

    return 0;
}