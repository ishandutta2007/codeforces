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
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

const int mod = 1000000007;

int powmod(int a, int b){
    if(b == 0)
        return 1;
    if(b&1){
        return (ll)a * powmod(a,b^1) % mod;
    }
    int wtf = powmod(a,b >> 1);
    return (ll)wtf*wtf % mod;
}

int n,p;
int calc(vi s){
    int res = 0;
    FORR(i,s){
        res += powmod(p,i);
        res %= mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        sc(n,p);
        int a[n];
        GET(a);
        if(p == 1){
            cout << (n&1) << '\n';
            continue;
        }
        sort(a,a+n,greater<int>());
        /* { */
            /* vi s[2]; */
            /* int cls[2] = {}; */
            /* bool less = 0; */
            /* FORR(i,a){ */
            /*     less = s[1] < s[0]; */
            /*     s[less].push_back(i); */
            /*     if(s[less].size() > 1){ */
            /*         if(s[less].back() == *(s[less].end()-2)) */
            /*             ++cls[less]; */
            /*         else */
            /*             cls[less] = 1; */
            /*     } */
            /*     else{ */
            /*         cls[less] = 1; */
            /*     } */
            /*     while(cls[less] == p){ */
            /*         int wh = s[less].back(); */
            /*         FOR(i,0,p){ */
            /*             assert(s[less].back() == wh); */
            /*             s[less].pop_back(); */
            /*         } */
            /*         s[less].push_back(wh+1); */
            /*         cls[less] = 0; */
            /*         for(int i = s[less].size()-1; i >= 0 && s[less][i] == s[less].back(); --i){ */
            /*             ++cls[less]; */
            /*         } */
            /*     } */
            /*     assert(cls[less] < p); */
            /* } */
            /* less = s[1] < s[0]; */
            /* whatis(s[0]) */
            /* whatis(s[1]) */
            /* int wyn[2]; */
            /* FOR(i,0,2) */
            /*     wyn[i] = calc(s[i]); */
            /* /1* int dif = s[0] < s[1] ? wyn[1] - wyn[0] : wyn[0] - wyn[1]; *1/ */
            /* int dif = wyn[less^1] - wyn[less]; */
            /* dif = abs(dif); */
        /* } */
        ll dif = 0;
        int lspow = -1;
        bool alwgt = 0;
        FORR(i,a){
            if(dif == 0){
                lspow = i;
            }
            if(!alwgt)
            while(i < lspow){
                dif *= p;
                --lspow;
                if(dif > n){
                    alwgt = 1;
                    dif %= mod;
                    goto jump;
                }
                dif %= mod;
            }
            else{
jump:
                ll rem = powmod(p,lspow-i);
                dif *= rem;
                dif %= mod;
                lspow = i;
            }
            if(alwgt || dif){
                --dif;
            }
            else{
                ++dif;
            }
        }
        ll rem = powmod(p,lspow);
        dif *= rem;
        dif %= mod;
        dif += mod;
        dif %= mod;
        /* while(lspow--){ */
        /*     dif *= p; */
        /*     dif %= mod; */
        /* } */
        /* dif %= mod; */
        /* dif += mod; */
        /* dif %= mod; */
        cout << dif << '\n';
    }
}