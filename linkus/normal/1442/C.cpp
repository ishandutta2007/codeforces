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
    int n,m;
    sc(n,m);
    vi adj[2][n];
    int f,s;
    FOR(i,0,m){
        sc(f,s);
        --f,--s;
        adj[0][f].pb(s);
        adj[1][s].pb(f);
    }
    /* pair<int,int> len; */
    /* pair<int,int> best[n]; // lowest cost */
    // best od obu ph wsm!!
    /* pair<int,int> best[2][n]; // lowest cost */
    pair<int,int> best[2][200000]; // lowest cost
    memset(best,127,sizeof best);
    /* best[0] = {0,0}; */
    best[0][0] = {0,0};
    /* vi nx = {0}; */
    vi nx[2] = {{0},{0}};
    int ph = 0;
    /* auto lt = [&](int f, int s){ */
    /* auto lt = [&](const pi &f, int s){ */
    auto lt = [&](const pi &f, const pi &s){
        int mxpow2 = max(f.e1, s.e1);
        /* if(mxpow2 > 20){ */
        if(mxpow2 > 25){
            if(f.e1 == s.e1){
                return f.e2 < s.e2;
            }
            else{
                // zawsze first arg bdzie z .e1 >= ni drugiego
                /* return false; */
                // wsm poza infem z bega -> check
                return f.e1 < s.e1;
            }
        }
        else{
            // could mem?
            return (1 << f.e1) + f.e2 < (1 << s.e1) + s.e2;
        }
        /* int mxpow2 = max(best[f].e1, best[s].e1); */
        /* if(mxpow2 > 20){ */
        /*     if(best[f].e1 == best[s].e1){ */
        /*         return best[f].e2 < best[s].e2; */
        /*     } */
        /*     else{ */
        /*         // zawsze first arg bdzie z .e1 >= ni drugiego */
        /*         return false; */
        /*     } */
        /* } */
        /* else{ */
        /*     // could mem? */
        /*     return (1 << best[f].e1) + best[f].e2 < (1 << best[s].e1) + best[s].e2; */
        /* } */
    };
    // 2 layery musz trzyma?
    // initially 0 w obu layarach
    int cnt = 0;
    for(;;){
        whatis(nx[ph])
        /* if(nx.empty()) break; */
        if(nx[ph].empty()) break;
        // w kocu no new best surely

        // sort nx by cost (in best)
        // compare against normal queue
        // equal .e1 in best maj wic ez comp
        /* vi cr = nx; */
        /* sort(all(cr),[&](int f, int s){return best[f].e2 < best[s].e2;}); */
        /* // just in case */
        /* cr.erase(unique(all(cr)),cr.end()); */
        /* nx.clear(); */
        /* vi cr = nx; */
        vi &cr = nx[ph];
        /* sort(all(cr),[&](int f, int s){return best[f].e2 < best[s].e2;}); */
        // sorry, unimplemented:
        sort(all(cr),[&](int f, int s){return best[ph][f].e2 < best[ph][s].e2;});
        /* if(ph == 0){ */
        /*     sort(all(cr),[&](int f, int s){return best[0][f].e2 < best[0][s].e2;}); */
        /* } */
        /* else{ */
        /*     sort(all(cr),[&](int f, int s){return best[1][f].e2 < best[1][s].e2;}); */
        /* } */
        // just in case
        cr.erase(unique(all(cr)),cr.end());
        // 0 initowe though
        // -> clear pod koniec wasny
        /* nx[ph^1].clear(); */
        auto it = cr.begin();
        queue<int> qu;
        while(!qu.empty() || it != cr.end()){
            // .e1 equal tu te wic ez
            int v;
            if(qu.empty() || (it != cr.end() && best[ph][*it].e2 < best[ph][qu.front()].e2)){
                v = *it;
                ++it;
            }
            else{
                v = qu.front();
                qu.pop();
            }
            /* pi nwds = {best[v].e1, best[v].e2 + 1}; */
            // cnt == best[v].e1 || cnt == best[v].e1 + 1
            pi nwds = {cnt, best[ph][v].e2 + 1};
            /* pi nwdsp1 = {cnt + 1, best[ph][v].e2 + 1}; */
            whatis(v)
            whatis(nwds)
            // jeszcze do siebie samego instant?
            // -> tam nie trzeba wsm
            pi nwdsp1 = {cnt + 1, best[ph][v].e2};
            if(lt(nwdsp1, best[ph^1][v])){
                // -> rozny .e1?
                // (z cnt + 1 tu?)
                // raczej ta?
                /* best[ph^1][i] = nwds; */
                best[ph^1][v] = nwdsp1;
                /* qu.push(i); */
                // once per each -> could add some vis?
                /* nx.push_back(i); */
                nx[ph^1].push_back(v);
            }
            FORR(i,adj[ph][v]){
                whatis(i)
                /* if(lt(nwds, i)){ */
                // w teorii pod oba wsm
                // :? such divide
                if(lt(nwds, best[ph][i])){
                    best[ph][i] = nwds;
                    qu.push(i);
                    // once per each -> could add some vis?
                    /* nx.push_back(i); */
                    /* nx[ph^1].push_back(i); */
                }
                /* if(lt(nwds, best[ph^1][i])){ */
                /* if(lt(nwdsp1, best[ph^1][i])){ */
                /*     // -> rozny .e1? */
                /*     // (z cnt + 1 tu?) */
                /*     // raczej ta? */
                /*     /1* best[ph^1][i] = nwds; *1/ */
                /*     best[ph^1][i] = nwdsp1; */
                /*     /1* qu.push(i); *1/ */
                /*     // once per each -> could add some vis? */
                /*     /1* nx.push_back(i); *1/ */
                /*     nx[ph^1].push_back(i); */
                /* } */
            }
        }
        ph ^= 1;
        ++cnt;
        cr.clear();
    }
    whatis(best[n-1])
    const ll mod = 998244353;
    // 2^(best[n-1].e1) - 1 + best[n-1].e2
    int ind = (lt(best[0][n-1], best[1][n-1]) ? 0 : 1);
    ll res = 1;
    /* FOR(i,0,best[n-1].e1){ */
    FOR(i,0,best[ind][n-1].e1){
        res <<= 1;
        res %= mod;
    }
    whatis(res)
    --res;
    /* res += best[n-1].e2; */
    res += best[ind][n-1].e2;
    /* res = (res % mod + res) % mod; */
    res = (res % mod + mod) % mod;
    cout << res << '\n';
    // WA 7 :c
}