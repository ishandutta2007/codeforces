/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
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
#define whatis(x) cerr << #x << " is " << (x) << endl;
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
 
#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //mt19937_64 for 64bit
inline int rand(int l, int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    srand(213769);
    vector<int> primes;
    static bool is_composite[N]{};
    static int wh_pr_ind[N];
    static int func[N], cnt[N]; // If wanna wyliczy multiplicative function.
    // Mobius function calc by default.
    func[1] = 1;
    FOR(i,2,N){
        // without checking divisibility:
        if(!is_composite[i]){
            wh_pr_ind[i] = primes.size();
            primes.push_back(i);
            func[i] = -1; cnt[i] = 1; // If wanna wyliczy multiplicative function.
        }
        for(int j = 0; j <= wh_pr_ind[i] && i * primes[j] < N; ++j){
            is_composite[i * primes[j]] = 1;
            wh_pr_ind[i * primes[j]] = j;
            // If wanna wyliczy multiplicative function.
            if(j + 1 == wh_pr_ind[i]){
                /* func[i * primes[j]] = func[i] / cnt[i] * (cnt[i] + 1); */
                func[i * primes[j]] = 0;
                cnt[i * primes[j]] = cnt[i] + 1;
            }
            else{
                func[i * primes[j]] = func[i] * func[primes[j]];
                cnt[i * primes[j]] = 1;
            }
        }
    }
    auto gen_pr_facts = [&](int n){
        vi res;
        while(n != 1){
            int cr = primes[wh_pr_ind[n]];
            n /= cr;
            if(res.empty() || res.back() != cr)
                res.push_back(cr);
        }
        return res;
    };
    int n;
    sc(n);
    ll a[n];
    GET(a);
    set<ll> vis;
    vector<ll> tryout{2};
    /* vector<ll> odd; */
    /* FORR(i,a) */
    /*     if(i&1) */
    /*         odd.push_back(i); */
    /* if(odd.size()) */
    /* FOR(_,0,100){ */
    /* FOR(_,0,200){ */
    FOR(_,0,20){
        /* int ind = (ll)rand() * rand() % n; */
        // wait, moe rand() * rand() jest zy? xd.
        int ind = rand(0, n - 1);
        ll elem = a[ind];
        /* int ind = (ll)rand() * rand() % odd.size(); */
        /* ll elem = odd[ind]; */
        if(!vis.insert(elem).second)
            continue;
        // damn, was soo close xd. just missed the -1/+1
        vector<ll> elems = {elem - 1, elem, elem + 1};
        FORR(elem,elems){
            FORR(i,primes){
            /* FOR(i,2,1000001){ */
                if(i * i > elem)
                    break;
                if(elem % i == 0){
                    tryout.push_back(i);
                    while(elem % i == 0)
                        elem /= i;
                }
            }
            if(elem > 1)
                tryout.push_back(elem);
        }
        // omg. surely that's the bug. non-explicitly-boundaried ptle not even once...
        /* if(elem > 1) */
        /*     tryout.push_back(elem); */
    }
    sort(all(tryout));
    tryout.erase(unique(all(tryout)), tryout.end());
    ll res = LONG_LONG_MAX;
    /* auto solve = [&](long long u) { */
    /*     long long ret = 0; */
    /*     for (int i = 0; i < n; i++) { */
    /*         long long add = (a[i] < u ? u - a[i] : min(a[i] % u, u - a[i] % u)); */
    /*         ret = min((long long) n, ret + add); */
    /*     } */
    /*     return ret; */
    /* }; */
    FORR(i,tryout){
        ll cr = 0;
        /* cr = solve(i); */
        FORR(x,a){
            // remain positive.
            cr += min(x >= i ? x % i : LONG_MAX, i - x % i);
            // editorial has diff formula, hmm?.
            // albo i nie, bo tam jest formula na optimal elemsy, a nie disty.
            /* cr += min(x >= i ? x % i : LONG_MAX, i - x % i); */
            // -> surely just some bug.
        }
        /* whatis(i) */
        /* whatis(cr) */
        res = min(res, cr);
    }
    cout << res << '\n';
}