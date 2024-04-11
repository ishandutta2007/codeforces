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
template<class T> ostream& operator<<(ostream &os, array<T,3> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, array<T,2> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000000007

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    set<array<int,3>> st; //{votecnt,lst,idx}
    vector<int> vt[m];
    int f,s;
    int base = 0;
    FOR(i,0,n){
        sc(f,s);
        if(!--f){
            ++base;
        }
        else{
            vt[f].pb(s);
        }
    }
    FOR(i,1,m){
        sort(all(vt[i]));
        if(!vt[i].empty())
        st.insert({{{-(int)vt[i].size(),vt[i][0],i}}});
    }
    ll ans = LONG_LONG_MAX;
    FORE(i,0,n){
        int cr = base;
        auto cst = st;
        /* set<array<int,2>> st2; //{lst,idx}; */
        priority_queue<int> st2; //{lst,idx};
        vector<int> cvt[m];
        FOR(i,0,m){
            cvt[i] = vector<int>(vt[i].rbegin(),vt[i].rend());
        }
        ll crans = 0;
        bool mach = 0;
        while(!(cst.empty() || cr > -cst.begin()->front())){
            /* while(!cst.empty() && -cst.begin()->front() != (int)cvt[cst.begin()->back()].size()){ */
            /*     int idx = cst.begin()->back(); */
            /*     cst.erase(cst.begin()); */
            /*     if(!cvt[idx].empty()) */
            /*         cst.insert({{{-(int)cvt[idx].size(),cvt[idx].back(),idx}}}); */
            /* } */
            /* if(cst.empty() || cr > -cst.begin()->front()) break; */
            if(-cst.begin()->front() > i){
                int idx = cst.begin()->back();
                crans += cvt[idx].back();
                ++cr;
                cvt[idx].pop_back();
                cst.erase(cst.begin());
                if(!cvt[idx].empty())
                    cst.insert({{{-(int)cvt[idx].size(),cvt[idx].back(),idx}}});
            }
            else{
                if(!mach){
                    mach = 1;
                    FOR(i,1,m){
                        /* if(!cvt[i].empty()) */
                        /*     st2.insert({{{cvt[i].back(),i}}}); */
                        FORR(x,cvt[i]) st2.push(-x);
                    }
                }
                crans += -st2.top();
                st2.pop();
                ++cr;
                /* int idx = st2.begin()->back(); */
                /* ++cr; */
                /* crans += cvt[idx].back(); */
                /* cvt[idx].pop_back(); */
                /* st2.erase(st2.begin()); */
                /* if(!cvt[idx].empty()) */
                /*     st2.insert({{{cvt[idx].back(),idx}}}); */
            }
        }
        ans = min(ans,crans);
    }
    cout << ans << '\n';
}