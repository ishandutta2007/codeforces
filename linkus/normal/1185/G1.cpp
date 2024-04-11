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

int n,t;
/* vector<pi> s[3]; */
pi a[15];
int ans;

/* bool ban[15]; */
/* void rec(int rem, int b){ */
/*     if(!rem){ */
/*         ++ans; */
/*         return; */
/*     } */
/*     FOR(i,0,3){ */
/*         if(i == b) continue; */
/*         FORR(x,s[i]){ */
/*             if(!ban[x.e2] && x.e1 <= rem){ */
/*                 ban[x.e2] = 1; */
/*                 rec(rem-x.e1,i); */
/*                 ban[x.e2] = 0; */
/*             } */
/*         } */
/*     } */
/* } */

int cc[3]; //count off
int xd[16][16][16];
ll sil[16];
int mod = 1e9+7;
vi ind;
void rec(int rem, int k){
    if(k == n){
        if(rem) return;
        /* whatis(ind) */
        /* whatis("xdxd") */
        int lol[3] = {cc[0],cc[1],cc[2]};
        sort(lol,lol+3);
        if(lol[2]-1 > lol[1]+lol[0]) return;
        if(~xd[lol[0]][lol[1]][lol[2]]){
            ans += xd[lol[0]][lol[1]][lol[2]];
            if(ans > mod) ans -= mod;
            return;
        }
        string s;
        s += string(lol[0],'a');
        s += string(lol[1],'b');
        s += string(lol[2],'c');
        /* whatis(s) */
        ll wow = 0;
        do{
            ++wow;
            bool g = 1;
            FOR(i,1,s.size()){
                if(s[i] == s[i-1]){
                    g = 0;
                    --wow;
                    break;
                }
            }
            /* whatis(s) */
            /*     whatis(g) */
        }while(next_permutation(all(s)));
        /* whatis(s) */
        /* whatis(wow) */
        FOR(i,0,3)
            wow *= sil[lol[i]], wow %= mod;
        /* whatis(wow) */
        ans += xd[lol[0]][lol[1]][lol[2]] = wow;
        if(ans > mod) ans -= mod;
        return;
    }
    /* whatis(k) */
    /* whatis(rem) */
    if(a[k].e1 <= rem){
        ++cc[a[k].e2];
        rec(rem-a[k].e1,k+1);
        --cc[a[k].e2];
    }
    rec(rem,k+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(xd,-1,sizeof xd);
    sc(n,t);
    sil[0] = 1;
    FOR(i,1,16)
        sil[i] = sil[i-1]*i, sil[i] %= mod;
    FOR(i,0,n){
        int tt,l;
        sc(l,tt);
        --tt;
        /* s[tt].pb({l,i}); */
        a[i] = {l,tt};
    }
    /* rec(t,-1); */
    rec(t,0);
    cout << ans << '\n';
}