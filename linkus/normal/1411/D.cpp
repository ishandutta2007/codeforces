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
    string s;
    getstr(s);
    int xx,yy;
    sc(xx,yy);
    int cnt = count(all(s),'?');
    int cost[] = {yy,xx};
    FORR(i,s)
        if(i != '?')
            i -= '0';
    ll best = LONG_LONG_MAX;
    FOR(init,0,2){
        /* if(init ^ (xx < yy)) continue; */
        if(init ^ (xx > yy)) continue;
        ll lbest = LONG_LONG_MAX;
        vector<ll> vec;
        ll ilep[2]{}, iles[2]{};
        ll crres = 0;
        FORR(i,s){
            char ch;
            if(i != (init ^ 1)){
                ch = init;
                /* ++ilep[init]; */
            }
            else{
                ch = init ^ 1;
                /* ++ilep[init ^ 1]; */
            }
            /* crres += cost[ch] * ilep[ch]; */
            crres += cost[ch] * ilep[ch^1];
            ++ilep[ch];
        }
        best = min(best,crres);
        lbest = min(lbest,crres);
        vec.pb(crres);
        for(int i = s.size()-1; i >= 0; --i){
            /* if(s[i] != '?') continue; */
            if(s[i] != '?'){
                --ilep[s[i]];
                ++iles[s[i]];
                continue;
            }
            --ilep[init];
            crres -= cost[init] * ilep[init^1];
            crres -= cost[init^1] * iles[init^1];
            crres += cost[init^1] * ilep[init];
            crres += cost[init] * iles[init];
            ++iles[init^1];
            best = min(best,crres);
            lbest = min(lbest,crres);
            vec.pb(crres);
        }
        // wtf, this is so clearly not ternary, bo tylko do maxa d dwie funkcje czsto
        // chyba e dependent od tego czy xx < yy?
        // nah, zawsze ternary moe nie dziaa
        /* whatis(vec) */
        /* whatis(lbest) */
        /* FOR(i,1,vec.size()){ */
        /*     if(vec[i] != lbest){ */
        /*         assert(vec[i] != vec[i-1]); */
        /*     } */
        /* } */
        // -> AC
    }
    /* auto f = [&](int mid, char whpref){ */
    /*     int rem = mid; */
    /*     ll crres = 0; */
    /*     int cc[2]{}; */
    /*     FOR(i,0,s.size()){ */
    /*         char ch; */
    /*         if(s[i] == '?'){ */
    /*             ch = rem-- > 0 ? whpref : whpref ^ 1; */
    /*         } */
    /*         else{ */
    /*             ch = s[i]; */
    /*             /1* crres += cost[s[i]] * cc[s[i]^1]; *1/ */
    /*             /1* ++cc[s[i]]; *1/ */
    /*         } */
    /*         /1* crres += cost[s[i]] * cc[s[i]^1]; *1/ */
    /*         /1* ++cc[s[i]]; *1/ */
    /*         // wa */
    /*         /1* crres += cost[ch] * cc[ch^1]; *1/ */
    /*         crres += 1ll * cost[ch] * cc[ch^1]; */
    /*         ++cc[ch]; */
    /*     } */
    /*     return crres; */
    /* }; */
    /* /1* while(low <= high){ *1/ */
    /* /1* array<ll,3> best; *1/ */
    /* /1* memset(best.data(), 127, 3 << 3); *1/ */
    /* ll best = LONG_LONG_MAX; */
    /* FOR(prefs,0,2){ */
    /*     int low = 0, high = cnt, mid, ans; */
    /*     while(low < high){ */
    /*     // le hoax */
    /*     /1* while(low <= high){ *1/ */
    /*         mid = (low+high)/2; */
    /*         /1* ll crres = f(mid,1); *1/ */
    /*         /1* ll pres = f(mid+1,1); *1/ */
    /*         /1* ll crres = f(mid+1,1); *1/ */
    /*         /1* ll pres = f(mid,1); *1/ */
    /*         ll crres = f(mid+1,prefs); */
    /*         ll pres = f(mid,prefs); */
    /*         /1* if(crres > pres){ *1/ */
    /*         if(crres < pres){ */
    /*             ans = mid + 1; */
    /*             /1* best = max(best,array<ll,3>{c}); *1/ */
    /*             /1* best = min(best,array<ll,3>{crres, 1, ans}); *1/ */
    /*             // wa */
    /*             /1* best = min(best,crres); *1/ */
    /*             low = mid + 1; */
    /*         } */
    /*         else{ */
    /*             high = mid; */
    /*         } */
    /*     } */
    /*     /1* best = min(best,f(ans,1)); *1/ */
    /*     best = min(best,f(ans,prefs)); */
    /* } */
    /* cout << f(ans,best[1]); */
    cout << best << '\n';
}