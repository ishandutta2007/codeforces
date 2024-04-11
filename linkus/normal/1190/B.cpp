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

int n;

bool rec(vi pl){
    /* if(pl.size() == 1 && pl[0] == 0) return 0; */
    sort(all(pl));
    if(pl.back() == 0) return 0;
    bool w = 0;
    FORR(i,pl){
        if(i){
            --i;
            set<int> st;
            FORR(i,pl)
                st.insert(i);
            if(st.size() == pl.size()){
                w |= !rec(pl);
            }
            ++i;
        }
    }
    return w;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    sc(n);
    int a[n];
    GET(a);
    ll s = 0;
    map<int,int> mp;
    FORR(i,a){
        ++mp[i];
        s += i;
    }
    bool ans = 1; //czy zacz
    /* if(n == 1 && a[0] == 0){ */
    /*     REE("cslnb") */
    /* } */
    ll rem = (ll)n*(n-1)/2;
    ans = (s-rem)%2;
    if(mp.size() == n){
        ans = (s-rem)%2;
        /* if(*mp.rbegin() == n-1){ */
        /* } */
    }
    else if(mp.size()+1 < n){
        ans = 0;
    }
    else{
        FORR(i,mp){
            if(i.e2 == 2){
                if(!i.e1){
                    ans = 0;
                    break;
                }
                --i.e2;
                ++mp[i.e1-1];
                if(mp.size() != n){
                    ans = 0;
                    break;
                }
                /* --s; */
                /* ans = s%2 == 1; */
                break;
            }
        }
    }
    /* FOR(i,0,8){ */
    /*     FOR(x,0,8){ */
    /*         FOR(j,0,8){ */
    /*             FOR(c,0,8){ */
    /*             n = 4; */
    /*             vi pl = {i,x,j,c}; */
    /*             bool a1 = rec(pl); */
    /*             /1* /2* cout << rec(pl) << ' '; *2/ *1/ */
    /*             /1* whatis(vector<int>({i,x,j})) *1/ */
    /*                 whatis(pl); */
    /*             /1* whatis(rec(pl)) *1/ */
    /*             /1* if(i != x && j != x && i != j ){ *1/ */
    /*             /1*     assert(rec(pl) == ((i+x+j)%2==0)); *1/ */
    /*             /1* } *1/ */
    /*             /1* else{ *1/ */
    /*             /1* } *1/ */
    /*             vi a = pl; */
    /*             ll s = 0; */
    /*             map<int,int> mp; */
    /*             FORR(i,a){ */
    /*                 ++mp[i]; */
    /*                 s += i; */
    /*             } */
    /*             bool ans = 1; //czy zacz */
    /*             /1* if(n == 1 && a[0] == 0){ *1/ */
    /*             /1*     REE("cslnb") *1/ */
    /*             /1* } *1/ */
    /*             ll rem = n*(n-1)/2; */
    /*             ans = (s-rem)%2; */
    /*             if(mp.size() == n){ */
    /*                 ans = (s-rem)%2; */
    /*                 /1* if(*mp.rbegin() == n-1){ *1/ */
    /*                 /1* } *1/ */
    /*             } */
    /*             else if(mp.size()+1 < n){ */
    /*                 ans = 0; */
    /*             } */
    /*             else{ */
    /*                 FORR(i,mp){ */
    /*                     if(i.e2 == 2){ */
    /*                         if(!i.e1){ */
    /*                             ans = 0; */
    /*                             break; */
    /*                         } */
    /*                         --i.e2; */
    /*                         ++mp[i.e1-1]; */
    /*                         if(mp.size() != n){ */
    /*                             ans = 0; */
    /*                             break; */
    /*                         } */
    /*                         /1* --s; *1/ */
    /*                         /1* ans = s%2 == 1; *1/ */
    /*                         break; */
    /*                     } */
    /*                 } */
    /*             } */
    /*             /1* if(n == 1){ *1/ */
    /*             /1*     ans = a[0]%2; *1/ */
    /*             /1* } *1/ */
    /*             /1* if(n == 1 && a[0] == 0){ *1/ */
    /*             /1*     /2* ans = 0; *2/ *1/ */
    /*             /1*     /2* /3* REE("cslnb") *3/ *2/ *1/ */
    /*             /1* } *1/ */
    /*             /1* if(n == 1 && a[0] == 1){ *1/ */
    /*             /1*     /2* ans = 1; *2/ *1/ */
    /*             /1*     /2* /3* REE("cslnb") *3/ *2/ *1/ */
    /*             /1* } *1/ */
    /*             whatis(ans) */
    /*             assert(a1 == ans); */
    /*         } */
    /*         } */
    /*         /1* cout << '\n'; *1/ */
    /*     } */
    /*     /1* cout << '\n'; *1/ */
    /* } */
    cout << (ans?"sjfnb":"cslnb");
}