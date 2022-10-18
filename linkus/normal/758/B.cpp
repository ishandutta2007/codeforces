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
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    getstr(s);
    int cnt[4]{};
    FORR(i,s){
        if(i == 'R')
            i = 0;
        if(i == 'B')
            i = 1;
        if(i == 'Y')
            i = 2;
        if(i == 'G')
            i = 3;
    }
    // xd. couldn't upsolve this problem after 4.7 years.
    FOR(x,0,4){
        int wh = -1;
        int cn = 0;
        for(int i = x; i < (int)s.size(); i += 4){
            if(s[i] == '!')
                ++cn;
            else
                wh = s[i];
        }
        cnt[wh] = cn;
    }
    /* FOR(i,0,s.size()){ */
    /*     if(s[i] == '!'){ */
    /*         int sth[4]; // closest that can be (can't -> INF). */
    /*         FORR(x,sth) */
    /*             x = INF - 2; */
    /*             for(int x = max(0, i - 3); x < i; ++x){ */
    /*                 if(s[x] == '!') continue; */
    /*                 sth[s[x]] = INF; */
    /*             } */
    /*         for(int x = i + 1; x < min<int>(s.size(), i + 4); ++x){ */
    /*             if(s[x] == '!') continue; */
    /*             sth[s[x]] = INF; */
    /*             /1* sth[s[x]] = INF - 2; *1/ */
    /*         } */
    /*         /1* for(int x = i + 1; x < min<int>(s.size(), i + 4); ++x){ *1/ */
    /*         for(int x = i + 1; x < (int)s.size(); ++x){ */
    /*             if(s[x] == '!') continue; */
    /*             if(sth[s[x]] == INF - 2) */
    /*                 sth[s[x]] = x; */
    /*         } */
    /*         int wh = min_element(sth, sth + 4) - sth; */
    /*         /1* whatis(i) *1/ */
    /*         /1* whatis(wh) *1/ */
    /*         /1* whatis(sth[wh]) *1/ */
    /*         assert(sth[wh] != INF); */
    /*         s[i] = wh; */
    /*         ++cnt[wh]; */
    /*     } */
    /* } */
    FORR(i,cnt)
        cout << i << ' ';
    cout << '\n';
}