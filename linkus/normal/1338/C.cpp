#include <stdio.h>
#include <algorithm>
#include <vector>
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
    /* vi ret; */
    /* set<int> st; */
    /* static bool st[44000]; */
    /* int n = 20; */
    /* FOR(i,0,n){ */
    /*     vi pos; */
    /*     FOR(x,1,200){ */
    /*     FOR(j,x+1,200){ */
    /*     FOR(k,j+1,200){ */
    /*         if(st[x] || st[j] || st[k]) continue; */
    /*         if(x^j^k) continue; */
    /*         if(pos.empty() || vector<int>({x,j,k}) < pos){ */
    /*             pos = {x,j,k}; */
    /*         } */
    /*     } */
    /*     } */
    /*     } */
    /*     ret.pb(pos[0]); */
    /*     ret.pb(pos[1]); */
    /*     ret.pb(pos[2]); */
    /*     FORR(i,pos) */
    /*         st[i] = 1; */
    /*         /1* st.insert(i); *1/ */
    /* } */
    /* whatis(ret) */
    /* /1* FOR(i,0,21){ *1/ */
    /* /1*     whatis(i+1) *1/ */
    /*     whatis(bitset<10>(ret[i])) */
    /* } */
    /* int nn = 5; */
        vi ress;
    int opp[4] = {}; //jakie b dla a
    opp[0] = 0;
    opp[1] = 2;
    opp[2] = 3;
    opp[3] = 1;
    int t;
    sc(t);
    while(t--){
        ll crr;
        sc(crr);
        int mod = (crr-1) % 3;
        ll nn = (crr-1) / 3;
        if(!nn){
            /* ress.pb(1 + mod); */
            cout << 1+mod << '\n';
            /* cout << "01\n"; */
        }
        else{
            ll cr = nn-1;
            ll len = 1;
            ll dec = 4;
            while(cr >= dec){
                cr -= dec;
                dec <<= 2;
                ++len;
            }
            /* cr <<= 2; */
            string res;
            int xd = len;
            for(;len > 0;cr /= 4, --len){
                string ss = bitset<2>(cr).to_string();
                if(mod == 1){
                    ss = bitset<2>(opp[cr&3]).to_string();
                }
                else if(mod == 2){
                    ss = bitset<2>(cr^opp[cr&3]).to_string();
                }
                reverse(all(ss));
                res += ss;
                /* whatis(bitset<2>(cr).to_string()) */
            }
            reverse(all(res));
            if(mod == 0)
                res = "1" + res;
            else if(mod == 1)
                res = "10" + res;
            else if(mod == 2)
                res = "11" + res;
            /* ull numix = bitset<64>(res).to_ullong(); */
            cout << bitset<64>(res).to_ullong() << '\n';
            /* whatis(res) */
            /* ress.pb(numix); */
        }
    }
    /* whatis(ress) */
    //4 kombi na kazda z trzech, co 4^n (^(log4n-2))
    //1->assume its a -> set it mod 3 to 1 or sth, keep additional flag
    //2->while rem >= 4 -> rem /= 4, up by 2
    //first 2 -> % 4 na pae (od 0)
    //1-> get len? -> ezer
    //for said len ->  -= suma 4^n? n < len? (4+16+...)
    //while n-nxt >= 0 -> dec, ez
    //od 0 -> ez?
    //01
    //100 (0)
    //101 (1)
    //110 (...)
    //111
    //10000 (4)
    //10001 (5)
    //10010 (6)
    //10011 (7)
    //10100 (8)
    //...
    //1000000 (20)
    /* vi xd[3]; */
    /* FOR(i,0,ret.size()){ */
    /*     xd[i%3].pb(ret[i]); */
    /* } */
    /* whatis(xd[0]) */
    /* FOR(i,0,25) */
    /*     /1* whatis(bitset<10>(xd[0][i])) *1/ */
    /*     whatis(bitset<10>(ret[i])) */
    /* /1* FOR(i,0,3) *1/ */
    /*     whatis(xd[i]) */
    /* vi d[3]; */
    /* FOR(i,1,3){ */
    /*     d[i] = {0}; */
    /*     FOR(x,1,xd[i].size()){ */
    /*         d[i].pb(xd[i][x]-xd[i][x-1]); */
    /*     } */
    /*     whatis(d[i]) */
    /* } */
    /* vi l[3]; */
    /* FOR(i,1,3){ */
    /*     FOR(x,1,d[i].size()){ */
    /*         if(x%4 == 1) */
    /*             l[i].pb(d[i][x]); */
    /*     } */
    /*     whatis(l[i]) */
    /* } */
}