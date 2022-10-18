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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r,n;
    sc(r,n);
    /* deque<array<int,4>> dq; */
    vector<array<int,4>> dq;
    int mxoutofdq = -0x7f7f7f7f;
    dq.push_back({1,1});
    int t,x,y;
    int res = 0;
    /* auto it = dq.begin(); */
    int it = 0;
    FOR(i,0,n){
        sc(t,x,y);
        /* while(dq.size() && t - dq.front()[2] >= 2*r){ */
        while(it < dq.size() && t - dq[it][2] >= 2 * r){
            mxoutofdq = max(mxoutofdq, dq[it][3]);
            ++it;
        }
        int cr = mxoutofdq + 1;
        for(int j = it; j < dq.size(); ++j){
            if(abs(x - dq[j][0]) + abs(y - dq[j][1]) <= t - dq[j][2])
                cr = max(cr, dq[j][3] + 1);
        }
        res = max(res, cr);
        dq.push_back({x, y, t, cr});

        // XDDDDD PO PROSTU OD NOWA TO SAMO NAPISAEM, I ZACZO DZIAA
        // nice taktyk

        // miaem it w indeksie zamiast j w drugiej ptli, that's why

        /* whatis(it) */
        /* while(it != dq.size() && t - dq[it][2] >= 2*r){ */
        /*     /1* mxoutofdq = max(mxoutofdq, dq.front()[3]); *1/ */
        /*     mxoutofdq = max(mxoutofdq, dq[it][3]); */
        /*     ++it; */
        /*     /1* dq.pop_back(); *1/ */
        /*     /1* dq.pop_front(); *1/ */
        /* } */
        /* int cr = mxoutofdq + 1; */
        /* /1* FORR(j,dq){ *1/ */
        /* for(int j = it; j < dq.size(); ++j){ */
        /*     /1* if(abs(x - j[0]) + abs(y - j[1]) <= t - j[2]) *1/ */
        /*     /1*     cr = max(cr, j[3] + 1); *1/ */
        /*     if(abs(x - dq[it][0]) + abs(y - dq[it][1]) <= t - dq[it][2]) */
        /*         cr = max(cr, dq[it][3] + 1); */
        /* } */
        /* // vector iterators can change on a push_back... */
        /* dq.push_back({x, y, t, cr}); */
        /* res = max(res, cr); */
    }
    cout << res << '\n';
}