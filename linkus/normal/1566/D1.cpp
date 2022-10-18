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

int ans;

inline void merge_sort(pair<int,int> *beg, pair<int,int> *end){
    if(beg + 1 == end) return;
    int32_t allsize = end-beg;
    int32_t size1 = allsize >> 1;
    int32_t size2 = size1 + (allsize&1);
    pair<int,int> *middle = beg+size1;
    merge_sort(beg,middle);
    merge_sort(middle,end);
    pair<int,int> vec1[size1];
    pair<int,int> vec2[size2];
    copy_n(beg,size1,vec1);
    copy_n(middle,size2,vec2);
    auto it1 = vec1;
    auto it2 = vec2;
    auto end1 = vec1+size1;
    auto end2 = vec2+size2;
    while(beg < end){
        if(it1->e2 <= it2->e2){ //Sortowanie wedle docelowej pozycji
            *beg++ = *it1;
            if(++it1 == end1){
                while(beg < end)
                    *beg++ = *it2++;
                break;
            }
        }
        else{
            *beg++ = *it2;
            ans += end1-it1; //Zliczanie zamian
            if(++it2 == end2){
                while(beg < end)
                    *beg++ = *it1++;
                break;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int nnn,m;
        sc(nnn,m);
        int a[m];
        GET(a);
        FORR(i,a)
            --i;
        reverse(a,a+m);
        ans = 0;
        pair<int,int> arr[m];
        /* int ilesame = 0; */
        vi srt(a, a+m);
        sort(all(srt));
        map<int,int> cnt;
        FOR(i,0,m){
            /* if(i && a[i-1] == a[i]){ */
            /*     /1* ++ilesame; *1/ */
            /* } */
            /* else{ */
            /*     ilesame = 0; */
            /* } */
            arr[i].e1 = a[i];
            int sth = lower_bound(all(srt), a[i]) - srt.begin();
            /* arr[i].e2  = sth + ilesame; */
            // kozak.
            arr[i].e2  = sth + cnt[a[i]]++;;
        }
        merge_sort(arr, arr + m);
        cout << ans << '\n';
        // gj....
        /* FORR(i,a) */
        /*     i = min(i, m - 1); */
        /* bool fre[m]; */
        /* /1* memset(fre,0,sizeof fre); *1/ */
        /* memset(fre,1,sizeof fre); */
        /* int res = 0; */
        /* FOR(i,0,m){ */
        /*     for(int x = a[i]; x >= 0; --x){ */
        /*         if(fre[x]){ */
        /*             bool kk = 1; */
        /*             vi rem; */
        /*             FOR(j,i + 1, m){ */
        /*                 rem.push_back(a[j]); */
        /*             } */
        /*             sort(all(rem)); */
        /*             set<int> fest; */
        /*             FOR(x,0,m) */
        /*                 if(fre[x]) */
        /*                     fest.insert(x); */
        /*             FORR(j,rem){ */
        /*                 auto it = fest.upper_bound(j); */
        /*                 if(it == fest.begin()){ */
        /*                     kk = 0; */
        /*                     break; */
        /*                 } */
        /*                 fest.erase(--it); */
        /*             } */
        /*             whatis(kk) */
        /*             if(kk){ */
        /*                 fre[x] = 1; */
        /*                 res += accumulate(fre,fre + x, 0); */
        /*                 break; */
        /*             } */
        /*         } */
        /*     } */
        /* } */
        /* cout << res << '\n'; */
    }
}