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
#define whatis(x) cerr << #x << " is " << x << endl;
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

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

deque<pair<int,int>> qumax; //front max, back min, {val,ind}
deque<pair<int,int>> qumin; //front min, back max, {val,ind}
void insertmx(int val, int ind){
    while(!qumax.empty() && qumax.back().first <= val)
        qumax.pop_back();
    qumax.push_back({val,ind});
}
void insertmn(int val, int ind){
    while(!qumin.empty() && qumin.back().first >= val)
        qumin.pop_back();
    qumin.push_back({val,ind});
}
int mnnn(int ind){ //maximum admissible index
    while(qumin.front().second > ind)
        qumin.pop_front();
    return qumin.front().first;
}
int mxxx(int ind){ //maximum admissible index
    while(qumax.front().second > ind)
        qumax.pop_front();
    return qumax.front().first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int a[n];
    GET(a);
    int b[n];
    FOR(i,0,n)
        b[i] = getchar_unlocked()-48;
    int subsum = 0;
    for(int i = n-1; i >= n-5; --i){
        /* ++ast[a[i]], subsum += b[i]; */
        subsum += b[i];
        insertmn(a[i], i);
        insertmx(a[i], i);
    }
    subsum -= b[n-1];
    int l = -1000000000, r = 1000000000;
    for(int i = n-1; i > 3; --i){
        if(b[i]){
            if(b[i-1] == b[i]){ //zadne z pow. nie moze byc jesli sa 1 all w b
                if(subsum == 4){
                    int mn = mnnn(i);
                    /* int mn = ast.begin()->e1; */
                    if(mn > r){
                        r = mn;
                    }
                }
            }
            else{ //musi byc all 0 (assert), oraz all < l
                /* int mx = ast.rbegin()->e1; */
                int mx = mxxx(i);
                if(mx >= l){
                    l = mx+1;
                }
            }
        }
        else{
            if(b[i-1] == b[i]){ //zadne z pow. nie moze byc jesli sa 0 all w b
                if(subsum == 0){
                    int mx = mxxx(i);
                    /* int mx = ast.rbegin()->e1; */
                    if(mx < l){
                        l = mx;
                    }
                }
            }
            else{ //musi byc all 1 (assert), oraz all > r
                /* int mn = ast.begin()->e1; */
                int mn = mnnn(i);
                if(mn <= r){
                    r = mn-1;
                }
            }
        }
        /* if(!--ast[a[i]]) */
        /*     ast.erase(a[i]); */
        subsum -= b[i-1];
        if(i-5 >= 0)
            /* ++ast[a[i-5]], */
            insertmn(a[i-5], i-5),
            insertmx(a[i-5], i-5),
            subsum += b[i-5];
    }
    cout << l << ' ' << r << '\n';
}