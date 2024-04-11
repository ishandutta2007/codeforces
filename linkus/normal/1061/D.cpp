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
typedef int64_t ll;
typedef std::pair<ll,ll> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

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
#define N 1000000007

struct xd{
    ll e1,e2,id;
    bool operator < (xd oth) const{
        if(e1 != oth.e1) return e1 < oth.e1;
        if(e2 != oth.e2) return e2 < oth.e2;
        return id < oth.id;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,y,x;
    sc(n,x,y);
    set<xd> ls,rls;
    pi tmp;
    FOR(i,0,n){
        sc(tmp.e1,tmp.e2);
        ls.insert({tmp.e1,tmp.e2,i});
        rls.insert({tmp.e2,tmp.e1,i});
    }
    ll sth = x/y; //max merge len
    set<xd>::iterator it;
    set<pair<int,int>> st;
    set<int> ww;
    FORR(i,rls){
        if(!ww.insert(i.e1).e2) continue;
        it = ls.lower_bound({i.e1+1,-1,-1});
        if(it == ls.end()) continue;
        if(it->e1-i.e1 <= sth)
            st.insert({it->e1-i.e1,i.e1});
    }
    int id = n;
    while(!st.empty()){
        auto t = *st.begin();
        st.erase(st.begin());
        auto itt = rls.lower_bound({t.e2,-1,-1});
        if(itt == rls.end() || itt->e1 != t.e2) continue;
        it = ls.lower_bound({t.e2+1,-1,-1});
        if(it == ls.end()) continue;
        if(it->e1-t.e2 == t.e1){
            //mrg
            ls.insert({itt->e2,it->e2,id});
            rls.insert({it->e2,itt->e2,id++});
            ls.erase({itt->e2,itt->e1,itt->id});
            rls.erase({itt->e1,itt->e2,itt->id});
            rls.erase({it->e2,it->e1,it->id});
            ls.erase({it->e1,it->e2,it->id});
        }
        {
        auto itt = rls.lower_bound({t.e2,-1,-1});
        if(itt == rls.end() || itt->e1 != t.e2) continue;
        it = ls.lower_bound({t.e2+1,-1,-1});
        if(it == ls.end()) continue;
        if(it->e1-t.e2 <= sth){
            st.insert({it->e1-t.e2,t.e2});
        }
        }
    }
    ll ans = 0;
    FORR(i,ls){
        ans += x+(i.e2-i.e1)*y;
        ans %= N;
    }
    /* whatis(sth) */
    /* while(!ls.empty()){ */
    /*     /1* whatis("cd") *1/ */
    /*     int tt = ls.begin()->e2; */
    /*     ll cs = x+(ls.begin()->e2-ls.begin()->e1)*y; */
    /*     cs %= N; */
    /*     ls.erase(ls.begin()); */
    /*     /1* whatis(cs) *1/ */
    /*     /1* whatis(tt) *1/ */
    /*     while(it = ls.lower_bound({tt+1,-1,-1}), it != ls.end()){ */
    /*         /1* whatis(*it) *1/ */
    /*         ll nw = (it->e2-tt)*y; */
    /*         ll alt = x+(it->e2-it->e1)*y; */
    /*         if(alt < nw) break; */
    /*         /1* whatis(nw) *1/ */
    /*         /1* whatis(cs) *1/ */
    /*         cs += nw; */
    /*         cs %= N; */
    /*         tt = it->e2; */
    /*         ls.erase(it); */
    /*     } */
    /*     ans += cs; */
    /*     ans %= N; */
    /* } */
    cout << ans << '\n';
}