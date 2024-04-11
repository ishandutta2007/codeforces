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

ll h[300];
int palcnt(int beg, int end){ //exclusive!
    vector<ll> ss(h+beg,h+end);
    /* whatis(ss) */
    vector<ll> s(ss.size()*2);
    s[0] = -1;
    FOR(i,1,s.size()){
        if((i-1)&1) s[i] = -1;
        else s[i] = ss[(i-1)/2];
    }
    s.push_back(-1);
    /* int n = s.size(); */
    int n = s.size();
    /* vector<int> len(n + 1); */
    /* int l = 1, r = 1; */
    /* for(int i = 1; i <= n; i++){ */
    /*     len[i] = min(r - i, len[l + (r - i)]); */
    /*     while(s[i - len[i]] == s[i + len[i]]) ++len[i]; */
    /*     if(i + len[i] > r){ */
    /*         l = i - len[i]; */
    /*         r = i + len[i]; */
    /*     } */
    /* } */
    /* len.erase(begin(len)); */
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    /* whatis(d1) */
    /* whatis(len) */
    int ret = 0;
    FOR(i,0,n){
        /* ret += len[i]/2; */
        ret += d1[i]/2;
    }
    /* whatis(ret) */
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll A = 301;
    ll B = 1000000007;
    int p[300];
    p[0] = 1;
    FOR(i,1,300)
        p[i] = p[i-1]*A%B;
    int n,m;
    sc(n,m);
    int s[n][m];
    char c;
    FORR(i,s){
        FORR(x,i){
            getch(c);
            x = c-'a'+1;
        }
    }
    int ans = 0;
    int cnt[n][27];
    int odd[n];
    FOR(i,0,m){
        memset(cnt,0,sizeof cnt);
        memset(odd,0,sizeof odd);
        memset(h,0,sizeof h);
        FOR(x,i,m){
            vi brk;
            FOR(j,0,n){
                int wh = s[j][x];
                if(++cnt[j][wh] & 1) ++odd[j];
                else --odd[j];
                h[j] += p[wh];
                h[j] %= B;
                if(odd[j] > 1){
                    brk.pb(j);
                }
            }
            brk.pb(n);
            int pr = 0;
            FORR(j,brk){
                if(pr != j)
                    ans += palcnt(pr,j);
                pr = j+1;
            }
        }
    }
    cout << ans << '\n';
}