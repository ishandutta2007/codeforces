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


/* int arr[300007]; */
/* int deq[300007]; */
pi deq[300007];
int l = 0, r = 0;

void ins(int el, int pos){
    // cache unfriendly much?
    /* while(l != r && arr[deq[r-1]] >= arr[pos]) */
    while(l != r && deq[r-1].e2 >= el)
        --r;
    /* deq[r++] = {pos, el}; */
    // cache friendlier much?
    /* while(l != r && arr[deq[r-1]] >= el) */
    /*     --r; */
    deq[r++] = {pos, el};
    // very slight improvement
    /* while(deq.size() && deq.back().e2 >= el) */
    /*     deq.pop_back(); */
    /* deq.push_back({pos, el}); */
}

// hmm double var
/* int get(int l){ */
    /* while(l != r && deq[l].e1 < l) */
    /*     ++l; */
int get(int ll){
    while(l != r && deq[l].e1 < ll)
        ++l;
    return deq[l].e2;
    /* while(l != r && deq[l] < ll) */
    /*     ++l; */
    /* return arr[deq[l]]; */
    /* while(deq.size() && deq.front().e1 < ll) */
    /*     deq.pop_front(); */
    /* return deq.front().e2; */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        bool ile[n];
        // ????
        whatis(n)
        memset(ile,0,n);
        bool res[n];
        memset(res,0,n);
        FORR(i,a){
            --i;
            ile[i] = 1;
        }
        res[0] = accumulate(ile,ile+n,0) == n;
            /* l = r = 0; */
        /* int k = 2; */
        /* vi crr; */
        /*     for(int i = 0; i < n; ++i){ */
        /*         ins(a[i], i); */
        /*         if(i - k + 1 >= 0){ */
        /*             int cr = get(i - k + 1); */
        /*                 crr.push_back(cr); */
        /*             /1* if(cr >= k || res[cr]){ *1/ */
        /*             /1*     /2* whatis(k) *2/ *1/ */
        /*             /1*     /2* whatis(cr) *2/ *1/ */
        /*             /1*     /2* kk = 0; *2/ *1/ */
        /*             /1*     crr.push_back(cr); *1/ */
        /*             /1*     /2* break; *2/ *1/ */
        /*             /1* } *1/ */
        /*             /1* else{ *1/ */
        /*             /1*     res[cr] = 1; *1/ */
        /*             /1* } *1/ */
        /*             /1* cr.pb(get(i - k + 1)); *1/ */
        /*         } */
        /*     } */
        /*     l = r = 0; */
        /*     whatis(crr) */
        /* int low = 2, high = n, mid, ans = -1; */
        int low = 2, high = n, mid, ans = -1;
        while(low <= high){
            mid = (low + high) / 2;
            bool kk = 1;
            l = r = 0;
            int k = mid;
            // right point
            /* vi crr; */
            bool res[n];
            memset(res,0,n);
            for(int i = 0; i < n; ++i){
                ins(a[i], i);
                if(i - k + 1 >= 0){
                    int cr = get(i - k + 1);
                    /* whatis(cr); */
                    /* if(cr >= k || res[cr]){ */
                    // xd
                    if(cr > (n - k) || res[cr]){
                        /* whatis(k) */
                        /* whatis(cr) */
                        kk = 0;
                        /* crr.push_back(cr); */
                        /* break; */
                    }
                    else{
                        res[cr] = 1;
                    }
                    /* cr.pb(get(i - k + 1)); */
                }
            }
            /* whatis(k) */
            /* whatis(crr) */
            if(kk){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // n == 1 edge case
        /* assert(ans != -1); */
            // bruh, 
        if(ans != -1)
        for(int i = ans - 1; i < n; ++i)
            res[i] = 1;
        FORR(i,res)
            cout << i;
        cout << '\n';
    }
}