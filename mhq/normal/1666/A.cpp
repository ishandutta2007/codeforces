#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt,avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 20010;

int n;
string s;

vector<string> mask_str = {"RD", "LD", "UL", "RU", "LRD", "UDL", "RLU", "UDR", "UDLR"};
int mask[9];
map<char, int> letter2bit = {{'L', 1}, {'R', 2}, {'D', 4}, {'U', 8}};
bool valid[16];
int flag[MAXN];


bool fast_compatible[9][16];

bool _compatible(int id, int f) { // can be made faster
    return valid[f & mask[id]];
}

void precompute_compatible() {
    for (int id = 0; id < 9; id++) {
        for (int f = 0; f < 16; f++) fast_compatible[id][f] = _compatible(id, f);
    }
}

void gen_masks() {
    for (int id = 0; id < 9; id++) {
        for (char c: mask_str[id]) mask[id] |= letter2bit[c];
    }
}

void init_flag() {
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
        if (i >= 1 and s[i-1] == 'R') flag[i] |= 1;
        if (i < n-1 and s[i+1] == 'L') flag[i] |= 2;
    }
}

void update_flag(int m) {
    for (int i = 0; i < n; i++) {
        flag[i] &= 3;
        if (i >= m and s[i-m] == 'D') flag[i] |= 8;
        if (i + m < n and s[i+m] == 'U') flag[i] |= 4;
    }
}

int streak[9];
int finish_cnt[MAXN];
int solve(int m) {
    for (int id = 0; id < 9; id++) streak[id] = 0;
    for (int i = 0; i < n; i++) finish_cnt[i] = 0;
    update_flag(m);

    int res = 0;
    
    for (int i = n-1; i >= 0; i--) {
        int fi = flag[i];
        if (i + m <= n) {
            int fim = flag[i + m - 1];
            bool first_row =
                fast_compatible[0][fi]
                && (streak[4] >= m-2)
                && fast_compatible[1][fim];
            bool central_row =
                fast_compatible[7][fi]
                && (streak[8] >= m-2)
                && fast_compatible[5][fim];
            bool last_row =
                fast_compatible[3][fi]
                && (streak[6] >= m-2)
                && fast_compatible[2][fim];
            // dbg(i, first_row, central_row, last_row);
            if (first_row) res += finish_cnt[i + m];
            if (central_row) finish_cnt[i] = finish_cnt[i+m];
            else finish_cnt[i] = 0;
            if (last_row) finish_cnt[i]++;
        }
        // {4, 6, 8}
        for (int id = 4; id <= 8; id += 2) {
            if (fast_compatible[id][fi]) streak[id]++;
            else streak[id] = 0;
        }
    }
    return res;
}

bool is_good_mat(vector<string> M) {
    int a = M.size();
    int b = M[0].size();
    vector<vector<int>> cnt(a, vector<int>(b, 0));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int di = 0, dj = 0;
            if (M[i][j] == 'L') dj--;
            if (M[i][j] == 'R') dj++;
            if (M[i][j] == 'U') di--;
            if (M[i][j] == 'D') di++;

            int i0 = i + di, j0 = j + dj;
            if (i0 < 0 or i0 >= a or j0 < 0 or j0 >= b) return false;
            if (cnt[i0][j0]) return false;
            cnt[i0][j0]++;
        }
    }
    return true;
}

bool is_good_str(string A) {
    int l = A.size();
    for (int m = 1; m <= l; m++) {
        if (l % m) continue;
        vector<string> rows(l/m);
        for (int i = 0; i < l/m; i++) rows[i] = A.substr(i*m, m);
        if (is_good_mat(rows)) return true;
    }
    return false;
}

int naive(string A) {
    int res = 0;
    int l = s.size();
    for (int i = 0; i < l; i++) for (int j = i; j < l; j++) {
        res += is_good_str(A.substr(i, j-i+1));
    }
    return res;
}

int real_main(string _s) {
    s = _s;
    n = SZ(s);
    
    
    init_flag();

    LL res = 0;
    for (int m = 2; m <= n/2; m++) {
        int ris = solve(m);
        res += ris;
    }

    for (int i = 0; i < n; i++) {
        int len = 0;
        while (i + len + 1 < n and s[i + len] == 'R' and s[i+len+1] == 'L') len += 2;
        res += len / 2;
        for (int m = 2; m <= len / 2; m += 2) res -= (len/m) - 1;
    }

    for (int i = 0; i < n; i++) {
        int len = 0;
        while (i + len + 1 < n and s[i + len] == 'D' and s[i+len+1] == 'U') len += 2;
        res += len / 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    valid[1] = valid[2] = valid[4] = valid[8] = true;
    assert(SZ(mask_str) == 9);
    gen_masks();
    precompute_compatible();

    // vector<char> alpha = {'L', 'R', 'D', 'U'};
    // for (int len = 1; len <= 30; len++) {
        // cout << len << endl;
        // for (int _ = 0; _ < 10000; _++) {
            // string _s(len, '.');
            // for (int i = 0; i < len; i++) _s[i] = alpha[rand() % 4];
            // if (real_main(_s) != naive(_s)) cout << _s << endl;
            // assert(real_main(_s) == naive(_s));
        // }
    // }
    // return 0;

    // string _s(20000, '.');
    // for (int i = 0; i < 10000; i++) _s[2*i] = 'D', _s[2*i+1] = 'D';
    // cout << _s << endl;
    string _s;
    cin >> _s;
    cout << real_main(_s) << "\n";
    // cout << naive(_s) << "\n";
}