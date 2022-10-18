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
#define N 100005

ull len[N];
string res;

void rec(int n, ull lef){
    if(len[n] < lef){
        res += '.';
        return;
    }
    if(n == 0){
        res += "What are you doing at the end of the world? Are you busy? Will you save us?"[lef-1];
        return;
    }
    if(lef <= 34){
        res += "What are you doing while sending \""[lef-1];
        return;
    }
    lef -= 34;
    if(lef <= len[n-1]){
        rec(n-1,lef);
        return;
    }
    lef -= len[n-1];
    if(lef <= 32){
        res += "\"? Are you busy? Will you send \""[lef-1];
        return;
    }
    lef -= 32;
    if(lef <= len[n-1]){
        rec(n-1,lef);
        return;
    }
    lef -= len[n-1];
    if(lef <= 2){
        res += "\"?"[lef-1];
        return;
    }
    lef -= 2;
    assert(0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    len[0] = 75;
    FOR(i,1,N){
        len[i] = 34+len[i-1]+32+len[i-1]+2;
        if(i >= 60){
            len[i] = LONG_LONG_MAX;
        }
        /* whatis(i) */
        /* whatis(len[i]) */
        /* if(len[i] > 1e17){ */
        /*     whatis(i) */
        /*     whatis(len[i]) */
        /* } */
    }
    /* whatis(len[N-1]) */
    int q;
    sc(q);
    while(q--){
        ull n,k;
        sc(n,k);
        /* if(n >= 60){ */
        /*     /1* if(k <= 33){ *1/ */
        /*         /1* continue; *1/ */
        /*     /1* } *1/ */
        /*     /1* k -= 33; *1/ */
        /*     res += "What are you doing while sending \""[(k-1)%34]; */
        /* } */
        /* else{ */
            rec(n,k);
        /* } */
    }
    cout << res<< '\n';
}