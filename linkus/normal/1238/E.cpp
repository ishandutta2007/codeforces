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
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//ll dp[1<<20][20]; //{res,tabelka z tymi na r,discardujesz swoje na wejsciu,dodajesz na wyjsciu te spoza maska}
ll dp[1<<20]; //{res,tabelka z tymi na r,discardujesz swoje na wejsciu,dodajesz na wyjsciu te spoza maska}
int n,m;
int xd[20][20];
//int cntp[1<<20][20]; //na prawo
int add[1<<20];
int cadd;
int cnt[20];
bool vis[1<<20];
void recp(int mask){
    //whatis(mask)
    //whatis(cr)
    vis[mask] = 1;
    FOR(i,0,m){
        int nxm = mask | (1 << i);
        if(vis[nxm]) continue;
        //int add = 0; //rozmiar zbioru
        int cr = i;
        int ilown = cnt[cr];
        cnt[cr] -= ilown;
        cadd -= ilown;
        FOR(i,0,m){
            int nxm = mask | 1 << i;
            if(nxm == mask) continue;
            cnt[i] += xd[cr][i];
            cadd += xd[cr][i];
        }
        /*FOR(i,0,m){
            cntp[nxm][i] = cnt[i];
        }*/
        add[nxm] = cadd;
        recp(nxm);
        /*FOR(i,0,m){
            add += cnt[i];
        }*/
        /*int ndp = dp[mask][cr];
        if(dp[nxm][i] > ndp+add){
            dp[nxm][i] = ndp+add;
            rec(nxm,i);
        }*/
        FOR(i,0,m){
            int nxm = mask | 1 << i;
            if(nxm == mask) continue;
            cnt[i] -= xd[cr][i];
            cadd -= xd[cr][i];
        }
        cnt[cr] += ilown;
        cadd += ilown;
    }
}

//void rec(int mask, int cr){
void rec(int mask){
    //whatis(mask)
    //whatis(cr)
    //int add = 0; //rozmiar zbioru
    /*FOR(i,0,m){
        cnt[i] = cntp[mask][i];;
    }
    assert(cnt[cr] == 0);*/
    /*int ilown = cnt[cr];
    cnt[cr] -= ilown;*/
    /*FOR(i,0,m){
        int nxm = mask | 1 << i;
        if(nxm == mask) continue;
        cnt[i] += xd[cr][i];
    }*/
    /*FOR(i,0,m){
        add += cnt[i];
    }*/
    FOR(i,0,m){
        int nxm = mask | (1 << i);
        if(nxm == mask) continue;
        //ll ndp = dp[mask][cr];
        ll ndp = dp[mask];
        //if(dp[nxm][i] > ndp+add[mask]){
            //dp[nxm][i] = ndp+add[mask];
        if(dp[nxm] > ndp+add[mask]){
            dp[nxm] = ndp+add[mask];
            //rec(nxm,i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m);
    string s;
    getstr(s);
    FORR(i,s)
        i -= 'a';
    memset(xd,0,sizeof xd);
    FOR(i,1,n){
        int mn = min(s[i-1],s[i]);
        int mx = max(s[i-1],s[i]);
        if(mn == mx) continue;
        ++xd[mn][mx];
        ++xd[mx][mn];
    }
    memset(dp,127,sizeof dp);
    recp(0);
    FOR(i,0,m){
        dp[1<<i] = 0;
        //rec(1 << i, i);
    }
    FOR(i,0,1<<m){
        FOR(x,0,m){
            if(i & (1 << x)){
                rec(i);
                break;
            }
                //rec(i,x);
        }
    }
    /*ll res = (ll)1 << ((ll)62);
    FOR(i,0,m)
        res = min(res,(ll)dp[(1<<m)-1][i]);*/
    ll res = dp[(1<<m)-1];
    //res += size tabelki; wywalasz z tabelki rowne nextowi
    cout << res << '\n';
}