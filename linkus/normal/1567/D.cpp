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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int s,n;
        sc(s,n);
        /* vector<int> res = {s}; */
        vector<string> res = {to_string(s)};
        while(res.size() < n){
            bool kk = 0;
            FOR(i,0,res[0].size()){
                /* if(res[0][i] != '1'){ */
                /* if(res[0][i] != '1' && res[0][i] != '0'){ */
                if((i == 0 && res[0][i] != '1') || (i != 0 && res[0][i] != '0')){
                    --res[0][i];
                    res.push_back("1" + string(res[0].size() - i - 1, '0'));
                    kk = 1;
                    break;
                }
            }
            /* assert(0); */
            // try 2 cases, rozbicie smallest > 10, rozbicie 10s.
            // or po prostu just 10s, gdy starczy ich rozbicie.
            if(!kk)
                break;
        }
        string cr = "10";
        while(res.size() < n){
            // w8, moze byc min wyzszy od 100 przeciez..
            xd:
            auto it3 = find(all(res), cr);
            if(it3 == res.end()){
                cr += '0';
                goto xd;
            }
            else{
                res.erase(it3);
            }
            /* int rem = 100; */
            int rem = stoi(cr);
            /* FOR(x,0,min(rem,res.size()-n)){ */
            int it = min<int>(rem, n - res.size());
            /* FOR(x,0,it){ */
            while(rem > 0){
                // lepiej w dziesitkach.
                int wh;
                /* if(n - res.size() > 1) */
                /*     wh = 1; */
                /* else */
                /*     wh = rem; */
                /* whatis(rem) */
                /* whatis(n-res.size()) */
                if(n - res.size() == 1)
                    wh = rem;
                /* else if(n - res.size() - 1 <= rem - 10) */
                // xd. najs conv.
                // unrolling for the performance reasons obv.
                /* else if(n - (int)res.size() - 1 <= rem - 10000000000) */
                /*     wh = 10000000000; */
                else if(n - (int)res.size() - 1 <= rem - 1000000000)
                    wh = 1000000000;
                else if(n - (int)res.size() - 1 <= rem - 100000000)
                    wh = 100000000;
                else if(n - (int)res.size() - 1 <= rem - 10000000)
                    wh = 10000000;
                else if(n - (int)res.size() - 1 <= rem - 1000000)
                    wh = 1000000;
                else if(n - (int)res.size() - 1 <= rem - 100000)
                    wh = 100000;
                else if(n - (int)res.size() - 1 <= rem - 10000)
                    wh = 10000;
                else if(n - (int)res.size() - 1 <= rem - 1000)
                    wh = 1000;
                else if(n - (int)res.size() - 1 <= rem - 100)
                    wh = 100;
                else if(n - (int)res.size() - 1 <= rem - 10)
                    wh = 10;
                else
                    wh = 1;
                whatis(wh)
                res.push_back(to_string(wh));
                rem -= wh;
            }
        }
        /* int cnt10 = 0; */
        /* FORR(i,res) */
        /*     cnt10 += i == "10"; */
        /* if(cnt10 * 9 >= n - res.size()){ */
        /*     while(res.size() < n){ */
        /*         res.erase(find(all(res), "10")); */
        /*         int rem = 10; */
        /*         /1* FOR(x,0,min(rem,res.size()-n)){ *1/ */
        /*         int it = min<int>(rem, n - res.size()); */
        /*         /1* FOR(x,0,it){ *1/ */
        /*         while(rem > 0){ */
        /*             int wh; */
        /*             if(n - res.size() > 1) */
        /*                 wh = 1; */
        /*             else */
        /*                 wh = rem; */
        /*             res.push_back(to_string(wh)); */
        /*             rem -= wh; */
        /*         } */
        /*     } */
        /* } */
        /* else{ */
        /*     while(res.size() < n){ */
        /*         // w8, moze byc min wyzszy od 100 przeciez.. */
        /*         res.erase(find(all(res), "100")); */
        /*         int rem = 100; */
        /*         /1* FOR(x,0,min(rem,res.size()-n)){ *1/ */
        /*         int it = min<int>(rem, n - res.size()); */
        /*         /1* FOR(x,0,it){ *1/ */
        /*         while(rem > 0){ */
        /*             // lepiej w dziesitkach. */
        /*             int wh; */
        /*             /1* if(n - res.size() > 1) *1/ */
        /*             /1*     wh = 1; *1/ */
        /*             /1* else *1/ */
        /*             /1*     wh = rem; *1/ */
        /*             /1* whatis(rem) *1/ */
        /*             /1* whatis(n-res.size()) *1/ */
        /*             if(n - res.size() == 1) */
        /*                 wh = rem; */
        /*             /1* else if(n - res.size() - 1 <= rem - 10) *1/ */
        /*             // xd. najs conv. */
        /*             else if(n - (int)res.size() - 1 <= rem - 10) */
        /*                 wh = 10; */
        /*             else */
        /*                 wh = 1; */
        /*             whatis(wh) */
        /*             res.push_back(to_string(wh)); */
        /*             rem -= wh; */
        /*         } */
        /*     } */
        /* } */
        FORR(i,res)
            cout << i << ' ';
        cout << '\n';
    }

}