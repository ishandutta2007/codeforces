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
    int n;
    sc(n);
    vector<bool> a(n);
    FOR(i,0,n){
        bool tmp;
        sc(tmp);
        a[i] = tmp;
    }
    vector<vi> vec;
    /* if(n <= 6){ */
    auto dopos = [&](vi pos){
        FORR(i,pos){
            /* whatis(i) */
            a[i] = !a[i];
        }
        vec.push_back(pos);
    };
    /* while(n > 12){ */
    while(n > 14){
        int ile = count(a.begin() + n - 6, a.begin() + n, 1);
        whatis("top")
        int cnt = 0;
            FOR(beg,n-6,n){
                whatis(a[beg])
            }
        // bruh?
        // nie no git
        // -> nope, n - 3 tez opwinno byc considered xd.
        /* FOR(beg,n-6,n-3){ */
        /* FOR(beg,n-6,n-2){ */
        /*     if(a[beg] && a[beg + 1] && a[beg + 2]){ */
        /*         ++cnt; */
        /*         dopos({beg, beg + 1, beg + 2}); */
        /*     } */
        /* } */
        // tego brakowao... (zbyt trash st8 na kodowanie takiej implementacji
        // dzi.)
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 6){
            /* assert(0); // ??? XD niby jak. */
            // -> XD, not updating ile b4 this but after the 3cons handler.
            dopos({n - 1, n - 2, n - 3});
            dopos({n - 4, n - 5, n - 6});
            ++cnt;
            ++cnt;
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 5){
            /* if(a[n-1] && a[n-3] && a[n-5]) */
            if(a[n-1] && a[n-3] && a[n-5] && a[n-2] && a[n-6]) // !a[n-4]
                dopos({n-1,n-3,n-5}); // 2 6
            /* else if(a[n-2] && a[n-4] && a[n-6]) */
            else if(a[n-2] && a[n-4] && a[n-6] && a[n-1] && a[n-5]) // !a[n-3]
                dopos({n-2,n-4,n-6}); // 1 5
            else if(!a[n-1])
                dopos({n-3,n-4,n-5}); // 2 6
            else if(!a[n-6])
                dopos({n-2,n-3,n-4}); // 1 5
            else if(!a[n-2])
                dopos({n-3,n-4,n-5}); // 1 6
            else if(!a[n-5])
                dopos({n-2,n-3,n-4}); // 1 6
            else
                assert(0);
            /* FOR(beg,n-6,n){ */
            /*     whatis(a[beg]) */
            /* } */
            /* assert(0); */
            assert(cnt == 0);
            ++cnt;
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        FOR(beg,n-6,n-2){
            if(a[beg] && a[beg + 1] && a[beg + 2]){
                ++cnt;
                dopos({beg, beg + 1, beg + 2});
            }
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 4){
            /* FOR(beg,n-6,n-3){ */
            /*     if(a[beg] && a[beg + 1] && a[beg + 2]) */
            /*         dopos({beg, beg + 1, beg + 2}); */
            /* } */
            vi wh;
            /* FOR(i,n-6,n-3){ */
            FOR(i,n-6,n){
                if(a[i])
                    wh.push_back(i);
            }
            // thx assert <3.
            assert(wh.size() == 4);
            dopos({wh[0], wh[2], wh[0] - (wh[2] - wh[0])});
            dopos({wh[1], wh[3], wh[1] - (wh[3] - wh[1])});
            assert(cnt == 0);
            ++cnt;
            ++cnt;
            ile = count(a.begin() + n - 6, a.begin() + n, 1);
            assert(ile == 0);
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 3){
            vi wh;
            FOR(i,n-6,n){
                if(a[i])
                    wh.push_back(i);
            }
            dopos({wh[0], wh[2], wh[0] - (wh[2] - wh[0])});
            assert(cnt == 0);
            ++cnt;
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 2){
            vi wh;
            FOR(i,n-6,n){
                if(a[i])
                    wh.push_back(i);
            }
            dopos({wh[0], wh[1], wh[0] - (wh[1] - wh[0])});
            assert(cnt <= 1);
            ++cnt;
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        if(ile == 1){
            vi wh;
            FOR(i,n-6,n){
                if(a[i])
                    wh.push_back(i);
            }
            int oth = n - 7;
            // wrong ord. oth < wh[0].
            /* dopos({wh[0], oth, wh[0] - (oth - wh[0])}); */
            dopos({oth, wh[0], oth - (wh[0] - oth)});
            ++cnt;
        }
        ile = count(a.begin() + n - 6, a.begin() + n, 1);
        assert(ile == 0);
        /* assert(cnt <= 2); */ // RTE 10.
        assert(cnt <= 2);
        n -= 6;
    }
        whatis(n)
    whatis(vec)
    /* if(n <= 12){ */
    if(n <= 14){
    /* if(n <= 9){ */
    /* if(n <= 7){ */
        /* for(int i = n; i < a.size(); ++i) */
        /*     assert(!a[i]); */
        set<vector<bool>> st;
        /* queue<vector<bool>> qu; */
        queue<pair<vector<bool>, vector<vector<int>>>> qu;
        vector<bool> na(a.begin(), a.begin() + n);
        a = std::move(na);
        qu.push({a,{}});
        st.insert(a);
        while(!qu.empty()){
            auto cr = qu.front(); qu.pop();
            if(cr.e1 == vector<bool>(n,0)){
                cout << "YES\n";
                /* cr.e2 = vec + cr.e2; */
                cr.e2.insert(cr.e2.begin(), all(vec));
                cout << cr.e2.size() << '\n';
                FORR(i,cr.e2){
                    FORR(x,i)
                        cout << x + 1 << ' ';
                    cout << '\n';
                }
                return 0;
            }
            FOR(i,0,n){
                FOR(x,1,n){
                    vi pos = {i, i + x, i + 2 * x};
                    if(pos.back() >= n)
                        continue;
                    auto nw = cr;
                    FORR(i,pos){
                        nw.e1[i] = !nw.e1[i];
                        /* nw.e2.push_back(pos); */
                    }
                    nw.e2.push_back(pos);
                    if(st.insert(nw.e1).e2)
                        qu.push(nw);
                }
            }
        }
        cout << "NO\n";
    }
    else{
        assert(0);
    }
    /* else{ */
    /*     /1* cout << "YES\n"; *1/ */
    /*     /1* vector<vi> vec; *1/ */
    /*     /1* auto xd = [&](int thr){ *1/ */
    /*     /1*     /2* FOR(i,0,n){ *2/ *1/ */
    /*     /1*     /2*     // kox nlogn xd. *2/ *1/ */
    /*     /1*     /2*     FOR(x,1,n){ *2/ *1/ */
    /*     /1*     /2*         vi pos = {i, i + x, i + 2 * x}; *2/ *1/ */
    /*     /1*     /2*         if(pos.back() >= n) *2/ *1/ */
    /*     /1*     /2*             continue; *2/ *1/ */
    /*     /1*     /2*         int cnt = 0; *2/ *1/ */
    /*     /1*     /2*         FORR(j,pos) *2/ *1/ */
    /*     /1*     /2*             cnt += a[j]; *2/ *1/ */
    /*     /1*     /2*         if(cnt >= thr){ *2/ *1/ */
    /*     /1*     /2*             FORR(i,pos){ *2/ *1/ */
    /*     /1*     /2*                 a[i] = !a[i]; *2/ *1/ */
    /*     /1*     /2*             } *2/ *1/ */
    /*     /1*     /2*             vec.push_back(pos); *2/ *1/ */
    /*     /1*     /2*         } *2/ *1/ */
    /*     /1*     /2*     } *2/ *1/ */
    /*     /1*     /2* } *2/ *1/ */
    /*     /1*     // super correct sth: (but nlogn at least) *1/ */
    /*     /1*     FOR(i,1,n){ *1/ */
    /*     /1*         for(int x = i; x < n; x += i){ *1/ */
    /*     /1*             /2* vi pos = {i, i + x, i + 2 * x}; *2/ *1/ */
    /*     /1*             vi pos = {x, x + i, x + 2 * i}; *1/ */
    /*     /1*             if(pos.back() >= n) *1/ */
    /*     /1*                 continue; *1/ */
    /*     /1*             int cnt = 0; *1/ */
    /*     /1*             FORR(j,pos) *1/ */
    /*     /1*                 cnt += a[j]; *1/ */
    /*     /1*             if(cnt >= thr){ *1/ */
    /*     /1*                 FORR(i,pos){ *1/ */
    /*     /1*                     a[i] = !a[i]; *1/ */
    /*     /1*                 } *1/ */
    /*     /1*                 vec.push_back(pos); *1/ */
    /*     /1*             } *1/ */
    /*     /1*         } *1/ */
    /*     /1*     } *1/ */
    /*     /1* }; *1/ */
    /*     /1* xd(3); *1/ */
    /*     /1* xd(2); *1/ */
    /*     /1* xd(3); *1/ */
    /*     /1* /2* xd(2); *2/ *1/ */
    /*     /1* /2* xd(3); *2/ *1/ */
    /*     /1* /2* xd(2); *2/ *1/ */
    /*     /1* /2* xd(3); *2/ *1/ */
    /*     /1* /2* xd(2); *2/ *1/ */
    /*     /1* /2* xd(3); *2/ *1/ */
    /*     /1* // kox. *1/ */
    /*     /1* FOR(i,0,n){ *1/ */
    /*     /1*     if(a[i]){ *1/ */
    /*     /1*         auto dopos = [&](vi pos){ *1/ */
    /*     /1*             FORR(i,pos){ *1/ */
    /*     /1*                 whatis(i) *1/ */
    /*     /1*                 a[i] = !a[i]; *1/ */
    /*     /1*             } *1/ */
    /*     /1*             vec.push_back(pos); *1/ */
    /*     /1*         }; *1/ */
    /*     /1*         int ni = i; *1/ */
    /*     /1*         /2* while(ni < 6 && ni + 6 <= n){ *2/ *1/ */
    /*     /1*         /2* while(ni < 6 && ni + 6 >= n){ *2/ *1/ */
    /*     /1*         while(ni >= 3 && (ni < 6 && ni + 6 >= n)){ *1/ */
    /*     /1*             /2* whatis(ni) *2/ *1/ */
    /*     /1*             /2* assert(ni >= 3); *2/ *1/ */
    /*     /1*             dopos({ni - 1, ni - 2, ni - 3}); *1/ */
    /*     /1*             dopos({ni, ni - 1, ni - 2}); *1/ */
    /*     /1*             ni -= 3; *1/ */
    /*     /1*         } *1/ */
    /*     /1*         if(ni >= 6){ *1/ */
    /*     /1*             dopos({ni - 5, ni - 4, ni - 3}); *1/ */
    /*     /1*             dopos({ni - 6, ni - 5, ni - 4}); *1/ */
    /*     /1*             dopos({ni - 6, ni - 3, ni}); *1/ */
    /*     /1*         } *1/ */
    /*     /1*         /2* else{ *2/ *1/ */
    /*     /1*         else if(ni + 6 < n){ *1/ */
    /*     /1*             dopos({ni + 5, ni + 4, ni + 3}); *1/ */
    /*     /1*             dopos({ni + 6, ni + 5, ni + 4}); *1/ */
    /*     /1*             dopos({ni + 6, ni + 3, ni}); *1/ */
    /*     /1*         } *1/ */
    /*     /1*     } *1/ */
    /*     /1* } *1/ */
    /*     /1* FOR(i,0,n){ *1/ */
    /*     /1*     /2* assert(!a[i]); *2/ *1/ */
    /*     /1*     if(a[i]) *1/ */
    /*     /1*         REE("NO") *1/ */
    /*     /1* } *1/ */
    /*     /1* cout << vec.size() << '\n'; *1/ */
    /*     /1* FORR(i,vec){ *1/ */
    /*     /1*     FORR(x,i) *1/ */
    /*     /1*         cout << x + 1 << ' '; *1/ */
    /*     /1*     cout << '\n'; *1/ */
    /*     /1* } *1/ */
    /* } */
}