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
    int t;
    sc(t);
    while(t--){
        string s;
        getstr(s);
        sort(all(s));
        int n = s.size();
        map<char,int> mp;
        FORR(i,s)
            ++mp[i];
        bool d = 0;
        FORR(i,mp){
            if(i.e2 == 1){
                cout << i.e1;
                FORR(x,s){
                    if(x != i.e1)
                        cout << x;
                }
                cout << '\n';
                d = 1;
                break;
            }
        }
        if(d)
            continue;
        // aababaa -> can't with a; bbaaaaa; maybe mix case? -> idk ba idea
        // raczej; ale za to, can delay my chars to end -> bbaaaaaaaabab like
        // this -> or at least b4 any greater characters than own.
        // bbaaaaababcccc
        // bbaaaaaabcbccc better, and best.
        // -> till either greater char next in queue, or have to cause
        // (n-nxt+1)/2 < i.e2-2

        // baaaaabcb? another case?
        // -> interesting hmm.
        // baaaaaabab would be bad obv.
        // but...
        // baaaaaaabb is actually best.
        // unless...
        // abbbaaaaaa xd. -> can't be "ab" later on.
        // abbbaaaaaacc
        // better:aaaaacbbcaa
        //
        // abaaaaaacbbc now that's complex (can only do that with 3 chars).
        // -> Zawsze zaczynanie lowest charem (unless can have 0 f(t))
        // jak n/2 >= i.e2-1, to aabababa... wiadomo jak.
        // else za duo, i:
        // 1. have >= 3 chars:
        // abaaaaaacbbc 
        // 2. have 2 chars:
        // abbbaaaaaaaa
        // btw, hard edge case jak i.e2 == 2? aabbbbbbbb git zawsze wtedy.
        // so can only put 2nd b4, if 
        FORR(i,mp){
            // can 2 (1 actually, prev is 0) beg with this char.
            /* if(n/2 >= i.e2-1){ */
            string ss;
            FORR(x,s)
                if(x != i.e1)
                    ss += x;
            if(i.e2 == 2){
                cout << i.e1 << i.e1 << ss << '\n';
                d = 1;
            }
            else if((n-1+1)/2 >= i.e2-1){
                cout << i.e1;
                cout << i.e1;
                int remown = i.e2 - 2;
                auto it = ss.begin();
                int x = 2;
                /* while(it != ss.end() && *it < i.e1 && (n - (x + 1) + 1) / 2 >= i.e2 - 2){ */
                while(it != ss.end() && *it < i.e1 && (n - (x + 1) + 1) / 2 >= remown){
                    assert(0);
                    cout << *it++;
                    ++x;
                }
                /* for(int x = 2; x < n; ++x){ */
                /* } */
                for(; x < n; ++x){
                    /* if(remown){ */
                    if(x != 2 && remown){
                        cout << i.e1;
                        --remown;
                        ++x;
                    }
                    if(x < n)
                        cout << *it++;
                }
                assert(it == ss.end());
                assert(remown == 0);
                cout << '\n';
                d = 1;
            }
            else if(mp.size() >= 3){
                // abaaaaaacbbc 
                cout << i.e1;
                --i.e2;
                auto snd = next(mp.begin());
                cout << snd->e1;
                --snd->e2;
                while(i.e2--)
                    cout << i.e1;
                auto thr = next(snd);
                cout << thr->e1;
                --thr->e2;
                FORR(x,mp){
                    while(x.e2 > 0){
                        cout << x.e1;
                        --x.e2;
                    }
                }
                cout << '\n';
            }
            else{
                // abbbaaaaaaaa
                cout << i.e1;
                cout << ss;
                /* cout << string(i.e1,i.e2-1); */
                cout << string(i.e2-1,i.e1);
                cout << '\n';
            }
            d = 1;
            break;
        }
        if(!d){
            assert(mp.size() == 1);
            cout << s << '\n';
        }
        /* assert(d); */
        // ((n-1)+1)/2 >= cntx
    }
}