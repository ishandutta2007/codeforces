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
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
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
#define debug(x...) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
/* template<class T, enable_if_t<!is_same<T, string>::value>> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; } */
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
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
    int a[n];
    FOR(i,0,n){
        sc(a[i]); --a[i];
    }
    vector<vector<int>> comps[4]; // (sz - 1) % 4.
    bool vis[n];
    memset(vis,0,n);
    vi vec;
    int rem = 0;
    FOR(i,0,n){
        int crsz = 0;
        int v = i;
        vi crvec;
        while(!vis[v]){
            crvec.push_back(v);
            vis[v] = 1;
            ++crsz;
            v = a[v];
        }
        if(crsz >= 2){
            /* vec.push_back(crsz); */
            comps[(crsz - 1) & 3].emplace_back(std::move(crvec)); // Citadel Securities <3.
            ++rem;
        }
    }
    /* whatis(vec); */
    vector<pair<vector<int>, vector<int>>> res;
    /* for(;rem > 1;){ */
    for(;rem;){
        vi v1, v2;
        vector<vi> toadd;
        auto makeop = [&](int md, int ile){
            assert(comps[md].size());
            /* ile = min<int>(ile, comps[md].size() - 1); */
            ile = min<int>(ile, comps[md].back().size() - 1);
            debug(md, ile, comps[md].back());
            assert(comps[md].back().size() > ile);
            v1.insert(v1.end(), comps[md].back().end() - (ile + 1), comps[md].back().end());
            /* v2.insert(v1.end(), comps[md].back().end() - (ile + 1), comps[md].back().end()); */
            v2.insert(v2.end(), comps[md].back().end() - (ile + 1), comps[md].back().end());
            std::rotate(v2.end() - (ile + 1), v2.end() - ile, v2.end()); // rotate w lewo o 1.
            comps[md].back().erase(comps[md].back().end() - ile, comps[md].back().end());
            if(comps[md].back().size() != 1){
                toadd.emplace_back(std::move(comps[md].back()));
                /* toadd.emplace_back(comps[md].back()); */
                assert(toadd.back().size() > 1);
            }
            else{
                --rem;
            }
            comps[md].pop_back(); // move and pop_back is perfectly fine https://stackoverflow.com/questions/43416087/c-stl-container-pop-with-move
            /* if(comps[md].back().size() == 1) */
            /*     comps[md].pop_back(); */
        };
        if(comps[1].size()){
            makeop(1, 1); // also, gotta make sure not to make op on the same thing.
            // -> let's pop on makeop(); i pod koniec iteracji readd, at new
            // modulos btw.
            for(int md = 2;;md = (md + 1) & 3){
                if(comps[md].size()){
                    makeop(md, 2);
                    break;
                }
                if(md == 1)
                    break;
            }
        }
        else if(comps[2].size()){
            makeop(2, 2);
            for(int md = 2;;md = (md + 1) & 3){
                if(comps[md].size()){
                    makeop(md, 1);
                    break;
                }
                if(md == 1)
                    break;
            }
        }
        else{
            for(int i = 0; i < 4; ++i){
                if(comps[i].size()){
                    makeop(i, 4);
                    break;
                }
            }
        }
        res.emplace_back(v1, v2);
        debug(v1, v2, toadd);
        for(auto &i: toadd){
            comps[(i.size() - 1) & 3].emplace_back(std::move(i));
        }
    }
    /* while(rem == 1){ */
    /*     for(int i = 0; i < 4; ++i){ */
    /*         if(comps[i].size()) */
    /*             makeop(); */
    /*     } */
    /* } */
    cout << res.size() << '\n';
    for(auto &i: res){
        cout << i.e1.size() << '\n';
        for(int x = 0; x < i.e1.size(); ++x){
            /* cout << i.e1[x] << ' '; */
            cout << i.e1[x] + 1 << ' ';
        }
        cout << '\n';
        for(int x = 0; x < i.e1.size(); ++x){
            /* cout << i.e2[x] << ' '; */
            cout << i.e2[x] + 1 << ' ';
        }
        cout << '\n';
    }
}