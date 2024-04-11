#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
#define N 1000001

bool isnum(string s){
    // thank god for the "01" sample case.
    if(s[0] == '0')
        return 0;
    FORR(i,s)
        if(!isdigit(i))
            return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    vector<pair<int, string>> unrl; // {0/1, wh}
    string crs;
    int crid;
    vector<pair<string,string>> res;
    set<int> frpre, frsuf;
    FORE(i,1,n)
        frpre.insert(i);
    frsuf = frpre;
    int cntpre = 0;
    /* vector<pair<int, string>> rel; */
    vector<string> xd;
    vector<pair<int, int>> rel;
    FOR(i,0,n){
        getstr(crs);
        sc(crid);
        xd.push_back(crs);
        // actually, 1 is for sample (pre), 0 for regular.
        // -> let's just xor.
        crid ^= 1;
        /* cntpre += crid == 0; */
        cntpre += crid == 0;
        /* if(isnum(crs) && stoi(crs) <= n && stoi(crs) >= 0){ */
        if(isnum(crs) && stoi(crs) <= n && stoi(crs) >= 1){
            frpre.erase(stoi(crs));
            frsuf.erase(stoi(crs));
            rel.push_back({crid, stoi(crs)});
        }
        else{
            unrl.push_back({crid, crs});
        }
    }
    /* whatis(rel) */
    /* whatis(unrl) */
    whatis(cntpre)
    FORE(i,1,cntpre)
        frsuf.erase(i);
    FORE(i,cntpre+1,n)
        frpre.erase(i);
    whatis("x0")
    /* vector<pi> mism; */
    vector<int> mism[2];
    FORR(i,rel){
        if(i.e1 == 0){
            if(i.e2 <= cntpre){
            }
            else{
                /* mism[i.e1].pb(i.e2); */
                mism[i.e1^1].pb(i.e2);
            }
        }
        else{
            if(i.e2 > cntpre){
            }
            else{
                /* mism.pb(i); */
                // i.e1 -> where currently is, so rev.
                mism[i.e1^1].pb(i.e2);
            }
        }
    }
    whatis("x1")
    bool c = 1;
    for(;c;){
        c = 0;
        if(mism[0].size()){
            if(frsuf.size()){
                int cr = mism[0].back();
                mism[0].pop_back();
                res.push_back({to_string(cr), to_string(*frsuf.begin())});
                frsuf.erase(frsuf.begin());
                frpre.insert(cr);
                c = 1;
            }
        }
        if(mism[1].size()){
            if(frpre.size()){
                int cr = mism[1].back();
                mism[1].pop_back();
                res.push_back({to_string(cr), to_string(*frpre.begin())});
                frpre.erase(frpre.begin());
                frsuf.insert(cr);
                c = 1;
            }
        }
    }
    whatis("x2")
    if(mism[0].size() || mism[1].size()){
        sort(all(xd));
        string wh;
        /* for(;;){ */
        // 2 many loops.
        FOR(i,0,200000){
            wh = "";
            int ii = i;
            FOR(x,0,6){
                wh += 'a' + ii % 26;
                ii /= 26;
            }
            if(!binary_search(all(xd), wh))
                break;
        }
            // xd.
            /* if(!binary_search(all(xd), wh)) */
            /*     break; */
        /* } */
        assert(mism[0].size() && mism[1].size());
        int cr = mism[0].back();
        mism[0].pop_back();
        res.push_back({to_string(cr), wh});
        /* unrl.push_back({0, wh}); */
        unrl.push_back({1, wh}); // 1, bo mism 0 by w 0 chce byc w 1.
        frpre.insert(cr);
    }
    whatis("x3")
    c = 1;
    for(;c;){
        c = 0;
        if(mism[0].size()){
            if(frsuf.size()){
                int cr = mism[0].back();
                mism[0].pop_back();
                res.push_back({to_string(cr), to_string(*frsuf.begin())});
                frsuf.erase(frsuf.begin());
                frpre.insert(cr);
                c = 1;
            }
        }
        if(mism[1].size()){
            if(frpre.size()){
                int cr = mism[1].back();
                mism[1].pop_back();
                res.push_back({to_string(cr), to_string(*frpre.begin())});
                frpre.erase(frpre.begin());
                frsuf.insert(cr);
                c = 1;
            }
        }
    }
    whatis("x4")
    assert(mism[0].empty() && mism[1].empty());
    FORR(i,unrl){
        if(i.e1 == 0){
            assert(frpre.size());
            string cr = i.e2;
            res.push_back({cr, to_string(*frpre.begin())});
            frpre.erase(frpre.begin());
        }
        else{
            assert(frsuf.size());
            string cr = i.e2;
            res.push_back({cr, to_string(*frsuf.begin())});
            // bruh.
            /* frpre.erase(frsuf.begin()); */
            frsuf.erase(frsuf.begin());
        }
    }
    cout << res.size() << '\n';
    FORR(i,res){
        cout << "move " << i.e1 << ' ' << i.e2 << '\n';
    }
}